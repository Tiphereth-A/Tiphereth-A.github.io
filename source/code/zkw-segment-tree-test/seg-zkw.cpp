#include <cassert>
#include <cstdio>
#include <iostream>
#include <sys/time.h>

using u64 = uint64_t;
using u32 = uint32_t;

#define FINLINE __inline__ __attribute__((always_inline))

struct timeval start, end;

namespace FastIO {
const u32 MAX_BUFFER_SIZE = 1 << 21;
char buf_read[MAX_BUFFER_SIZE], buf_print[MAX_BUFFER_SIZE], a[30];
char *p_read = buf_read, *p_print = buf_read;
int p, now_print = -1;
FINLINE int getc() {
  return p_read == p_print && (p_print = (p_read = buf_read) +
                                         fread(buf_read, 1, 1 << 21, stdin),
                               p_read == p_print) ?
           EOF :
           *p_read++;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getc();
  while (!isdigit(ch)) { ch = getc(); }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getc();
  }
}
template <typename T>
inline void read(T &x, T &y) {
  read(x);
  read(y);
}
inline void flush() {
  fwrite(buf_print, 1, now_print + 1, stdout), now_print = -1;
}
template <typename T>
inline void print(T x) {
  if (now_print > MAX_BUFFER_SIZE / 2) flush();
  do { a[++p] = x % 10 + 48; } while (x /= 10);
  do { buf_print[++now_print] = a[p]; } while (--p);
  buf_print[++now_print] = '\n';
}
}  // namespace FastIO
using FastIO::print;
using FastIO::read;
//================================================================
const u32 _N = 2e7 + 5;
u32 n, m;

namespace zkwSegtree {

#define _ls(p) ((p) << 1)
#define _rs(p) ((p) << 1 | 1)
#define _now(p) tree[p]
#define _lch(p) tree[_ls(p)]
#define _rch(p) tree[_rs(p)]

struct node {
  u64 sum, lazy;
  void operator+=(const node &other) {
    sum += other.sum;
    lazy += other.lazy;
  }
} tree[_N << 2];

u32 N = 1;

FINLINE void init() {
  for (; N <= n + 1; N <<= 1);
  for (u32 i = N + 1; i <= N + n; ++i) read(_now(i).sum);
  for (u32 i = N - 1; i; --i) _now(i).sum = _lch(i).sum + _rch(i).sum;
}
void update(u32 &s, u32 &t, u64 &k) {
  u64 lNum = 0, rNum = 0, nNum = 1;
  for (s = N + s - 1, t = N + t + 1; s ^ t ^ 1; s >>= 1, t >>= 1, nNum <<= 1) {
    _now(s).sum += k * lNum;
    _now(t).sum += k * rNum;
    if (~s & 1) {
      _now(s ^ 1) += {k * nNum, k};
      lNum += nNum;
    }
    if (t & 1) {
      _now(t ^ 1) += {k * nNum, k};
      rNum += nNum;
    }
  }
  for (; s; s >>= 1, t >>= 1) {
    _now(s).sum += k * lNum;
    _now(t).sum += k * rNum;
  }
}
u64 query(u32 &s, u32 &t) {
  u64 lNum = 0, rNum = 0, nNum = 1;
  u64 ans = 0;
  for (s = N + s - 1, t = N + t + 1; s ^ t ^ 1; s >>= 1, t >>= 1, nNum <<= 1) {
    if (_now(s).lazy) ans += _now(s).lazy * lNum;
    if (_now(t).lazy) ans += _now(t).lazy * rNum;
    if (~s & 1) {
      ans += _now(s ^ 1).sum;
      lNum += nNum;
    }
    if (t & 1) {
      ans += _now(t ^ 1).sum;
      rNum += nNum;
    }
  }
  for (; s; s >>= 1, t >>= 1) ans += _now(s).lazy * lNum + _now(t).lazy * rNum;
  return ans;
}
}  // namespace zkwSegtree
using zkwSegtree::init;
using zkwSegtree::query;
using zkwSegtree::update;
char c;
u32 x, y;
u64 k;

int main(int argc, char *argv[]) {
  assert(argc == 4);
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);
  freopen(argv[3], "a", stderr);
  gettimeofday(&start, NULL);
  //================================================================
  read(n, m);
  init();
  while (m--) {
#ifdef __linux

#FastIO::getc();
#endif
    c = FastIO::getc();
    assert(c == '1' || c == '2');
    read(x, y);
    if (c & 1) {
      read(k);
      update(x, y, k);
    } else print(query(x, y));
  }
  FastIO::flush();
  //================================================================
  gettimeofday(&end, NULL);
  std::cerr << start.tv_sec << "." << start.tv_usec << std::endl
            << end.tv_sec << "." << end.tv_usec << std::endl
            << std::endl;
  return 0;
}
