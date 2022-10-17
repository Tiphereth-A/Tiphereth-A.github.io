#include <bits/stdc++.h>

#include "ModInteger.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  mod_integer<int64_t> a(998244353);

  cin >> a;
  cout << a << endl;
  a = a.inverse();
  cout << +a << endl << -a << endl;

  decltype(a) b(a), c = a;

  c = b.transform_unary_raw([](const int64_t &x) { return x + 3; })
        .transform_binary_raw(a, std::multiplies<int64_t>())
        .safe_mod()
        .inverse();

  cout << c << endl;

  c.data() += 2;

  cout << c << endl;

  cout << a + b << endl
       << a - b << ' ' << b - a << endl
       << a * b << endl
       << a / b << endl;

  cout << (a += b) << endl
       << (a -= b) << endl
       << (a *= b) << endl
       << (a /= b) << endl;

  cout << std::boolalpha << (a == b) << endl
       << (a != b) << endl
       << (a < b) << endl
       << (a > b) << endl
       << (a <= b) << endl
       << (a >= b) << endl;
  return 0;
}
