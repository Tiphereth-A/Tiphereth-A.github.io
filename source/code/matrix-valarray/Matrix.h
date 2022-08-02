template <class Tp, bool USE_EUCLIDIAN = std::is_integral_v<Tp>, class Iszero_t = std::function<bool(Tp)>>
class matrix {
  protected:
    inline ptrdiff_t do_gauss_default_(bool clear_all);
    constexpr ptrdiff_t do_gauss_euclidian_(bool clear_all);

  public:
    matrix(
        size_t row,
        size_t col,
        const Tp &val = Tp{},
        Iszero_t iszero_func = [](const Tp &x) { return x == Tp{}; });
    matrix(
        size_t row,
        size_t col,
        const std::valarray<Tp> &data_,
        Iszero_t iszero_func = [](const Tp &x) { return x == Tp{}; });

    constexpr size_t row_size() const;
    constexpr size_t col_size() const;
    inline std::valarray<Tp> view() const;

    inline Tp &operator()(size_t r, size_t c);
    inline Tp operator()(size_t r, size_t c) const;

    friend inline std::istream &operator>>(std::istream &is, self &mat);
    friend inline std::ostream &operator<<(std::ostream &os, const self &mat);


    inline std::valarray<Tp> row(size_t r) const;
    inline std::valarray<Tp> col(size_t c) const;
    inline std::valarray<Tp> diag(ptrdiff_t d) const;
    inline self submatrix(size_t row_l, size_t row_r, size_t col_l, size_t col_r) const;
    inline std::slice_array<Tp> row(size_t r);
    inline std::slice_array<Tp> col(size_t c);
    inline std::slice_array<Tp> diag(ptrdiff_t d);
    inline std::gslice_array<Tp> submatrix_raw(size_t row_l, size_t row_r, size_t col_l, size_t col_r);


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
    // using guass method to calc lhs^{-1}*rhs
    friend inline self operator|(const self &lhs, const self &rhs);
    friend inline self operator^(self lhs, const self &rhs);
    friend inline self operator<<(self lhs, const self &rhs);
    friend inline self operator>>(self lhs, const self &rhs);


    friend inline matrix<bool> operator&&(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator||(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator==(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator==(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator<(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator<=(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator>(const self &lhs, const Tp &val);
    friend inline matrix<bool> operator>=(const self &lhs, const Tp &val);

    friend inline matrix<bool> operator&&(const self &lhs, const self &rhs);
    friend inline matrix<bool> operator||(const self &lhs, const self &rhs);
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
    // using guass method to calc lhs^{-1}*rhs
    inline self &operator|=(const self &rhs);
    inline self &operator^=(const self &rhs);
    inline self &operator<<=(const self &rhs);
    inline self &operator>>=(const self &rhs);


    // [lhs] [rhs] -> [lhs; rhs]
    friend inline self merge_ud(const self &lhs, const self &rhs);
    // [lhs] [rhs] -> [lhs rhs]
    friend inline self merge_lr(const self &lhs, const self &rhs);

    inline ptrdiff_t do_gauss(bool clear_all = true);
    inline self transpose() const;
    inline self inverse() const;
    inline Tp trace() const;
    inline size_t rank() const;
    inline Tp det() const;

  protected:
    size_t r_sz, c_sz;
    Iszero_t iszero;
    std::valarray<Tp> data;
};
