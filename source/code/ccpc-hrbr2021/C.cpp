#include <bits/stdc++.h>
using namespace std;
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<vector<int>> e(n);
  for (int i = 1, x; i < n; ++i) cin >> x, --x, e[x].push_back(i);
  vector<int> col(n);
  for (auto &x : col) cin >> x;
  int cnt = 0;
  vector<int> ans(n), mx(n), id(n);
  vector<set<int>> s(n);
  vector<map<int, int>> m(n);
  auto merge = [&](int u, int x) {
    ++m[u][x];
    if (m[u][x] > mx[u]) mx[u] = m[u][x], s[u].clear();
    if (mx[u] == m[u][x]) s[u].insert(x);
  };
  auto dfs = [&](auto dfs, int u) -> void {
    int maxson = -1;
    id[u] = cnt++;
    for (auto v : e[u]) {
      dfs(dfs, v);
      if (maxson == -1 || s[id[maxson]].size() < s[id[v]].size()) maxson = v;
    }
    if (maxson == -1) {
      merge(id[u], col[u]), ans[id[u]] = 1;
      return;
    }
    id[u] = id[maxson];
    for (auto v : e[u])
      if (v != maxson) {
        for (auto x : s[id[v]]) merge(id[u], x);
        ans[id[u]] += ans[id[v]];
      }
    ans[id[u]] -= mx[id[u]] - 1;
    if (mx[id[u]] > 1) {
      mx[id[u]] = 1, m[id[u]].clear();
      for (auto x : s[id[u]]) m[id[u]][x] = 1;
    }
  };
  dfs(dfs, 0);
  cout << ans[id[0]];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
