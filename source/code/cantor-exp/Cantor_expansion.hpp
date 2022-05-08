/*
 * @Author: Tifa
 * @LastEditTime: 2020-11-14 15:13:13
 * @Description: Cantor expansion, O(nlogn)
 */
namespace Cantor_expansion {
using std::size_t;
const size_t N = 1e6 + 5;
const size_t MOD = ULLONG_MAX;

size_t n, p[N];

template <const std::size_t N = (std::size_t)1e6 + 5, typename T = std::ptrdiff_t>
class BIT {
  private:
    T tree[N];

    std::size_t lowbit(std::ptrdiff_t x) { return x & (-x); }

  public:
    BIT() { memset(tree, 0, sizeof(tree)); }

    void clear() { memset(tree, 0, sizeof(tree)); }

    void modify(std::size_t pos, T val = 1) {
        for (std::size_t i = pos; i < N; i += lowbit(i)) tree[i] += val;
    }
    T query(std::size_t pos) {
        T ret = 0;
        for (std::size_t i = pos; i; i = (std::ptrdiff_t)i - lowbit(i)) ret += tree[i];
        return ret;
    }
};
BIT<N> tr;

size_t frac[N] = {1};
void init(size_t n) {
    tr.clear();
    for (size_t i = 1; i <= n; ++i) frac[i] = i * frac[i - 1] % MOD;
}

size_t main(size_t n, const size_t a[]) {
    init(n);
    size_t ret = 1;
    for (size_t i = n; i; --i) {
        p[i] = tr.query(a[i]);
        tr.modify(a[i]);
    }
    for (size_t i = 1; i <= n; ++i) ret = (ret + p[i] * frac[n - i] % MOD) % MOD;
    return ret;
}
}  // namespace Cantor_expansion
