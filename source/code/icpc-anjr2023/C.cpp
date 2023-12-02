#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
void solve(int t_ = 0) {
  i64 p, m;
  cin >> p >> m;
  if (p == 2) {
    cout << m / 2 + 1 << '\n';
    return;
  }
  i64 k = max(i64(0), m / p - 2), ans = k;
  for (i128 i = 0; i <= 10; ++i) ans += (((k + i) * p + 1) ^ (p - 1)) <= m;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  int t_ = 0;
  cin >> t_;
  for (i_ = 0; i_ < t_; ++i_) solve(i_);
  return 0;
}
