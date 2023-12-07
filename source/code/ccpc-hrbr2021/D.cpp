#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;
void solve(int t_ = 0) {
  string strp, strq;
  cin >> strp >> strq;
  i64 p = stoll(strp), q = stoll(strq);
  int n = strp.size();
  i64 ans = p;
  for (int i = 1; i < (1 << n); ++i) {
    string strp1 = "";
    for (int j = 0; j < n; ++j)
      if ((i >> j) & 1) strp1 += strp[j];
    i64 p1 = stoll(strp1);
    if (!p1 || p1 >= ans) continue;
    int si = ((1 << n) - 1) ^ i;
    vector<int> a(10);
    for (int j = 0; j < n; ++j)
      if ((si >> j) & 1) ++a[strp[j] - '0'];
    i128 q1 = i128(p1) * q;
    if (q1 % p) continue;
    q1 /= p;
    stringstream ss;
    string strq1;
    ss.clear();
    ss << i64(q1);
    ss >> strq1;
    auto revq = strq, revq1 = strq1;
    reverse(revq.begin(), revq.end());
    reverse(revq1.begin(), revq1.end());
    int nowq1 = 0;
    bool flag = 0;
    for (int j = 0; j < revq.size(); ++j) {
      if (nowq1 < revq1.size() && revq[j] == revq1[nowq1]) {
        ++nowq1;
        continue;
      }
      if (a[revq[j] - '0']) --a[revq[j] - '0'];
      else if (nowq1 == revq1.size() && revq[j] == '0') {
      } else {
        flag = 1;
        break;
      }
    }
    for (int j = 0; j < 10; ++j)
      if (a[j]) flag = 1;
    if (nowq1 != revq1.size()) flag = 1;
    if (flag) continue;
    ans = min(ans, p1);
  }
  pair<i64, i64> ans1 = {ans, i64(i128(ans) * q / p)};
  cout << ans1.first << ' ' << ans1.second << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  int t_ = 0;
  cin >> t_;
  for (i_ = 0; i_ < t_; ++i_) solve(i_);
  return 0;
}
