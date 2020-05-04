#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; dec(i))
using namespace std;
const int N = 1000000 + 7, M = 60 + 7, Mod = 998244353;
string S;
int n, A[N];
int Dp1[N][M], Dp2[N][M], Sum[N], tot[N][M];
int f1[M][M], f2[M][M], Cnt[N];
void Inc(int &A, int B) { (A = A + B) %= Mod; }
void Dec(int &A, int B) { (A = A - B + Mod) %= Mod; }
int Mul(int A, int B) { return 1ll * A * B % Mod; }
int main() {
  cin >> S, n = S.size();
  Rep(i, 1, n) {
    char C = S[i - 1];
    if (isdigit(C)) A[i] = C - '0';
    else if (C <= 'Z') A[i] = C - 'A' + 10;
    else A[i] = C - 'a' + 36;
  }
  Rep(i, 1, n) {
    Rep(j, 0, 61) {
      Dp1[i][j] = Dp1[i - 1][j];
      Dp2[i][j] = Dp2[i - 1][j];
      tot[i][j] = tot[i - 1][j];
    }
    inc(tot[i][A[i]]);
    Rep(j, 0, 61) if (j != A[i]) {
      Inc(Dp1[i][j], tot[i - 1][j]);
      Inc(Dp2[i][A[i]], tot[i - 1][j]);
    }
    Rep(j, 0, 61) Inc(Sum[i], Dp2[i][j]);
  }
  int Ans = 0, tem;
  rep(i, n, 1) {
    Rep(j, 0, 61) if (j != A[i]) {
      Inc(f1[A[i]][j], f2[j][A[i]]);
      Inc(f2[A[i]][j], Cnt[j]);
    }
    inc(Cnt[A[i]]);
    Rep(j, 0, 61) if (j != A[i]) {
      tem = Sum[i - 1];
      Dec(tem, Dp1[i - 1][A[i]]);
      Dec(tem, Dp1[i - 1][j]);
      Dec(tem, Dp2[i - 1][j]);
      Dec(tem, Dp2[i - 1][A[i]]);
      Inc(tem, Mul(tot[i - 1][j], tot[i - 1][A[i]]));
      Inc(Ans, Mul(f1[j][A[i]], tem));
    }
  }
  cout << Ans;
  return 0;
}
