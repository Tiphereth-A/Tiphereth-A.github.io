#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<int> a(40);
  for (int i = 0; i < n; ++i) {
    i64 x;
    cin >> x;
    for (int j = 0; j < 40; ++j)
      if ((x >> j) & 1) a[j] += 1;
  }
  while (a.back() == 0) a.pop_back();
  int ans = 0;
  while (a.size()) {
    ++ans;
    int flag = -1;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] && flag != -1) a[i] -= 1, a[flag] += 1, flag = -1;
      if (a[i]) a[i] -= 1;
      else if (flag == -1) flag = i;
    }
    while (a.size() && a.back() == 0) a.pop_back();
  }
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
