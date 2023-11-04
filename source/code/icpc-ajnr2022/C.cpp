#include <bits/stdc++.h>
using ll = long long;
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
const int MOD = 998244353;
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> sz(n + 1), son(n + 1);
  vector<ll> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
  for (int i = 1, u, v; i < n; ++i)
    cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
  auto dfs = [&](auto &&dfs, int u, int fa) -> ll {
    sz[u] = 1;
    ll ret = 1;
    for (auto v : e[u])
      if (v != fa) {
        ++son[u];
        (ret *= dfs(dfs, v, u)) %= MOD;
        sz[u] += sz[v];
      }
    return ret * fac[son[u]] % MOD;
  };
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  dp[1][1] = dfs(dfs, 1, 0);
  auto dfs1 = [&](auto &&dfs1, int u, int fa) -> void {
    vector<vector<ll>> dp1(son[u] + 1, vector<ll>(sz[u] + 1));
    int tot = 0, szz = 0;
    dp1[0][0] = 1;
    for (auto v : e[u])
      if (v != fa) {
        tot++, szz += sz[v];
        for (int i = tot; i >= 1; --i)
          for (int j = szz; j >= sz[v]; --j)
            (dp1[i][j] += dp1[i - 1][j - sz[v]]) %= MOD;
      }
    for (auto v : e[u])
      if (v != fa) {
        for (int i = 1; i <= tot; ++i)
          for (int j = sz[v]; j <= szz; ++j)
            (dp1[i][j] += MOD - dp1[i - 1][j - sz[v]]) %= MOD;
        vector<ll> f(sz[u] + 1);
        for (int i = 0; i <= sz[u] - sz[v]; ++i)
          for (int j = 0; j < son[u]; ++j)
            (f[i + 1] +=
             dp1[j][i] * fac[j] % MOD * fac[son[u] - j - 1] % MOD) %= MOD;
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= sz[u]; ++j) {
            if (i + j > n) break;
            (dp[v][i + j] += dp[u][i] * f[j] % MOD) %= MOD;
          }
        for (int i = tot; i >= 1; --i)
          for (int j = szz; j >= sz[v]; --j)
            (dp1[i][j] += dp1[i - 1][j - sz[v]]) %= MOD;
      }
    for (auto v : e[u])
      if (v != fa) dfs1(dfs1, v, u);
  };
  dfs1(dfs1, 1, 0);
  auto KSM = [&](ll x, ll p = 998244351) {
    ll ret = 1;
    while (p) {
      if (p & 1) ret = ret * x % MOD;
      x = x * x % MOD, p >>= 1;
    }
    return ret;
  };
  for (int i = 1; i <= n; ++i) {
    ll sum = 0;
    for (int j = 1; j <= n; ++j) (sum += dp[i][j]) %= MOD;
    for (int j = 1; j <= n; ++j)
      cout << dp[i][j] * dp[1][1] % MOD * KSM(sum) % MOD << " \n"[j == n];
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
