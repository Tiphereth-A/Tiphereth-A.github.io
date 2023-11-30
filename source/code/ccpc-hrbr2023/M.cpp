#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <class... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <class... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
struct op {
  string opt;
  i64 x1, y1, x2, y2, r;
  string str;
};
void solve(int t_ = 0) {
  int n;
  cin >> n;
  vector<op> oplist(n);
  for (int i = 0; i < n; ++i) {
    op opi;
    cin >> opi.opt;
    if (opi.opt == "Circle") {
      cin >> opi.x1 >> opi.y1 >> opi.r >> opi.str;
    } else if (opi.opt == "Rectangle") {
      cin >> opi.x1 >> opi.y1 >> opi.x2 >> opi.y2 >> opi.str;
    } else {
      cin >> opi.x1 >> opi.y1 >> opi.x2 >> opi.y2;
      for (i64 y = opi.y2; y >= opi.y1; --y) {
        for (i64 x = opi.x1; x <= opi.x2; ++x) {
          string now = ".";
          for (int j = i - 1; j >= 0; --j) {
            if (oplist[j].opt == "Circle") {
              if ((oplist[j].x1 - x) * (oplist[j].x1 - x) +
                    (oplist[j].y1 - y) * (oplist[j].y1 - y) <=
                  oplist[j].r * oplist[j].r) {
                now = oplist[j].str;
                break;
              }
            } else if (oplist[j].opt == "Rectangle") {
              if (oplist[j].x1 <= x && x <= oplist[j].x2 && oplist[j].y1 <= y &&
                  y <= oplist[j].y2) {
                now = oplist[j].str;
                break;
              }
            }
          }
          cout << now;
        }
        cout << "\n";
      }
    }
    oplist[i] = opi;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
