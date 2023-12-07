#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class Tp>
using vec = vector<Tp>;
template <class Tp>
using vvec = vector<vector<Tp>>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vvec<int> mat(n, vec<int>(m));
  for (auto &i : mat)
    for (auto &j : i) cin >> j;
  auto mata = mat, matb = mat;
  for_(i, 0, n - 1) {
    int mina = 0;
    for_(j, 1, m - 1)
      if (mat[i][j] < mat[i][mina]) mina = j;
    for_(j, 0, m - 1) mata[i][j] = mat[i][mina];
  }
  for_(j, 0, m - 1) {
    int minb = 0;
    for_(i, 1, n - 1)
      if (mat[i][j] < mat[minb][j]) minb = i;
    for_(i, 0, n - 1) matb[i][j] = mat[minb][j];
  }
  int ans = 0;
  for_(i, 0, n - 1)
    for_(j, 0, m - 1) ans += mat[i][j] == mata[i][j] && mat[i][j] == matb[i][j];
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
