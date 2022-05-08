#define _RM4(_1, _2, _3, _4, ...) __VA_ARGS__
#define _SEL4(_1, _2, _3, _4, ...) _1, _2, _3, _4

// use this
// remove first 4 elements
#define RM4(...) _RM4(__VA_ARGS__)

// use this
// select first 4 elements
#define SEL4(...) _SEL4(__VA_ARGS__)
