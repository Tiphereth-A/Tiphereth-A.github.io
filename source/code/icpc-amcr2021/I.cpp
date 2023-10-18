#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

vector<vector<u32>> pos(1);
template <u32 SZ = 26>
class ex_suffix_automaton {
  // super root is 0
  struct YYZ {
    u32 len, link;
    std::array<u32, SZ> nex{};
  };

public:
  u32 sz;
  vector<YYZ> st;
  ex_suffix_automaton(): sz(1), st(1) { st[0].len = 0, st[0].link = -1; }
  u32 extend(u32 last, char c) {
    if (st[last].nex[c]) {
      u32 p = last, q = st[p].nex[c];
      if (st[p].len + 1 == st[q].len) return q;
      else {
        u32 clone = sz++;
        st.push_back(YYZ()), pos.push_back(vector<u32>());
        st[clone].len = st[p].len + 1;
        st[clone].link = st[q].link;
        st[clone].nex = st[q].nex;
        while (p != -1u && st[p].nex[c] == q)
          st[p].nex[c] = clone, p = st[p].link;
        st[q].link = clone;
        return clone;
      }
    }
    u32 cur = sz++, p = last;
    st.push_back(YYZ()), pos.push_back(vector<u32>());
    st[cur].len = st[last].len + 1;
    while (p != -1u && !st[p].nex[c]) st[p].nex[c] = cur, p = st[p].link;
    if (p == -1u) st[cur].link = 0;
    else {
      u32 q = st[p].nex[c];
      if (st[p].len + 1 == st[q].len) st[cur].link = q;
      else {
        u32 clone = sz++;
        st.push_back(YYZ()), pos.push_back(vector<u32>());
        st[clone].len = st[p].len + 1;
        st[clone].link = st[q].link;
        st[clone].nex = st[q].nex;
        while (p != -1u && st[p].nex[c] == q)
          st[p].nex[c] = clone, p = st[p].link;
        st[q].link = st[cur].link = clone;
      }
    }
    return cur;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  u32 n;
  cin >> n;
  ex_suffix_automaton sam;
  string s;
  for (u32 i = 0, last = 0; i < n; ++i, last = 0) {
    cin >> s;
    for (auto c : s) last = sam.extend(last, c - 'a'), pos[last].push_back(i);
  }
  vector<vector<u32>> e(sam.sz);
  for (u32 i = 1; i < sam.sz; ++i) e[sam.st[i].link].push_back(i);
  vector<u32> a(sam.sz), root(sam.sz, -1u), fa(n, -1u);
  iota(a.begin(), a.end(), 0);
  sort(a.begin(), a.end(), [&](u32 a, u32 b) {
    return sam.st[a].len > sam.st[b].len;
  });
  u64 ans = 0;
  auto gf = [&](auto &&gf, u32 x) -> u32 {
    return fa[x] == -1u ? x : fa[x] = gf(gf, fa[x]);
  };
  auto merge = [&](u32 x, u32 y) {
    x = gf(gf, x), y = gf(gf, y);
    if (x == y) return 0;
    return fa[x] = y, 1;
  };
  for (u32 i = 0; i < sam.sz - 1; i++) {
    u32 root_ = -1u;
    for (auto v : pos[a[i]])
      if (root_ == -1u) root_ = v;
      else if (merge(root_, v)) ans += sam.st[a[i]].len;
    for (auto x : e[a[i]])
      if (root[x] != -1u) {
        if (root_ == -1u) root_ = root[x];
        else if (merge(root_, root[x])) ans += sam.st[a[i]].len;
      }
    root[a[i]] = root_;
  }
  cout << ans << '\n';
  return 0;
}