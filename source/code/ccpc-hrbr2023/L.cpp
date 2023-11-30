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
  int n;
  cin >> n;
  deque<int> a(n), b(n), c(n);
  for (auto &x : a) cin >> x, --x;
  for (auto &x : b) cin >> x, --x;
  for (int i = 0; i < n; ++i) c[b[i]] = i;
  for (int i = 0; i < n; ++i) a[i] = c[a[i]], b[i] = (i + 1) % n;
  string ans = "";
  auto op1 = [&](deque<int> &a) {
    int a0 = a.front();
    a.pop_front();
    a.push_back(a0);
    ans += '1';
  };
  auto op2 = [&](deque<int> &a) {
    int a0 = a.front();
    a.pop_front();
    int a1 = a.front();
    a.pop_front();
    a.push_front(a0);
    a.push_back(a1);
    ans += '2';
  };
  for (int i = 0; i < n; ++i) {
    int t = a[0];
    while (1) {
      if (b[a[0]] == t) break;
      op1(a);
    }
    while (1) {
      if (a[1] == t) break;
      op2(a);
    }
  }
  while (1) {
    if (a[0] == 0) break;
    op1(a);
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
