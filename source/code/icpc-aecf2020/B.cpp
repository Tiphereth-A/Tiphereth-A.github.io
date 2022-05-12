#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
#define inc(i) (++(i))
#define dec(i) (--(i))
#define Rep(i, a, b) for (int i = (a), i##Limit = (b); i <= i##Limit; inc(i))
#define rep(i, a, b) for (int i = (a), i##Limit = (b); i >= i##Limit; dec(i))
using namespace std;
const int N = 500 + 7;
int n, m, Up[N][N], Down[N][N];
bool Book[N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int Ans = n * (n + 1) * m * (m + 1) / 4, x, y;
    Rep(i, 1, n)
        Rep(j, 1, m)
            Up[i][j] = 0,
            Down[i][j] = n + 1;
    while (cin >> x >> y) {
        int u = 0, d = n + 1;
        for (int j = y; j >= 1 && !Book[x][j]; dec(j)) {
            u = max(u, Up[x][j]), d = min(d, Down[x][j]);
            int uu = u, dd = d;
            for (int k = y; k <= m && !Book[x][k]; inc(k)) {
                uu = max(uu, Up[x][k]), dd = min(dd, Down[x][k]);
                Ans -= (x - uu) * (dd - x);
            }
        }
        Rep(i, x + 1, n) if (!Book[i][y]) Up[i][y] = x;
        else break;
        rep(i, x - 1, 1) if (!Book[i][y]) Down[i][y] = x;
        else break;
        cout << Ans << '\n';
        Book[x][y] = 1;
    }
    return 0;
}
