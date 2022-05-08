inv[1] = 1;
for (int i = 2; i <= n; ++i) inv[i] = (int64_t)(p - p / i)  * inv[p % i] % p;
