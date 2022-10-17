namespace Matrix {
template <class Tp, class Iszero_t = std::function<bool(Tp)>>
class matrix {
#define ASSERTT_(expr, text) \
  if (!(expr)) throw std::runtime_error(text);
#define ASSERT_(expr) ASSERTT_(expr, #expr)
  using self = matrix<Tp, Iszero_t>;

protected:
  constexpr bool
  gauss_swapr__(size_t &row_, size_t row_pre_, size_t col_, size_t row_end) {
    row_ = row_pre_;
    for (size_t j = row_ + 1; j < row_end; ++j)
      if (std::abs((*this)(j, col_)) > std::abs((*this)(row_, col_))) row_ = j;
    if (row_ != row_pre_) {
      swap_row(row_, row_pre_);
      return true;
    }
    return false;
  }

protected:
  size_t r_sz, c_sz;
  Iszero_t iszero;
  std::valarray<Tp> data;

public:
  matrix(size_t row, size_t col, Iszero_t iszero_func, const Tp &val = Tp{})
    : r_sz(row), c_sz(col), iszero(iszero_func), data(val, row * col) {
    ASSERT_(row > 0 && col > 0);
  }
  matrix(size_t row,
         size_t col,
         Iszero_t iszero_func,
         const std::valarray<Tp> &data_)
    : r_sz(row), c_sz(col), iszero(iszero_func), data(data_) {
    ASSERT_(row > 0 && col > 0);
  }
  constexpr size_t row_size() const { return r_sz; }
  constexpr size_t col_size() const { return c_sz; }
  inline std::valarray<Tp> view() const { return data; }

  inline Tp &operator()(size_t r, size_t c) { return data[r * col_size() + c]; }
  inline Tp operator()(size_t r, size_t c) const {
    return data[r * col_size() + c];
  }

  friend inline std::istream &operator>>(std::istream &is, self &mat) {
    for (auto &i : mat.data) is >> i;
    return is;
  }
  friend inline std::ostream &operator<<(std::ostream &os, const self &mat) {
    for (size_t i = 0; i < mat.row_size(); ++i)
      for (size_t j = 0; j < mat.col_size(); ++j)
        os << mat(i, j) << " \n"[j == mat.col_size() - 1];
    return os;
  }

#define INVOKES_SLICE__(name, para1_t, para1, ...)                          \
  inline std::valarray<Tp> name(para1_t para1)                              \
    const __VA_ARGS__ inline std::slice_array<Tp>                           \
    name(para1_t para1) __VA_ARGS__ inline std::valarray<Tp> name##_varray( \
      para1_t para1) const __VA_ARGS__

  INVOKES_SLICE__(row, size_t, r, {
    return data[std::slice(r * col_size(), col_size(), 1)];
  })
  INVOKES_SLICE__(col, size_t, c, {
    return data[std::slice(c, row_size(), col_size())];
  })
  INVOKES_SLICE__(diag_cycle, ptrdiff_t, d, {
    return data[d >= 0 ?
                  std::slice(d, row_size(), col_size() + 1) :
                  std::slice(-d * row_size(), row_size(), col_size() + 1)];
  })

#undef INVOKES_SLICE__

  inline self
  submatrix(size_t row_l, size_t row_r, size_t col_l, size_t col_r) const {
    return self(row_r - row_l,
                col_r - col_l,
                data[std::gslice(row_l * col_size() + col_l,
                                 {row_r - row_l, col_r - col_l},
                                 {col_size(), 1})],
                iszero);
  }

  inline std::gslice_array<Tp>
  submatrix_raw(size_t row_l, size_t row_r, size_t col_l, size_t col_r) {
    return data[std::gslice(row_l * col_size() + col_l,
                            {row_r - row_l, col_r - col_l},
                            {col_size(), 1})];
  }

#define OPB__(op)                                                              \
  friend inline matrix<bool> operator op(const self &lhs, const Tp &val) {     \
    return matrix<bool>(lhs.row_size(), lhs.col_size(), lhs.data op val);      \
  }                                                                            \
  friend inline matrix<bool> operator op(const self &lhs, const self &rhs) {   \
    ASSERT_(lhs.row_size() == rhs.row_size() &&                                \
            lhs.col_size() == rhs.col_size());                                 \
    return matrix<bool>(lhs.row_size(), lhs.col_size(), lhs.data op rhs.data); \
  }

  OPB__(==)
  OPB__(!=)
  OPB__(<)
  OPB__(<=)
  OPB__(>)
  OPB__(>=)

#undef OPB__

#define OP__(op)                                                           \
  friend inline self operator op(self lhs, const Tp &val) {                \
    return lhs op## = val;                                                 \
  }                                                                        \
  inline self &operator op##=(const Tp &val) {                             \
    data op## = val;                                                       \
    return *this;                                                          \
  }                                                                        \
  friend inline self operator op(self lhs, const self &rhs) {              \
    return lhs op## = rhs;                                                 \
  }                                                                        \
  inline self &operator op##=(const self &rhs) {                           \
    ASSERT_(row_size() == rhs.row_size() && col_size() == rhs.col_size()); \
    data op## = rhs.data;                                                  \
    return *this;                                                          \
  }

  OP__(+)
  OP__(-)
  OP__(%)
  OP__(&)
  OP__(^)
  OP__(<<)
  OP__(>>)

