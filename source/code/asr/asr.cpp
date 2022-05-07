double F(double num) {
    //按需补充
}
double simpson(double a, double b) {
    double mid = (a + b) / 2;
    return (F(a) + 4 * F(mid) + F(b)) * (b - a) / 6;
}
double asr(double a, double b, double eps, double S) {
    double mid = (a + b) / 2;
    double S_l = simpson(a, mid), S_r = simpson(mid, b);
    if (abs(S_l + S_r - S) <= 15 * eps) return S_l + S_r + (S_l + S_r - S) / 15;
    return asr(a, mid, eps / 2, S_l) + asr(mid, b, eps / 2, S_r);  //注意eps要减半
}