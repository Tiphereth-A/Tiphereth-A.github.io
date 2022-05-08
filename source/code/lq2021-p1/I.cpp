// From AgOH
//! AgOH TQL
//! stO AgOH Orz
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define _for(i, l, r) for (decltype(l + r) i = (l); i <= (r); ++i)
#define _set_nul(a) memset(a, 0, sizeof(a))

const int N = 5e3 + 5, MOD = 1e9 + 7;
int lb[N];
int dp[N][N], pre[N][N];
int calc(string &s) {
    int l = 0, r = 0, cnt = 0, len_lb = 0, x = 0;
    for (char c : s) {
        if (c == 40) {
            ++l;
            ++cnt;
        } else {
            lb[++len_lb] = max(++r - l, 0);
            --cnt;
        }
        if (cnt < 0) {
            ++x;
            ++cnt;
        }
    }
    _set_nul(dp);
    _set_nul(pre);
    _for(i, lb[1], x) pre[dp[1][i] = 1][i] = i - lb[1] + 1;
    _for(i, 2, len_lb)
        _for(j, lb[i], x) {
            dp[i][j] = pre[i - 1][j];
            pre[i][j] = j ? pre[i][j - 1] + dp[i][j] % MOD : dp[i][j];
        }
    return dp[len_lb][x];
}
int main() {
    string s;
    cin >> s;
    i64 ans = calc(s);
    transform(s.begin(), s.end(), s.begin(), [](char c) -> char { return c ^ 1; });
    reverse(s.begin(), s.end());
    cout << ans * calc(s) % MOD << endl;
    return 0;
}
