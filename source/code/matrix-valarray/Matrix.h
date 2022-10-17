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
  inline std::valarray<Tp> view() const;

  inline Tp &operator()(size_t r, size_t c);
  inline Tp operator()(size_t r, size_t c) const;

  friend inline std::istream &operator>>(std::istream &is, self &mat);
  friend inline std::ostream &operator<<(std::ostream &os, const self &mat);

  inline std::valarray<Tp> row(size_t r) const;
  inline std::valarray<Tp> col(size_t c) const;
  inline std::valarray<Tp> diag_cycle(ptrdiff_t d) const;
  inline std::slice_array<Tp> row(size_t r);
  inline std::slice_array<Tp> col(size_t c);
  inline std::slice_array<Tp> diag_cycle(ptrdiff_t d);
  inline std::valarray<Tp> row_varray(size_t r) const;
  inline std::valarray<Tp> col_varray(size_t c) const;
  inline std::valarray<Tp> diag_cycle_varray(ptrdiff_t d) const;
  inline self
  submatrix(size_t row_l, size_t row_r, size_t col_l, size_t col_r) const;
  inline std::gslice_array<Tp>
  submatrix_raw(size_t row_l, size_t row_r, size_t col_l, size_t col_r);

  friend inline self operator+(self lhs, const Tp &val);
  friend inline self operator-(self lhs, const Tp &val);
  friend inline self operator%(self lhs, const Tp &val);
  friend inline self operator*(self lhs, const Tp &val);
  friend inline self operator/(self lhs, const Tp &val);
  friend inline self operator&(self lhs, const Tp &val);
  friend inline self operator|(self lhs, const Tp &val);
  friend inline self operator^(self lhs, const Tp &val);
  friend inline self operator<<(self lhs, const Tp &val);
  friend inline self operator>>(self lhs, const Tp &val);

  friend inline self operator+(self lhs, const self &rhs);
  friend inline self operator-(self lhs, const self &rhs);
  friend inline self operator*(const self &lhs, const self &rhs);
  friend inline self operator/(const self &lhs, const self &rhs);
  friend inline self operator%(self lhs, const self &rhs);
  friend inline self operator&(self lhs, const self &rhs);
  // using gauss method to calc lhs^{-1}*rhs
  friend inline self operator|(const self &lhs, const self &rhs);
  friend inline self operator^(self lhs, const self &rhs);
  friend inline self operator<<(self lhs, const self &rhs);
  friend inline self operator>>(self lhs, const self &rhs);

  friend inline matrix<bool> operator==(const self &lhs, const Tp &val);
  friend inline matrix<bool> operator==(const self &lhs, const Tp &val);
  friend inline matrix<bool> operator<(const self &lhs, const Tp &val);
  friend inline matrix<bool> operator<=(const self &lhs, const Tp &val);
  friend inline matrix<bool> operator>(const self &lhs, const Tp &val);
  friend inline matrix<bool> operator>=(const self &lhs, const Tp &val);

  friend inline matrix<bool> operator==(const self &lhs, const self &rhs);
  friend inline matrix<bool> operator==(const self &lhs, const self &rhs);
  friend inline matrix<bool> operator<(const self &lhs, const self &rhs);
  friend inline matrix<bool> operator<=(const self &lhs, const self &rhs);
  friend inline matrix<bool> operator>(const self &lhs, const self &rhs);
  friend inline matrix<bool> operator>=(const self &lhs, const self &rhs);

  inline self &operator+=(const Tp &val);
  inline self &operator-=(const Tp &val);
  inline self &operator*=(const Tp &val);
  inline self &operator/=(const Tp &val);
  inline self &operator%=(const Tp &val);
  inline self &operator&=(const Tp &val);
  inline self &operator|=(const Tp &val);
  inline self &operator^=(const Tp &val);
  inline self &operator<<=(const Tp &val);
  inline self &operator>>=(const Tp &val);

  inline self &operator+=(const self &rhs);
  inline self &operator-=(const self &rhs);
  inline self &operator*=(const self &rhs);
  inline self &operator/=(const self &rhs);
  inline self &operator%=(const self &rhs);
  inline self &operator&=(const self &rhs);
  // using gauss method to calc lhs^{-1}*rhs
  inline self &operator|=(const self &rhs);
  inline self &operator^=(const self &rhs);
  inline self &operator<<=(const self &rhs);
  inline self &operator>>=(const self &rhs);

  // [lhs] [rhs] -> [lhs; rhs]
  friend inline self merge_ud(const self &lhs, const self &rhs);
  // [lhs] [rhs] -> [lhs rhs]
  friend inline self merge_lr(const self &lhs, const self &rhs);

  constexpr void swap_row(size_t r1, size_t r2);
  constexpr void swap_col(size_t c1, size_t c2);
  constexpr void swap_diag_cycle(size_t d1, size_t d2);

  inline virtual int64_t
  do_gauss_range(size_t row_start, size_t row_end, bool clear_all = true);
  inline ptrdiff_t do_gauss(bool clear_all = true);
  inline self transpose() const;
  inline self inverse() const;
  inline Tp trace() const;
  inline size_t rank() const;
  inline Tp det() const;
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

  inline int64_t do_gauss_range(size_t row_start,
                                size_t row_end,
                                bool clear_all = true) override;
};

class matrix_bool: public matrix<bool> {
public:
  matrix_bool(size_t row, size_t col, bool val = false);
  matrix_bool(size_t row, size_t col, const std::valarray<bool> &data_);

  inline int64_t do_gauss_range(size_t row_start,
                                size_t row_end,
                                bool clear_all = true) override;
};
