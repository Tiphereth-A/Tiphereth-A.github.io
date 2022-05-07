void Euler_sieve(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            mu[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}
