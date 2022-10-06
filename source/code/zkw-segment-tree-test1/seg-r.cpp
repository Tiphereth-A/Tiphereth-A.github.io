#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/time.h>

#define fp(i, l, r) for (register uint64_t i = (l); i <= (r); ++i)
#define fr(a) freopen((a), "r", stdin)
#define fw(a) freopen((a), "w", stdout)
#define fc fclose(stdin), fclose(stdout)
#define il inline
#define ls rt << 1
#define rs rt << 1 | 1
#define Mid uint64_t m = ((r - l) >> 1) + l
#define tpn typename
#define MAXN 10000005
#define MAXBUF 140000000

using i64 = int64_t;
using u64 = uint64_t;

il char gc() {
  static char buf[MAXBUF], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXBUF, stdin), p1 == p2) ? EOF : *p1++;
}
template <tpn A>
il void read(A &x) {
  char c;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
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

u64 sum[MAXN << 2], add[MAXN << 2], a[MAXN];
const std::string str1("data"), str3(".in"), str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test1.txt");
struct timeval start, end;

il void PushUp(const u64 &rt) {
  sum[rt] = sum[ls] + sum[rs];
}
il void PushDown(const u64 &rt, const u64 &ln, const u64 &rn) {
  add[ls] += add[rt];
  sum[ls] += add[rt] * ln;
  add[rs] += add[rt];
  sum[rs] += add[rt] * rn;
  add[rt] = 0;
}
void Build(const u64 &l, const u64 &r, const u64 &rt) {
  if (l == r) {
    sum[rt] = a[l];
    return;
  }
  Mid;
  Build(l, m, ls);
  Build(m + 1, r, rs);
  PushUp(rt);
}
void Update(const u64 &L, const u64 &R, const u64 &c, const u64 &l, const u64 &r, const u64 &rt) {
  if (L <= l && r <= R) {
    sum[rt] += c * (r - l + 1);
    add[rt] += c;
    return;
  }
  Mid;
  PushDown(rt, m - l + 1, r - m);
  if (L <= m)
    Update(L, R, c, l, m, ls);
  if (R > m)
    Update(L, R, c, m + 1, r, rs);
  PushUp(rt);
}
u64 Query(const u64 &L, const u64 &R, const u64 &l, const u64 &r, const u64 &rt) {
  u64 ans = 0;
  if (L <= l && r <= R)
    return sum[rt];
  Mid;
  PushDown(rt, m - l + 1, r - m);
  if (L <= m)
    ans += Query(L, R, l, m, ls);
  if (R > m)
    ans += Query(L, R, m + 1, r, rs);
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
    u64 n = 0, m = 0;
    read(n, m);
    fp(i, 1, n) read(a[i]);
    Build(1, n, 1);
    u64 o = 0, x = 0, y = 0, k = 0;
    while (m--) {
      read(o, x, y);
      if (o & 1) {
        read(k);
        Update(x, y, k, 1, n, 1);
      } else printf("%llu\n", Query(x, y, 1, n, 1));
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
