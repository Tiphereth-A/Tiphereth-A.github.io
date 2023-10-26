#include <bits/stdc++.h>
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; ++i)
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; --i)

using namespace std;
using i64 = long long;
using u32 = uint32_t;

template <class... Ts>
void print(Ts const &...p) {
  ((cout << p << ' '), ...);
}
#define debug(var)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if (n == 3) cout << "Unlucky", exit(0);
  if (n % 2 == 0) {
    while (n > 2) {
      n -= 4;
      cout << "1001";
    }
    if (n) cout << "10";
    exit(0);
  }
  if (n % 4 == 1) {
    while (n > 5) {
      n -= 4;
      cout << "1001";
    }
    if (n) cout << "10001";
    exit(0);
  }
  if (n % 4 == 3) {
    while (n > 3) {
      n -= 4;
      cout << "1001";
    }
    if (n) cout << "010";
    exit(0);
  }
  return 0;
}