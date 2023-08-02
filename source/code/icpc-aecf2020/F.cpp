#include <bits/stdc++.h>
using namespace std;
#define N 400010
int n, m, b[N];
struct node {
  int x, y, id, belong;
} a[N];
bool cmp1(node x, node y) { return x.x < y.x || (x.x == y.x && x.y < y.y); }
bool cmp2(node x, node y) { return x.y < y.y || (x.y == y.y && x.x < y.x); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
    a[i].belong = 0;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a[n + i].x, &a[n + i].y);
    a[n + i].id = i + n;
    a[n + i].belong = 1;
  }
  sort(a + 1, a + n + m + 1, cmp1);
  for (int i = 2; i <= n + m; ++i) {
    if (a[i].x == a[i - 1].x && a[i].belong != a[i - 1].belong) {
      b[a[i].id] = 1;
      b[a[i - 1].id] = 1;
    }
  }
  sort(a + 1, a + n + m + 1, cmp2);
  for (int i = 2; i <= n + m; ++i) {
    if (a[i].y == a[i - 1].y && a[i].belong != a[i - 1].belong) {
      b[a[i].id] = 1;
      b[a[i - 1].id] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d", b[i]);
  puts("");
  for (int i = 1; i <= m; ++i) printf("%d", b[n + i]);
  return 0;
}