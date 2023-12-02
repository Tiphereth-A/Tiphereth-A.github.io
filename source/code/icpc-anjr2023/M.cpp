#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class Tp>
using vec = vector<Tp>;
#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
struct segtree {
  struct YYZ {
    i64 sum, mx, lazy;
    YYZ(): sum(0), mx(0), lazy(0) {}
  };
  vec<YYZ> tr;
  segtree(int N): tr(N * 4) {}
  void update(int x) {
    tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
    tr[x].mx = max(tr[x << 1].mx, tr[x << 1 | 1].mx);
  }
  void build(int x, int l, int r, const vec<i64> &a) {
    tr[x].lazy = 0;
    if (l == r) {
      tr[x].sum = tr[x].mx = a[l];
      return;
    }
    int mid = l + (r - l) / 2;
    build(x << 1, l, mid, a), build(x << 1 | 1, mid + 1, r, a);
    update(x);
  }
  void pushdown(int x, int l, int r) {
    if (tr[x].lazy) {
      int mid = l + (r - l) / 2;
      tr[x << 1].lazy = tr[x << 1].mx = tr[x].lazy,
              tr[x << 1].sum = (mid - l + 1) * tr[x].lazy;
      tr[x << 1 | 1].lazy = tr[x << 1 | 1].mx = tr[x].lazy,
                  tr[x << 1 | 1].sum = (r - mid) * tr[x].lazy;
      tr[x].lazy = 0;
    }
  }
  void modify(int x, int l, int r, int L, int R, i64 k) {
    if (L <= l && R >= r) {
      tr[x].lazy = tr[x].mx = k;
      tr[x].sum = (r - l + 1) * k;
      return;
    }
    pushdown(x, l, r);
    int mid = l + (r - l) / 2;
    if (L <= mid) modify(x << 1, l, mid, L, R, k);
    if (R > mid) modify(x << 1 | 1, mid + 1, r, L, R, k);
    update(x);
  }
  int query(int x, int l, int r, i64 k) {
    if (tr[1].mx < k) return r + 1;
    if (l == r) {
      if (l == 0 && tr[x].mx > k) return -1;
      return l;
    }
    pushdown(x, l, r);
    int mid = l + (r - l) / 2;
    if (tr[x << 1].mx > k) return query(x << 1, l, mid, k);
    else return query(x << 1 | 1, mid + 1, r, k);
  }
};
void solve(int t_ = 0) {
  int n;
  cin >> n;
  i64 mx = 0, sm = 0;
  vec<i64> a(n), b(n), f(n), g(n);
  for_(i, 0, n - 1)
    cin >> a[i], mx = max(mx, a[i]), b[n - 1 - i] = a[i], sm += a[i];
  f[0] = a[0];
  for (int i = 1; i < n; ++i) f[i] = max(f[i - 1], a[i]);
  g[0] = b[0];
  for (int i = 1; i < n; ++i) g[i] = max(g[i - 1], b[i]);
  segtree tf(n), tg(n);
  tf.build(1, 0, n - 1, f);
  tg.build(1, 0, n - 1, g);
  int q;
  cin >> q;
  for_(i, 1, q, l, v) {
    cin >> l >> v;
    --l;
    a[l] += v, sm += v;
    mx = max(mx, a[l]);
    int r = tf.query(1, 0, n - 1, a[l]);
    if (r - 1 >= l) tf.modify(1, 0, n - 1, l, r - 1, a[l]);
    r = tg.query(1, 0, n - 1, a[l]);
    if (r - 1 >= n - l - 1) tg.modify(1, 0, n - 1, n - l - 1, r - 1, a[l]);
    cout << tf.tr[1].sum + tg.tr[1].sum - n * mx - sm << '\n';
  }
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
