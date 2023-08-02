#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/time.h>

#define fp(i, l, r) for (uint64_t(i) = (l); (i) <= (r); (i)++)
#define fd(i, l, r) for (uint64_t i = l; i >= r; --i)
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
  read(a), read(b);
}
template <tpn A, tpn B, tpn C>
il void read(A &a, B &b, C &c) {
  read(a), read(b), read(c);
}

u64 tree[MAXN << 2], add[MAXN << 2];
u64 n, N = 1, m;
const std::string str1("data"), str3(".in"), str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test2.txt");
struct timeval start, end;

il void build() {
  read(n, m);
  for (; N <= n + 1; N <<= 1)
    ;
  fp(i, N + 1, N + n) read(tree[i]);
  fd(i, N - 1, 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
il void update(u64 &s, u64 &t, u64 &k) {
  u64 lNum = 0, rNum = 0, nNum = 1;
  for (s = N + s - 1, t = N + t + 1; s ^ t ^ 1; s >>= 1, t >>= 1, nNum <<= 1) {
    tree[s] += k * lNum;
    tree[t] += k * rNum;
    if (~s & 1) {
      add[s ^ 1] += k;
      tree[s ^ 1] += k * nNum;
      lNum += nNum;
    }
    if (t & 1) {
      add[t ^ 1] += k;
      tree[t ^ 1] += k * nNum;
      rNum += nNum;
    }
  }
  for (; s; s >>= 1, t >>= 1) {
    tree[s] += k * lNum;
    tree[t] += k * rNum;
  }
}
il u64 query(u64 &s, u64 &t) {
  u64 lNum = 0, rNum = 0, nNum = 1;
  u64 ans = 0;
  for (s = N + s - 1, t = N + t + 1; s ^ t ^ 1; s >>= 1, t >>= 1, nNum <<= 1) {
    if (add[s]) ans += add[s] * lNum;
    if (add[t]) ans += add[t] * rNum;
    if (~s & 1) {
      ans += tree[s ^ 1];
      lNum += nNum;
    }
    if (t & 1) {
      ans += tree[t ^ 1];
      rNum += nNum;
    }
  }
  for (; s; s >>= 1, t >>= 1) {
    ans += add[s] * lNum;
    ans += add[t] * rNum;
  }
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
    build();
    char c = 0;
    u64 x = 0, y = 0, k = 0;
    while (m--) {
      read(c, x, y);
      if (c & 2) printf("%llu\n", query(x, y));
      else {
        u64 k;
        read(k);
        update(x, y, k);
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
