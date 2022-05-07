// From AgOH
//! AgOH TQL
//! stO AgOH Orz
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct E {
    int to, next;
} e[N];
int cnt_edge, head[N];
void addEdge(int u, int v) {
    e[++cnt_edge] = {v, head[u]};
    head[u] = cnt_edge;
}
int f[N];
void dfs(int u) {
    int sum = 0, max_f = 0;
    for (int i = head[u], v; i; i = e[i].next) {
        v = e[i].to;
        ++sum;
        dfs(v);
        max_f = max(max_f, f[v]);
    }
    f[u] = max_f + sum;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2, fa; i <= n; ++i) {
        cin >> fa;
        addEdge(fa, i);
    }
    dfs(1);
    cout << f[1] << endl;
    return 0;
}
