#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;

#define for_(i, l, r, v...) for (ll i = (l), i##e = (r), ##v; i <= i##e; ++i)
#define fors_(i, l, r, s, v...) \
  for (ll i = (l), i##e = (r), ##v; i <= i##e; i += s)
#define rfor_(i, r, l, v...) for (ll i = (r), i##e = (l), ##v; i >= i##e; --i)
#define rfors_(i, r, l, s, v...) \
  for (ll i = (r), i##e = (l), ##v; i >= i##e; i -= s)
#define forit_(it, cont) \
  for (auto it = (cont).begin(); it != (cont).end(); ++it)
#define foritr_(it, cont, l, r) \
  for (auto it = (cont).begin() + l; it != (cont).begin() + r; ++it)
#define rforit_(it, cont) \
  for (auto it = (cont).rbegin(); it != (cont).rend(); ++it)
#define rforitr_(it, cont, l, r) \
  for (auto it = (cont).rbegin() + l; it != (cont).rbegin() + r; ++it)
#define Rep for_
#define rep rfor_
template <class Tp>
Tp dec(Tp &i) {
  return --i;
}
template <class Tp>
Tp inc(Tp &i) {
  return ++i;
}

template <class Tp>
inline void debug(Tp x) {
#ifdef LOCAL_
  std::cerr << x << std::endl;
#endif
}
template <class Tp, class... Ts>
inline void debug(Tp x, Ts... args) {
#ifdef LOCAL_
  std::cerr << x << ' ';
  debug(args...);
#endif
}
#define debug_line_ (std::cerr << __LINE__ << ' ' << __FUNCTION__ << std::endl)
#define debug_withname_(var) debug(#var, var)

using namespace std;

const int N = 100000 + 7;
bool Cut[N];
//! vertex ID start from 0
template <class Tp>
uint64_t rooted_tree_hash(std::vector<std::vector<Tp>> const &g,
                          size_t now = 0,
                          size_t fa = 0) {
  auto f = [](uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  };
  uint64_t ans = 1;
  for (auto to : g[now])
    if (to != fa && !Cut[to]) ans += f(rooted_tree_hash(g, to, now));
  return ans;
}

#define USE_CIN
#define MULTI_CASES
inline void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  Rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    dec(u), dec(v);
    E[u].push_back(v), E[v].push_back(u);
  }
  if (m == n - 1) {
  YES:
    cout << "YES\n";
    return;
  }
  if (m > n) {
  NO:
    cout << "NO\n";
    return;
  }
  vector<int> Fa(n), DFN(n), cy;
  vector<uint64_t> hash(n);
  int dfn = 0, flag = 0;
  function<void(int, int)> DFS = [&](int u, int fa) {
    Fa[u] = fa, DFN[u] = inc(dfn);
    for (auto v : E[u])
      if (v != fa) {
        if (DFN[v]) {
          Fa[v] = u, flag = 1, cy.push_back(u), Cut[u] = 1;
          return;
        }
        DFS(v, u);
        if (flag) return;
      }
    if (flag) return;
  };
  DFS(0, -1);
  int Now = Fa[cy[0]], cnt = 0;
  while (Now != cy[0]) {
    cy.push_back(Now), Cut[Now] = 1;
    Now = Fa[Now];
  }
  flag = 0;
  Rep(i, 0, cy.size() - 1) {
    hash[i] = rooted_tree_hash(E, cy[i], cy[i]);
    if (cy.size() & 1) {
      if (hash[i] != hash[0]) {
        flag = 1;
        break;
      }
    } else {
      if (hash[i] != hash[i % 2]) {
        flag = 1;
        break;
      }
    }
  }
  for (auto x : cy) Cut[x] = 0;
  if (flag) goto NO;
  else goto YES;
}

signed main() {
#ifdef LOCAL_
  auto CLOCK_ST_ = std::chrono::high_resolution_clock::now();
#endif
#ifdef USE_CIN
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
#endif
  int i_ = 0;
#ifdef MULTI_CASES
  int t_ = 0;
  std::cin >> t_;
  for (i_ = 0; i_ < t_; ++i_)
#endif
    debug("Case", i_), solve(i_);
#ifdef LOCAL_
  auto CLOCK_ED_ = std::chrono::high_resolution_clock::now();
  std::clog << "\n---\nTime used: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(CLOCK_ED_ -
                                                                    CLOCK_ST_)
                   .count() *
                 1e-6l
            << " ms" << std::endl;
#endif
  return 0;
}