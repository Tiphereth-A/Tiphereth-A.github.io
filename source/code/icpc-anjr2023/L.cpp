#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class Tp>
using vec = vector<Tp>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
struct parcel {
  i64 c, f;
  bool operator<(const parcel &x) { return x.f < f; }
};
void solve(int t_ = 0) {
  int n, w;
  i64 k;
  cin >> n >> k;
  vec<parcel> a(n);
  for_(i, 0, n - 1) cin >> a[i].c >> w >> a[i].f, a[i].c *= w;
  sort(a.begin(), a.end());
  i64 sy = 0, last = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (sy) {
      int t = min(a[i].c, k - sy);
      a[i].c -= t;
      sy += t;
    }
    if (!a[i].c) continue;
    ans += a[i].c / k * a[i].f;
    sy = a[i].c % k, last = a[i].f;
    if (sy) ans += last;
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
