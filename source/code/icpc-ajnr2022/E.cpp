#include <bits/stdc++.h>
using ll = long long;
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
#define YES return void(cout << "YES\n")
#define NO return void(cout << "NO\n")
void solve(int t_ = 0) {
  int n, k;
  cin >> n >> k;
  if (n == k) YES;
  if (k == 1) NO;
  if (!(k & 1)) YES;
  if (n % k == 0) NO;
  int _ = (k + 1) / 2;
  ll b = 2ll * _ * _;
  if (n >= b) NO;
  int x = n / k;
  if (n - x * k <= x - 2) NO;
  if ((x + 1) * k - n <= x - 1) NO;
  YES;
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
