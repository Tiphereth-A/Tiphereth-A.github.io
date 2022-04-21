---
title: 模板 - 光速幂
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - 数学
  - 光速幂
date: 2021-10-24 20:34:44
---

光速幂是一种针对固定底数和模数的高速求幂算法, 其基本思路和 BSGS 相同

<!-- more -->

基本思路和 BSGS 相同, 就是分成两块 $y=a\lfloor\sqrt p\rfloor+b$ 然后就有
$$x^y=\left(x^{\lfloor\sqrt p\rfloor}\right)^a+x^b$$

当然也可以分成长度为 256 的四个块来卡 cache

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
template <typename Tp = int64_t>
class rpow final {
  private:
    uint32_t mod;
    Tp base;
    std::array<Tp, 65536> block1, block2;

  public:
    rpow(const Tp& _base, const uint32_t& _mod) : base(_base), mod(_mod) {
        block1[0] = block2[0] = 1;
        for (uint32_t i = 1; i < 65536; i++) block1[i] = block1[i - 1] * base % mod;
        Tp _(block1.back() * base % mod);
        for (uint32_t i = 1; i < 65536; i++) block2[i] = block2[i - 1] * _ % mod;
    }

    Tp&& get_base() { return std::move(base); }
    uint32_t&& get_mod() { return std::move(mod); }

    Tp operator()(std::make_unsigned_t<Tp>&& exponent) { return block1[exponent & 65535] * block2[exponent >> 16] % mod; }
};
```

</details>
