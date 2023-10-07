#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)

void solve() {
  int n, m;
  cin >> n >> m;
  map<string, bool> M;
  vector<string> Q1, Q2, Q3;
  Rep(i, 1, n) {
    string S;
    cin >> S;
    if (M.find(S) == M.end()) Q1.push_back(S), M[S] = 1;
  }
  M.clear();
  Rep(i, 1, m) {
    string S;
    cin >> S;
    if (M.find(S) == M.end()) Q2.push_back(S), M[S] = 1;
  }
  M.clear();
  int a = 0, b = 0;
  while (a != Q1.size() || b != Q2.size()) {
    if (a != Q1.size()) {
      if (M.find(Q1[a]) == M.end()) Q3.push_back(Q1[a]), M[Q1[a]] = 1;
      ++a;
    }
    if (b != Q2.size()) {
      if (M.find(Q2[b]) == M.end()) Q3.push_back(Q2[b]), M[Q2[b]] = 1;
      ++b;
    }
  }
  for (auto x : Q3) cout << x << '\n';
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