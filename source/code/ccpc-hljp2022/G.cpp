#include <cstdio>
#include <iostream>
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; dec(i))
using namespace std;
const int N = 2000 + 7, Mod = 998244353;
int n, A[N], Dp[N];
int main() {
  scanf("%d", &n);
  Rep(i, 1, n) scanf("%d", A + i);
  Dp[0] = 1;
  Rep(i, 1, n) if (A[i]) rep(j, n, A[i])(Dp[j] += Dp[j - A[i]]) %= Mod;
  int Ans = n;
  while (!Dp[Ans]) dec(Ans);
  printf("%d %d", Ans, Dp[Ans]);
  return 0;
}