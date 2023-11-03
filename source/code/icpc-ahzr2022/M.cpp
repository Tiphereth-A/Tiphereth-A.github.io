#include <bits/stdc++.h>
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; ++i)
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; --i)
using namespace std;
using i64 = long long;

int n, k;
i64 ans;
struct tree {
  int tot;
  vector<vector<pair<int, int>>> e;
  vector<i64> s, d;
  vector<int> dfn, cnt, de, sz, node;
  tree(int n)
    : tot(0), e(n), s(n), d(n), dfn(n), cnt(n), de(n), sz(n), node(n) {}
  void add(int u, int v, int w) {
    e[u].emplace_back(v, w), e[v].emplace_back(u, w);
  }
  void dfs1(int u, int fa) {
    dfn[u] = tot++, node[dfn[u]] = u, cnt[u] = de[u], sz[u] = 1;
    for (auto [v, w] : e[u])
      if (v != fa) {
        d[v] = d[u] + w;
        dfs1(v, u);
        cnt[u] += cnt[v];
        s[u] += s[v] + 1ll * cnt[v] * w;
        sz[u] += sz[v];
      }
  }
  void dfs2(int u, int fa, i64 dis_) {
    for (auto [v, w] : e[u])
      if (v != fa) {
        dfs2(
          v, u, dis_ + s[u] - s[v] - 1ll * cnt[v] * w + 1ll * (k - cnt[v]) * w);
      }
    s[u] += dis_;
  }
};
struct segment {
  vector<i64> t;
  segment(int n): t(n * 4) {}
  void build(int x, int l, int r, vector<i64> const &a) {
    if (l == r) {
      t[x] = a[l];
      return;
    }
    int mid = l + (r - l) / 2;
    build(x << 1, l, mid, a), build(x << 1 | 1, mid + 1, r, a);
    t[x] = gcd(t[x << 1], t[x << 1 | 1]);
  }
  void update(int x, int l, int r, int pos, i64 k) {
    if (l == r) {
      t[x] += k;
      return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) update(x << 1, l, mid, pos, k);
    else update(x << 1 | 1, mid + 1, r, pos, k);
    t[x] = gcd(t[x << 1], t[x << 1 | 1]);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  vector<int> c(k), dfnc(k);
  tree tr(n);
  for (auto &x : c) cin >> x, --x, tr.de[x] = 1;
  Rep(i, 1, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    tr.add(u, v, w);
  }
  tr.dfs1(0, 0), tr.dfs2(0, 0, 0);
  sort(c.begin(), c.end(), [&](int a, int b) { return tr.dfn[a] < tr.dfn[b]; });
  vector<i64> a(k);
  for (int i = 0; i < k; ++i) a[i] = tr.d[c[i]], dfnc[i] = tr.dfn[c[i]];
  for (int i = k - 1; i; --i) a[i] = a[i] - a[i - 1];
  segment seg(k);
  seg.build(1, 0, k - 1, a);
  ans = INT64_MAX;
  dfnc.push_back(INT32_MAX);
  auto dfs = [&](auto &&dfs, int u, int fa) -> void {
    if (seg.t[1]) ans = min(ans, abs(tr.s[u] / seg.t[1]));
    else ans = 0;
    for (auto [v, w] : tr.e[u])
      if (v != fa) {
        int a;
        // dfn[v] .. dfn[v] + sz[v] - 1
        if (tr.dfn[v] <= dfnc[0] && dfnc[0] <= tr.dfn[v] + tr.sz[v] - 1)
          seg.update(1, 0, k - 1, 0, -w);
        else {
          seg.update(1, 0, k - 1, 0, w);
          a = lower_bound(dfnc.begin(), dfnc.end(), tr.dfn[v]) - dfnc.begin();
          if (a < k) seg.update(1, 0, k - 1, a, -2 * w);
        }
        a = upper_bound(dfnc.begin(), dfnc.end(), tr.dfn[v] + tr.sz[v] - 1) -
            dfnc.begin();
        if (a < k) seg.update(1, 0, k - 1, a, 2 * w);

        dfs(dfs, v, u);

        if (tr.dfn[v] <= dfnc[0] && dfnc[0] <= tr.dfn[v] + tr.sz[v] - 1)
          seg.update(1, 0, k - 1, 0, w);
        else {
          seg.update(1, 0, k - 1, 0, -w);
          a = lower_bound(dfnc.begin(), dfnc.end(), tr.dfn[v]) - dfnc.begin();
          if (a < k) seg.update(1, 0, k - 1, a, 2 * w);
        }
        a = upper_bound(dfnc.begin(), dfnc.end(), tr.dfn[v] + tr.sz[v] - 1) -
            dfnc.begin();
        if (a < k) seg.update(1, 0, k - 1, a, -2 * w);
      }
  };
  dfs(dfs, 0, 0);
  cout << ans * 2;
  return 0;
}