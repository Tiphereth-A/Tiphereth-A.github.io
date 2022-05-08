#define _P2_HELPER(a, b, ...) a, b, __VA_ARGS__, b, a, __VA_ARGS__
#define _P3_HELPER(a, b, c, ...) _P2_HELPER(a, b, c, __VA_ARGS__), _P2_HELPER(b, c, a, __VA_ARGS__), _P2_HELPER(c, a, b, __VA_ARGS__)
#define P4(a, b, c, d) _P3_HELPER(a, b, c, d), _P3_HELPER(b, c, d, a), _P3_HELPER(c, d, a, b), _P3_HELPER(d, a, b, c)
