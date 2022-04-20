---
title: 模板 - 矩阵
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 数学
  - 矩阵
  - Gauss消去法
date: 2021-10-31 21:28:15
---

基于 C++14 标准, 实现了矩阵的四则运算, 求逆, 转置, 秩, 行列式与对输入输出流的支持

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

## 使用说明

- 元素类型 `Tp` 须有接受 1 个整数的构造函数, 否则需手动偏特化 `Matrix::Matrix_helper::Zero` (零元) 与 `Matrix::Matrix_helper::One` (幺元)
- Gauss-Jordan 消元法有普通版与辗转相除版, 其中普通版推荐用于浮点数, 辗转相除版推荐用于 $\Z_m$, `gauss(a)` 与 `gauss_half(a)` 默认执行普通版, 若需执行辗转相除版需手动偏特化 `namespace Matrix::Matrix_helper::gauss_tag`, 示例见代码末尾的注释
  
  > 当然嫌麻烦也可以直接把 `protected` 里面的那四个函数暴露出来用, 记得同时修改 `det()`, `trans()`, `rank()`, `gauss()`, `gauss_half()`

## 成员函数&友元函数简介

### 符号说明

- `self`: 类自身的类型
- `data_t`: 元素类型
- `i`, `j`: 正整数
- `s`: 元素
- `a`, `b`: 类型为 `self` 的类
- `un`: 一元函数
- `bin`: 二元函数

### 简介

| 成员函数/友元函数                                            | 返回类型             | 功能                                                                                                                                   | 调用后是否改变当前类 |
| ------------------------------------------------------------ | -------------------- | -------------------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| `self(i, j, equ)`                                            | -                    | 构造 `i` 行 `j` 列的矩阵, 以 `equ` 作为元素的 `operator==`, `i` 或 `j` 为 `0` 时抛出 `std::logic_error` 异常                           | -                    |
| `self(i, j, s, equ)`                                         | -                    | 构造 `i` 行 `j` 列的矩阵, 以 `equ` 作为元素的 `operator==`, 并将所有元素初始化为 `s`, `i` 或 `j` 为 `0` 时抛出 `std::logic_error` 异常 | -                    |
| `a.data(i, j)` / `a.data(i, j) const`                        | `data_t&`            | 返回 `a(i, j)`                                                                                                                         | 否                   |
| `a.clear()`                                                  | `self&`              | 清空并返回 `a`                                                                                                                         | 是                   |
| `a.get_row() const`                                          | `const std::size_t&` | 返回 `a` 的行数                                                                                                                        | 否                   |
| `a.get_col() const`                                          | `const std::size_t&` | 返回 `a` 的列数                                                                                                                        | 否                   |
| `a.transform_unary(un)`                                      | `self&`              | 将 `a` 中的所有元素 `a(i, j)` 改为 `un(a(i, j))`                                                                                       | 是                   |
| `a.transform_binary(b, bin)`                                 | `self&`              | 将 `a` 中的所有元素 `a(i, j)` 改为 `bin(a(i, j), b(i, j))`                                                                             | 是                   |
| `calc_unary(a, un)`                                          | `self`               | 返回 `un(a)`                                                                                                                           | -                    |
| `calc_binary(a, b, bin)`                                     | `self`               | 返回 `bin(a, b)`                                                                                                                       | -                    |
| `gauss(a)`                                                   | `std::ptrdiff_t`     | 对 `a` 应用 Gauss-Jordan 消元法, 将 `a` 化为准对角矩阵, 返回 $\operatorname{rk}(a)\cdot\operatorname{sgn}\det(a)$                                             | 是                   |
| `gauss_half(a)`                                                   | `std::ptrdiff_t`     | 对 `a` 应用 Gauss-Jordan 消元法, 将 `a` 化为准上三角矩阵, 返回 $\operatorname{rk}(a)\cdot\operatorname{sgn}\det(a)$                                             | 是                   |
| `a.trans()`                                                  | `self`               | 返回 `a` 的转置矩阵                                                                                                                    | 否                   |
| `a.rank() const`                                             | `std::size_t`        | 返回 `a` 的秩                                                                                                                          | 否                   |
| `a.det() const`                                              | `data_t`             | 返回 `a` 的行列式值, 不存在时抛出 `std::runtime_error` 异常                                                                            | 否                   |
| `a.inverse() const`                                          | `self`               | 返回 `a` 的逆矩阵, 不存在时抛出 `std::runtime_error` 异常                                                                              | 否                   |
| `a.add(b)`, `a.minus(b)`, `a.multiply(b)`, `a.divide(b)`     | `self&`              | 逐元素四则运算                                                                                                                         | 是                   |
| `a.add(s)`, `a.minus(s)`, `a.multiply(s)`, `a.divide(s)`     | `self&`              | 逐元素四则运算                                                                                                                         | 是                   |
| `add(a, b)`, `minus(a, b)`, `multiply(a, b)`, `divide(a, b)` | `self&`              | 逐元素四则运算                                                                                                                         | -                    |
| `add(a, s)`, `minus(a, s)`, `multiply(a, s)`, `divide(a, s)` | `self&`              | 逐元素四则运算                                                                                                                         | -                    |

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
namespace Matrix {

#define _TRAITS(expression, __...) std::enable_if_t<expression, ##__>* = nullptr

#define _CONVERTIBLE(Tp, Up) std::is_convertible<Tp, Up>::value

namespace Matrix_helper {
struct normal_tag {};
struct euclid_tag {};

template <typename>
struct gauss_tag { using type = normal_tag; };

template <>
struct gauss_tag<euclid_tag> { using type = euclid_tag; };

template <typename Tp>
struct Zero final { static constexpr Tp value = 0; };

template <typename Tp>
struct One final { static constexpr Tp value = 1; };
}  // namespace Matrix_helper
using namespace Matrix_helper;

template <class Tp, class Equal = std::equal_to<Tp>>
class matrix {

#define _for(i, begin, end, vals...) for (std::size_t i = (begin), ##vals; i < (end); ++i)

#define _for_row(i, vals...) _for(i, 0, this->get_row(), ##vals)

#define _for_col(i, vals...) _for(i, 0, this->get_col(), ##vals)

#define _for_each(i, j) _for_row(i) _for_col(j)

#define _square_matrix_needed \
    if (this->get_row() != this->get_col()) throw std::runtime_error("The matrix is not square matrix")

