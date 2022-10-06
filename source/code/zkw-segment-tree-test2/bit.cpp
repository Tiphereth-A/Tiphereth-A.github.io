#include <cassert>
#include <cstdio>
#include <iostream>
#include <sys/time.h>

#define _lowbit(x) (1 << __builtin_ctz(x))

#define FINLINE __inline__ __attribute__((always_inline))
using u64 = uint64_t;
using u32 = uint32_t;

struct timeval start, end;

namespace FastIO {
char buf_read[1 << 21], buf_print[1 << 21], a[30];
char *p_read = buf_read, *p_print = buf_read;
int p, now_print = -1;
FINLINE int getc() {
  return p_read == p_print && (p_print = (p_read = buf_read) + fread(buf_read, 1, 1 << 21, stdin), p_read == p_print) ? EOF : *p_read++;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getc();
  while (!isdigit(ch)) {
    ch = getc();
  }
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
  if (now_print > 1 << 20)
    flush();
  do {
    a[++p] = x % 10 + 48;
  } while (x /= 10);
  do {
    buf_print[++now_print] = a[p];
  } while (--p);
  buf_print[++now_print] = '\n';
}
}  // namespace FastIO
using FastIO::print;
using FastIO::read;
//================================================================
const u32 N = 2e7 + 5;
u64 n, m;

namespace bit {
u64 c1[N], c2[N], num[N];
FINLINE void _add(u64 *r, u32 pos, const u64 &v) {
  for (; pos <= n; pos += _lowbit(pos))
    r[pos] += v;
}
FINLINE u64 _query(u64 *r, u32 pos) {
  u64 ans(0);
  for (; pos; pos -= _lowbit(pos))
    ans += r[pos];
  return ans;
}
FINLINE void init() {
  for (u32 i = 1; i <= n; ++i) {
    read(num[i]);
    _add(c1, i, num[i] - num[i - 1]);
    _add(c2, i, (i - 1) * (num[i] - num[i - 1]));
  }
}
FINLINE void update(u32 x, u32 y, u64 k) {
  _add(c1, x, k);
  _add(c1, y + 1, -k);
  _add(c2, x, k * (x - 1));
  _add(c2, y + 1, -k * y);
}
FINLINE u64 query(u32 x, u32 y) {
  return y * _query(c1, y) - _query(c2, y) -
         ((x - 1) * _query(c1, x - 1) - _query(c2, x - 1));
}

}  // namespace bit
using bit::init;
using bit::query;
using bit::update;

u64 op, x, y, k;

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
    op = FastIO::getc();
    read(x, y);
    if (op & 1) {
      read(k);
      update(x, y, k);
    } else
      print(query(x, y));
  }
  FastIO::flush();
  //================================================================
  gettimeofday(&end, NULL);
  std::cerr << start.tv_sec << "." << start.tv_usec << std::endl
            << end.tv_sec << "." << end.tv_usec << std::endl
            << std::endl;
  return 0;
}
