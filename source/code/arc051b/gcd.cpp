int gcd(int a, int b) {
  if (b == 0) return a;
  counter++;
  return gcd(b, a % b);
}
