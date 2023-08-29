
template <class T>
class NewtonInterp {
  // {(x_0,y_0),(x__1,y_1),...,(x_{n-1},y_{n-1})}
  std::vector<std::pair<T, T>> points;
  // diffs[r][l] = f[x_l,x_{l+1},...,x_r]
  std::vector<std::vector<T>> diffs;
  // (x-x_0)(x-x_1)...(x-x_{n-1})
  std::vector<T> base;
  // f[x_0]+f[x_0,x_1](x-x_0)+...+f[x_0,x_1,...,x_n](x-x_0)(x-x_1)...(x-x_{n-1})
  std::vector<T> fit;

public:
  explicit NewtonInterp() = default;

  // Insert a point
  //! x should be DIFFERENT from points have been inserted
  NewtonInterp &insert(T const &x, T const &y);

  // @return fit
  std::vector<T> coeffs() const;

  // @return f(x)
  T evaluate(T const &x);
};