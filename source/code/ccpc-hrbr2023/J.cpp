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
  vector<vec<int>> e(n);
  auto add = [&](int u, int v) { e[u].push_back(v), e[v].push_back(u); };
  for (int i = 0, u, v; i < m; ++i) cin >> u >> v, --u, --v, add(u, v);
  int sg = 0;
  vector<int> rt, sz(n);
  auto dfs = [&](auto dfs, int u) -> void {
    sz[u] = 1;
    for (auto v : e[u])
      if (!sz[v]) dfs(dfs, v), sz[u] += sz[v];
  };
  auto ssg = [](int x) {
    if (!x) return 0;
    return x & 1 ? 1 : 2;
  };
  for (int i = 0; i < n; ++i)
    if (!sz[i]) {
      dfs(dfs, i), rt.push_back(i);
      sg ^= ssg(sz[i]);
    }
  if (!sg) return void(cout << 0);
  int ans = 0;
  auto getans = [&](auto getans, int u, int fa, int ssz) -> void {
    int t = ssg(ssz - sz[u]);
    for (auto v : e[u])
      if (v != fa) {
        if (0 == (sg ^ (ssg(sz[v]) ^ ssg(ssz - sz[v])))) ++ans;
        getans(getans, v, u, ssz);
        t ^= ssg(sz[v]);
      }
    if (0 == (sg ^ t)) ++ans;
  };
  for (auto x : rt) {
    sg ^= ssg(sz[x]);
    getans(getans, x, x, sz[x]);
    sg ^= ssg(sz[x]);
  }
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
