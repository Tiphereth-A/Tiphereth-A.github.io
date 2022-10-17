double binary_search(double l, double r, double EPS) {
  double mid;
  while (r - l > EPS) {
    mid = l + (r - l) / 2;  // 防溢出
    if (F(mid) * F(l) <= 0) r = mid;
    else l = mid;
  }
  return mid;
}
