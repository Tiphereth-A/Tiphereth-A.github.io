#include <bits/stdc++.h>
#define Rep(i, a, b, vars...)                                               \
  for (std::make_signed_t<decltype(a + b)> i = (a), i##Limit = (b), ##vars; \
       i <= i##Limit;                                                       \
       ++i)
#define rep(i, a, b, vars...)                                               \
  for (std::make_signed_t<decltype(a + b)> i = (a), i##Limit = (b), ##vars; \
       i >= i##Limit;                                                       \
       --i)
using i32 = int;
using i64 = long long;
using namespace std;

constexpr i32 inf = INT32_MAX;
i32 n, k;
vector<i32> t;
void build(i32 x, i32 l, i32 r, vector<i32> const &a) {
  if (l == r) return void(t[x] = a[l > n ? l - n : l]);
  i32 mid = l + (r - l) / 2;
  build(x << 1, l, mid, a), build(x << 1 | 1, mid + 1, r, a);
  t[x] = min(t[x << 1], t[x << 1 | 1]);
}
void update(i32 x, i32 l, i32 r, i32 pos) {
  if (l == r) return void(t[x] = inf);
  i32 mid = l + (r - l) / 2;
  if (pos <= mid) update(x << 1, l, mid, pos);
  else update(x << 1 | 1, mid + 1, r, pos);
  t[x] = min(t[x << 1], t[x << 1 | 1]);
}
i32 query(i32 x, i32 l, i32 r, i32 L, i32 R) {
  if (L > R) return inf;
  if (L <= l && R >= r) return t[x];
  i32 mid = l + (r - l) / 2, ret = inf;
  if (L <= mid) ret = query(x << 1, l, mid, L, R);
  if (R > mid) ret = min(ret, query(x << 1 | 1, mid + 1, r, L, R));
  return ret;
}
i32 dis(i32 u, i32 v) {
  if (u > v) swap(u, v);
  return min(v - u, u + n - v);
}

void solve(int _t = 0) {
  cin >> n >> k;
  vector<i32> a(n + 1), p(n + 1);
  t = vector<i32>(n * 4 + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i], p[a[i]] = i;
  build(1, 1, n, a);
  vector<vector<i64>> dp(n + 1, vector<i64>(2, 1000'000'000'000));
  i64 ans = 1000'000'000'000;
  i32 t = query(1, 1, n, k + 1, n);
  if (t == inf) {
    cout << "0\n";
    return;
  }
  dp[t][0] = dis(p[t], 1), dp[t][1] = dis(p[t], k);
  Rep(i, 1, n) {
    update(1, 1, n, p[i]);
    if (i < t) continue;
    // 1    p[i], p[i] + k - 1   n
    i32 nex0 = min(query(1, 1, n, max(1, p[i] + k - n), p[i] - 1),
                   query(1, 1, n, p[i] + k, n));
    if (nex0 == inf) ans = min(ans, dp[i][0]);
    else {
      dp[nex0][0] = min(dp[nex0][0], dp[i][0] + dis(p[i], p[nex0]));
      dp[nex0][1] = min(dp[nex0][1], dp[i][0] + dis(p[i] + k - 1, p[nex0]));
    }
    // 1    p[i] - k + 1, p[i]   n
    i32 nex1 = min(query(1, 1, n, 1, p[i] - k),
                   query(1, 1, n, p[i] + 1, min(n, p[i] + n - k)));
    if (nex1 == inf) ans = min(ans, dp[i][1]);
    else {
      dp[nex1][0] = min(dp[nex1][0], dp[i][1] + dis(p[i] - k + 1, p[nex1]));
      dp[nex1][1] = min(dp[nex1][1], dp[i][1] + dis(p[i], p[nex1]));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  Rep(i, 1, t) solve(i);
  return 0;
}