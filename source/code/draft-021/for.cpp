for (auto it = container.begin(); it != container.end();) {
  std::cout << *it++;
  if (it != container.end()) std::cout << ", ";
}