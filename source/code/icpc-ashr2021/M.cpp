#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << fixed << setprecision(9) << 1. / n / ((n + 1) / 2) / (n / 2 + 1)
       << '\n';
  return 0;
}