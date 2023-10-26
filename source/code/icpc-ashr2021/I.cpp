#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; dec(i))
using namespace std;

const int N = 100 + 7, M = 1300 * 2 + 4;
int n, k, m;
ll Dp[N][N][M];
int v[N], W[N];

int main() {
  scanf("%d%d", &n, &k), m = n * 13;
  Rep(i, 1, n) scanf("%d%d", v + i, W + i);
  Rep(l, 0, n)
    Rep(i, 0, k)
      Rep(j, 0, 2 * m) Dp[l][i][j] = -100000000007;
  Dp[0][0][m] = 0;
  Rep(i, 1, n)
    Rep(j, 0, min(i, k))
      Rep(l, 0, 2 * m)
        if (Dp[i - 1][j][l] != -100000000007) {
          Dp[i][j][l] = max(Dp[i][j][l], Dp[i - 1][j][l]);
          if (l + W[i] <= 2 * m)
            Dp[i][j][l + W[i]] =
              max(Dp[i][j][l + W[i]], Dp[i - 1][j][l] + v[i]);
          if (l - W[i] >= 0)
            Dp[i][j][l - W[i]] =
              max(Dp[i][j][l - W[i]], Dp[i - 1][j][l] + v[i]);
          if (j != min(i, k)) {
            if (l + 2 * W[i] <= 2 * m)
              Dp[i][j + 1][l + 2 * W[i]] =
                max(Dp[i][j + 1][l + 2 * W[i]], Dp[i - 1][j][l] + v[i]);
            if (l - 2 * W[i] >= 0)
              Dp[i][j + 1][l - 2 * W[i]] =
                max(Dp[i][j + 1][l - 2 * W[i]], Dp[i - 1][j][l] + v[i]);
          }
        }
  ll Ans = -100000000007;
  Rep(j, 0, k) Ans = max(Ans, Dp[n][j][m]);
  printf("%lld", Ans);
  return 0;
}