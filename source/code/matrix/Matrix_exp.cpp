#include <bits/stdc++.h>

#include "Matrix.hpp"

using namespace std;

// template <> struct Matrix::Matrix_helper::gauss_tag<int> { using type = Matrix::Matrix_helper::normal_tag; };

auto _ = [](const double& x, const double& y) { return std::abs(x - y) <= 1e-8; };

int main() {
    int n;
    cin >> n;
    Matrix::matrix<double, decltype(_)> a(n, n, _);
    cin >> a;
    cout << a << endl
         << a.trans() << endl
         << a.inverse() << endl
         << a.trans().inverse() << endl
         << a.rank() << endl
         << a.det() << endl;
    decltype(a) b(a);
    decltype(a) c(a.inverse());
    decltype(a) d(a.trans());
    cout << -a - +c * d + a / c << endl
         << a - b << endl
         << a * b << endl
         << a / b << endl;
    return 0;
}
