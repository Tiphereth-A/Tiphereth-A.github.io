#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;
using ldb = long double;

#define for_(i, l, r) for (ll i = (l), i##ed__ = (r); i <= i##ed__; ++i)
#define Rep(i, l, r) for_(i, l, r)

constexpr ldb eps = 1e-6;

struct P {
  ldb x, y;

  explicit P(ldb x = 0, ldb y = 0): x(x), y(y) {}

  bool operator==(const P &r) const {
    return abs(x - r.x) < eps && abs(y - r.y) < eps;
  }
  P operator-(const P &r) const { return P{x - r.x, y - r.y}; }
  P operator*(ldb d) const { return P{x * d, y * d}; }
  ldb dist2() const { return x * x + y * y; }
  ldb dot(const P &r) const { return x * r.x + y * r.y; }
  ldb cross(const P &r) const { return x * r.y - y * r.x; }
  ldb cross(const P &a, const P &b) const {
    return (a - *this).cross(b - *this);
  }
};

ldb segdist2(P const &s, P const &e, P const &p) {
  if (s == e) return (p - s).dist2();
  ldb d = (e - s).dist2(), t = min(d, max(0.l, (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist2() * 1.l / d / d;
}

bool on_seg(P const &s, P const &e, P const &p) {
  return segdist2(s, e, p) < eps;
}

int nxt(int x, int n) { return (++x) == n ? 0 : x; };
bool in_poly(vector<P> const &p, P const &a) {
  int cnt = 0, n = p.size();
  for_(i, 0, n - 1) {
    P const &q = p[nxt(i, n)];
    if (on_seg(p[i], q, a)) return true;
    cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

void solve() {
  int n, q;
  cin >> n >> q;

  vector<P> poly(n);
  for (auto &[x, y] : poly) cin >> x >> y;

  for_(i, 1, q) {
    P p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    P c{(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    ldb r2 = (p1 - p2).dist2() / 4;
    if (in_poly(poly, c)) {
      cout << r2 / 2 << '\n';
      continue;
    }
    ldb d = 1e4514l;
    for_(i, 0, n - 1) d = min(d, segdist2(poly[i], poly[nxt(i, n)], c));
    cout << d + r2 / 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
#ifdef MULCAS
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; ++i)
#endif
    solve();
  return 0;
}