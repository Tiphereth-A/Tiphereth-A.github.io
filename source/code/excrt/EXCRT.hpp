namespace EXCRT {
using T = int64_t;
T abs(T a) { return a < 0 ? -a : a; }
T mod_mul(T a, T b, T mod) {
  T res = 0;
  for (; b; b >>= 1, (a += a) %= mod)
    if (b & 1) (res += a) %= mod;
  return res;
}
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
T exgcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T res = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return res;
}

bool solve_2equ(T b1, T b2, T m1, T m2, T &x, T &M) {
  ((b1 %= m1) += m1) %= m1;
  ((b2 %= m2) += m2) %= m2;
  T g = gcd(m1, m2), r = b2 - b1;
  M = m1 / g * m2;
  if (abs(r) % g) return false;
  T k1, k2;
  exgcd(m1, m2, k1, k2);
  if (r < 0) k1 = -k1;
  ((k1 %= M) += M) %= M;
  k1 = mod_mul(k1, abs(r) / g, M);
  x = ((mod_mul(k1, m1, M) + b1) % M + M) % M;
  return true;
}

bool excrt(T b[], T m[], const int len, T &res) {
  T pre_b = b[1], pre_m = m[1];
  T now_b, now_m;
  for (int i = 2; i <= len; ++i) {
    now_b = b[i];
    now_m = m[i];
    if (!solve_2equ(pre_b, now_b, pre_m, now_m, pre_b, pre_m)) return false;
  }
  res = pre_b;
  return true;
}
}  // namespace EXCRT
using EXCRT::excrt;
