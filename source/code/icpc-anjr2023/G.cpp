#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
void solve(int t_ = 0) {
  int n, W, k;
  cin >> n >> W >> k;
  vector<pair<int, int>> a(n);
  for (auto &[w, v] : a) cin >> w >> v;
  sort(a.begin(), a.end());
  vector<vector<i64>> dp(n, vector<i64>(W + 1));
  for (int i = 0; i < n; ++i)
    for (int j = W; j >= 0; --j)
      if (i == 0) {
        if (a[i].first <= j) dp[i][j] = a[i].second;
      } else {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (a[i].first <= j)
          dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
      }
  int i = n - 1;
  multiset<int> s;
  i64 ans = 0, ret = 0;
  for (; s.size() != k; --i) {
    s.insert(a[i].second);
    ret += a[i].second;
  }
  for (; i >= 0; --i) {
    ans = max(ans, ret + dp[i][W]);
    s.insert(a[i].second);
    ret += a[i].second;
    ret -= *s.begin();
    s.erase(s.begin());
  }
  ans = max(ans, ret);
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
