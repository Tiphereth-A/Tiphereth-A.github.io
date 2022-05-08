#define _static_assert(exp) sizeof(struct { int: -!!(exp); })
