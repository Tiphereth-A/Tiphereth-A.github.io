#include <bits/stdc++.h>
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
template <class T>
using vec = std::vector<T>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
struct basis {
  vec<bitset<32>> base;
  basis(u32 n = 21): base(n) {}
  u32 rank() const {
    u32 ans = 0;
    for (u32 i = 0; i < base.size(); ++i) ans += base[i][i];
    return ans;
  }
  bool ins(u32 x_) {
    bitset<32> x = x_;
    bool ok = 0;
    for (u32 i = base.size() - 1; ~i; --i) {
      if (!x[i]) continue;
      if (base[i][i]) x ^= base[i];
      else {
        for (u32 j = 0; j < i; ++j)
          if (x[j]) x ^= base[j];
        for (u32 j = i + 1; j < base.size(); ++j)
          if (base[j][i]) base[j] ^= x;
        base[i] = x;
        ok = 1;
        break;
      }
    }
    return ok;
  }
};
constexpr u32 MOD = 998244353;
u64 qpow(u64 a, u64 b) {
  u64 res = 1;
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1) res = res * a % MOD;
  return res;
}
void solve(int t_ = 0) {
  u32 n;
  cin >> n;
  vec<u32> a(n);
  for (u32 &i : a) cin >> i;
  vec<basis> vbs(n + 1);
  vec<u32> cnt(n + 1), scnt(n + 1);
  for (u32 i : a) ++cnt[i];
  for_(i, 1, n)
    if (cnt[i])
      for (u32 j = 0; i * j <= n; ++j) {
        scnt[i * j] += cnt[i];
        vbs[i * j].ins(i);
      }
  i64 ans = qpow(2, n - vbs[0].rank()) - 1;
  for_(i, 1, n)
    if (cnt[i]) { (ans += qpow(2, scnt[i] - vbs[i].rank())) %= MOD; }
  cout << ans << '\n';
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  int t_ = 0;
  std::cin >> t_;
  for (i_ = 0; i_ < t_; ++i_) solve(i_);
  return 0;
}
