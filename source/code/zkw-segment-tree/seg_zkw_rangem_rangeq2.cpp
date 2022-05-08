void build() {
  for (N = 1; N <= n + 1; N <<= 1);
  fp(i, N + 1, N + n) scanf("%d", tree + i);
  fd(i, N - 1, 1) {
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    tree[i << 1] -= tree[i];
    tree[i << 1 | 1] -= tree[i];
  }
}
void update(int s, int t, int k) {
  int tmp;
  for (s += N - 1, t += N + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (~s & 1) tree[s ^ 1] += k;
    if (t & 1) tree[t ^ 1] += k;
    tmp = min(tree[s], tree[s ^ 1]);
    tree[s] -= tmp;
    tree[s ^ 1] -= tmp;
    tree[s >> 1] += tmp;
    tmp = min(tree[t], tree[t ^ 1]);
    tree[t] -= tmp;
    tree[t ^ 1] -= tmp;
    tree[t >> 1] += tmp;
  }
  for (; s != 1; s >>= 1) {  //记得要上推到根结点
    tmp = min(tree[s], tree[s ^ 1]);
    tree[s] -= tmp;
    tree[s ^ 1] -= tmp;
    tree[s >> 1] += tmp;
  }
}
int query(int s, int t) {  //闭区间
  int sAns = 0, tAns = 0;
  s += N, t += N;
  if (s != t) {  //防止查询单点时死循环
    for (; s ^ t ^ 1; s >>= 1, t >>= 1) {
      sAns += tree[s];
      tAns += tree[t];
      if (~s & 1) sAns = min(sAns, tree[s ^ 1]);
      if (t & 1) tAns = min(tAns, tree[t ^ 1]);
    }
  }
  int ans = min(sAns + tree[s], tAns + tree[t]);
  while (s > 1) ans += tree[s >>= 1];
  return ans;
}
