int get_sum(int n) {
  int ans = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans += n / l * (r - l + 1);
  }
  return ans;
}
