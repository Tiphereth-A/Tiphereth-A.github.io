#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class Tp>
using vec = vector<Tp>;
template <class Tp>
using vvec = vector<vector<Tp>>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
vec<int> dijkstra(vvec<pair<int, int>> const &g, int s) {
  vec<int> dis(g.size(), 0x3f3f3f3f);
  vec<bool> vis(g.size());
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>
    q;
  q.emplace(dis[s] = 0, s);
  while (!q.empty()) {
    auto [dis_now, now] = q.top();
    q.pop();
    if (vis[now]) continue;
    vis[now] = 1;
    for (auto [to, w] : g[now])
      if (dis[now] + w < dis[to]) {
        dis[to] = dis[now] + w;
        if (!vis[to]) q.emplace(dis[to], to);
      }
  }
  return dis;
}
void solve(int t_ = 0) {
  int t, r;
  cin >> t >> r;
  int n, m;
  cin >> n >> m;
  vvec<pair<int, int>> g(n + 1);
  for_(i, 1, m, u, v, w) {
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  int k;
  cin >> k;
  vec<int> a(k);
  vec<double> p(k);
  for_(i, 0, k - 1) cin >> a[i] >> p[i], p[i] /= 100;
  auto dis0 = dijkstra(g, 1);
  if (dis0[n] == 0x3f3f3f3f) {
    cout << "-1\n";
    return;
  }
  vvec<int> dis;
  for_(i, 0, k - 1) dis.push_back(dijkstra(g, a[i]));
  int state = 1 << k;
  vec<vec<double>> ans(state, vec<double>(k, 1e50)),
    pi(state, vec<double>(k, 0));
  for (int i = 0; i < k; ++i) {
    ans[1 << i][i] = 1.0 * dis0[a[i]] / t;
    pi[1 << i][i] = 1;
  }
  double mn = 1. * dis0[n] / t;
  for (int sta = 1; sta < state; ++sta) {
    for (int i = 0; i < k; ++i) {
      if ((sta >> i) & 1) {
        for (int j = 0; j < k; ++j) {
          if (!((sta >> j) & 1)) {
            if (p[i] < 1e-6) {
              mn = min(mn,
                       ans[sta][i] + pi[sta][i] * dis[i][n] *
                                       ((1.0 - p[i]) / r + p[i] / t));
            } else {
              ans[sta | (1 << j)][j] =
                min(ans[sta | (1 << j)][j],
                    ans[sta][i] + pi[sta][i] * (1. - p[i]) * dis[i][n] / r +
                      pi[sta][i] * p[i] * dis[i][a[j]] / t);
              pi[sta | (1 << j)][j] = pi[sta][i] * p[i];
            }
          }
        }
      }
    }
  }
  for (int sta = 1; sta < state; ++sta) {
    for (int i = 0; i < k; ++i) {
      if ((sta >> i) & 1) {
        mn = min(mn,
                 ans[sta][i] +
                   pi[sta][i] * dis[i][n] * ((1.0 - p[i]) / r + p[i] / t));
      }
    }
  }
  cout << fixed << setprecision(8) << mn << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
