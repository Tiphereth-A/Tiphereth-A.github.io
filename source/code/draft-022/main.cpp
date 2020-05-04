#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

deque<int> a;
vector<int> s;

int main() {
  int _;
  while (cin >> _) a.push_back(_);
  if (a.empty()) {
    cout << 0 << endl;
    return 0;
  }
  s.push_back(a.front());
  a.pop_front();
  for (int num : a) {
    if (num < s.back()) s.push_back(num);
    else *lower_bound(s.begin(), s.end(), num, greater<int>()) = num;
    // print s
    // for (int num : s) clog << num << " ";
    // clog << endl;
  }

  cout << s.size() << endl;
  return 0;
}

/* input:
89 126 85 103 101 86 86 98 96 99 89 81 101 92 79 77 82 97 83 100 78 72 79 97 71
80 98 89 69 74
*/

/* expected output:
12
*/
