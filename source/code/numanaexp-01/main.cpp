/*
 * @Author: Tifa
 * @LastEditTime: 2021-04-16 20:30:47
 * @Description: Exp.1
 */
// -std=c++14
#include <cmath>
#include <cstdio>

using num_t = double;

// data
const int N = 3001;
const num_t pi = acos(-1.0);
// iteration
const int A_3 = 71000;
// step
const num_t STEP = 1e-1;
// inverse of step
const num_t INV_STEP = 1.0 / STEP;

// result
num_t psi[N] = {pi * pi / 6};

int main() {
    // 0 < x < 1
    for (int i = 1; i < INV_STEP; ++i) {
        num_t psi_now = 0;
        for (int j = 1; j <= A_3; ++j) psi_now += 1.0 / (j * (j + 1) * (j + STEP * i));
        psi[i] = psi_now * (1 - STEP * i) + 1;
    }
    // x >= 1
    for (int i = INV_STEP; i < N; ++i) psi[i] = (1 - INV_STEP / i) * psi[(size_t)(i - INV_STEP)] + INV_STEP * INV_STEP / (i * i);
    for (int i = 0; i < N; ++i) printf("%6.2f %16.12f\n", STEP * i, psi[i]);
    return 0;
}
