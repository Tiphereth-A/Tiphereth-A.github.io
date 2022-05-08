void Eratosthenes_sieve(int n) {
    for (int i = 2; i <= n; ++i)
        if (!vis[i]) {
            prime[++cnt] = i;
            for (int j = i * 2; j <= n; j += i) vis[j] = 1;
        }
}
