#include <climits>
#include <ctime>
#include <fstream>
#include <random>
#include <sstream>

using namespace std;
const int max_n[] = {1, (int)1e6, (int)5e6, (int)1e7, (int)2e7};

ofstream out;
stringstream ss;
string filename;

int main() {
  int cnt = 1;
  for (int i = 1; i < sizeof(max_n) / sizeof(max_n[0]); ++i) {
    default_random_engine e(time(NULL));
    uniform_int_distribution<unsigned> u_mn(max_n[i - 1], max_n[i]),
      u_case(1, 2);
    uniform_int_distribution<uint64_t> u_data(0, ULLONG_MAX);
    for (register int i = 0; i < 5; ++i, ++cnt) {
      ss.clear();
      ss << cnt << ".in";
      ss >> filename;
      out.open(filename);
      int n = u_mn(e), m = u_mn(e);
      out << n << " " << m << endl;
      for (register int i = 1; i < n; ++i) out << u_data(e) << " ";
      out << u_data(e) << endl;
      uniform_int_distribution<unsigned> u_range(1, n);
      for (register int i = 0; i < m; ++i) {
        int op = u_case(e);
        unsigned x = u_range(e), y = u_range(e);
        if (op & 1)
          out << op << " " << min(x, y) << " " << max(x, y) << " " << u_data(e)
              << endl;
        else out << op << " " << min(x, y) << " " << max(x, y) << endl;
      }
      out.close();
    }
  }
  return 0;
}
