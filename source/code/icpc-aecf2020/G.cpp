#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
int n, m, a[N], lst[N], h[N];
int tag1[N << 2], tag2[N << 2], cov[N << 2], cnt[N << 2];
ll sum[N << 2], ans[N];
struct Query {
  int x, y, id;
} q[N];
inline bool operator<(Query x, Query y) {
  return x.y < y.y || (x.y == y.y && x.x < y.x);
}
inline void pushdown(int v, int l, int r) {
  int mid = l + r >> 1;
  if (cov[v]) {
    cov[v] = 0;
    cov[v << 1] ^= 1;
    swap(tag1[v << 1], tag2[v << 1]);
    cnt[v << 1] = mid - l + 1 - cnt[v << 1];
    cov[v << 1 | 1] ^= 1;
    swap(tag1[v << 1 | 1], tag2[v << 1 | 1]);
    cnt[v << 1 | 1] = r - mid - cnt[v << 1 | 1];
  }
  if (tag1[v]) {
    tag1[v << 1] += tag1[v];
    sum[v << 1] += 1ll * tag1[v] * cnt[v << 1];
    tag1[v << 1 | 1] += tag1[v];
    sum[v << 1 | 1] += 1ll * tag1[v] * cnt[v << 1 | 1];
    tag1[v] = 0;
  }
  if (tag2[v]) {
    tag2[v << 1] += tag2[v];
    sum[v << 1] += 1ll * tag2[v] * (mid - l + 1 - cnt[v << 1]);
    tag2[v << 1 | 1] += tag2[v];
    sum[v << 1 | 1] += 1ll * tag2[v] * (r - mid - cnt[v << 1 | 1]);
    tag2[v] = 0;
  }
}
void change(int v, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    cov[v] ^= 1;
    swap(tag1[v], tag2[v]);
    cnt[v] = r - l + 1 - cnt[v];
    return;
  }
  int mid = l + r >> 1;
  pushdown(v, l, r);
  if (x <= mid) change(v << 1, l, mid, x, y);
  if (mid < y) change(v << 1 | 1, mid + 1, r, x, y);
  sum[v] = sum[v << 1] + sum[v << 1 | 1];
  cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
}
void add(int v, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    tag1[v]++;
    sum[v] += 1ll * cnt[v];
    return;
  }
  int mid = l + r >> 1;
  pushdown(v, l, r);
  if (x <= mid) add(v << 1, l, mid, x, y);
  if (mid < y) add(v << 1 | 1, mid + 1, r, x, y);
  sum[v] = sum[v << 1] + sum[v << 1 | 1];
  cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
}
ll query(int v, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return sum[v];
  }
  int mid = l + r >> 1;
  pushdown(v, l, r);
  ll res = 0;
  if (x <= mid) res += query(v << 1, l, mid, x, y);
  if (mid < y) res += query(v << 1 | 1, mid + 1, r, x, y);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    lst[i] = h[a[i]];
    h[a[i]] = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &q[i].x, &q[i].y);
    q[i].id = i;
  }
  sort(q + 1, q + m + 1);
  for (int i = 1, j = 1; i <= n && j <= m; ++i) {
    change(1, 1, n, lst[i] + 1, i);
    add(1, 1, n, 1, i);
    while (q[j].y == i) {
      ans[q[j].id] = query(1, 1, n, q[j].x, q[j].y);
      ++j;
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}