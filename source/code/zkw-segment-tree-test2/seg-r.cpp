#include <cassert>
#include <cstdio>
#include <iostream>
#include <sys/time.h>

#define _for_u64(i, l, r) for (register u64 i = (l); i <= (r); ++i)
#define _for_u32(i, l, r) for (register u32 i = (l); i <= (r); ++i)
#define FINLINE __inline__ __attribute__((always_inline))
using u64 = uint64_t;
using u32 = uint32_t;

struct timeval start, end;

namespace FastIO {
char buf_read[1 << 21], buf_print[1 << 21], a[30];
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
  if (now_print > 1 << 20) flush();
  do { a[++p] = x % 10 + 48; } while (x /= 10);
  do { buf_print[++now_print] = a[p]; } while (--p);
  buf_print[++now_print] = '\n';
}
}  // namespace FastIO
using FastIO::print;
using FastIO::read;
//================================================================
const u32 N = 2e7 + 5;
u32 n, m;
u64 a[N];

namespace Segtree {

#define _ls(p) ((p) << 1)
#define _rs(p) ((p) << 1 | 1)
#define _mid u64 m = ((r - l) >> 1) + l
#define _now tree[p]
#define _lch tree[_ls(p)]
#define _rch tree[_rs(p)]
struct node {
  u64 sum, lazy;
  void operator+=(const node &other) {
    sum += other.sum;
    lazy += other.lazy;
  }
} tree[N << 2];

FINLINE void push_up(u32 p) { _now.sum = _lch.sum + _rch.sum; }
FINLINE void push_down(u32 p, u32 ln, u32 rn) {
  _lch += {_now.lazy * ln, _now.lazy};
  _rch += {_now.lazy * rn, _now.lazy};
  _now.lazy = 0;
}
void init(u32 l = 1, u32 r = n, u32 p = 1) {
  if (l == r) {
    _now = {a[l], 0};
    return;
  }
  _mid;
  init(l, m, _ls(p));
  init(m + 1, r, _rs(p));
  push_up(p);
}
void update(u32 L, u32 R, u64 c, u32 l = 1, u32 r = n, u32 p = 1) {
  if (L <= l && r <= R) {
    _now += {c * (r - l + 1), c};
    return;
  }
  _mid;
  push_down(p, m - l + 1, r - m);
  if (L <= m) update(L, R, c, l, m, _ls(p));
  if (R > m) update(L, R, c, m + 1, r, _rs(p));
  push_up(p);
}
u64 query(u32 L, u32 R, u32 l = 1, u32 r = n, u32 p = 1) {
  if (L <= l && r <= R) return _now.sum;
  _mid;
  u64 ans = 0;
  push_down(p, m - l + 1, r - m);
  if (L <= m) ans += query(L, R, l, m, _ls(p));
  if (R > m) ans += query(L, R, m + 1, r, _rs(p));
  return ans;
}
}  // namespace Segtree
using Segtree::init;
using Segtree::query;
using Segtree::update;

u32 o, x, y;
u64 k;

int main(int argc, char *argv[]) {
  assert(argc == 4);
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);
  freopen(argv[3], "a", stderr);
  gettimeofday(&start, NULL);
  //================================================================
  read(n, m);
  _for_u32(i, 1, n) read(a[i]);
  init();
  while (m--) {
#ifdef __linux

#FastIO::getc();
#endif
    o = FastIO::getc();
    read(x, y);
    if (o & 1) {
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
