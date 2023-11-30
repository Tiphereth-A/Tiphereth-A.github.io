#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
template <class Tp>
using vec = vector<Tp>;
template <class Tp>
using vvec = vector<vector<Tp>>;
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
double eps = 1e-8;
bool ge(vvec<double> &b) {
  u32 n = b.size(), m = b[0].size();
  for (u32 i = 0; i < n; ++i) {
    {
      u32 j = i;
      for (u32 k = i + 1; k < n; ++k)
        if (abs(b[j][i]) < abs(b[k][i])) j = k;
      if (j != i) swap(b[i], b[j]);
      if (abs(b[i][i]) < eps) return 1;
    }
    for (u32 j = i + 1; j < m; ++j) b[i][j] /= b[i][i];
    b[i][i] = 1;
    for (u32 j = 0; j < n; ++j) {
      if (j == i) continue;
      double d = b[j][i];
      b[j][i] = 0;
      for (u32 k = i + 1; k < m; ++k) b[j][k] -= d * b[i][k];
    }
  }
  return 0;
}
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<vec<int>> w(n, vec<int>(n));
  for (auto &y : w)
    for (auto &x : y) cin >> x;
  double ans = 0;
  for (int sta = 1; sta < (1 << n); ++sta) {
    vector<int> a;
    for (int i = 0; i < n; ++i)
      if ((sta >> i) & 1) a.push_back(i);
    if (a.size() <= 1) continue;
    vector<vec<double>> b(a.size() + 1, vec<double>(a.size() + 2));
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a.size(); ++j) b[i][j] = i == j ? 0 : w[a[i]][a[j]];
      b[i][a.size()] = 1;
    }
    for (int i = 0; i < a.size(); ++i) b[a.size()][i] = 1;
    b[a.size()][a.size() + 1] = 1;
    if (ge(b)) continue;
    double ret = 0;
    bool flag = 0;
    for (int i = 0; i < a.size(); ++i)
      if (b[i].back() < 0) flag = 1;
    if (flag) continue;
    for (int i = 0; i < a.size(); ++i)
      for (int j = i + 1; j < a.size(); ++j) {
        ret += b[i].back() * b[j].back() * w[a[i]][a[j]];
      }
    ans = max(ans, ret);
  }
  cout << fixed << setprecision(8) << ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
