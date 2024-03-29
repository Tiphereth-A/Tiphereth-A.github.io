/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-22 22:57:59
 * @Description:
 */

namespace Algo0 {
i64 qpow(i64 a, i64 b) {
  i64 res = 1;
  for (; b; b >>= 1, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

int main() {
  int _t;
  cin >> _t;
  while (_t--) {
    i64 n, k;
    cin >> n >> k;
    i64 ans = 0;
    _for(i, 1ll, n) ans += qpow(i, k);
    cout << ans << '\n';
  }
  return 0;
}
}  // namespace Algo0

namespace Algo1 {
int main() {
  int _t;
  cin >> _t;
  while (_t--) {
    i64 n, k;
    cin >> n >> k;

    if (k == 0) {
      cout << n << endl;
      return;
    }
    if (k == 1) {
      cout << n * (n + 1) / 2 << endl;
      return;
    }
    if (k == 2) {
      cout << n * (n + 1) / 2 * (2 * n + 1) / 3 << endl;
      return;
    }
    if (k == 3) {
      n = n * (n + 1) / 2;
      cout << n * n << endl;
      return;
    }
  }
  return 0;
}
}  // namespace Algo1

namespace Algo2 {
const int OFFSET = 5;
const int N = 5e4 + OFFSET;
const u64 p = 49999;

u64 s[N];

u64 qpow(u64 a, u64 b, const u64 &mod = p) {
  u64 res(1);
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (res *= a) %= mod;
  return res;
}

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    u64 n, k;
    cin >> n >> k;
    k %= p - 1;
    _for(i, 1, p) s[i] = (s[i - 1] + qpow(i, k)) % p;
    cout << (n / p % p * s[p] + s[n % p]) % p << '\n';
  }
  return 0;
}
}  // namespace Algo2

// O(k^2) version
namespace Algo3_k2 {
const int OFFSET = 5;
const int N = 3e3 + OFFSET;
const i64 p = i64(1e18) - 11;

i64 inv[N];
void init_inv(const i64 &n = N - 1) {
  inv[1] = 1;
  _for(i, 2, n) inv[i] = i128(p - p / i) * inv[p % i] % p;
}

i64 comb[N][N];
void init_comb(const i64 &n = N - 1) {
  _for(i, 0, n) comb[i][0] = comb[i][i] = 1;
  _for(i, 2, n)
    _for(j, 1, i - 1) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
}

i64 s[N];

int main() {
  init_inv();
  init_comb();

  int kase;
  cin >> kase;
  while (kase--) {
    i64 n, k;
    cin >> n >> k;

    i128 _(1);
    _for(i, 0, k) s[i] = ((_ *= n + 1) %= p) - 1;

    _for(r, 1, k) {
      _for(t, 0, r - 1) s[r] = (s[r] - i128(comb[r + 1][t]) * s[t] % p + p) % p;
      s[r] = i128(s[r]) * inv[r + 1] % p;
    }
    cout << s[k] << '\n';
  }
  return 0;
}
}  // namespace Algo3_k2

// O(k) version
namespace Algo3_k {
const int OFS = 5;
const int N = 1e6 + OFS;
const i64 MOD = i64(1e18) - 11;

const int P = N / 10 + OFS;
int pri[P], cnt;
bool vis[N];
i64 pow_k[N];

void init_pow_k(int k) {
  pow_k[1] = 1;
  for (int i = 2; i <= k + 2; ++i) {
    if (!vis[i]) pow_k[i] = qpow(pri[++cnt] = i, k, MOD);
    for (int j = 1; j <= cnt && i * pri[j] <= k + 2; ++j) {
      vis[i * pri[j]] = 1;
      pow_k[i * pri[j]] = mul_mod(pow_k[i], pow_k[pri[j]], MOD);
      if (i % pri[j] == 0) break;
    }
  }
  _for(i, 2, k + 2)
    pow_k[i] = (pow_k[i] + pow_k[i - 1] > MOD ? pow_k[i] + pow_k[i - 1] - MOD :
                                                pow_k[i] + pow_k[i - 1]);
}

i64 pre[N], suc[N];
i64 fac[N], inv[N];

void init(const int k = N - OFS) {
  fac[0] = inv[0] = 1;
  _for(i, 1, k + 2) fac[i] = mul_mod(fac[i - 1], i, MOD);
  inv[k + 2] = qpow(fac[k + 2], MOD - 2, MOD);
  _rfor(i, k + 1, 1) inv[i] = mul_mod(inv[i + 1], i + 1, MOD);
}

const auto __STATIC__ = []() {
  init();
  return 0;
}();

void main() {
  int kase;
  cin >> kase;
  while (kase--) {
    i64 n, k;
    cin >> n >> k;
    memset(vis, 0, sizeof(vis[0]) * (k + 2));
    cnt = 0;
    init_pow_k(k);
    if (n <= k + 2) {
      cout << pow_k[n] << '\n';
      continue;
    }
    i64 ans = 0;
    pre[0] = suc[0] = suc[k + 3] = 1;
    _for(i, 1, k + 2) pre[i] = mul_mod(pre[i - 1], n - i, MOD);
    _rfor(i, k + 2, 1) suc[i] = mul_mod(suc[i + 1], n - i, MOD);
    _for(i, 1, k + 2) {
      i64 a = mul_mod(pre[i - 1], suc[i + 1], MOD);
      i64 b = mul_mod(
        inv[i - 1], (k - i) % 2 ? (MOD - inv[k + 2 - i]) : inv[k + 2 - i], MOD);
      ans = (ans + mul_mod(mul_mod(pow_k[i], a, MOD), b, MOD)) % MOD;
    }
    cout << ans << '\n';
  }
}
}  // namespace Algo3_k

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  return Algo3_k::main();
}
