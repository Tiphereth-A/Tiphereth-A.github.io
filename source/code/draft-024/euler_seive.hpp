#ifndef EULER_SEIVE_HPP
#define EULER_SEIVE_HPP 1

#include <vector>
#include <type_traits>
#include <cmath>

namespace euler_seive {
namespace type_traits__ {
struct tag_base__ {};
struct null_tag: tag_base__ {};
struct min_pfactor_tag: tag_base__ {};
struct euler_phi_tag: tag_base__ {};
struct mobius_tag: tag_base__ {};
}  // namespace type_traits__
using namespace type_traits__;

namespace detail__ {
template <class Tp, bool IsNull, class Fp, class Fij, class Mulf>
requires std::integral<Tp>
constexpr auto seive_impl_(Tp n, Fp f_p, Fij f_ij, Mulf mulf)
  -> std::pair<std::vector<Tp>, std::vector<Tp>> {
  std::vector<Tp> ret, prime;
  std::vector<bool> vis((size_t)n);

  if constexpr (!IsNull) {
    ret.resize((size_t)n);
    ret[1] = 1;
  }
  prime.reserve(n <= 55 ? 16 : n / (log((long double)n) - 4));

  for (Tp i = 2; i < n; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      if constexpr (!IsNull) ret[i] = f_p(i);
      prime.push_back(i);
    }
    for (auto &&j : prime) {
      Tp ij = i * j;
      if (ij >= n) break;
      vis[ij] = 1;
      if (i % j == 0) {
        if constexpr (!IsNull) ret[ij] = f_ij(ret, i, j);
        break;
      } else if constexpr (!IsNull) ret[ij] = mulf(ret, i, j);
    }
  }
  return {prime, ret};
}

#define PARAMS_(v, i, j) (std::vector<Tp> const &v, Tp i, Tp j)

template <class Tp>
constexpr auto seive_helper(Tp n, null_tag) {
  return seive_impl_<Tp, true>(n, nullptr, nullptr, nullptr);
}
template <class Tp>
auto seive_helper(Tp n, min_pfactor_tag) {
  return seive_impl_<Tp, false>(
    n,
    [](Tp x) { return x; },
    [] PARAMS_(v, i, j) { return j; },
    [] PARAMS_(v, i, j) { return j; });
}
template <class Tp>
constexpr auto seive_helper(Tp n, euler_phi_tag) {
  return seive_impl_<Tp, false>(
    n,
    [](Tp x) { return x - 1; },
    [] PARAMS_(v, i, j) { return v[i] * j; },
    [] PARAMS_(v, i, j) { return v[i] * v[j]; });
}
template <class Tp>
constexpr auto seive_helper(Tp n, mobius_tag) {
  return seive_impl_<Tp, false>(
    n,
    [](Tp x) { return -1; },
    [] PARAMS_(v, i, j) { return 0; },
    [] PARAMS_(v, i, j) { return v[i] * v[j]; });
}

#undef PARAMS_
}  // namespace detail__

template <class Tp, class Tag>
requires std::derived_from<Tag, tag_base__>
constexpr auto seive(Tp n) {
  return detail__::seive_helper<Tp>(n, Tag{});
}
}  // namespace euler_seive

#endif
