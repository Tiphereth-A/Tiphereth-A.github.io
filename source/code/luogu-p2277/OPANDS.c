#define _CPROD1_4_HELPER(a, b, c, d, ...) a, __VA_ARGS__, b, __VA_ARGS__, c, __VA_ARGS__, d, __VA_ARGS__

#define _CPROD2_4_HELPER(a, b, c, d, ...) _CPROD1_4_HELPER(a, b, c, d, a, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, b, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, c, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, d, __VA_ARGS__)

#define CPROD3_4(a, b, c, d) _CPROD2_4_HELPER(a, b, c, d, a), _CPROD2_4_HELPER(a, b, c, d, b), _CPROD2_4_HELPER(a, b, c, d, c), _CPROD2_4_HELPER(a, b, c, d, d)

// use this
#define OPANDS CPROD3_4(+, -, *, /)
