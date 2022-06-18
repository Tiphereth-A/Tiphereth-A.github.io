#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define ll long long
int n, num, h[N];
ll ans, f[N][2], g[N][2];
struct Edge {
    int to, nxt, z;
} e[N << 1];
inline void ins(int x, int y, int z) {
    e[++num].to = y;
    e[num].nxt = h[x];
    e[num].z = z;
    h[x] = num;
    e[++num].to = x;
    e[num].nxt = h[y];
    e[num].z = z;
    h[y] = num;
}
struct node {
    int x;
    ll f1, f2;
} a[N];
inline bool operator<(node x, node y) {
    return x.x < y.x;
}
void dfs(int x, int fa, int c) {
    f[x][0] = 1ll;
    f[x][1] = 1ll;
    int now = 0;
    for (int i = h[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs(y, x, e[i].z);
        ++now;
        if (e[i].z > c) f[x][0] += f[y][0];
        if (e[i].z < c) f[x][1] += f[y][1];
    }
    if (now) {
        now = 0;
        for (int i = h[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (y == fa) continue;
            a[++now] = (node){e[i].z, f[y][0], f[y][1]};
        }
        sort(a + 1, a + now + 1);
        int m = 0;
        for (int i = 1; i <= now; ++i) {
            if (i != 1 && a[i].x == a[i - 1].x) {
                g[m][0] += a[i].f1;
                g[m][1] += a[i].f2;
            } else {
                g[++m][0] = a[i].f1;
                g[m][1] = a[i].f2;
            }
        }
        ll res = 0;
        for (int i = 1; i <= m; ++i) {
            res += g[i][0] + g[i][1];
        }
        for (int i = 2; i <= m; ++i) {
            g[i][1] += g[i - 1][1];
        }
        for (int i = 2; i <= m; ++i) {
            res += g[i - 1][1] * g[i][0];
        }
        ans += res;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ins(x, y, z);
    }
    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}