  public:
    using self = matrix<Tp, Equal>;
    using data_t = Tp;

  protected:
    inline constexpr friend std::ptrdiff_t _gauss(self& now) {
        std::size_t rk = 0;
        bool neg = false;
        _for(i, 0, std::min(now.get_row(), now.get_col()), now_row = 0) {
            now_row = rk;
            _for(j, now_row + 1, now.get_row()) if (std::abs(now.data(j, i)) > std::abs(now.data(now_row, i))) now_row = j;
            if (now.equ(now.data(now_row, i), now.get_zero())) continue;
            if (now_row != rk) {
                std::swap(now.mat[now_row], now.mat[rk]);
                neg ^= true;
            }
            _for(j, 0, now.get_row()) {
                if (j == rk) continue;
                data_t _ = now.data(j, i) / now.data(rk, i);
                now.data(j, i) = now.get_zero();
                _for(k, i + 1, now.get_col()) now.data(j, k) -= now.data(rk, k) * _;
            }
            ++rk;
        }
        return static_cast<std::ptrdiff_t>(neg ? -rk : rk);
    }

    inline constexpr friend std::ptrdiff_t _gauss_half(self& now) {
        std::size_t rk = 0;
        bool neg = false;
        _for(i, 0, std::min(now.get_row(), now.get_col()), now_row = 0) {
            now_row = rk;
            _for(j, now_row + 1, now.get_row()) if (std::abs(now.data(j, i)) > std::abs(now.data(now_row, i))) now_row = j;
            if (now.equ(now.data(now_row, i), now.get_zero())) continue;
            if (now_row != rk) {
                std::swap(now.mat[now_row], now.mat[rk]);
                neg ^= true;
            }
            _for(j, rk + 1, now.get_row()) {
                data_t _ = now.data(j, i) / now.data(rk, i);
                now.data(j, i) = now.get_zero();
                _for(k, i + 1, now.get_col()) now.data(j, k) -= now.data(rk, k) * _;
            }
            ++rk;
        }
        return static_cast<std::ptrdiff_t>(neg ? -rk : rk);
    }

