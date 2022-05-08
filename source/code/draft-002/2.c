#include <math.h>
#include <stdio.h>

#define GENERAL_ABS(x) _Generic((x), \
    int    : abs,                    \
    float  : fabsf,                  \
    double : fabs)(x)

int main(void) {
  printf("intabs:%d\n", GENERAL_ABS(-12));
  printf("floatabs:%f\n", GENERAL_ABS(-12.04f));
  printf("doubleabs:%f\n", GENERAL_ABS(-13.09876));

  int a = 10;
  int b = 0, c = 0;

  _Generic(a + 0.1f, int : b, float : c, default : b)++;
  printf("b=%d,c=%d\n", b, c);

  _Generic(a += 1.1f, int : b, float : c, default : b)++;
  printf("a=%d,b=%d,c=%d\n", a, b, c);
}
