#include <bits/stdc++.h>
#include "Persistable_seg_tree.hpp"

using namespace std;

const size_t N = 1e6 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    persistable_seg_tree<int> tree(a, n);
    for (int i = 1, v, op, loc, value; i <= m; ++i) {
        cin >> v >> op >> loc;
        if (op & 1) {
            cin >> value;
            tree.modify(v, loc, value);
        } else
            cout << tree.query(v, loc) << '\n';
    }
    return 0;
}
