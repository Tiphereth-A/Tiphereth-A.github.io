#include <bits/stdc++.h>
using namespace std;
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<int> pos(101);
  vector<vector<int>> f(n + 1);
  vector<int> a(201, 0);
  f[0] = a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    f[i] = f[i - 1];
    for (int j = 1; j <= 100; ++j) {
      if (pos[j]) f[i][x + j] = max(f[i][x + j], f[pos[j] - 1][x + j] + 2);
    }
    pos[x] = i;
  }
  int ans = 0;
  for (int i = 1; i <= 200; ++i) ans = max(ans, f[n][i]);
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
