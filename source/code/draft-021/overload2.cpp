#include <iostream>
#include <set>
#include <vector>

template <class CharT,
          class Traits,
          class Container,
          decltype(std::declval<Container>().begin(),
                   std::declval<Container>().end(),
                   0) * = nullptr>
std::basic_ostream<CharT, Traits> &
operator<<(std::basic_ostream<CharT, Traits> &os, const Container &container) {
  if (container.begin() == container.end()) return os << "[]";
  os << '[';
  for (auto it = container.begin(); it != container.end();) {
    std::cout << *it++;
    if (it != container.end()) std::cout << ", ";
  }
  os << ']';
  return os;
}

int main() {
  std::vector<int> v{1, 1, 4, 5, 1, 4};
  std::cout << v << std::endl;  // [1, 1, 4, 5, 1, 4]
  std::set<int> s{1, 1, 4, 5, 1, 4};
  std::cout << s << std::endl;  // [1, 4, 5]
  std::string str = "114514";
  std::cout << str << std::endl;  // 114514
  return 0;
}