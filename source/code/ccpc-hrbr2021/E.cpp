#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class Tp>
using vec = vector<Tp>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vec<i64> a(n);
  for (auto &i : a) cin >> i;
  if (a[0] > 1) {
    cout << "-1\n";
    return;
  }
  if (a[0] == 0) {
    for_(i, 1, n - 1)
      if (a[i]) {
        cout << "-1\n";
        return;
      }
    cout << "1\n";
    return;
  }
  auto chk = [&](i64 m) -> bool {
    if (m < 2) return 0;
    for_(i, 1, n - 1)
      if (a[i] != a[i - 1] * 2 % m) return 0;
    return 1;
  };
  int idx = -1;
  for_(i, 1, n - 1)
    if (a[i] != a[i - 1] * 2) {
      idx = i;
      break;
    }
  if (idx == -1) {
    cout << "-1\n";
    return;
  }
  i64 m = 2 * a[idx - 1] - a[idx];
  if (!chk(m) || chk(m * 2) || chk(m / 2)) {
    cout << "-1\n";
    return;
  }
  cout << m << '\n';
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
