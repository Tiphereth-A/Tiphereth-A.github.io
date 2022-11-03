#include <bits/stdc++.h>
#define inc(i) (++(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define int long long
using namespace std;
string S;
int getval(string S) {
  int Base, Begin, tot = 0, flag = 0;
  if (S[0] == 'b') Base = 1, Begin = 5;
  if (S[0] == 'c') Base = 1, Begin = 5;
  if (S[0] == 'i') Base = 4, Begin = 4;
  if (S[0] == 'f') Base = 4, Begin = 6;
  if (S[0] == 'd') Base = 8, Begin = 7;
  if (S[0] == 'l' && S[5] == 'l') Base = 8, Begin = 10;
  if (S[0] == '_') Base = 16, Begin = 9;
  if (S[0] == 'l' && S[5] == 'd') Base = 16, Begin = 12;
  Rep(i, Begin, S.size()) {
    if (S[i] == '[') flag = 1;
    if (flag && S[i] >= '0' && S[i] <= '9') tot = tot * 10 + S[i] - '0';
  }
  if (tot == 0) tot = 1;
  return Base * tot;
}
int Solve() {
  int n;
  cin >> n;
  getchar();
  int Ret = 0;
  Rep(i, 1, n) {
    getline(cin, S);
    Ret += getval(S);
  }
  Ret = (Ret / 1024) + (bool)(Ret % 1024);
  return Ret;
}
signed main() {
  int T;
  cin >> T;
  Rep(Case, 1, T) {
    int Ret = Solve();
    cout << "Case #" << Case << ": " << Ret << "\n";
  }
  return 0;
}
