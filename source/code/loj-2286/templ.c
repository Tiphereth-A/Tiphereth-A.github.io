#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

using u32 = uint32_t;
using u64 = uint64_t;

inline u32 next_integer(u32 x) {
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}

bool output_arr(void *a, u32 size) {
  if (size % 4) {
    return puts("-1"), 0;
  }

  u32 blocks = size / 4;
  u32 *A = (u32 *)a;
  u32 ret = size;
  u32 x = 23333333;
  u32 i;
  for (i = 0; i < blocks; i++) {
    ret = ret ^ (A[i] + x);
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
  }

  return printf("%u\n", ret), 1;
}

// ===== header ======

void Sorting_main() {
  int n;
  u32 seed;
  scanf("%d%u", &n, &seed);

  u32 *a = malloc(n * sizeof(u32));
  int i;
  for (i = 0; i < n; i++) {
    seed = next_integer(seed);
    a[i] = seed;
  }

  // sort(a, n);

  output_arr(a, n * sizeof(u32));
}

void Game_main() {
  int n, q;
  scanf("%d%d", &n, &q);

  char *s1 = malloc((n + 1) * sizeof(char));
  char *s2 = malloc((n + 1) * sizeof(char));
  scanf("%s%s", s1, s2);

  u32 *anss = malloc(q * sizeof(u32));
  int *q_x = malloc(q * sizeof(int));
  int *q_y = malloc(q * sizeof(int));
  int *q_len = malloc(q * sizeof(int));

  int i;

  for (i = 0; i < q; i++) {
    scanf("%d%d%d", q_x + i, q_y + i, q_len + i);
  }

  // solve(n, q, s1, s2, q_x, q_y, q_len, anss);

  output_arr(anss, q * sizeof(u32));
}

void Parentheses_main() {
  int n;
  scanf("%d", &n);

  char *s = malloc((n + 1) * sizeof(char));
  scanf("%s", s);

  u32 ans;
  // ans = solve(n, s);

  printf("%u\n", ans);
}

int main() {
  int task_id;
  scanf("%d", &task_id);

  switch (task_id) {
    case 1:
      Sorting_main();
      break;
    case 2:
      Game_main();
      break;
    case 3:
      Parentheses_main();
      break;
  }

  return 0;
}
