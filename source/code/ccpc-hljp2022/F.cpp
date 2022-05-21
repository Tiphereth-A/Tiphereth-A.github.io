#include <cstdio>
#include <iostream>
using namespace std;
const int A[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 2, 3, 3, 4},
    {0, 1, 0, 2, 1, 2, 2, 3},
    {0, 1, 2, 0, 1, 2, 2, 3},
    {0, 2, 1, 1, 0, 1, 1, 2},
    {0, 3, 2, 2, 1, 0, 2, 1},
    {0, 3, 2, 2, 1, 2, 0, 1},
    {0, 4, 3, 3, 2, 1, 1, 0}};
int main() {
    int T, a1, a2, b1, b2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        printf("%d\n", min(A[a1][b1] + A[a2][b2], A[a1][b2] + A[a2][b1]));
    }
    return 0;
}