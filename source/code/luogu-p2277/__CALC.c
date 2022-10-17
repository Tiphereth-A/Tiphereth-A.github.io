#define ___CALC0(a, b, c, d, opab, opbc, opcd) \
  Node(0,                                      \
       a,                                      \
       b,                                      \
       c,                                      \
       d,                                      \
       #opab,                                  \
       #opbc,                                  \
       #opcd,                                  \
       ((double(a) opab double(b))opbc double(c))opcd double(d))

#define ___CALC1(a, b, c, d, opab, opbc, opcd) \
  Node(1,                                      \
       a,                                      \
       b,                                      \
       c,                                      \
       d,                                      \
       #opab,                                  \
       #opbc,                                  \
       #opcd,                                  \
       (double(a) opab(double(b) opbc double(c)))opcd double(d))

#define ___CALC2(a, b, c, d, opab, opbc, opcd) \
  Node(2,                                      \
       a,                                      \
       b,                                      \
       c,                                      \
       d,                                      \
       #opab,                                  \
       #opbc,                                  \
       #opcd,                                  \
       double(a) opab((double(b) opbc double(c))opcd double(d)))

#define ___CALC3(a, b, c, d, opab, opbc, opcd) \
  Node(3,                                      \
       a,                                      \
       b,                                      \
       c,                                      \
       d,                                      \
       #opab,                                  \
       #opbc,                                  \
       #opcd,                                  \
       double(a) opab(double(b) opbc(double(c) opcd double(d))))

#define ___CALC4(a, b, c, d, opab, opbc, opcd) \
  Node(4,                                      \
       a,                                      \
       b,                                      \
       c,                                      \
       d,                                      \
       #opab,                                  \
       #opbc,                                  \
       #opcd,                                  \
       ((double(a) opab double(b))opbc(double(c) opcd double(d))))

#define ___CALC(a, b, c, d, opab, opbc, opcd) \
  ___CALC0(a, b, c, d, opab, opbc, opcd),     \
    ___CALC1(a, b, c, d, opab, opbc, opcd),   \
    ___CALC2(a, b, c, d, opab, opbc, opcd),   \
    ___CALC3(a, b, c, d, opab, opbc, opcd),   \
    ___CALC4(a, b, c, d, opab, opbc, opcd)

// use this
#define __CALC(...) ___CALC(__VA_ARGS__)
