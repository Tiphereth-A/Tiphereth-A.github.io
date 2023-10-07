#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int mx = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    mx = max(mx, x);
  }
  cout << max(2, (mx + m - 1) / m) << '\n';
}