#undef OP__

#define OPF__(op, ...)                                             \
  friend inline self operator op(self lhs, const Tp &val) {        \
    return lhs op## = val;                                         \
  }                                                                \
  inline self &operator op##=(const Tp &val) {                     \
    data op## = val;                                               \
    return *this;                                                  \
  }                                                                \
  friend inline self operator op(const self &lhs, const self &rhs) \
    __VA_ARGS__ inline self &                                      \
    operator op##=(const self &rhs) {                              \
    return *this = *this op rhs;                                   \
  }
  OPF__(*, {
    ASSERT_(lhs.col_size() == rhs.row_size());
    self ret(lhs.row_size(), rhs.col_size(), lhs.iszero, Tp{});
    for (size_t i = 0; i < ret.row_size(); ++i) {
      auto &&r_ = lhs.row(i);
      for (size_t j = 0; j < ret.col_size(); ++j)
        ret(i, j) = (r_ * rhs.col(j)).sum();
    }
    return ret;
  })

  OPF__(/, { return lhs * rhs.inverse(); })
  // using guass method to calc lhs^{-1}*rhs
  OPF__(|, {
    ASSERT_(lhs.row_size() == lhs.col_size() &&
            rhs.row_size() == lhs.row_size());
    self tmp_ = merge_lr(lhs, rhs);
    ASSERTT_(std::abs(tmp_.do_gauss()) == lhs.row_size(), "Inverse not exist");
    for (size_t i = 0; i < lhs.row_size(); ++i)
      tmp_
        .data[std::slice(i * (lhs.col_size() + rhs.col_size()) + lhs.col_size(),
                         rhs.col_size(),
                         1)] /= std::valarray<Tp>(tmp_(i, i), rhs.col_size());
    return tmp_.submatrix(
      0, rhs.row_size(), lhs.col_size(), lhs.col_size() + rhs.col_size());
  })

#undef OPF__

  // [lhs] [rhs] -> [lhs; rhs]
  friend inline self merge_ud(const self &lhs, const self &rhs) {
    ASSERT_(lhs.col_size() == rhs.col_size());
    self ret(lhs.row_size() + rhs.row_size(), lhs.col_size(), Tp{}, lhs.iszero);
    ret.data[std::slice(0, lhs.row_size() * lhs.col_size(), 1)] = lhs.view();
    ret.data[std::slice(
      lhs.row_size() * lhs.col_size(), rhs.row_size() * rhs.col_size(), 1)] =
      rhs.view();
    return ret;
  }

  // [lhs] [rhs] -> [lhs rhs]
  friend inline self merge_lr(const self &lhs, const self &rhs) {
    ASSERT_(lhs.row_size() == rhs.row_size());
    self ret(lhs.row_size(), lhs.col_size() + rhs.col_size(), Tp{}, lhs.iszero);
    ret.data[std::gslice(
      0, {lhs.row_size(), lhs.col_size()}, {ret.col_size(), 1})] = lhs.view();
    ret.data[std::gslice(
      lhs.col_size(), {rhs.row_size(), rhs.col_size()}, {ret.col_size(), 1})] =
      rhs.view();
    return ret;
  }

  constexpr void swap_row(size_t r1, size_t r2) {
    if (r1 == r2) return;
    std::valarray<Tp> __ = row(r1);
    row(r1) = row(r2);
    row(r2) = __;
  }
  constexpr void swap_col(size_t c1, size_t c2) {
    if (c1 == c2) return;
    std::valarray<Tp> __ = col(c1);
    col(c1) = col(c2);
    col(c2) = __;
  }
  constexpr void swap_diag_cycle(size_t d1, size_t d2) {
    if (d1 == d2) return;
    std::valarray<Tp> __ = diag_cycle(d1);
    diag_cycle(d1) = diag_cycle(d2);
    diag_cycle(d2) = __;
  }

  inline virtual int64_t
  do_gauss_range(size_t row_start, size_t row_end, bool clear_all = true) {
    assert(row_start < row_end && row_end <= row_size());
    size_t rk = 0;
    bool neg = false;
    for (size_t i = row_start, now_row; i < std::min(row_end, col_size());
         ++i) {
      neg ^= gauss_swapr__(now_row, rk, i, row_end);
      if (iszero((*this)(rk, i))) continue;
      std::valarray<Tp> tmp_ =
        data[std::slice(rk * col_size() + i + 1, col_size() - i - 1, 1)];
      for (int64_t j = clear_all ? 0 : rk + 1; j < (int64_t)row_end; ++j) {
        if (j == rk || iszero((*this)(j, i))) continue;
        Tp &&_ = (*this)(j, i) / (*this)(rk, i);
        (*this)(j, i) = 0;
        data[std::slice(j * col_size() + i + 1, col_size() - i - 1, 1)] -=
          tmp_ * _;
      }
      ++rk;
    }
    return neg ? -rk : rk;
  }
  inline ptrdiff_t do_gauss(bool clear_all = true) {
    return do_gauss_range(0, std::min(row_size(), col_size()), clear_all);
  }

  inline self transpose() const {
    self ret(col_size(), row_size(), iszero, Tp{});
    for (size_t i = 0; i < row_size(); ++i) ret.col(i) = row(i);
    return ret;
  }

  inline self inverse() const {
    ASSERT_(row_size() == col_size());
    self ret(row_size(), col_size(), iszero, Tp{});
    ret.diag_cycle(0) = 1;
    ASSERTT_(std::abs((ret = merge_lr(*this, ret)).do_gauss()) == row_size(),
             "Inverse not exist");
    for (size_t i = 0; i < row_size(); ++i)
      ret.data[std::slice((i * 2 + 1) * col_size(), col_size(), 1)] /=
        std::valarray<Tp>(ret(i, i), col_size());
    ret = ret.submatrix(0, row_size(), col_size(), col_size() * 2);
    return ret;
  }
  inline Tp trace() const { return diag_cycle(0).sum(); }
  inline size_t rank() const { return std::abs(self(*this).do_gauss(false)); }

  inline Tp det() const {
    ASSERT_(row_size() == col_size());
    self tmp_(*this);
    ptrdiff_t rk_ = tmp_.do_gauss(false);
    if (std::abs(rk_) != row_size()) return Tp{};
    Tp ret = tmp_(0, 0);
    for (size_t i = 1; i < row_size(); ++i) ret *= tmp_(i, i);
    return rk_ < 0 ? -ret : ret;
  }

  friend self pow(self mat, size_t b) {
    self res(mat.row_size(), mat.col_size(), mat.iszero, Tp{});
    res.diag_cycle(0) = 1;
    for (; b; b >>= 1, mat *= mat)
      if (b & 1) res *= mat;
    return res;
  }
