#include <bits/stdc++.h>
template <class T>
using vec = std::vector<T>;
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      --x;
      a[i].push_back(x);
    }
  }
  auto op = [](vector<int> a, vector<int> b) {
    vec<int> c(a.size());
    for (int i = 0; i < a.size(); ++i) c[i] = a[b[i]];
    return c;
  };
  if (m <= 20) {
    int state = (1 << m) - 1;
    map<vector<int>, int> ans;
    for (int sta = 1; sta <= state; ++sta) {
      vector<vector<int>> now;
      for (int i = 0; i < m; ++i)
        if ((sta >> i) & 1) { now.push_back(a[i]); }
      vector<int> c = now[0];
      for (int i = 1; i < now.size(); ++i) { c = op(c, now[i]); }
      ans[c] = 1;
    }
    cout << ans.size();
  } else {
    map<vector<int>, int> ans;
    for (int i = 0; i < m; ++i) {
      auto ans1 = ans;
      for (auto [x, y] : ans) { ans1[op(x, a[i])] = 1; }
      ans = ans1;
      ans[a[i]] = 1;
    }
    cout << ans.size();
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
