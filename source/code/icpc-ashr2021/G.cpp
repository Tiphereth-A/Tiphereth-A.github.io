#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; dec(i))
using namespace std;

const int N = 100000 + 7, Mod = 998244353;
int n, Dp[N], M[N], Sign[N], Cnt[N], Fac[N], Fac1[N], Sz[N];
vector<int> E[N];
int Mul(int A, int B) { return 1ll * A * B % Mod; }
void Add(int u, int v) { E[u].push_back(v), E[v].push_back(u); }
int KSM(int x, int p) {
  int Ret = 1;
  while (p) {
    if (p & 1) Ret = Mul(Ret, x);
    p >>= 1, x = Mul(x, x);
  }
  return Ret;
}

void dp(int u, int fa) {
  int v, cnt = 0, S0 = 1, S1 = 1;
  Sz[u] = 1;
  Rep(i, 0, E[u].size() - 1)
    if ((v = E[u][i]) != fa) dp(v, u), Sz[u] += Sz[v];
  Rep(i, 0, E[u].size() - 1)
    if ((v = E[u][i]) != fa) {
      inc(Cnt[u]);
      if (Sz[v] % 2 == 1) S0 = Mul(S0, Dp[v]), inc(cnt);
      if (Sz[v] % 2 == 0) S1 = Mul(S1, Dp[v]);
    }
  Dp[u] = Mul(Mul(Mul(Mul(S0, S1), Fac[cnt]), M[cnt / 2]), Fac1[cnt / 2]);
}

int main() {
  scanf("%d", &n);
  int u, v;
  Rep(i, 1, n - 1) scanf("%d%d", &u, &v), Add(u, v);
  M[0] = Fac[0] = Fac[1] = 1;
  Rep(i, 2, n) Fac[i] = Mul(Fac[i - 1], i);
  Rep(i, 0, n) Fac1[i] = KSM(Fac[i], Mod - 2);
  Rep(i, 1, n) M[i] = Mul(M[i - 1], 2);
  Rep(i, 1, n) M[i] = KSM(M[i], Mod - 2);
  dp(1, 0);
  printf("%d", Dp[1]);
  return 0;
}