#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
char str[N];
stack<int> q;
int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
        if (str[i] == '-') printf("%d ", i);
        else if (str[i] == '(') {
            q.push(i);
        } else {
            printf("%d ", i);
            printf("%d ", q.top());
            q.pop();
        }
    }
    return 0;
}