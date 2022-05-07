const double PHI = 0.61803399, mPHI = 0.38196601;
double gold_search(double l, double r, double EPS) {
  double mid1 = l + mPHI * (r - l), mid2 = l + PHI * (r - l);
  while (r - l > EPS) {
    if (F(mid1) < F(mid2)) {
      l    = mid1;
      mid1 = mid2;
      mid2 = l + PHI * (r - l);
    } else {
      r    = mid2;
      mid2 = mid1;
      mid1 = l + mPHI * (r - l);
    }
  }
  return (mid1 + mid2) / 2;
}