    inline constexpr friend std::ptrdiff_t _gauss_euclid(self& now) {
        std::size_t rk = 0;
        bool neg = false;
        _for(i, 0, std::min(now.get_row(), now.get_col()), now_row = 0) {
            now_row = rk;
            _for(j, now_row + 1, now.get_row()) if (std::abs(now.data(j, i)) > std::abs(now.data(now_row, i))) now_row = j;
            if (now.equ(now.data(now_row, i), now.get_zero())) continue;
            if (now_row != rk) {
                std::swap(now.mat[now_row], now.mat[rk]);
                neg ^= true;
            }
            _for(j, 0, now.get_row()) {
                if (now.data(j, i) > now.data(i, i)) {
                    std::swap(now.mat[j], now.mat[i]);
                    neg ^= true;
                }
                while (!now.equ(now.data(i, i), now.get_zero())) {
                    std::ptrdiff_t _ = now.data(j, i) / now.data(i, i);
                    _for(k, i, now.get_row()) now.data(j, k) -= now.data(i, k) * data_t(_);
                    std::swap(now.mat[j], now.mat[i]);
                    neg ^= true;
                }
            }
            ++rk;
        }
        return static_cast<std::ptrdiff_t>(neg ? -rk : rk);
    }

    inline constexpr friend std::ptrdiff_t _gauss_half_euclid(self& now) {
        std::size_t rk = 0;
        bool neg = false;
        _for(i, 0, std::min(now.get_row(), now.get_col()), now_row = 0) {
            now_row = rk;
            _for(j, now_row + 1, now.get_row()) if (std::abs(now.data(j, i)) > std::abs(now.data(now_row, i))) now_row = j;
            if (now.equ(now.data(now_row, i), now.get_zero())) continue;
            if (now_row != rk) {
                std::swap(now.mat[now_row], now.mat[rk]);
                neg ^= true;
            }
            _for(j, rk + 1, now.get_row()) {
                if (now.data(j, i) > now.data(i, i)) {
                    std::swap(now.mat[j], now.mat[i]);
                    neg ^= true;
                }
                while (!now.equ(now.data(i, i), now.get_zero())) {
                    std::ptrdiff_t _ = now.data(j, i) / now.data(i, i);
                    _for(k, i, now.get_row()) now.data(j, k) -= now.data(i, k) * data_t(_);
                    std::swap(now.mat[j], now.mat[i]);
                    neg ^= true;
                }
            }
            ++rk;
        }
        return static_cast<std::ptrdiff_t>(neg ? -rk : rk);
    }

  public:
    matrix(const std::size_t& _row, const std::size_t& _col, const Equal& _equal = Equal()) : row(_row), col(_col), mat(_row, std::vector<data_t>(_col)), equ(_equal) {
        if (_row == 0 || _col == 0) throw std::logic_error("invalid parameters");
    }

    template <typename Up, _TRAITS(_CONVERTIBLE(Up, data_t))>
    matrix(const std::size_t& _row, const std::size_t& _col, Up&& scalar, const Equal& _equal = Equal()) : row(_row), col(_col), mat(_row, std::vector<data_t>(_col, scalar)), equ(_equal) {
        if (_row == 0 || _col == 0) throw std::logic_error("invalid parameters");
    }

    template <typename Up, _TRAITS(_CONVERTIBLE(Up, self&))>
    matrix(Up&& rhs) : row(std::forward<self>(rhs).get_row()), col(std::forward<self>(rhs).get_col()), mat(row), equ(std::forward<self>(rhs).equ) { _for_row(i) this->mat[i] = std::forward<self>(rhs).mat[i]; }

    template <typename Up, _TRAITS(_CONVERTIBLE(Up, self))>
    self& operator=(Up&& rhs) {
        _for_row(i) this->mat[i] = std::forward<self>(rhs).mat[i];
        return *this;
    }

    inline constexpr self& clear() {
        _for_each(i, j) this->data(i, j) = 0;
        return *this;
    }

    inline constexpr const std::size_t& get_row() const { return this->row; }
    inline constexpr const std::size_t& get_col() const { return this->col; }
    inline constexpr const data_t& get_zero() const { return this->zero; }
    inline constexpr const data_t& get_one() const { return this->one; }

