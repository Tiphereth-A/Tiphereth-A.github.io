#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#define inc(i) (++(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
using namespace std;
const int N = 5000 + 7, M = 10000 + 7;
int n, m, k, Dis[N][N], Min[N];
vector<int> E[N];
queue<int> Q;
void BFS(int S) {
  Q.push(S), Dis[S][S] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : E[u])
      if (-1 == Dis[S][v]) {
        Dis[S][v] = Dis[S][u] + 1;
        Q.push(v);
      }
  }
}
double f(int k, int b) {
  return b ? 1.0 * (k % b) / (k / b + 2.0) + 1.0 * (b - k % b) / (k / b + 1.0) :
             0.0;
}
double sanfen(int a, int b) {
  int l = 0, r = k;
  while (r > l) {
    int Mid1 = l + (r - l) / 3, Mid2 = r - (r - l) / 3;
    double f1 = f(Mid1, a) * 2 + f(k - Mid1, b);
    double f2 = f(Mid2, a) * 2 + f(k - Mid2, b);
    if (f1 <= f2) r = Mid2 - 1;
    else l = Mid1 + 1;
  }
  return f(l, a) * 2.0 + f(k - l, b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m >> k;
  int u, v;
  Rep(i, 1, m) cin >> u >> v, E[u].push_back(v), E[v].push_back(u);
  Rep(i, 1, n) Rep(j, 1, n) Dis[i][j] = -1;
  Rep(i, 1, n) BFS(i);
  Rep(i, 0, n) Min[i] = 2147483647;
  int s1, s2, t1, t2;
  cin >> s1 >> t1 >> s2 >> t2;
  double Ans = sanfen(0, Dis[s1][t1] + Dis[s2][t2]);
  Rep(i, 1, n) Rep(j, 1, n) {
    if (~Dis[i][j] && ~Dis[s1][i] && ~Dis[s2][i] && ~Dis[j][t1] && ~Dis[j][t2])
      Min[Dis[i][j]] =
        min(Min[Dis[i][j]], Dis[s1][i] + Dis[s2][i] + Dis[j][t1] + Dis[j][t2]);
    if (~Dis[i][j] && ~Dis[s1][i] && ~Dis[s2][j] && ~Dis[j][t1] && ~Dis[i][t2])
      Min[Dis[i][j]] =
        min(Min[Dis[i][j]], Dis[s1][i] + Dis[s2][j] + Dis[j][t1] + Dis[i][t2]);
  }
  Rep(i, 0, n) if (Min[i] != 2147483647) Ans = min(Ans, sanfen(i, Min[i]));
  cout << fixed << setprecision(10) << Ans;
  return 0;
}
