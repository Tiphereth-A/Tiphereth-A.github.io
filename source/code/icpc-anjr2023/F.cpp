#include <bits/stdc++.h>
using namespace std;
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
  vector<vector<int>> op(n);
  vector<int> pos(m + 1, -1);
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    vector<int> now(sz);
    for (int j = 0; j < sz; ++j) {
      int x;
      cin >> x;
      now[j] = x;
      pos[x] = i;
    }
    op[i] = now;
  }
  vector<vector<int>> e(n);
  vector<int> in(n, 0);
  for (int i = 0; i < n; ++i) {
    e[i].clear();
    for (int j = 0; j < op[i].size(); ++j) {
      if (i != pos[op[i][j]]) {
        e[i].push_back(pos[op[i][j]]);
        in[pos[op[i][j]]]++;
      }
    }
  }
  priority_queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!in[i]) { q.push(i); }
  }
  int flag = 0, cnt = 0;
  vector<int> ans(n, 0);
  while (!q.empty()) {
    if (q.size() > 1) flag = 1;
    int x = q.top();
    q.pop();
    ans[cnt++] = x;
    for (auto y : e[x]) {
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  int i = 0;
  for (; i < n; ++i) {
    if (ans[i] != i) break;
  }
  if (!flag || i == n) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  cout << ans[0] + 1;
  for (i = 1; i < n; ++i) cout << " " << ans[i] + 1;
  cout << "\n";
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
