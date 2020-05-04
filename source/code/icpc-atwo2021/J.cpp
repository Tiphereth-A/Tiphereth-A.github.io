#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  if (any_of(s.begin(), s.end(), [](const char &ch) { return !isdigit(ch); }) ||
      any_of(t.begin(), t.end(), [](const char &ch) { return !isdigit(ch); })) {
    cout << "NaN\n";
    return 0;
  }
  stringstream ss;
  int a, b;
  ss << s << ' ' << t;
  ss >> a >> b;
  cout << a - b;
  return 0;
}
