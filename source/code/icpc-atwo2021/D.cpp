#include <bits/stdc++.h>
using namespace std;
#define read_var_(type, name) \
  type name;                  \
  std::cin >> name
inline auto solve(int t_) -> void {
  read_var_(int, n);
  cout << fixed << setprecision(12) << 1. * n / (2 * (n - 1)) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve(0);
  return 0;
}
