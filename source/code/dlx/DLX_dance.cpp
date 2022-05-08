std::size_t find_min_col() {
    std::size_t res = _r(0);
    _for(i, 0, r)
        if (cnt_col[i] < cnt_col[res]) res = i;
    return res;
}

/**
 * @param std::size_t* _ans : 答案
 * @param std::size_t& _len : 答案长度
 * @return bool : 是否有解
 */
bool dance(std::size_t *_ans, std::size_t &_len) {
    if (_r(0) == 0) return true;
    std::size_t now_r = find_min_col();
    remove_col(now_r);
    _for(i, now_r, d) {
        _ans[++_len] = _row(i);
        _for(j, i, r) remove_col(_col(j));
        if (dance(_ans, _len)) {
            _for(j, i, l) resume_col(_col(j));
            return true;
        }
        --_len;
        _for(j, i, l) resume_col(_col(j));
    }
    resume_col(now_r);
    return false;
}
