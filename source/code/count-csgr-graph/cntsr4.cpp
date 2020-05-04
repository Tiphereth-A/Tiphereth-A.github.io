#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
inline auto solve([[maybe_unused]] int t_ = 0) -> void {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  vector<vector<int>> dg(n + 1);
  vector<vector<int>> g(n + 1);
  auto __lt__ = [&](int u, int v) -> bool {
    return deg[u] < deg[v] || (deg[u] == deg[v] && u < v);
  };
  {
    vector<pair<int, int>> edges;
    edges.reserve(m);
    for (int i = 1, u, v; i <= m; ++i) {
      cin >> u >> v;
      ++deg[u];
      ++deg[v];
      edges.emplace_back(u, v);
    }
    for (auto [u, v] : edges) {
      if (!__lt__(u, v)) swap(u, v);
      dg[u].push_back(v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  i64 c4 = 0;
  vector<int> pre(n + 1), cnt(n + 1);
  for (int u = 1; u <= n; ++u)
    for (auto &&v : dg[u])
      for (auto &&w : g[v]) {
        if (u == w || !__lt__(u, w)) continue;
        if (pre[w] != u) cnt[w] = 0;
        c4 += cnt[w]++;
        pre[w] = u;
      }
  cout << c4 << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int i_ = 0;
  solve(i_);
  return 0;
}
