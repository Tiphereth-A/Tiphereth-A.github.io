/*
 * @Author: AgOH
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 998244353;

template <int row, int col>
struct Mat {
  int ele[row][col];
};
template <int row, int col, int row2>
Mat<row, row2> operator*(const Mat<row, col> &m1, const Mat<col, row2> &m2) {
  Mat<row, row2> matt;
  for (int i = 0; i < row; i++) memset(matt.ele[i], 0, row2 * sizeof(int));
  for (int i = 0; i < row; i++)
    for (int k = 0; k < col; k++)
      for (int j = 0; j < row2; j++)
        matt.ele[i][j] =
          (matt.ele[i][j] + (int64_t)m1.ele[i][k] * m2.ele[k][j] % mod) % mod;
  return matt;
}

Mat<6, 6> ident = {{
  {1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1},
}};
Mat<6, 6> M[] = {ident, ident, ident, ident, ident, ident, ident};
char dict[130];
auto ___ = []() {
  M[1].ele[0][5] = M[2].ele[1][0] = M[3].ele[2][1] = M[4].ele[3][2] =
    M[5].ele[4][3] = 1;
  fill(begin(dict), end(dict), 6);
  dict['F'] = 1;
  dict['e'] = 2;
  dict['i'] = 3;
  dict['M'] = 4;
  dict['a'] = 5;
  return 0.0;
}();

Mat<6, 6> mpow[6][maxn];

char s[maxn];
struct Node {
  int l, r, f;
  Mat<6, 6> val;
} sgt[maxn << 2];

#define ls(k) (k << 1)

#define rs(k) (k << 1 | 1)
inline void push_up(int k) { sgt[k].val = sgt[rs(k)].val * sgt[ls(k)].val; }
inline void push_down(int k) {
  int f = sgt[k].f;
  sgt[k].f = 0;
  sgt[ls(k)].f = sgt[rs(k)].f = f;
  if (f == 6) sgt[ls(k)].val = sgt[rs(k)].val = ident;
  else {
    sgt[ls(k)].val = mpow[f][sgt[ls(k)].r - sgt[ls(k)].l + 1];
    sgt[rs(k)].val = mpow[f][sgt[rs(k)].r - sgt[rs(k)].l + 1];
  }
}
void build(int l, int r, int k = 1) {
  sgt[k].l = l, sgt[k].r = r, sgt[k].f = 0;
  if (l == r) sgt[k].val = M[(int)dict[(int)s[l - 1]]];
  else {
    int m = (l + r) >> 1;
    build(l, m, ls(k));
    build(m + 1, r, rs(k));
    push_up(k);
  }
}
void modify(int x, int y, int z, int k = 1) {
  int l = sgt[k].l, r = sgt[k].r;
  if (x <= l && y >= r) {
    sgt[k].f = z;
    if (z == 6) sgt[k].val = ident;
    else sgt[k].val = mpow[z][r - l + 1];
    return;
  }
  if (sgt[k].f) push_down(k);
  int m = (l + r) >> 1;
  if (x <= m) modify(x, y, z, ls(k));
  if (y > m) modify(x, y, z, rs(k));
  push_up(k);
}
auto query(int x, int y, int k = 1) {
  int l = sgt[k].l, r = sgt[k].r;
  if (x <= l && y >= r) return sgt[k].val;
  if (sgt[k].f) push_down(k);
  int m = (l + r) >> 1;
  auto ret = ident;
  if (x <= m) ret = ret * query(x, y, ls(k));
  if (y > m) ret = ret * query(x, y, rs(k));
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 1; i <= 5; i++) mpow[i][0] = ident;
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 10001; j++) mpow[i][j] = mpow[i][j - 1] * M[i];
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q >> s;
    build(1, n);
    while (q--) {
      int l, r;
      char c;
      cin >> l >> r >> c;
      modify(l, r, dict[(int)c]);
      cout << query(1, n).ele[4][5] << endl;
    }
  }
  return 0;
}
