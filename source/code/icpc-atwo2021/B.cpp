#include <bits/stdc++.h>
using namespace std;
using u32 = std::uint32_t;
#define for_(i, l, r, vars...) for (decltype(l + r) i = (l), i##end = (r), ##vars; i <= i##end; ++i)
#define read_var_(type, name) \
    type name;                \
    std::cin >> name
const u32 OFFSET = 5;
const u32 N = 1e6 + OFFSET;
int divsum[N];
const auto STATIC__ = []() {
    divsum[1] = 0;
    for_(i, 2, N - OFFSET) {
        for (int j = 1, sqn = sqrt(i); j <= sqn; ++j) {
            if (i % j == 0) {
                divsum[i] += j;
                if (j == i / j) continue;
                if (i % (i / j) == 0) divsum[i] += i / j;
            }
        }
        divsum[i] -= i;
    }
    return 0;
}();
inline auto solve(int t_) -> void {
    read_var_(int, n);
    for_(i, 1, n, x) {
        cin >> x;
        cout << (x == divsum[x] ? "perfect" : x > divsum[x] ? "deficient" :
                                                              "abundant")
             << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve(0);
    return 0;
}
