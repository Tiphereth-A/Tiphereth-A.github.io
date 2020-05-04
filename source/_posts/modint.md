---
title: 模板 - 自动取模的整数类 (mod_int)
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 数学
date: 2021-10-26 22:44:15
---

即 $\Z_m$

基于 C++14 标准, 实现了四则运算, 逆元与对输入输出流的支持

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

## 成员函数&友元函数简介

### 符号说明

- `self`: 类自身的类型
- `data_t`: 存储整数的类型
- `mod_t`: 模的类型
- `a`, `b`: 类型为 `self` 的类
- `un`: 一元函数
- `bin`: 二元函数

### 简介

| 成员函数/友元函数                | 返回类型  | 功能                                                                            | 调用后是否改变当前类 |
| -------------------------------- | --------- | ------------------------------------------------------------------------------- | -------------------- |
| `a.data()` / `a.data() const`    | `data_t&` | 返回存储的整数                                                                  | 否                   |
| `a.get_mod() const`              | `mod_t`   | 返回模数                                                                        | 否                   |
| `a.no_check_mod()`               | `self&`   | 对 `a.data()` 取模, 不检查正负                                                  | 是                   |
| `a.safe_mod()`                   | `self&`   | 对 `a.data()` 取模, 检查正负                                                    | 是                   |
| `a.transform_unary(un)`          | `self&`   | 将 `a.data()` 改为 `un(a.data())`, 对结果取模                                   | 是                   |
| `a.transform_unary_raw(un)`      | `self&`   | 将 `a.data()` 改为 `un(a.data())`, 不对结果取模                                 | 是                   |
| `a.transform_binary(b, bin)`     | `self&`   | 将 `a.data()` 改为 `bin(a.data(), b.data())`, 对结果取模                        | 是                   |
| `a.transform_binary_raw(b, bin)` | `self&`   | 将 `a.data()` 改为 `bin(a.data(), b.data())`, 不对结果取模                      | 是                   |
| `calc_unary(a, un)`              | `self`    | 返回存储 `un(a.data())` 的类, 对结果取模                                        | -                    |
| `calc_unary_raw(a, un)`          | `self`    | 返回存储 `un(a.data())` 的类, 不对结果取模                                      | -                    |
| `calc_binary(a, b, bin)`         | `self`    | 返回存储 `bin(a.data(), b.data())` 的类, 对结果取模                             | -                    |
| `calc_binary_raw(a, b, bin)`     | `self`    | 返回存储 `bin(a.data(), b.data())` 的类, 不对结果取模                           | -                    |
| `a.inverse() const`              | `self`    | 返回 `a.data()` 模 `a.get_mod()` 的逆元, 不存在时抛出 `std::runtime_error` 异常 | 否                   |

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
namespace ModInteger {

#define _TRAITS(expression, __...) std::enable_if_t<expression, ##__>* = nullptr

template <typename Tp>
class mod_integer {
  public:
    using self = mod_integer<Tp>;
    using data_t = Tp;
    using mod_t = Tp;
    using common_t = std::common_type_t<data_t, mod_t>;
    using signed_common_t = std::make_signed_t<common_t>;
    using unsigned_common_t = std::make_unsigned_t<common_t>;

  protected:
    data_t num;
    mod_t mod;

  private:
    inline constexpr common_t gcd(common_t m, common_t n) const {
        while (n != 0) {
            common_t t = m % n;
            m = n;
            n = t;
        }
        return m;
    }

  public:
    mod_integer(const data_t& _num, const mod_t& _mod) noexcept : num(_num), mod(_mod) { this->safe_mod(); }

    template <typename Up, _TRAITS(std::is_convertible<Up, self&>::value)>
    mod_integer(Up&& rhs) noexcept : num(std::forward<self>(rhs).data()), mod(std::forward<self>(rhs).get_mod()) {}

    inline self& operator=(const data_t& num) noexcept {
        this->data() = num;
        return *this;
    }

    template <typename Up, _TRAITS(std::is_convertible<Up, self&>::value)>
    inline self& operator=(Up&& rhs) noexcept {
        this->data() = std::forward<self>(rhs).data();
        this->mod = std::forward<self>(rhs).get_mod();
        return *this;
    }

    operator data_t() { return this->data(); }

    inline constexpr self& no_check_mod() {
        this->num %= this->get_mod();
        return *this;
    }
    inline constexpr self& safe_mod() {
        if (this->no_check_mod().data() < 0) this->num += this->get_mod();
        return *this;
    }

    inline constexpr data_t& data() noexcept { return this->num; }
    inline constexpr data_t& data() const noexcept { return const_cast<self* const>(this)->num; }

    inline constexpr mod_t get_mod() const noexcept { return mod; }

    template <typename Unary>
    inline constexpr self& transform_unary_raw(Unary&& op) {
        this->data() = op(this->data());
        return *this;
    }
    template <typename Unary>
    inline constexpr self& transform_unary(Unary&& op) { return this->transform_unary_raw(std::move(op)).safe_mod(); }
    template <typename Binary>
    inline constexpr self& transform_binary_raw(const self& rhs, Binary&& op) {
        this->data() = op(this->data(), rhs.data());
        return *this;
    }
    template <typename Binary>
    inline constexpr self& transform_binary(const self& rhs, Binary&& op) { return this->transform_binary_raw(rhs, std::move(op)).safe_mod(); }

