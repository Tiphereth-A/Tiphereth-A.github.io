// Z[sqrt(p)], p < 0
//! NO overflow protect
template <class Tp, int p = -1>
class GaussInt {
  static_assert(p < 0, "p should be negative");

  using self = GaussInt<Tp, p>;

protected:
  Tp r_, i_;

public:
  constexpr GaussInt(Tp real = Tp{}, Tp imag = Tp{}): r_(real), i_(imag) {}

  constexpr friend std::istream &operator>>(std::istream &is, self &x) { return is >> x.r_ >> x.i_; }
  constexpr friend std::ostream &operator<<(std::ostream &os, const self &x) { return os << x.r_ << " " << x.i_; }

  constexpr Tp norm() const { return r_ * r_ + i_ * i_ * -p; }
  constexpr self conj() const { return self(r_, -i_); }

  constexpr self &operator*=(const Tp &k) {
    r_ *= k;
    i_ *= k;
    return *this;
  }
  constexpr friend self operator*(self lhs, const Tp &k) { return lhs *= k; }
  constexpr friend self operator*(const Tp &k, self lhs) { return lhs *= k; }
  constexpr self &operator/=(const Tp &k) {
    r_ /= k;
    i_ /= k;
    return *this;
  }
  constexpr friend self operator/(self lhs, const Tp &k) { return lhs /= k; }

  constexpr self &operator+=(const self &rhs) {
    r_ += rhs.r_;
    i_ += rhs.i_;
    return *this;
  }
  constexpr friend self operator+(self lhs, const self &rhs) { return lhs += rhs; }
  constexpr self &operator-=(const self &rhs) {
    r_ -= rhs.r_;
    i_ -= rhs.i_;
    return *this;
  }
  constexpr friend self operator-(self lhs, const self &rhs) { return lhs -= rhs; }

  constexpr self &operator*=(const self &rhs) {
    Tp a = r_, b = i_;
    r_ = a * rhs.r_ + b * rhs.i_ * p;
    i_ = b * rhs.r_ + a * rhs.i_;
    return *this;
  }
  constexpr friend self operator*(self lhs, const self &rhs) { return lhs *= rhs; }
  constexpr self &operator/=(const self &rhs) { return (*this *= rhs.conj()) /= rhs.norm(); }
  constexpr friend self operator/(self lhs, const self &rhs) { return lhs /= rhs; }
};
