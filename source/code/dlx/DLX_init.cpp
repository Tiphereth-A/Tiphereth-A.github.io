void init(std::size_t _width, std::size_t _height) {
  width = cnt_node = _width;
  height = _height;
  for (std::size_t i = 1; i <= width; ++i) node[i] = {i - 1, i + 1, i, i, 0, i};
  node[_r(width) = 0] = {width, 1, 0, 0, 0, 0};
}
