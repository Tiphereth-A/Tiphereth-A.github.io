#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 1, l = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] - l >= k) {
      ans++;
      l = a[i];
    }
  }
  cout << ans;
}