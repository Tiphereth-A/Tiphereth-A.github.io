#define _RM3(_1, _2, _3, ...) __VA_ARGS__
#define _SEL3(_1, _2, _3, ...) _1, _2, _3

// use this
// remove first 3 elements
#define RM3(...) _RM3(__VA_ARGS__)

// use this
// select first 3 elements
#define SEL3(...) _SEL3(__VA_ARGS__)
