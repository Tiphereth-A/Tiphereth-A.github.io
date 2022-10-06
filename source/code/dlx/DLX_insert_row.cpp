/**
 * @param std::size_t  _ln       : i
 * @param std::size_t* _cols     : R(i)中所有结点的列编号
 * @param std::size_t  _len_cols : |R(i)|
 */
void insert_row(std::size_t _ln, std::size_t * const _cols, std::size_t _len_cols) {
  for (std::size_t i = 1; i <= _len_cols; ++i) {
    node[cnt_node + i] = {cnt_node + i - 1, cnt_node + i + 1, _u(_cols[i]), _cols[i], _ln, _cols[i]};
    _d(_u(_cols[i])) = cnt_node + i;
    _u(_cols[i]) = cnt_node + i;
    ++cnt_col[_cols[i]];
    if (_d(_cols[i]) == _cols[i]) _d(_cols[i]) = cnt_node + i;
  }
  _l(cnt_node + 1) = cnt_node + _len_cols;
  _r(cnt_node + _len_cols) = cnt_node + 1;
  cnt_node += _len_cols;
}
