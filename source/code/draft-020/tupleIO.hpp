#ifndef TUPLE_IO_HPP_
#define TUPLE_IO_HPP_

#include <tuple>
#include <type_traits>
#include <iostream>

template <typename... Ts>
std::istream &operator>>(std::istream &is, std::tuple<Ts...> &p) {
  std::apply([&](Ts &...args) { ((is >> args), ...); }, p);
  return is;
}

template <typename... Ts>
std::ostream &operator<<(std::ostream &os, std::tuple<Ts...> const &p) {
  std::apply(
    [&](Ts const &...args) {
      std::size_t n{0};
      ((os << args << (++n != sizeof...(Ts) ? " " : "")), ...);
    },
    p);
  return os;
}

#endif