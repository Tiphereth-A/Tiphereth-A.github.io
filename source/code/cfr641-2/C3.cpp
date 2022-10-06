int main() {
  read(n);
  _for(i, 1, n) read(a[i]);
  _repr(i, n, 0) suf[i] = gcd(suf[i + 1], a[i]);
  _for(i, 1, n) ans = gcd(ans, lcm(a[i], suf[i + 1]));
  print(ans);
  return 0;
}
