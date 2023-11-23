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
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (auto &x : c) cin >> x;
  vector<vector<int>> dp(n, vector<int>(2));
  int ans = 0;
  vector<vector<int>> e(n);
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    --u, --v;
    e[u].push_back(v), e[v].push_back(u);
  }
  auto dfs = [&](auto dfs, int u, int fa) -> void {
    dp[u][c[u] & 1] = c[u];
    for (auto v : e[u])
      if (v != fa) {
        dfs(dfs, v, u);
        if (dp[v][k & 1] == -1) continue;
        auto f0 = dp[u][0], f1 = dp[u][1];
        if (f0 && dp[v][0]) dp[u][0] = max(dp[u][0], f0 + dp[v][0]);
        if (f1 && dp[v][1]) dp[u][0] = max(dp[u][0], f1 + dp[v][1]);
        if (f0 && dp[v][1]) dp[u][1] = max(dp[u][1], f0 + dp[v][1]);
        if (f1 && dp[v][0]) dp[u][1] = max(dp[u][1], f1 + dp[v][0]);
      }
    if (dp[u][k & 1] >= k) dp[u][k & 1] = -1, ++ans;
  };
  dfs(dfs, 0, -1);
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
