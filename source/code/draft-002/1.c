#define min(x, y) ({                   \
    typeof(x) _min_1 = (x);            \
    typeof(y) _min_2 = (y);            \
    (void)(&_min_1 == &_min_2);        \
    _min_1 < _min_2 ? _min_1 : _min_2; \
  })
