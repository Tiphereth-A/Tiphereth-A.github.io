#include <bits/stdc++.h>
using namespace std;
mt19937 rd(1);
const int inf = 1e8;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1e6, m = 1e6;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; ++i) cout << (int)rd() % inf << ' ';
    cout << '\n';
    for (int i = 1; i <= 999990; ++i) cout << i - 1 << ' ' << 1 << ' ' << rd() % n + 1 << ' ' << (int)rd() % inf << '\n';
    for (int i = 1; i <= 10; ++i) cout << 999990 << ' ' << 2 << ' ' << rd() % n + 1 << '\n';
    return 0;
}