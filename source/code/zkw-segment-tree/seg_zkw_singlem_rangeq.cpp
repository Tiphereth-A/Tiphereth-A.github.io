// 单点修改+区间查询
#include <cstdio>

const int MAXN = 2e5 + 5;
int tree[MAXN << 2];  // tree是线段树数组
int n, N = 1;         // n是原数组实际长度, N下面会解释

#define fp(i, l, r) for (register int i = (l); i <= (r); ++i)
#define fd(i, r, l) for (register int i = (r); i >= (l); --i)

void build() {
  scanf("%d", &n);
  for (; N <= n + 1; N <<= 1)
    ;
  fp(i, N + 1, N + n) scanf("%d", tree + i);  // 等价于scanf("%d", &tree[i])
  fd(i, N - 1, 1) tree[i] =
    tree[i << 1] +
    tree[i << 1 | 1];  // 等价于tree[i] = tree[i*2] + tree[i*2 + 1]
}

void modify(int x, int k) {
  for (x += N; x; x >>= 1) tree[x] += k;
}

int query(int s, int t) {
  int ans = 0;
  // 这个for的信息量有点大
  // 第一个分号前面就是将s和t初始化
  // s ^ r ^ 1就是判断对应结点的父结点是否相同
  // 很容易看出来当对应结点互为左右儿子时, s^t = 1, 再^1之后就是0
  // 而其他情况时, s^t大于1, ^1后当然不是0
  // 第二个分号后面就是s,t上移
  for (s = N + s - 1, r = N + r + 1; s ^ r ^ 1; s >>= 1, r >>= 1) {
    if (~s & 1) ans += tree[s ^ 1];
    if (r & 1) ans += tree[r ^ 1];
    // 这两句的含义对照上面的实现过程看就能明白
  }
  return ans;
}

int main() {
  // 按需补充吧
}
