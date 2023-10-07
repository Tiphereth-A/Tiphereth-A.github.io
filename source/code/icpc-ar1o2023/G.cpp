#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)
#define pii pair<int, int>

void solve() {
  int n;
  const int mod = 998244353;
  auto KSM = [&](int x, int p) {
    int ret = 1;
    while (p) {
      if (p & 1) ret = 1ll * ret * x % mod;
      x = 1ll * x * x % mod, p >>= 1;
    }
    return ret;
  };
  cin >> n;
  vector<pii> e(n);
  vector<int> fa(n + 1), dep(n + 1), f(n + 1), sz(n + 1, 1);
  vector<vector<int>> E(n + 1);
  iota(fa.begin(), fa.end(), 0);
  function<int(int)> GF = [&](int x) {
    return x == fa[x] ? x : fa[x] = GF(fa[x]);
  };
  Rep(i, 1, n - 1) cin >> e[i].first >> e[i].second;
  Rep(i, 1, n - 1) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v), E[v].push_back(u);
  }
  function<void(int, int)> DFS = [&](int u, int fa) {
    f[u] = fa, dep[u] = dep[fa] + 1;
    for (auto v : E[u])
      if (v != fa) DFS(v, u);
  };
  DFS(1, 0);
  int ans = 1;
  Rep(i, 1, n - 1) {
    int u = e[i].first, v = e[i].second;
    int fu = GF(u), fv = GF(v);
    if (dep[fu] > dep[fv]) swap(u, v), swap(fu, fv);
    if (GF(f[fv]) != fu) {
      cout << 0;
      return;
    }
    ans = 1ll * ans * sz[fu] % mod * sz[fv] % mod;
    sz[fu] += sz[fv];
    fa[fv] = fu;
  }
  cout << KSM(ans, mod - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef MULCAS
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; ++i)
#endif
    solve();
  return 0;
}