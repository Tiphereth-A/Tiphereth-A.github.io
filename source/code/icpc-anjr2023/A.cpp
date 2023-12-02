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
  vec<vec<char>> ma(n + 2, vec<char>(m + 2, 'O'));
  vec<vec<char>> ret;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> ma[i][j];
  vec<vec<int>> vis(n + 2, vec<int>(m + 2, 0));
  const vec<pair<int, int>> fx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int sx, sy, ans = 0, sz = 0;
  auto dfs = [&](auto dfs, int x, int y) -> void {
    if (ma[x][y] == 'O' || vis[x][y]) return;
    vis[x][y] = 1, sz += 1;
    for (auto [xx, yy] : fx) dfs(dfs, x + xx, y + yy);
    vec<vec<char>> ma1(n + 2, vec<char>(m + 2, '.'));
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (i + x - sx < 1 || j + y - sy < 1 || i + x - sx > n ||
            j + y - sy > m)
          ma1[i][j] = 'O';
        else ma1[i][j] = ma[i + x - sx][j + y - sy];
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (ma1[i][j] == 'O') ret[i][j] = 'O';
  };
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (ma[i][j] == '.' && !vis[i][j]) {
        sz = 0, sx = i, sy = j,
        ret = vec<vec<char>>(n + 2, vec<char>(m + 2, '.'));
        dfs(dfs, i, j);
        int rt = 0;
        for (int a = 1; a <= n; ++a)
          for (int b = 1; b <= m; ++b) { rt += (ret[a][b] == 'O'); }
        if (rt == n * m - 1) ans += sz;
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
