#include <bits/stdc++.h>

#include "Matrix.hpp"

using std::cin, std::cout, std::endl;

int main() {
  int n;
  cin >> n;
  matrix<double> a(
    n, n, [](double x) { return std::abs(x) <= 1e-8; }, 0);
  cin >> a;
  cout << a << endl
       << a.transpose() << endl
       << a.inverse() << endl
       << a.transpose().inverse() << endl
       << a.trace() << endl
       << a.rank() << endl
       << a.det() << endl;
  decltype(a) b(a);
  decltype(a) c(a.inverse());
  decltype(a) d(a.transpose());
  cout << a - c * d + a / c << endl
       << a - b << endl
       << a * b << endl
       << a / b << endl
       << (b | a) << endl;
  return 0;
}
