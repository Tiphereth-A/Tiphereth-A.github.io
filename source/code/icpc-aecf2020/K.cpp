#include <bits/stdc++.h>
using namespace std;
int T, a[10], b[10];
char str[10];
int main() {
    scanf("%d", &T);
    while (T--) {
        char op;
        int f = 1;
        for (int i = 1; i <= 5; ++i) {
            scanf("%s", str);
            if (i == 1) {
                op = str[1];
            } else {
                if (op != str[1]) f = 0;
            }
            switch (str[0]) {
                case 'A':
                    a[i] = 1;
                    break;
                case 'T':
                    a[i] = 10;
                    break;
                case 'J':
                    a[i] = 11;
                    break;
                case 'Q':
                    a[i] = 12;
                    break;
                case 'K':
                    a[i] = 13;
                    break;
                default:
                    a[i] = str[0] - '0';
            }
            b[i] = a[i];
        }
        if (!f) {
            puts("check");
            continue;
        }
        sort(a + 1, a + 6);
        sort(b + 3, b + 6);
        if (b[2] < b[1]) swap(b[1], b[2]);
        if (a[1] == 1 && a[5] == 13 && a[4] == 12 && a[3] == 11 && a[2] == 10) {
            puts("allin");
        } else if (a[5] - a[1] == 4) {
            if (a[1] == 9) {
                puts("allin");
            } else if (a[1] == 8) {
                if (b[1] == 8 && b[2] == 9) {
                    puts("check");
                } else puts("allin");
            } else if (a[1] == 7) {
                if (b[4] == 10 && b[5] == 11) {
                    puts("check");
                } else puts("allin");
            } else if (a[1] == 1) {
                if (b[1] == 1 && b[2] == 5) {
                    puts("allin");
                } else puts("check");
            } else {
                if (b[2] == a[1] + 4) {
                    puts("allin");
                } else puts("check");
            }
        } else puts("check");
    }
    return 0;
}