#include <bits/stdc++.h>
using u32 = uint32_t;
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
template <class T>
struct fenwick {
  static constexpr u32 lowbit(u32 n) { return n & (-n); }
  vec<T> a;
  fenwick(u32 n): a(n + 1) {}
  void add(u32 pos, T const &x) {
    if (!pos) return;
    for (; pos < a.size(); pos += lowbit(pos)) a[pos] += x;
  }
  T sum(u32 pos) {
    T ans = 0;
    for (; pos; pos -= lowbit(pos)) ans += a[pos];
    return ans;
  }
};
vector<int> lst(5e5 + 1, 0);
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  int ans = -1, mn = m;
  vector<int> a(n + 1);
  fenwick<int> Tree(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    mn = min(mn, x);
    a[i] = x;
    if (x != 1) ans = max(ans, 0);
    if (lst[x] + 1 <= i - 1) {
      ans = max(ans, Tree.sum(i - 1) - Tree.sum(lst[x]) - x);
    }
    if (lst[x]) Tree.add(lst[x], -1);
    lst[x] = i;
    Tree.add(i, 1);
  }
  int mex = min(n, m) + 1;
  for (int i = 1; i <= min(n, m); ++i)
    if (!lst[i]) {
      mex = i;
      break;
    }
  for (int i = 1; i <= n; ++i)
    if (lst[a[i]] + 1 <= n) {
      ans = max(ans, Tree.sum(n) - Tree.sum(lst[a[i]]) - a[i]);
    }
  for (int i = 1; i <= n; ++i) { lst[a[i]] = 0; }
  ans = max(ans, Tree.sum(n) - mex);
  cout << ans << "\n";
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
