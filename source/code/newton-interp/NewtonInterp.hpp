template <class T>
class NewtonInterp {
  std::vector<std::pair<T, T>> points;
  std::vector<std::vector<T>> diffs;
  std::vector<T> base;
  std::vector<T> fit;

public:
  explicit NewtonInterp() = default;
  NewtonInterp &insert(T const &x, T const &y) {
    points.emplace_back(x, y);
    size_t n = points.size();
    if (n == 1) {
      base.push_back(1);
    } else {
      size_t m = base.size();
      base.push_back(0);
      for (size_t i = m; i; --i) base[i] = base[i - 1];
      base[0] = 0;
      for (size_t i = 0; i < m; ++i)
        base[i] = base[i] - points[n - 2].first * base[i + 1];
    }
    diffs.emplace_back(points.size());
    diffs[n - 1][n - 1] = y;
    if (n > 1)
      for (size_t i = n - 2; ~i; --i)
        diffs[n - 1][i] = (diffs[n - 2][i] - diffs[n - 1][i + 1]) /
                          (points[i].first - points[n - 1].first);
    fit.push_back(0);
    for (size_t i = 0; i < n; ++i) fit[i] = fit[i] + diffs[n - 1][0] * base[i];
    return *this;
  }
  std::vector<T> coeffs() const { return fit; }
  T evaluate(T const &x) {
    T ans{};
    for (auto it = fit.rbegin(); it != fit.rend(); ++it) ans = ans * x + *it;
    return ans;
  }
};