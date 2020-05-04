#define P3(a, b, c) \
  _P2_HELPER(a, b, c), _P2_HELPER(b, c, a), _P2_HELPER(c, a, b)
#define P4_3(a, b, c, d) P3(a, b, c), P3(b, c, d), P3(c, d, a), P3(d, a, b)
