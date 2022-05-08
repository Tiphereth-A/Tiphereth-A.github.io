/*
 * @Author: Tifa
 * @LastEditTime: 2020-10-25 17:31:27
 * @Description: multi_DLX
 */

#include <bits/stdc++.h>
using namespace std;

template <const std::size_t _Edge_len = 500 + 5, const std::size_t _Node_size = 7000 + 5>
class multi_DLX {
  private:
    struct Node {
        std::size_t l, r, u, d;
        std::size_t row, col;
    } node[_Node_size + _Edge_len];
    std::size_t width, height;
    std::size_t cnt_node;

    std::size_t cnt_col[_Edge_len];

#define _l(id) node[id].l
#define _r(id) node[id].r
#define _u(id) node[id].u
#define _d(id) node[id].d
#define _row(id) node[id].row
#define _col(id) node[id].col
#define _for(i, start, dir) for (std::size_t i = _##dir(start); i != start; i = _##dir(i))

    void remove_col(std::size_t _now_col) {
        _for(i, _now_col, d) {
            _r(_l(i)) = _r(i);
            _l(_r(i)) = _l(i);
        }
    }

    void resume_col(std::size_t _now_col) {
        _for(i, _now_col, u) _r(_l(i)) = _l(_r(i)) = i;
    }

    std::size_t find_min_col() {
        std::size_t res = _r(0);
        _for(i, 0, r)
            if (cnt_col[i] < cnt_col[res]) res = i;
        return res;
    }

    bool vis[_Edge_len];
    std::size_t H() {
        std::size_t ret = 0;
        memset(vis, 0, sizeof(vis));
        _for(i, 0, r) {
            if (vis[i]) continue;
            ++ret;
            vis[i] = true;
            _for(j, i, d)
                _for(k, j, r) vis[_col(k)] = true;
        }
        return ret;
    }

    bool dance(std::size_t *_ans, std::size_t &_ans_len, std::size_t max_depth, std::size_t now_depth = 1) {
        if (now_depth > max_depth) return false;
        if (_r(0) == 0) return true;
        std::size_t now_col = find_min_col();
        if (now_depth + H() > max_depth) return false;
        _for(i, now_col, d) {
            remove_col(i);
            _ans[++_ans_len] = _row(i);
            _for(j, i, r) remove_col(j);
            if (dance(_ans, _ans_len, max_depth, now_depth + 1)) {
                _for(j, i, l) resume_col(j);
                resume_col(i);
                return true;
            }
            --_ans_len;
            _for(j, i, l) resume_col(j);
            resume_col(i);
        }
        return false;
    }

  public:
    void clear() {
        memset(node, 0, sizeof(node));
        memset(cnt_col, 0, sizeof(cnt_col));
        width = height = cnt_node = 0;
    }

    void init(std::size_t _width, std::size_t _height) {
        width = cnt_node = _width;
        height = _height;
        for (std::size_t i = 1; i <= width; ++i) node[i] = {i - 1, i + 1, i, i, 0, i};
        node[_r(width) = 0] = {width, 1, 0, 0, 0, 0};
    }

    void insert_row(std::size_t _ln, std::size_t * const _cols, std::size_t _len_cols) {
        for (std::size_t i = 1; i <= _len_cols; ++i) {
            node[cnt_node + i] = {cnt_node + i - 1, cnt_node + i + 1, _u(_cols[i]), _cols[i], _ln, _cols[i]};
            _d(_u(_cols[i])) = cnt_node + i;
            _u(_cols[i]) = cnt_node + i;
            ++cnt_col[_cols[i]];
            if (_d(_cols[i]) == _cols[i]) _d(_cols[i]) = cnt_node + i;
        }
        _l(cnt_node + 1) = cnt_node + _len_cols;
        _r(cnt_node + _len_cols) = cnt_node + 1;
        cnt_node += _len_cols;
    }
    void insert_map(bool ** const _map, std::size_t _width, std::size_t _height, std::size_t _height_phy = _Edge_len) {
        std::size_t *_ = (std::size_t *)malloc(sizeof(std::size_t) * (_width + 1));
        for (std::size_t _ln = 1, len; _ln <= _height; ++_ln) {
            len = 0;
            for (std::size_t _col = 1; _col <= _width; ++_col)
                if (*((bool *)_map + _ln * _height_phy + _col)) _[++len] = _col;
            if (len) insert_row(_ln, _, len);
        }
        free(_);
    }

    std::size_t operator()(std::size_t *ans) {
        std::size_t len = 0, _ = 0;
        std::size_t l = 1, r = height, mid;
        while (l <= r) {
            mid = l + ((std::ptrdiff_t)r - l) / 2;
            _ = 0;
            if (dance(ans, _, mid)) {
                len = _;
                r = _ - 1;
            } else
                l = mid + 1;
        }
        return len;
    }

#undef _l
#undef _r
#undef _u
#undef _d
#undef _row
#undef _col
#undef _for
};
multi_DLX<> a;

const int N = 505;
int n, m;
bool maps[N][N];
std::size_t ans[N];

void test() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> maps[i][j];
    a.init(m, n);
    a.insert_map((bool **)maps, m, n, N);
    size_t len_ans = 0;
    if ((len_ans = a((std::size_t *)ans)) > 0)
        for (size_t i = 1; i <= len_ans; ++i) cout << ans[i] << " ";
    else
        cout << "No Solution!";
    return 0;
}
