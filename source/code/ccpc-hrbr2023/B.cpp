#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
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
  i64 now = 0, rem = 0;
  double now_ = 0;
  auto div2 = [&]() {
    if (rem == 0) rem = now % 2;
    now /= 2;
    now_ = now + .5 * rem;
  };
  auto add = [&](int x) {
    now_ += x;
    double fnow_ = floor(abs(now_));
    if (abs(abs(now_) - fnow_) < .1) {
      now = fnow_;
      rem = 0;
    } else {
      if (now_ < 0) rem = -1;
      else rem = 1;
      now = fnow_;
    }
    if (now_ < 0) { now = -now; }
  };
  auto out = [&]() {
    if (now_ > 0) cout << '+';
    else if (now_ < 0) cout << '-';
    else cout << '0';
  };
  for_(i, 0, n - 1) {
    int x;
    cin >> x;
    div2();
    add(x);
    out();
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
