s[0] = inv[1] = 1;
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
for (int i = n, v = qpow(s[n], p - 2); i > 1; v = v * a[i--] % p)
  inv[i] = v * s[i - 1] % p;
