#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
int a, b, c, d, n, m, h;
int Pd(int x) { return (h - b) * ((d + m - x) / b) + c >= x ? 1 : 0; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> n >> m >> h;
    c = (h - a) * (n / b), d = n % b;
    int l = 0, r = m - 1, Ans = 0, Mid;
    while (r >= l) {
      Mid = (l + r) >> 1;
      if (Pd(Mid)) l = Mid + 1, Ans = Mid;
      else r = Mid - 1;
    }
    cout << n + m - Ans << '\n';
  }
  return 0;
}