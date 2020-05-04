#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define ll long long
int n, t[N], a[N];
ll ans = 0;
inline void add(int x) {
  for (; x <= n; x += x & (-x)) t[x]++;
}
inline int query(int x) {
  int y = 0;
  for (; x; x -= x & (-x)) y += t[x];
  return y;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += 1ll * (i - 1 - query(a[i]));
    add(a[i]);
  }
  cout << ans;
  return 0;
}
