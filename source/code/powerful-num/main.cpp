// Usage:
// - set n
// - run dfs(1, 1, 1);
// - the result is ans

// requires:
// - N: Count of prime
// - P: Max exponent
// - prime[]: Primes, started at prime[1] = 2
// - get_sum(n): Return $\sum_{i=1}^n g(i)$, usually use Du's method
// - F(i, now_exp): Return $f(p_i^q)$, which $p_i$ means prime[i] and $q$ means
// now_exp
// - G(i, now_exp): Return $f(p_i^q)$, which $p_i$ means prime[i] and $q$ means
// now_exp
i64 ans, n;
bool vis_h[N][P];
i64 h[N][P];
void dfs(i64 now_x, i64 now_h, i64 idx_prime) {
  ans = (ans + now_h * get_sum(n / now_x) % MOD) % MOD;
  if (idx_prime > 1 && now_x > n / prime[idx_prime] / prime[idx_prime]) return;
  _for(i, idx_prime, cnt_prime) {
    if (i > 1 && now_x > n / prime[i] / prime[i]) break;
    for (i64 now_exp = 1, next_x = now_x * prime[i]; next_x <= n;
         ++now_exp, next_x *= prime[i]) {
      if (!vis_h[i][now_exp]) {
        i64 f = F(i, now_exp), g = G(i, 1);
        _for(j, 1, now_exp) {
          f = ((f - g % MOD * h[i][now_exp - j] % MOD) % MOD + MOD) % MOD;
          //! Changing this depending on the problem recommended
          g = G(i, j + 1);
        }
        h[i][now_exp] = f;
        vis_h[i][now_exp] = 1;
      }
      if (h[i][now_exp]) dfs(next_x, h[i][now_exp] * now_h % MOD, i + 1);
    }
  }
}
