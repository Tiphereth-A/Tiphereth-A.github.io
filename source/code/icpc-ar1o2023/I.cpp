#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)
#define inc(i) (++(i))
constexpr i64 MOD = 998244353;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  i64 f[2][62][2][2][2];
  memset(f, 0, sizeof(f));
  i64 sum[2][2][2];
  memset(sum, 0, sizeof(sum));
  sum[0][0][0] = 1;
  int now = 0;
  for (int i = 0; i < n; ++i) {
    int lst = now;
    now ^= 1;
    memset(f[now], 0, sizeof(f[now]));
    if ('A' <= str[i] && str[i] <= 'Z') {
      int cur = str[i] - 'A' + 36;
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          f[now][cur][1][j][k] =
            ((sum[1][j][k] - f[lst][cur][1][j][k] + sum[0][j][k]) % MOD + MOD) %
            MOD;
        }
      }
    } else if ('0' <= str[i] && str[i] <= '9') {
      int cur = str[i] - '0';
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          f[now][cur][j][k][1] =
            ((sum[j][k][1] - f[lst][cur][j][k][1] + sum[j][k][0]) % MOD + MOD) %
            MOD;
        }
      }
    } else if ('a' <= str[i] && str[i] <= 'z') {
      int cur = str[i] - 'a' + 36;
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          f[now][cur][1][j][k] =
            ((sum[1][j][k] - f[lst][cur][1][j][k] + sum[0][j][k]) % MOD + MOD) %
            MOD;
        }
      }
      cur = str[i] - 'a' + 10;
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          f[now][cur][j][1][k] =
            ((sum[j][1][k] - f[lst][cur][j][1][k] + sum[j][0][k]) % MOD + MOD) %
            MOD;
        }
      }
    } else {
      for (int cur = 0; cur < 10; ++cur) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            f[now][cur][j][k][1] =
              ((sum[j][k][1] - f[lst][cur][j][k][1] + sum[j][k][0]) % MOD +
               MOD) %
              MOD;
          }
        }
      }
      for (int cur = 10; cur < 36; ++cur) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            f[now][cur][j][1][k] =
              ((sum[j][1][k] - f[lst][cur][j][1][k] + sum[j][0][k]) % MOD +
               MOD) %
              MOD;
          }
        }
      }
      for (int cur = 36; cur < 62; ++cur) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            f[now][cur][1][j][k] =
              ((sum[1][j][k] - f[lst][cur][1][j][k] + sum[0][j][k]) % MOD +
               MOD) %
              MOD;
          }
        }
      }
    }
    memset(sum, 0, sizeof(sum));
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int t = 0; t < 2; ++t) {
          for (int cur = 0; cur < 62; ++cur)
            sum[j][k][t] = (sum[j][k][t] + f[now][cur][j][k][t]) % MOD;
        }
      }
    }
  }
  cout << sum[1][1][1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef MULCAS
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; ++i)
#endif
    solve();
  return 0;
}