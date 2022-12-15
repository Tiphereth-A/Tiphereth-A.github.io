#include "euler_seive.hpp"
#include <iostream>
#include <tuple>

template <
  class Ch,
  class Tr,
  class Ct,
  std::enable_if_t<std::is_same<decltype(std::declval<Ct>().begin()),
                                typename Ct::iterator>::value &&
                   std::is_same<decltype(std::declval<Ct>().end()),
                                typename Ct::iterator>::value> * = nullptr>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os,
                                       const Ct &x) {
  if (x.begin() == x.end()) return os;
  for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ' ';
  os << x.back();
  return os;
}

int main() {
  std::vector<int> x, y;

#define SINGLE_TEST__(tag, n)                                    \
  std::tie(x, y) = euler_seive::seive<int, euler_seive::tag>(n); \
  std::cout << "tag: " << #tag << endl                           \
            << "n: " << n << endl                                \
            << "x: " << x << endl                                \
            << "y: " << y << endl                                \
            << endl

  SINGLE_TEST__(null_tag, 100);
  SINGLE_TEST__(min_pfactor_tag, 100);
  SINGLE_TEST__(euler_phi_tag, 100);
  SINGLE_TEST__(mobius_tag, 100);

#undef SINGLE_TEST__

  return 0;
}

// clang-format off
/* Output:
tag: null_tag
n: 100
x: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
y: 

tag: min_pfactor_tag
n: 100
x: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
y: 0 1 2 3 2 5 2 7 2 3 2 11 2 13 2 3 2 17 2 19 2 3 2 23 2 5 2 3 2 29 2 31 2 3 2 5 2 37 2 3 2 41 2 43 2 3 2 47 2 7 2 3 2 53 2 5 2 3 2 59 2 61 2 3 2 5 2 67 2 3 2 71 2 73 2 3 2 7 2 79 2 3 2 83 2 5 2 3 2 89 2 7 2 3 2 5 2 97 2 3

tag: euler_phi_tag
n: 100
x: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
y: 0 1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8 16 6 18 8 12 10 22 8 20 12 18 12 28 8 30 16 20 16 24 12 36 18 24 16 40 12 42 20 24 22 46 16 42 20 32 24 52 18 40 24 36 28 58 16 60 30 36 32 48 20 66 32 44 24 70 24 72 36 40 36 60 24 78 32 54 40 82 24 64 42 56 40 88 24 72 44 60 46 72 32 96 42 60

tag: mobius_tag
n: 100
x: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
y: 0 1 -1 -1 0 -1 1 -1 0 0 1 -1 0 -1 1 1 0 -1 0 -1 0 1 1 -1 0 0 1 0 0 -1 -1 -1 0 1 1 1 0 -1 1 1 0 -1 -1 -1 0 0 1 -1 0 0 0 1 0 -1 0 1 0 1 1 -1 0 -1 1 0 0 1 -1 -1 0 1 -1 -1 0 -1 1 0 0 1 -1 -1 0 0 1 -1 0 1 1 1 0 -1 0 1 0 1 1 1 0 -1 0 0

*/
