---
title: 「线段树的扩展之浅谈zkw线段树」一文的测试代码与结果更新
tags:
  - 程序设计
  - 洛谷日报
  - 测试
date: 2020-02-10 02:04:18
comments: false
---

更新的原因主要是笔者觉得以前的码风很乱 QwQ

<!--more-->

测试平台:

- 系统: Ubuntu 18.04 LTS 64 位

- CPU: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz

所有代码均使用基于`fread`和`fwrite`的快读快写模板, 并在编译时使用 C++98 标准和 O3 优化

结果 (单位: s):

|           | 递归线段树 | zkw 线段树 | 树状数组 |
| :-------: | :--------: | :--------: | :------: |
| 1e6(5 组) |  0.31803   |  0.20853   | 0.17850  |
| 5e6(5 组) |  2.04103   |  0.96225   | 1.45518  |
| 1e7(5 组) |  6.47973   |  3.73674   | 3.76717  |
| 2e7(5 组) |  14.7163   |  8.07310   | 7.91748  |

可以注意到, 正如 @[frankchenfu](https://www.luogu.com.cn/user/23398) 在原文评论里所说, 开了 O3 优化后, zkw 线段树得到了更显著的优化, 速度与树状数组更加接近(毕竟依 zkw julao 所说, 二者理论上速度应该差不多)

而且笔者自认为 zkw 线段树更优美, 所以还是推荐各位学习 zkw 线段树 QwQ

测试代码:

1. 递归线段树:

   ```cpp
   #include <sys/time.h>
   #include <cassert>
   #include <cstdio>
   #include <iostream>

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
                                 p_read == p_print)
               ? EOF
               : *p_read++;
   }
   template <typename T>
   inline void read(T& x) {
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
   inline void read(T& x, T& y) {
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
     void operator+=(const node& other) {
       sum += other.sum;
       lazy += other.lazy;
     }
   } tree[N << 2];

   FINLINE void push_up(u32 p) {
     _now.sum = _lch.sum + _rch.sum;
   }
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
     if (L <= m)
       update(L, R, c, l, m, _ls(p));
     if (R > m)
       update(L, R, c, m + 1, r, _rs(p));
     push_up(p);
   }
   u64 query(u32 L, u32 R, u32 l = 1, u32 r = n, u32 p = 1) {
     if (L <= l && r <= R)
       return _now.sum;
     _mid;
     u64 ans = 0;
     push_down(p, m - l + 1, r - m);
     if (L <= m)
       ans += query(L, R, l, m, _ls(p));
     if (R > m)
       ans += query(L, R, m + 1, r, _rs(p));
     return ans;
   }
   }  // namespace Segtree
   using Segtree::init;
   using Segtree::query;
   using Segtree::update;

   u32 o, x, y;
   u64 k;

   int main(int argc, char* argv[]) {
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

   #   FastIO::getc();
   #endif
       o = FastIO::getc();
       read(x, y);
       if (o & 1) {
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
   ```

2. zkw 线段树:

   ```cpp
   #include <sys/time.h>
   #include <cassert>
   #include <cstdio>
   #include <iostream>

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
     return p_read == p_print &&
                   (p_print = (p_read = buf_read) +
                               fread(buf_read, 1, MAX_BUFFER_SIZE, stdin),
                     p_read == p_print)
               ? EOF
               : *p_read++;
   }
   template <typename T>
   inline void read(T& x) {
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
   inline void read(T& x, T& y) {
     read(x);
     read(y);
   }
   inline void flush() {
     fwrite(buf_print, 1, now_print + 1, stdout), now_print = -1;
   }
   template <typename T>
   inline void print(T x) {
     if (now_print > MAX_BUFFER_SIZE / 2)
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
     void operator+=(const node& other) {
       sum += other.sum;
       lazy += other.lazy;
     }
   } tree[_N << 2];

   u32 N = 1;

   FINLINE void init() {
     for (; N <= n + 1; N <<= 1)
       ;
     for (u32 i = N + 1; i <= N + n; ++i)
       read(_now(i).sum);
     for (u32 i = N - 1; i; --i)
       _now(i).sum = _lch(i).sum + _rch(i).sum;
   }
   void update(u32& s, u32& t, u64& k) {
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
   u64 query(u32& s, u32& t) {
     u64 lNum = 0, rNum = 0, nNum = 1;
     u64 ans = 0;
     for (s = N + s - 1, t = N + t + 1; s ^ t ^ 1; s >>= 1, t >>= 1, nNum <<= 1) {
       if (_now(s).lazy)
         ans += _now(s).lazy * lNum;
       if (_now(t).lazy)
         ans += _now(t).lazy * rNum;
       if (~s & 1) {
         ans += _now(s ^ 1).sum;
         lNum += nNum;
       }
       if (t & 1) {
         ans += _now(t ^ 1).sum;
         rNum += nNum;
       }
     }
     for (; s; s >>= 1, t >>= 1)
       ans += _now(s).lazy * lNum + _now(t).lazy * rNum;
     return ans;
   }
   }  // namespace zkwSegtree
   using zkwSegtree::init;
   using zkwSegtree::query;
   using zkwSegtree::update;
   char c;
   u32 x, y;
   u64 k;

   int main(int argc, char* argv[]) {
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

   #   FastIO::getc();
   #endif
       c = FastIO::getc();
       assert(c == '1' || c == '2');
       read(x, y);
       if (c & 1) {
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
   ```

3. 树状数组:

   ```cpp
   #include <sys/time.h>
   #include <cassert>
   #include <cstdio>
   #include <iostream>

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
     return p_read == p_print && (p_print = (p_read = buf_read) +
                                           fread(buf_read, 1, 1 << 21, stdin),
                                 p_read == p_print)
               ? EOF
               : *p_read++;
   }
   template <typename T>
   inline void read(T& x) {
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
   inline void read(T& x, T& y) {
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
   FINLINE void _add(u64* r, u32 pos, const u64& v) {
     for (; pos <= n; pos += _lowbit(pos))
       r[pos] += v;
   }
   FINLINE u64 _query(u64* r, u32 pos) {
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

   int main(int argc, char* argv[]) {
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

   #   FastIO::getc();
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
   ```

4. 数据生成器:

   ```cpp
   #include <climits>
   #include <ctime>
   #include <fstream>
   #include <random>
   #include <sstream>

   using namespace std;
   const int max_n[] = {1, (int)1e6, (int)5e6, (int)1e7, (int)2e7};

   ofstream out;
   stringstream ss;
   string filename;

   int main() {
     int cnt = 1;
     for (int i = 1; i < sizeof(max_n) / sizeof(max_n[0]); ++i) {
       default_random_engine e(time(NULL));
       uniform_int_distribution<unsigned> u_mn(max_n[i - 1], max_n[i]),
           u_case(1, 2);
       uniform_int_distribution<uint64_t> u_data(0, ULLONG_MAX);
       for (register int i = 0; i < 5; ++i, ++cnt) {
         ss.clear();
         ss << cnt << ".in";
         ss >> filename;
         out.open(filename);
         int n = u_mn(e), m = u_mn(e);
         out << n << " " << m << endl;
         for (register int i = 1; i < n; ++i)
           out << u_data(e) << " ";
         out << u_data(e) << endl;
         uniform_int_distribution<unsigned> u_range(1, n);
         for (register int i = 0; i < m; ++i) {
           int op = u_case(e);
           unsigned x = u_range(e), y = u_range(e);
           if (op & 1)
             out << op << " " << min(x, y) << " " << max(x, y) << " " << u_data(e)
                 << endl;
           else
             out << op << " " << min(x, y) << " " << max(x, y) << endl;
         }
         out.close();
       }
     }
     return 0;
   }
   ```

[回到原文](..)
