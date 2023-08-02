#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/time.h>

#define fp(i, l, r) for (uint64_t i = (l); i <= (r); ++i)
#define lowbit(x) ((x) & -(x))
#define fr(a) freopen((a), "r", stdin)
#define fw(a) freopen((a), "w", stdout)
#define fc fclose(stdin), fclose(stdout)
#define il inline
#define tpn typename
#define MAXN 10000005
#define MAXBUF 140000000

using u64 = uint64_t;

il char gc() {
  static char buf[MAXBUF], *p1 = buf, *p2 = buf;
  return p1 == p2 &&
             (p2 = (p1 = buf) + fread(buf, 1, MAXBUF, stdin), p1 == p2) ?
           EOF :
           *p1++;
}
template <tpn A>
il void read(A &x) {
  char c;
  do { c = getchar(); } while (c < '0' || c > '9');
  x = 0;
  do {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  } while (c >= '0' && c <= '9');
}
template <tpn A, tpn B>
il void read(A &a, B &b) {
  read(a);
  read(b);
}
template <tpn A, tpn B, tpn C>
il void read(A &a, B &b, C &c) {
  read(a);
  read(b);
  read(c);
}

u64 n, m, c1[MAXN], c2[MAXN], num[MAXN];
const std::string str1("data"), str3(".in"), str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test3.txt");
struct timeval start, end;

void il add(u64 *r, u64 pos, const u64 &v) {
  for (; pos <= n; pos += lowbit(pos)) r[pos] += v;
}
u64 il query(u64 *r, u64 pos) {
  u64 ans(0);
  for (; pos; pos -= lowbit(pos)) ans += r[pos];
  return ans;
}
int main() {
  fp(j, 1, 16) {
    tmp.clear();
    tmp << j;
    tmp >> str2;
    std::string file(str1 + str2 + str3);
    fr(file.c_str());
    file = str1 + str2 + str4;
    fw(file.c_str());
    gettimeofday(&start, NULL);
    u64 op, x, y, k, sum1, sum2;
    read(n, m);
    fp(i, 1, n) {
      read(num[i]);
      add(c1, i, num[i] - num[i - 1]);
      add(c2, i, (i - 1) * (num[i] - num[i - 1]));
    }
    while (m--) {
      read(op, x, y);
      if (op & 1) {
        read(k);
        add(c1, x, k);
        add(c1, y + 1, -k);
        add(c2, x, k * (x - 1));
        add(c2, y + 1, -k * y);
      } else {
        sum1 = (x - 1) * query(c1, x - 1) - query(c2, x - 1);
        sum2 = y * query(c1, y) - query(c2, y);
        printf("%llu\n", sum2 - sum1);
      }
    }
    gettimeofday(&end, NULL);
    fout << "data#" << j << ":" << std::endl;
    fout << "\tstart:" << start.tv_sec << "." << start.tv_usec << std::endl;
    fout << "\tend:" << end.tv_sec << "." << end.tv_usec << std::endl;
    fc;
  }
  fout.close();
  return 0;
}
