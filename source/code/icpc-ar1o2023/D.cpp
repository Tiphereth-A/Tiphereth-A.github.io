#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)
#define inc(i) (++(i))

void solve() {
  int n, m, sz = 0;
  cin >> n >> m;
  vector<vector<int>> E(n + 1);
  vector<int> col(n + 1, 0);
  vector<int> a;
  vector<int> sz1, sz2;
  for_(i, 1, m) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  function<void(int)> dfs = [&](int u) {
    a.push_back(u), col[u] = sz, inc(sz1[sz]);
    for (auto v : E[u])
      if (!col[v]) dfs(v);
  };
  auto C = [](int n) -> ll { return 1ll * n * (n - 1) / 2; };
  sz1.push_back(0), sz2.push_back(0);
  Rep(i, 1, n)
    if (!col[i]) {
      a.clear(), inc(sz), sz1.push_back(0), sz2.push_back(0);
      dfs((int)i);
      for (auto x : a) sz2[sz] += E[x].size();
      sz2[sz] /= 2;
    }
  int flag = 1;
  ll ans = 0;
  int min1 = n, min2 = n;
  Rep(i, 1, sz) {
    if (C(sz1[i]) != sz2[i]) flag = 0, ans += C(sz1[i]) - sz2[i];
    else if (sz1[i] < min1) min2 = min1, min1 = sz1[i];
    else if (sz1[i] < min2) min2 = sz1[i];
  }
  if (flag) {
    cout << C(min2 + min1) - C(min1) - C(min2);
  } else cout << ans;
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