#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> e[MAXN];
int dis[MAXN], vis[MAXN];

void spfa(int n, int s) {
  for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;

  priority_queue<pair<int, int>> pq;
  dis[s] = 0, vis[s] = 1;
  pq.push(make_pair(-dis[s], s));

  int cnt = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    vis[u] = 0, ++cnt;
    for (size_t i = 0; i < e[u].size(); i++) {
      int v = e[u][i].first, w = e[u][i].second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (vis[v] == 0) {
          pq.push({-dis[v], v});
          vis[v] = 1;
        }
      }
    }
  }
  printf("%d\n", cnt);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[u].push_back(make_pair(v, w));
    e[v].push_back(make_pair(u, w));
  }
  spfa(n, 1);
  return 0;
}
