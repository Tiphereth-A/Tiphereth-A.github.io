#include <bits/stdc++.h>
using namespace std;
#define N 320
int n;
struct node {
  int b[3];
  string country;
} a[N];
bool operator<(node x, node y) {
  return x.b[0] > y.b[0] || (x.b[0] == y.b[0] && x.b[1] > y.b[1]) ||
         (x.b[0] == y.b[0] && x.b[1] == y.b[1] && x.b[2] > y.b[2]);
}
string s;
int main() {
  cin >> n;
  getline(cin, s);
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    int len = 0;
    getline(cin, s);
    a[i].b[0] = a[i].b[1] = a[i].b[2] = 0;
    while (cnt != 3) {
      if (s[len] == ' ') {
        ++cnt;
      } else a[i].b[cnt] = a[i].b[cnt] * 10 + s[len] - '0';
      string::iterator it = s.begin();
      s.erase(it);
    }
    a[i].country = s;
  }
  sort(a + 1, a + n + 1);
  cout << a[1].country;
  return 0;
}
