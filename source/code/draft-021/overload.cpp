#include <iostream>
#include <set>
#include <vector>

template <class Container,
          decltype(std::declval<Container>().begin(),
                   std::declval<Container>().end(),
                   0) * = nullptr>
std::ostream &operator<<(std::ostream &os, const Container &container) {
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
  return 0;
}