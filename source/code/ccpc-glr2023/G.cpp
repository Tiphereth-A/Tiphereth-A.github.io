#include <bits/stdc++.h>
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
void solve(int t_ = 0) {
  string str, ans = "";
  cin >> str;
  string str1 = str;
  reverse(str.begin(), str.end());
  int cntl = 0, cntr = 0;
  for (auto i : str) {
    if (i == '(') ++cntl;
    else ++cntr;
    if (cntl > cntr) {
      cout << "impossible\n";
      return;
    }
  }
  cout << str1 << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  int t_ = 0;
  std::cin >> t_;
  for (i_ = 0; i_ < t_; ++i_) solve(i_);
  return 0;
}
