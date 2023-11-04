#include <bits/stdc++.h>
using ll = long long;
template <class T>
using vc = std::vector<T>;
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
  int n;
  cin >> n;
  vc<string> a(n);
  for (auto &i : a) cin >> i, reverse(i.begin(), i.end());
  auto x = a[0];
  ll cnt = 0;
  auto add = [&](string_view a, string_view b) {
    if (a.size() > b.size()) swap(a, b);
    string retc(b.size() + 1, '0');
    for (int i = 0; i < b.size(); ++i) {
      int aa = i < a.size() ? a[i] - 48 : 0, bb = b[i] - 48;
      if (aa + bb + retc[i] - 48 >= 10) {
        ++cnt;
        retc[i] = retc[i] + aa + bb - 10;
        retc[i + 1] += 1;
      } else retc[i] = retc[i] + aa + bb;
    }
    while (retc.back() == '0') retc.pop_back();
    return retc;
  };
  string now = a[0];
  for (int i = 1; i < n; ++i) now = add(now, a[i]);
  cout << cnt << '\n';
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
