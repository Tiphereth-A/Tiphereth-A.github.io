#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)

#define MULCAS
void solve() {
  ll x11, y11, x12, y12, x21, y21, x22, y22;
  cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
  long double s =
    fabsl((x21 + x22) - (x11 + x12)) / 2 + fabsl((y21 + y22) - (y11 + y12)) / 2;
  long double r =
    sqrtl((x21 - x22) * (x21 - x22) + (y21 - y22) * (y21 - y22)) * sqrtl(2) / 2;
  cout << min(abs(s + r), abs(s - r)) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
#ifdef MULCAS
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; ++i)
#endif
    solve();
  return 0;
}