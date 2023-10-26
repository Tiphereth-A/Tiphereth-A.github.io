#include <bits/stdc++.h>
using namespace std;

int main() {
  int _t;
  cin >> _t;
  while (_t--) {
    int64_t p, q;
    cin >> p >> q;
    int64_t __ = p * p - 4 * q * q;
    if (int64_t _ = int64_t(sqrt(__)); _ * _ != __) {
      cout << "0 0\n";
      continue;
    }
    __ = sqrt(__);
    int64_t a = p + __, b = 2 * q;
    int64_t g = __gcd(a, b);
    a /= g;
    b /= g;
    if (a > 1e9 || b > 1e9) {
      cout << "0 0\n";
      continue;
    }
    cout << a << ' ' << b << '\n';
  }
}