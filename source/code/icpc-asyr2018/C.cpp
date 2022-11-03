#include <bits/stdc++.h>
#define inc(i) (++(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define int long long
using namespace std;
signed main() {
  int T, Case = 0;
  cin >> T;
  while (T--) {
    inc(Case);
    int n, k, P;
    cin >> n >> k >> P;
    k = min(n, k);
    int Ret = 1;
    Rep(i, 1, k)(Ret *= i) %= P;
    Ret = Ret * ((n - k - 1) * (n - k - 1) % P + (k + 1) * (n - k) % P) % P;
    cout << "Case #" << Case << ": " << Ret << '\n';
  }
  return 0;
}
