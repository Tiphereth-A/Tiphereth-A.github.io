#include <bits/stdc++.h>

float InvSqrt(float x, int it) {
  float xhalf = 0.5f * x;
  int i = *(int *)&x;

  i = 0x5f3759df - (i >> 1);
  x = *(float *)&i;
  for (register int i = 1; i <= it; ++i)
    x = x * (1.5f - xhalf * x * x);
  return x;
}
float GetRErr(float test, float real) {
  return fabs((test - real) / real * 100.0);
}
int main() {
  int i = 0;
  while (1) {
    float t;
    scanf("%f", &t);
    if (t < 0) return 0;
    float sys = 1.0 / sqrt(t),
          invs1 = InvSqrt(t, 1), invs2 = InvSqrt(t, 2),
          invs3 = InvSqrt(t, 3), invs4 = InvSqrt(t, 4),
          invs5 = InvSqrt(t, 5), invs6 = InvSqrt(t, 6);
    printf(
      "Test#%d n=%f\n"
      "System:\n%f\nTest:\n"
      "it#1:%f RelativeErr:%.2f%%\n"
      "it#2:%f RelativeErr:%.2f%%\n"
      "it#3:%f RelativeErr:%.2f%%\n"
      "it#4:%f RelativeErr:%.2f%%\n"
      "it#5:%f RelativeErr:%.2f%%\n"
      "it#6:%f RelativeErr:%.2f%%\n\n",
      ++i,
      t,
      sys,
      invs1,
      GetRErr(invs1, sys),
      invs2,
      GetRErr(invs2, sys),
      invs3,
      GetRErr(invs3, sys),
      invs4,
      GetRErr(invs4, sys),
      invs5,
      GetRErr(invs5, sys),
      invs6,
      GetRErr(invs6, sys));
  }
  return 0;
}
