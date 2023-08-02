template <class Tp, class Iszero_t = std::function<bool(Tp)>>
class matrix {
  using self = matrix<Tp, Iszero_t>;

public:
  matrix(size_t row, size_t col, Iszero_t iszero_func, const Tp &val);
  matrix(size_t row,
         size_t col,
         Iszero_t iszero_func,
         const std::valarray<Tp> &data_);

  constexpr size_t row_size() const;
  constexpr size_t col_size() const;
  std::valarray<Tp> view() const;

  Tp &operator()(size_t r, size_t c);
  Tp operator()(size_t r, size_t c) const;

  friend std::istream &operator>>(std::istream &is, self &mat);
  friend std::ostream &operator<<(std::ostream &os, const self &mat);

  std::valarray<Tp> row(size_t r) const;
  std::valarray<Tp> col(size_t c) const;
  std::valarray<Tp> diag_cycle(ptrdiff_t d) const;
  std::slice_array<Tp> row(size_t r);
  std::slice_array<Tp> col(size_t c);
  std::slice_array<Tp> diag_cycle(ptrdiff_t d);
  std::valarray<Tp> row_varray(size_t r) const;
  std::valarray<Tp> col_varray(size_t c) const;
  std::valarray<Tp> diag_cycle_varray(ptrdiff_t d) const;
  self submatrix(size_t row_l, size_t row_r, size_t col_l, size_t col_r) const;
  std::gslice_array<Tp>
  submatrix_raw(size_t row_l, size_t row_r, size_t col_l, size_t col_r);

  friend self operator+(self lhs, const Tp &val);
  friend self operator-(self lhs, const Tp &val);
  friend self operator%(self lhs, const Tp &val);
  friend self operator*(self lhs, const Tp &val);
  friend self operator/(self lhs, const Tp &val);
  friend self operator&(self lhs, const Tp &val);
  friend self operator|(self lhs, const Tp &val);
  friend self operator^(self lhs, const Tp &val);
  friend self operator<<(self lhs, const Tp &val);
  friend self operator>>(self lhs, const Tp &val);

  friend self operator+(self lhs, const self &rhs);
  friend self operator-(self lhs, const self &rhs);
  friend self operator*(const self &lhs, const self &rhs);
  friend self operator/(const self &lhs, const self &rhs);
  friend self operator%(self lhs, const self &rhs);
  friend self operator&(self lhs, const self &rhs);
  // using gauss method to calc lhs^{-1}*rhs
  friend self operator|(const self &lhs, const self &rhs);
  friend self operator^(self lhs, const self &rhs);
  friend self operator<<(self lhs, const self &rhs);
  friend self operator>>(self lhs, const self &rhs);

  friend matrix<bool> operator==(const self &lhs, const Tp &val);
  friend matrix<bool> operator==(const self &lhs, const Tp &val);
  friend matrix<bool> operator<(const self &lhs, const Tp &val);
  friend matrix<bool> operator<=(const self &lhs, const Tp &val);
  friend matrix<bool> operator>(const self &lhs, const Tp &val);
  friend matrix<bool> operator>=(const self &lhs, const Tp &val);

  friend matrix<bool> operator==(const self &lhs, const self &rhs);
  friend matrix<bool> operator==(const self &lhs, const self &rhs);
  friend matrix<bool> operator<(const self &lhs, const self &rhs);
  friend matrix<bool> operator<=(const self &lhs, const self &rhs);
  friend matrix<bool> operator>(const self &lhs, const self &rhs);
  friend matrix<bool> operator>=(const self &lhs, const self &rhs);

  self &operator+=(const Tp &val);
  self &operator-=(const Tp &val);
  self &operator*=(const Tp &val);
  self &operator/=(const Tp &val);
  self &operator%=(const Tp &val);
  self &operator&=(const Tp &val);
  self &operator|=(const Tp &val);
  self &operator^=(const Tp &val);
  self &operator<<=(const Tp &val);
  self &operator>>=(const Tp &val);

  self &operator+=(const self &rhs);
  self &operator-=(const self &rhs);
  self &operator*=(const self &rhs);
  self &operator/=(const self &rhs);
  self &operator%=(const self &rhs);
  self &operator&=(const self &rhs);
  // using gauss method to calc lhs^{-1}*rhs
  self &operator|=(const self &rhs);
  self &operator^=(const self &rhs);
  self &operator<<=(const self &rhs);
  self &operator>>=(const self &rhs);

  // [lhs] [rhs] -> [lhs; rhs]
  friend self merge_ud(const self &lhs, const self &rhs);
  // [lhs] [rhs] -> [lhs rhs]
  friend self merge_lr(const self &lhs, const self &rhs);

  constexpr void swap_row(size_t r1, size_t r2);
  constexpr void swap_col(size_t c1, size_t c2);
  constexpr void swap_diag_cycle(size_t d1, size_t d2);

  virtual int64_t
  do_gauss_range(size_t row_start, size_t row_end, bool clear_all = true);
  ptrdiff_t do_gauss(bool clear_all = true);
  self transpose() const;
  self inverse() const;
  Tp trace() const;
  size_t rank() const;
  Tp det() const;
  friend self pow(self mat, size_t b);

protected:
  size_t r_sz, c_sz;
  Iszero_t iszero;
  std::valarray<Tp> data;
};

template <class Tp>
class matrix_int: public matrix<Tp> {
public:
  matrix_int(size_t row, size_t col, const Tp &val = Tp{});
  matrix_int(size_t row, size_t col, const std::valarray<Tp> &data_);

  int64_t do_gauss_range(size_t row_start,
                         size_t row_end,
                         bool clear_all = true) override;
};

class matrix_bool: public matrix<bool> {
public:
  matrix_bool(size_t row, size_t col, bool val = false);
  matrix_bool(size_t row, size_t col, const std::valarray<bool> &data_);

  int64_t do_gauss_range(size_t row_start,
                         size_t row_end,
                         bool clear_all = true) override;
};
