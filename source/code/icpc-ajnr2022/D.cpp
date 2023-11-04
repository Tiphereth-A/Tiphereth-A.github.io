#include <bits/stdc++.h>
using ll = long long;
template <class T>
using vc = std::vector<T>;
#define for_(i, l, r, v...) for (ll i = (l), i##e = (r), ##v; i <= i##e; ++i)
template <typename... Ts>
void dec(Ts &...x) {
  ((--x), ...);
}
template <typename... Ts>
void inc(Ts &...x) {
  ((++x), ...);
}
using namespace std;
stringstream ss;
struct Node {
  int m;
  vc<tuple<int, int, int>> t;
  vc<tuple<int, int>> frozen;
  vc<string> state;
  vc<bool> vis, chosen;
  Node(int m): m(m), t(), state(m), vis(m), chosen(m) {}
  void parse() {
    for_(i, 0, m - 1) {
      ss.clear();
      ss << state[i];
      char op;
      ss >> op;
      if (op == '.') continue;
      if (op == '-') {
        int x;
        ss >> x;
        t.emplace_back(i, x, -1);
        continue;
      }
      if (op == '+') {
        int x, y;
        ss >> x;
        ss.get();
        ss >> y;
        t.emplace_back(i, x, y);
        continue;
      }
      int x, y;
      ss >> x >> y;
      t.emplace_back(i, y - x, -1);
      frozen.emplace_back(t.size() - 1, x);
    }
  }
  pair<int, ll> score() {
    int cnt = 0;
    ll tm = 0;
    for (auto [_, x, i] : t)
      if (i >= 0) {
        tm += i + 20 * (x - 1);
        ++cnt;
      }
    return {cnt, tm};
  }
  bool valid(pair<int, ll> const &s) {
    if (frozen.empty()) return score() == s;
    pair target = score();
    if (target > s) return 0;
    int fac = s.first - target.first;
    ll ftm = s.second - target.second;
    for_(i, 0, (1 << frozen.size()) - 1) {
      if (__builtin_popcountll(i) != fac) continue;
      ll minftm = 240 * fac, rftm = 59 * fac, minsp = 0, rsp = 0;
      for (int j = 0; j < frozen.size(); ++j) {
        if (!(i & (1 << j))) continue;
        auto &&[id_t, x] = frozen[j];
        auto &&[id, cnt, tm] = t[id_t];
        minsp += 20 * cnt;
        rsp += 20 * (x - 1);
      }
      if (ftm < minftm + minsp || ftm > minftm + rftm + minsp + rsp) continue;
      for (int j = 0; j < frozen.size(); ++j) {
        if (i & (1 << j)) continue;
        auto &&[id_t, x] = frozen[j];
        auto &[id, cnt, tm] = t[id_t];
        cnt += x;
      }
      for (int j = 0; j < frozen.size(); ++j) {
        if (!(i & (1 << j))) continue;
        auto &[id_t, x] = frozen[j];
        auto &[id, cnt, tm] = t[id_t];
        tm = 240;
        ++cnt;
        --x;
      }
      ftm -= minftm + minsp;
      if (ftm > rftm)
        for (int j = 0; j < frozen.size(); ++j) {
          if (!(i & (1 << j))) continue;
          auto &&[id_t, x] = frozen[j];
          auto &[id, cnt, tm] = t[id_t];
          int _ = min<int>((ftm - rftm) / 20 + (rftm > 20), x);
          cnt += _;
          if ((ftm -= 20 * _) <= rftm) break;
        }
      if (ftm)
        for (int j = 0; j < frozen.size(); ++j) {
          if (!(i & (1 << j))) continue;
          auto &&[id_t, x] = frozen[j];
          auto &[id, cnt, tm] = t[id_t];
          tm += min(59ll, ftm);
          if (!(ftm -= min(59ll, ftm))) break;
        }
      return 1;
    }
    return 0;
  }
  void pnt() {
    for (auto &i : state) i = ".";
    for (auto [id, cnt, tm] : t) {
      string _;
      ss.clear();
      ss << cnt;
      ss >> _;
      if (tm == -1) state[id] = "- " + _;
      else {
        state[id] = "+ " + _ + '/';
        ss.clear();
        ss << tm;
        ss >> _;
        state[id] += _;
      }
    }
  }
};
istream &operator>>(istream &is, Node &p) {
  for (auto &i : p.state)
    while (i.empty()) getline(cin, i);
  return is;
}
ostream &operator<<(ostream &os, Node &p) {
  p.pnt();
  for (auto const &i : p.state) os << i << '\n';
  return os;
}
void solve(int t_ = 0) {
  int n, m;
  cin >> n >> m;
  for_(i, 1, n) {
    pair<int, ll> score;
    cin >> score.first >> score.second;
    Node p(m);
    cin >> p;
    p.parse();
    auto [x, y] = p.score();
    if (!p.valid(score)) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    cout << p;
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cerr << std::fixed << std::setprecision(6);
  int i_ = 0;
  solve(i_);
  return 0;
}
