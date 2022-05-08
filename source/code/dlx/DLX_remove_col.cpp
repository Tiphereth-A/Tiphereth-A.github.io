void remove_col(std::size_t _now_col) {
    _r(_l(_now_col)) = _r(_now_col);
    _l(_r(_now_col)) = _l(_now_col);
    _for(i, _now_col, d)
        _for(j, i, r) {
            _u(_d(j)) = _u(j);
            _d(_u(j)) = _d(j);
            --cnt_col[_col(j)];
        }
}
