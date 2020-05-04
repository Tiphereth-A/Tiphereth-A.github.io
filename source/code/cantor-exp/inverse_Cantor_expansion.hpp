/*
 * @Author: Tifa
 * @LastEditTime: 2020-11-14 16:15:29
 * @Description: inverse Cantor expansion, O(nlogn)
 */
namespace inverse_Cantor_expansion {
using std::size_t;
const size_t N = 64;

size_t n, p[N];

// based on BIT, need discretization before using
template <const std::size_t N = (std::size_t)1e6 + 5>
class BT {
  std::size_t LOG_N;
  std::size_t tree[N];

  std::size_t lowbit(std::ptrdiff_t x) { return x & (-x); }

  void modify(std::size_t pos, std::size_t val = 1) {
    for (std::size_t i = pos; i < N; i += lowbit(i)) tree[i] += val;
  }
  std::size_t sum(std::size_t pos) {
    std::size_t ret = 0;
    for (std::size_t i = pos; i; i = (std::ptrdiff_t)i - lowbit(i))
      ret += tree[i];
    return ret;
  }
  std::size_t query_rk(std::size_t pos) {
    std::size_t idx = 0;
    for (std::size_t i = LOG_N; ~i; --i) {
      idx += 1 << i;
      if (idx >= N || tree[idx] >= pos) idx -= 1 << i;
      else pos -= tree[idx];
    }
    return idx + 1;
  }

public:
  BT() {
    memset(tree, 0, sizeof(tree));
    LOG_N = ceil(log2(N));
  }
  void clear() { memset(tree, 0, sizeof(tree)); }
  void insert(std::size_t pos) { modify(pos); }
  void remove(std::size_t pos) { modify(pos, -1); }
  std::size_t get_rank(std::size_t num) { return sum(num - 1) + 1; }
  std::size_t kth_num(std::size_t k) { return query_rk(k); }
  std::size_t pre(std::size_t num) { return query_rk(sum(num - 1)); }
  std::size_t suc(std::size_t num) { return query_rk(sum(num) + 1); }
};
BT<N> tr;

size_t frac[N] = {1};
void init(size_t n) {
  tr.clear();
  for (size_t i = 1; i <= n; ++i) frac[i] = i * frac[i - 1];
}

void main(size_t num, size_t a[], size_t n) {
  init(n);
  --num;
  for (size_t i = 1; i <= n; ++i) tr.insert(i);
  for (size_t i = 1; i <= n; ++i) {
    p[i] = num / frac[n - i];
    num %= frac[n - i];
  }
  for (size_t i = 1; i <= n; ++i) tr.remove(a[i] = tr.kth_num(p[i] + 1));
}
}  // namespace inverse_Cantor_expansion
