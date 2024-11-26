#ifndef NDSEIVE_HPP
#define NDSEIVE_HPP 1

#include <algorithm>
#include <vector>

template <size_t N, class Tp>
struct ndvector: public std::vector<ndvector<N - 1, Tp>> {
  static_assert(N > 0, "N should be positive");

  using base_tp = ndvector<N - 1, Tp>;
  using base = std::vector<base_tp>;
  using self = ndvector<N, Tp>;

  template <class T, typename... Ts>
  ndvector(T &&n, Ts &&...args): base(n, base_tp(args...)) {}

  constexpr size_t dim() const { return N; }

  template <class T>
  void fill(T &&x) {
    for (auto &i : *this) i.fill(x);
  }
};

template <class Tp>
struct ndvector<1, Tp>: public std::vector<Tp> {
  using base = std::vector<Tp>;
  using self = ndvector<1, Tp>;

  template <class T>
  ndvector(T &&n): base(n) {}

  constexpr size_t dim() const { return 1; }

  template <class T>
  void fill(T &&x) {
    std::fill(this->begin(), this->end(), x);
  }
};

#endif