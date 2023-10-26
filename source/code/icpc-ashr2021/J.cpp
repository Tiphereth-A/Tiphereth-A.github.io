#include <bits/stdc++.h>
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; ++i)
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; --i)
#define debug cout << __LINE__ << "RE" << endl
using namespace std;
using i64 = long long;
using u32 = uint32_t;

const int N = 50000 + 7;
void solve(int t_ = 0) {
  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    if (i) s[i] = s[i - 1];
    s[i] += a[i] == '1' ? 1 : -1;
  }
  bitset<N * 2> ans, les, gre;
  ans.set();
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int a, int b) { return s[a] < s[b]; });
  gre.set();
  for (int i = 0, j = 0, flag = 1; i < n; i = j + 1) {
    while (j + 1 < n && s[id[j + 1]] == s[id[i]]) ++j;
    if (flag && s[id[i]] > 0) {
      for (int k = n; k <= n + n; ++k) les[k] = 1, gre[k] = 0;
      flag = 0;
    }
    for (int k = i; k <= j; ++k)
      if (b[id[k]] == '1') ans &= les >> (n - 1 - id[k]);
      else ans &= gre >> (n - 1 - id[k]);
    for (int k = i; k <= j; ++k) les[n - 1 - id[k]] = 1, gre[n - 1 - id[k]] = 0;
  }
  for (int i = 1; i <= n; ++i) cout << ans[i];
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve(t);
  return 0;
}