#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int a1, a2, b1, b2, c1, c2;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
    double BC2 = (b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2);
    double AB2 = (b1 - a1) * (b1 - a1) + (b2 - a2) * (b2 - a2);
    double zuo = 2.0 * (sqrt(BC2 - 4) - sqrt(AB2 - 4));
    double you = 1.0 * (b1 - a1) * (c1 - b1) + (b2 - a2) * (c2 - b2);
    puts(zuo < you ? "yes" : "no");
  }
  return 0;
}