    inline constexpr data_t& data(const size_t& r, const size_t& c) const { return const_cast<self* const>(this)->mat[r][c]; }
    inline constexpr data_t& data(const size_t& r, const size_t& c) { return this->mat[r][c]; }
    data_t& operator()(const std::size_t& r, const std::size_t& c) { return this->data(r, c); }

    template <typename Unary>
    inline constexpr self& transform_unary(Unary&& op) {
        _for_each(i, j) this->data(i, j) = op(this->data(i, j));
        return *this;
    }
    template <typename Unary>
    friend inline constexpr self calc_unary(const self& lhs, Unary&& op) { return self(lhs).transform_unary(op); }

    template <typename Binary>
    inline constexpr self& transform_binary(const self& rhs, Binary&& op) {
        _for_each(i, j) this->data(i, j) = op(this->data(i, j), rhs.data(i, j));
        return *this;
    }
    template <typename Binary>
    friend inline constexpr self calc_binary(const self& lhs, const self& rhs, Binary&& op) { return self(lhs).transform_binary(rhs, op); }

    inline constexpr friend std::ptrdiff_t gauss(self& now, normal_tag) { return _gauss(now); }
    inline constexpr friend std::ptrdiff_t gauss(self& now, euclid_tag) { return _gauss_euclid(now); }

    inline constexpr friend std::ptrdiff_t gauss_half(self& now, normal_tag) { return _gauss_half(now); }
    inline constexpr friend std::ptrdiff_t gauss_half(self& now, euclid_tag) { return _gauss_half_euclid(now); }

    inline constexpr self trans() {
        self ret(this->get_col(), this->get_row(), this->equ);
        _for_each(i, j) ret.data(j, i) = this->data(i, j);
        return ret;
    }

    inline constexpr std::size_t rank() const {
        self _ = self(*this);
        return std::abs(gauss_half(_, typename gauss_tag<data_t>::type()));
    }

    inline constexpr data_t det() const {
        _square_matrix_needed;

        self _ = self(*this);
        std::ptrdiff_t rk = gauss_half(_, typename gauss_tag<data_t>::type());
        if (static_cast<std::size_t>(std::abs(rk)) != this->get_row()) return this->get_zero();

        data_t ans(rk > 0 ? this->get_one() : -(this->get_one()));
        _for_row(i) ans *= this->data(i, i);
        return ans;
    }

    inline constexpr self inverse() const {
        _square_matrix_needed;

        self _(this->get_row(), this->get_row() * 2, this->equ);
        _for_each(i, j) _.data(i, j) = this->data(i, j);
        _for_each(i, j) _.data(i, j + this->get_row()) = (i == j ? 1 : 0);

        std::size_t rk = std::abs(gauss(_, typename gauss_tag<data_t>::type()));
        if (rk != this->get_row()) throw std::runtime_error("inverse not exist");

        _for_row(i) {
            const data_t& now = _.data(i, i);
            _for_col(j) _.data(i, j + this->get_row()) /= now;
        }

        self ret(this->get_row(), this->get_col(), this->equ);
        _for_each(i, j) ret.data(i, j) = _.data(i, j + this->get_row());
        return ret;
    }

    inline constexpr self& add(const self& rhs) { return this->transform_binary(rhs, std::plus<data_t>()); }
    inline constexpr self& minus(const self& rhs) { return this->transform_binary(rhs, std::minus<data_t>()); }
    inline constexpr self& multiply(const self& rhs) { return this->transform_binary(rhs, std::multiplies<data_t>()); }
    inline constexpr self& divide(const self& rhs) { return this->transform_binary(rhs, std::divides<data_t>()); }
    inline constexpr self& add(const data_t& scalar) {
        return this->transform_unary([&](const data_t& x) { return std::plus<data_t>()(x, scalar); });
    }
    inline constexpr self& minus(const data_t& scalar) {
        return this->transform_unary([&](const data_t& x) { return std::minus<data_t>()(x, scalar); });
    }
    inline constexpr self& multiply(const data_t& scalar) {
        return this->transform_unary([&](const data_t& x) { return std::multiplies<data_t>()(x, scalar); });
    }
    inline constexpr self& divide(const data_t& scalar) {
        return this->transform_unary([&](const data_t& x) { return std::divides<data_t>()(x, scalar); });
    }