    template <typename Unary>
    friend inline constexpr self calc_unary_raw(const self& lhs, Unary&& op) { return self(lhs).transform_unary_raw(op); }
    template <typename Unary>
    friend inline constexpr self calc_unary(const self& lhs, Unary&& op) { return calc_unary_raw(lhs, std::move(op)).safe_mod(); }

    template <typename Binary>
    friend inline constexpr self calc_binary_raw(const self& lhs, const self& rhs, Binary&& op) { return self(lhs).transform_binary_raw(rhs, op); }
    template <typename Binary>
    friend inline constexpr self calc_binary(const self& lhs, const self& rhs, Binary&& op) { return calc_binary_raw(lhs, rhs, std::move(op)).safe_mod(); }

    inline constexpr self inverse() const {
        if (this->gcd(this->data(), this->get_mod()) != 1) throw std::runtime_error("inverse not exist");

        signed_common_t a = this->data(), b = this->get_mod();
        signed_common_t m0 = 0;

        for (signed_common_t q, _, m1 = 1; a;) {
            q = b / a;
            b -= a * q;
            m0 -= m1 * q;

            _ = b;
            b = a;
            a = _;
            _ = m0;
            m0 = m1;
            m1 = _;
        }

        return self(m0 + (m0 < 0 ? this->get_mod() / b : 0), this->get_mod());
    };

    self& operator++() {
        this->data()++;
        if (this->data() == this->get_mod()) this->data() = 0;
        return *this;
    }
    self& operator--() {
        if (this->data() == 0) this->data() = this->get_mod();
        this->data()--;
        return *this;
    }
    self operator++(int) {
        self ret = *this;
        ++*this;
        return ret;
    }
    self operator--(int) {
        self ret = *this;
        --*this;
        return ret;
    }

    self operator+() { return *this; }
    self operator-() { return self(this->get_mod() - this->data(), this->get_mod()); }

    self& operator+=(const self& rhs) { return this->transform_binary(rhs, std::plus<data_t>()); }
    self& operator-=(const self& rhs) { return this->transform_binary(rhs, std::minus<data_t>()); }
    self& operator*=(const self& rhs) { return this->transform_binary(rhs, std::multiplies<data_t>()); }
    self& operator/=(const self& rhs) { return this->transform_binary(rhs.inverse(), std::multiplies<data_t>()); }

    friend self operator+(const self& lhs, const self& rhs) { return self(lhs) += rhs; }
    friend self operator-(const self& lhs, const self& rhs) { return self(lhs) -= rhs; }
    friend self operator*(const self& lhs, const self& rhs) { return self(lhs) *= rhs; }
    friend self operator/(const self& lhs, const self& rhs) { return self(lhs) /= rhs; }

    friend bool operator==(const self& lhs, const self& rhs) { return lhs.data() == rhs.data(); }
    friend bool operator!=(const self& lhs, const self& rhs) { return lhs.data() != rhs.data(); }
    friend bool operator<(const self& lhs, const self& rhs) { return lhs.data() < rhs.data(); }
    friend bool operator>(const self& lhs, const self& rhs) { return lhs.data() > rhs.data(); }
    friend bool operator<=(const self& lhs, const self& rhs) { return lhs.data() <= rhs.data(); }
    friend bool operator>=(const self& lhs, const self& rhs) { return lhs.data() >= rhs.data(); }

    friend std::istream& operator>>(std::istream& is, self& x) {
        is >> x.data();
        x.safe_mod();
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const self& x) {
        os << x.data();
        return os;
    }
};

#undef _TRAITS
}  // namespace ModInteger
using ModInteger::mod_integer;
```

</details>

## 示例

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp

#include<bits/stdc++.h>

namespace ModInteger {
// ...
}
using ModInteger::mod_integer;

using std::cin;
using std::cout;
using std::endl;

int main() {
    mod_integer<int64_t> a(998244353);

    cin >> a;
    cout << a << endl;
    a = a.inverse();
    cout << +a << endl
         << -a << endl;

    decltype(a) b(a), c = a;

    c = b.transform_unary_raw([](const int64_t& x) { return x + 3; }).transform_binary_raw(a, std::multiplies<int64_t>()).safe_mod().inverse();

    cout << c << endl;

    c.data() += 2;

    cout << c << endl;

    cout << a + b << endl
         << a - b << ' ' << b - a << endl
         << a * b << endl
         << a / b << endl;

    cout << (a += b) << endl
         << (a -= b) << endl
         << (a *= b) << endl
         << (a /= b) << endl;

    cout << std::boolalpha << (a == b) << endl
         << (a != b) << endl
         << (a < b) << endl
         << (a > b) << endl
         << (a <= b) << endl
         << (a >= b) << endl;
    return 0;
}
```

</details>
