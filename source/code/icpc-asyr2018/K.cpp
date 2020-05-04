#include <bits/stdc++.h>
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define int long long
using namespace std;
int n, m, k;
int Get1(int n, int m) {
  if (m == 1) return (k - 1) % n;
  else return (Get1(n - 1, m - 1) + k) % n;
}
int Get2(int n, int m) {
  if (k == 1) return m - 1;
  int N = n - m + 1, Ret = Get1(N, 1);
  dec(m);
  while (m > 0) {
    int tem = (N - Ret) / (k - 1);
    if (m <= tem) return Ret = (Ret + m * k) % (N + m);
    else {
      Ret = (Ret + tem * k) % (N + tem);
      Ret = (Ret + k) % (N + tem + 1);
      N += tem + 1, m -= tem + 1;
    }
  }
  return Ret;
}
signed main() {
  int T;
  cin >> T;
  Rep(Case, 1, T) {
    int Ret;
    cin >> n >> m >> k;
    if (m <= 2000000) Ret = Get1(n, m) + 1;
    else Ret = Get2(n, m) + 1;
    cout << "Case #" << Case << ": " << Ret << '\n';
  }
  return 0;
}
