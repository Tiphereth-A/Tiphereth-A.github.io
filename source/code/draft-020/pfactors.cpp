#include <cstdint>
using u64 = std::uint64_t;

extern bool is_prime_miller_rabin(u64 n);
extern u64 pollard_rho(u64 n);

template <typename F>
void pfactors(u64 n, F callback) {
  if (n < 2) return;
  if (is_prime_miller_rabin(n)) {
    callback(n);
    return;
  }
  const u64 g = pollard_rho(n);
  pfactors(n / g, callback), pfactors(g, callback);
}

// examples:

#include <vector>

u64 get_max_prime_factor(u64 n) {
  u64 max_pf = 0;
  pfactors(n, [&](u64 p) { max_pf = std::max(max_pf, p); });
  return max_pf;
}

std::vector<u64> get_all_prime_factors(u64 n) {
  std::vector<u64> prime_factors;
  pfactors(n, [&](u64 p) { prime_factors.push_back(p); });
  return prime_factors;
}