#undef ASSERT_
#undef ASSERTT_
};

template <class Tp>
class matrix_int: public matrix<Tp> {
  static_assert(std::is_integral<Tp>::value);

  using self = matrix_int<Tp>;
  using base = matrix<Tp>;

private:
  constexpr static auto isz__ = [](Tp const &x) { return x == 0; };

public:
  matrix_int(size_t row, size_t col, const Tp &val = Tp{})
    : base(row, col, isz__, val) {}
  matrix_int(size_t row, size_t col, const std::valarray<Tp> &data_)
    : base(row, col, isz__, data_) {}

  inline int64_t do_gauss_range(size_t row_start,
                                size_t row_end,
                                bool clear_all = true) override {
    assert(row_start < row_end && row_end <= this->row_size());
    int64_t rk = 0;
    bool neg = false;
    for (size_t i = row_start, now_row; i < std::min(row_end, this->col_size());
         ++i) {
      neg ^= this->gauss_swapr__(now_row, rk, i, row_end);
      if (this->iszero((*this)(rk, i))) continue;
      std::valarray<Tp> tmp_ = this->row(rk);
      for (int64_t j = clear_all ? 0 : rk; j < (int64_t)row_end; ++j) {
        if (j == rk || this->iszero((*this)(j, i))) continue;
        Tp lcm_ = std::lcm((*this)(j, i), (*this)(rk, i)),
           j_ = lcm_ / (*this)(j, i), i_ = lcm_ / (*this)(rk, i);
        this->row(j) = j_ * this->row_varray(j) - i_ * tmp_;
      }
      ++rk;
    }
    return neg ? -rk : rk;
  }
};

class matrix_bool: public matrix<bool> {
  using self = matrix_bool;
  using base = matrix<bool>;

private:
  constexpr static auto isz__ = [](bool x) { return !x; };

public:
  matrix_bool(size_t row, size_t col, bool val = false)
    : base(row, col, isz__, val) {}
  matrix_bool(size_t row, size_t col, const std::valarray<bool> &data_)
    : base(row, col, isz__, data_) {}

  inline int64_t do_gauss_range(size_t row_start,
                                size_t row_end,
                                bool clear_all = true) override {
    assert(row_start < row_end && row_end <= this->row_size());
    size_t rk = 0;
    bool neg = false;
    for (size_t i = row_start, now_row; i < std::min(row_end, this->col_size());
         ++i) {
      neg ^= this->gauss_swapr__(now_row, rk, i, row_end);
      if (this->iszero((*this)(rk, i))) continue;
      std::valarray<bool> tmp_ = data[std::slice(
        rk * this->col_size() + i + 1, this->col_size() - i - 1, 1)];
      for (int64_t j = clear_all ? 0 : rk + 1; j < (int64_t)row_end; ++j) {
        if (j == rk || this->iszero((*this)(j, i))) continue;
        (*this)(j, i) = false;
        data[std::slice(
          j * this->col_size() + i + 1, this->col_size() - i - 1, 1)] ^= tmp_;
      }
      ++rk;
    }
    return neg ? -rk : rk;
  }
};
}  // namespace Matrix
using Matrix::matrix, Matrix::matrix_int, Matrix::matrix_bool;
