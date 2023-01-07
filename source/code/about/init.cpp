#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using db = double;
using ldb = long double;
using pii = pair<int, int>;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), i##end = (r), ##vals; i <= i##end; ++i)
#define _rfor(i, r, l, vals...) for (make_signed_t<decltype(r - l)> i = (r), i##end = (l), ##vals; i >= i##end; --i)
#define _foreach_val(i, container) for (auto i : container)
#define _foreach_ref(i, container) for (auto &i : container)
#define _foreach_cref(i, container) for (const auto &i : container)
#define _for_graph(head, e, i, now) for (int i = head[now], to = e[i].to; i; to = e[i = e[i].next].to)
#define _ins(a) std::inserter((a), (a).begin())
#define _all(a) (a).begin(), (a).end()
#define _set_nul(a) memset(a, 0, sizeof(a))
#define _set_inf(a) memset(a, 0x3f, sizeof(a))
#define _set_nul_n(a, n) memset(a, 0, sizeof(a[0]) * (n))
#define _set_inf_n(a, n) memset(a, 0x3f, sizeof(a[0]) * (n))
#define _fin goto FINISHED
#define _divb(l, r, n, expressions)                 \
  for (decltype(n) l = 2, r; l <= (n); l = r + 1) { \
    r = (n) / ((n) / l);                            \
    expressions;                                    \
  }
#define _run_exit(expressions) _run_return(expressions, 0)
#define _run_return(expressions, val) return (expressions), val
#define _run_return_void(expressions) \
  {                                   \
    expressions;                      \
    return;                           \
  }
#define _run_fin(expressions) \
  {                           \
    expressions;              \
    _fin;                     \
  }
#define _run_break(expressions) \
  {                             \
    expressions;                \
    break;                      \
  }
#define _run_continue(expressions) \
  {                                \
    expressions;                   \
    continue;                      \
  }
#define _mid(l, r) ((l) + (((r) - (l)) >> 1))
#define _len(l, r) ((r) - (l) + 1)
#define _lowbit(x) (1 << __builtin_ctz(x))
#define _lowbit_64(x) (1 << __builtin_ctzll(x))
#define _debug                                          \
  {                                                     \
    fprintf(stderr, "%d %s\n", __LINE__, __FUNCTION__); \
    fflush(stderr);                                     \
  }

template <class T>
bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T>
bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }

const int OFFSET = 5;
const int N = 5e5 + OFFSET, M = 2e5 + OFFSET, K = 21;
const int MOD = 1e9 + 7;
const db EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const i64 INFLL = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1.0);
const pii DIR4[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const pii DIR8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

#define MULTI_CASES

auto __STATIC__ = []() { return 0.0; }();

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
  clock_t _CLOCK_ST = clock();
#endif
  //======================================
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#ifdef MULTI_CASES
  int _t;
  cin >> _t;
  while (_t--)
#endif
    solve();
  //======================================
FINISHED:
#ifndef ONLINE_JUDGE
  std::cerr << "\n---\n"
            << "Time used: " << clock() - _CLOCK_ST << std::endl;
#endif
  return 0;
}
