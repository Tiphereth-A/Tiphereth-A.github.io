#include <bits/stdc++.h>
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
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (a[x + 1] == 1) {
    } else {
      ++cnt;
    }
    a[x] = 1;
  }
  cout << cnt << "\n";
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
