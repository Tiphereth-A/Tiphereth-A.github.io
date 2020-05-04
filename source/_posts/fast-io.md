---
title: 模板 - 基于 fread / fwrite 的快读快写
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 常数优化
date: 2021-07-28 21:40:03
---

实现了 有符号算术类型、无符号算术类型、C 风格字符串、`std::string` 的读入和有符号算术类型、无符号算术类型、`char`、`std::string` 的输出

<!-- more -->

~~实际上没什么应用价值, 开了 O2、关闭流同步、解绑、不使用 `std::endl` 等的 `std::cin` / `std::cout` 的性能已经和本模板差不多了, 就当作模板偏特化方面的练习了~~

经测试, 当数据规模在 1e7 及以上时, 该模板效率提升显著

{% note warning %}

- 若使用了 `FastIO::print()`, 记得后面跟上 `FastIO::flush();`
- 为了保证性能, `FastIO::print(char)` 内部没有添加防溢出机制, 若需要频繁调用 `FastIO::print(char)`, 请记得补充
- `FastIO::print(const std::string&)` 里有 `[[unlikely]]` 注解, 若不使用 C++20 请删除
  > 讲道理用 C++20 的 `concept` 写模板偏特化更舒服些, 但笔者懒得再写了

{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
namespace FastIO {
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf;
int p, p3 = -1;
inline int getc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++; }
inline void flush() { fwrite(buf2, 1, p3 + 1, stdout), p3 = -1; }

inline void read() {}
template <class T, typename std::enable_if<is_signed_v<T>>::type* = nullptr>
inline void read(T& x) {
    int f = x = 0;
    char ch = getc();
    while (!isdigit(ch)) {
        if (ch == '-') f = 1;
        ch = getc();
    }
    while (isdigit(ch)) { x = x * 10 + ch - '0', ch = getc(); }
    if (f) x = -x;
}
template <class T, typename std::enable_if<is_unsigned_v<T>>::type* = nullptr>
inline void read(T& x) {
    x = 0;
    char ch = getc();
    while (!isdigit(ch)) ch = getc();
    while (isdigit(ch)) { x = x * 10 + ch - '0', ch = getc(); }
}
inline void read(char* str) {
    char ch = getc(), *now = str;
    while (!isprint(ch)) ch = getc();
    while (isprint(ch)) { *(now++) = ch, ch = getc(); }
    *(now++) = '\0';
}
inline void read(std::string& str) {
    char ch = getc();
    while (!isprint(ch)) ch = getc();
    while (isprint(ch)) { str.push_back(ch), ch = getc(); }
}
template <typename T, typename... T2, typename std::enable_if<is_signed_v<T> || is_unsigned_v<T> || is_same_v<T, char*> || is_same_v<T, string&>>::type* = nullptr>
inline void read(T& x, T2&... oth) {
    read(x);
    read(oth...);
}

inline void print() {}
inline void print(char a) { buf2[++p3] = a; }
template <class T, typename std::enable_if<is_signed_v<T>>::type* = nullptr>
inline void print(T x) {
    if (x < 0) { buf2[++p3] = '-', x = -x; }
    do { a[++p] = x % 10 + 48; } while (x /= 10);
    do { buf2[++p3] = a[p]; } while (--p);
}
template <class T, typename std::enable_if<is_unsigned_v<T>>::type* = nullptr>
inline void print(T x) {
    do { a[++p] = x % 10 + 48; } while (x /= 10);
    do { buf2[++p3] = a[p]; } while (--p);
}
inline void print(const std::string& str) {
    for (char ch : str) {
        if (p3 > 1 << 20) [[unlikely]] flush();
        print(ch);
    }
}
template <typename T, typename... T2, typename std::enable_if<is_signed_v<T> || is_unsigned_v<T> || is_same_v<T, char> || is_same_v<T, string&> || is_same_v<T, const string&>>::type* = nullptr>
inline void print(T x, T2... oth) {
    if (p3 > 1 << 20) flush();
    print(x);
    print(oth...);
}
}  // namespace FastIO
using FastIO::print;
using FastIO::read;
```

</details>
