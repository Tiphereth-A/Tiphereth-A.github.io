#include <bits/stdc++.h>
using i64 = int64_t;
template <class T>
using vec = std::vector<T>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
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
  int n;
  cin >> n;
  int len = n / 2;
  vec<int> a(n), b(n);
  for_(i, 0, n - 1) cin >> a[i] >> b[i];
  auto chk = [&](int k) -> bool {
    int sx = 0;
    vec<int> diff(n);
    for_(i, 0, n - 1) sx += (a[i] >= k);
    for_(i, 0, n - 1) diff[i] = (b[i] >= k) - (a[i] >= k);
    int len1 = 0;
    {
      int cnt = 0;
      for_(i, 0, n - 1) {
        len1 = max(len1, cnt += diff[i]);
        if (cnt < 0) cnt = 0;
      }
    }
    return (sx + len1 >= len + 1);
  };
  int l = 2e9, r = 0;
  for (int i : a) l = min(l, i), r = max(r, i);
  for (int i : b) l = min(l, i), r = max(r, i);
  int ans = l;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (chk(mid)) {
      ans = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  cout << ans << '\n';
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
