#include <bits/stdc++.h>
using namespace std;

int main() {
  mt19937 rad(time(0));
  int m = 0;
  auto walk = [](int x) {
    cout << "walk " << x << '\n';
    cout.flush();
    int ret = 0;
    cin >> ret;
    return ret;
  };
  int k = 3333;
  for (int i = 1; i <= k; i++) m = max(m, walk(rad() % 1000000000));
  unordered_map<int, int> a;
  auto guess = [](int x) {
    cout << "guess " << x << '\n';
    exit(0);
  };
  for (int i = 1; i < k; i++) {
    int x = walk(1);
    if (a[x]) guess(i - 1);
    a[x] = i;
  }
  int x = walk(m), step = k - 1 + m;
  if (a[x]) guess(step - a[x]);
  for (int i = 1; i <= k; i++) {
    x = walk(k - 1), step += k - 1;
    if (a[x]) guess(step - a[x]);
  }
  return 0;
}