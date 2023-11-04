#include <bits/stdc++.h>
using ll = long long;
using i64 = ll;
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x) b.push_back(x), x /= 2;
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  auto dis = [](i64 a, i64 b) {
    if (a >= b) return a - b;
    i64 ret = b - a, t = 0;
    while (b > a) {
      b /= 2, ++t;
      ret = min(ret, t + abs(a - b));
    }
    return ret;
  };
  i64 ans = INT64_MAX;
  for (auto x : b) {
    vector<i64> ret;
    for (auto y : a) ret.push_back(dis(x, y));
    sort(ret.begin(), ret.end());
    i64 rett = 0;
    for (int i = 0; i < n - m; ++i) rett += ret[i];
    ans = min(ans, rett);
  }
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
