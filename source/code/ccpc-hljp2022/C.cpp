#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n, num, h[N], a[N], f[N][2][2];
struct node {
    int to, nxt;
} e[N << 1];
inline void ins(int x, int y) {
    e[++num].to = y;
    e[num].nxt = h[x];
    h[x] = num;
    e[++num].to = x;
    e[num].nxt = h[y];
    h[y] = num;
}
void dfs(int u, int father) {
    int sz = 0;
    int fa = 1, fb = 1;
    f[u][0][0] = a[u];
    f[u][0][1] = 0;
    f[u][1][0] = n + 1;
    f[u][1][1] = a[u];
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == father) continue;
        ++sz;
        dfs(v, u);
        if (f[v][1][0] <= a[u] && f[v][0][0] <= a[u]) fa = 0;
        int t = n + 1;
        if (f[v][1][0] > a[u]) {
            t = min(f[v][1][1], t);
        }
        if (f[v][0][0] > a[u]) {
            t = min(f[v][0][1], t);
        }
        f[u][0][1] = max(f[u][0][1], t);
        t = 0;
        if (f[v][0][1] >= a[u] && f[v][1][1] >= a[u]) fb = 0;
        if (f[v][0][1] < a[u]) {
            t = max(f[v][0][0], t);
        }
        if (f[v][1][1] < a[u]) {
            t = max(f[v][1][0], t);
        }
        f[u][1][0] = min(f[u][1][0], t);
    }
    if (!sz) {
        f[u][0][0] = a[u];
        f[u][0][1] = 0;
        f[u][1][0] = n + 1;
        f[u][1][1] = a[u];
    } else {
        if (!fa) {
            f[u][0][0] = 0;
            f[u][0][1] = n + 1;
        }
        if (!fb) {
            f[u][1][0] = 0;
            f[u][1][1] = n + 1;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ins(x, y);
    }
    memset(f, -1, sizeof(f));
    dfs(1, 0);
    if (f[1][0][0] == a[1] || f[1][1][1] == a[1]) puts("YES");
    else puts("NO");
    return 0;
}