    friend inline constexpr self& add(const self& lhs, const self& rhs) { return self(lhs).add(rhs); }
    friend inline constexpr self& minus(const self& lhs, const self& rhs) { return self(lhs).minus(rhs); }
    friend inline constexpr self& multiply(const self& lhs, const self& rhs) { return self(lhs).multiply(rhs); }
    friend inline constexpr self& divide(const self& lhs, const self& rhs) { return self(lhs).divide(rhs); }
    friend inline constexpr self& add(const self& lhs, const data_t& scalar) { return self(lhs).add(scalar); }
    friend inline constexpr self& minus(const self& lhs, const data_t& scalar) { return self(lhs).minus(scalar); }
    friend inline constexpr self& multiply(const self& lhs, const data_t& scalar) { return self(lhs).multiply(scalar); }
    friend inline constexpr self& divide(const self& lhs, const data_t& scalar) { return self(lhs).divide(scalar); }

    self operator*(const self& rhs) {
        if (this->get_col() != rhs.get_row()) throw std::logic_error("you can not multiple (" + std::to_string(this->get_row()) + "x" + std::to_string(this->get_col()) + ") matrix and (" + std::to_string(rhs.get_row()) + "x" + std::to_string(rhs.get_col()) + ") matrix");

        self ret(this->get_row(), rhs.get_col(), 0, this->equ);
        _for_row(i) _for_col(k) _for(j, 0, rhs.get_col()) ret.data(i, j) += this->data(i, k) * rhs.data(k, j);
        return ret;
    }

    self operator+() { return *this; }
    self operator-() { return self(*this).multiply(-1); }

    self& operator+=(const self& rhs) { return this->add(rhs); }
    self& operator-=(const self& rhs) { return this->minus(rhs); }
    self& operator*=(const self& rhs) { return *this = *this * rhs; }
    self& operator/=(const self& rhs) { return *this *= rhs.inverse(); }

    self operator+(const self& rhs) { return self(*this) += rhs; }
    self operator-(const self& rhs) { return self(*this) -= rhs; }
    self operator/(const self& rhs) { return self(*this) /= rhs; }

    bool operator==(const self& rhs) const {
        _for_each(i, j) if (!this->equ(this->data(i, j), rhs.data(i, j))) return false;
        return true;
    }
    bool operator!=(const self& rhs) const { return !(*this == rhs); }

    friend std::istream& operator>>(std::istream& is, self& x) {
        _for(i, 0, x.get_row()) _for(j, 0, x.get_col()) is >> x.data(i, j);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const self& x) {
        _for(i, 0, x.get_row()) _for(j, 0, x.get_col()) {
            os << x.data(i, j);
            if (i + 1 < x.get_row() || j + 1 < x.get_col()) os << (j + 1 == x.get_col() ? '\n' : ' ');
        }
        return os;
    }

  protected:
    const std::size_t row, col;
    std::vector<std::vector<Tp>> mat;
    Equal equ;
    static constexpr data_t zero = Zero<data_t>::value, one = One<data_t>::value;

#undef _for

#undef _for_row

#undef _for_col

#undef _for_each

#undef _square_matrix_needed
};

#undef _TRAITS

#undef _CONVERTIBLE
}  // namespace Matrix
using Matrix::matrix;

// example
// template <> struct Matrix::Matrix_helper::gauss_tag<int64_t> { using type = Matrix::Matrix_helper::euclid_tag; };
```

</details>

## 示例

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp

#include <bits/stdc++.h>

namespace Matrix {
  // ...
}  // namespace Matrix
using Matrix::matrix;

using namespace std;

// template <> struct Matrix::Matrix_helper::gauss_tag<int> { using type = Matrix::Matrix_helper::normal_tag; };

auto _ = [](const double& x, const double& y) { return std::abs(x - y) <= 1e-8; };

int main() {
    int n;
    cin >> n;
    Matrix::matrix<double, decltype(_)> a(n, n, _);
    cin >> a;
    cout << a << endl
         << a.trans() << endl
         << a.inverse() << endl
         << a.trans().inverse() << endl
         << a.rank() << endl
         << a.det() << endl;
    decltype(a) b(a);
    decltype(a) c(a.inverse());
    decltype(a) d(a.trans());
    cout << -a - +c * d + a / c << endl
         << a - b << endl
         << a * b << endl
         << a / b << endl;
    return 0;
}
```

</details>
