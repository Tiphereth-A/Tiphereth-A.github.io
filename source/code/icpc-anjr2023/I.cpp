#include <bits/stdc++.h>
using namespace std;
template <class Tp>
using vec = vector<Tp>;
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vec<pair<int, int>> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  int flag = 0;
  for (int i = 0; i < m; ++i) {
    if (a[i].first < a[i].second) {
      flag = 1;
      break;
    }
    if (i == 0) continue;
    if (a[i - 1].first == a[i].first) {
      if (a[i].second != a[i - 1].second) {
        flag = 1;
        break;
      } else continue;
    }
    auto l = a[i - 1].first - a[i - 1].second, r = a[i - 1].first;
    auto li = a[i].first - a[i].second, ri = a[i].first;
    if (l == li) continue;
    if (a[i - 1].second == 0) {
      if (li < r) {
        flag = 1;
        break;
      }
    } else {
      if (li <= r) {
        flag = 1;
        break;
      }
    }
  }
  if (flag) cout << "No\n";
  else cout << "Yes\n";
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
