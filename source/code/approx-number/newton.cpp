double newton(double x0, int n) {
    for(int i=0; i<n; ++i) x0 -= f(x0) / df(x0);
    return x0;
}
