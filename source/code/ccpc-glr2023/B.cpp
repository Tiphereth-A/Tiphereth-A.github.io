#include <bits/stdc++.h>
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
#define int long long
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  multiset<int> s1, s2;
  int flag = 0, X = 0;
  for (int i = 0; i < m; ++i) {
    if (a[i + n - m] > b[i]) {
      flag = 1;
      break;
    }
    X += b[i] - a[i + n - m];
  }
  for (int i = 0; i < n; ++i) {
    if (i < n - m) s1.insert(a[i]);
    else s2.insert(a[i]);
  }
  if (X > n - m) flag = 1;
  if (flag == 1) {
    cout << "-1\n";
    return;
  }
  vector<int> ans;
  while (n - m > X) {
    auto it = s1.begin();
    auto mn = *it;
    s1.erase(it);
    ans.push_back(mn);
    mn += 1;
    s1.insert(mn);
    if (*s1.rbegin() > *s2.begin()) {
      int aa = *s1.rbegin(), bb = *s2.begin();
      s1.erase(prev(s1.end()));
      s2.erase(s2.begin());
      s1.insert(bb);
      s2.insert(aa);
      X -= aa - bb;
      if (*s2.begin() > b[0] || X < 0) {
        flag = 1;
        break;
      }
    }
    s1.erase(s1.begin()), --n;
  }
  if (n - m != X) {
    cout << "-1\n";
    return;
  } else {
    int i = 0;
    while (s2.size()) {
      auto t = *s2.begin();
      s2.erase(s2.begin());
      while (t < b[i]) ans.push_back(t), ++t;
      ++i;
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  int t_ = 0;
  std::cin >> t_;
  for (i_ = 0; i_ < t_; ++i_) solve(i_);
  return 0;
}
