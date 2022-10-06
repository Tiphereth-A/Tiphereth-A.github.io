int prime[N], cnt_prime;
int a[N], b[N];
void Dirichlet_sum(int n) {
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  for (int i = 1; i <= cnt_prime; ++i)
    for (int j = 1; j * prime[i] <= n; ++j)
      b[j * prime[i]] += b[j];
}
