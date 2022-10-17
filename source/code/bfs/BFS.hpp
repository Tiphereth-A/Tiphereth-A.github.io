namespace BFS {
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

//!
using _state_t = int;
using _point_t = int;
using _step_t = int64_t;
using _map_t = char;

//!
const int N = 305, M = 305;
const _state_t __valid__ = 0, __forbidden__ = 1;

int n, m;
_state_t __state[N][M];
_map_t __map[N][M];

struct Point {
  _point_t x, y;

  Point operator=(const Point &rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
  Point operator+=(const Point &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  Point operator+(const Point &rhs) { return (Point){x + rhs.x, y + rhs.y}; }
  Point operator-(const Point &rhs) { return (Point){x - rhs.x, y - rhs.y}; }
  bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
  _state_t get_state() const { return __state[x][y]; }
  _map_t get_map() const { return __map[x][y]; }
  //!
  bool valid() const {
    return x > 0 && y > 0 && x <= n && y <= m &&
           this->get_state() != __forbidden__;
  }
  void set_state(_state_t state) const { __state[x][y] = state; }
  void set_map(_map_t val) const { __map[x][y] = val; }
};

struct Node {
  Point p;
  _step_t step;

  Node operator+=(const Node &rhs) {
    p += rhs.p;
    step += rhs.step;
    return *this;
  }
  Node operator+(const Node &rhs) const {
    Node tmp = *this;
    return tmp += rhs;
  }
  bool operator<(const Node &rhs) const { return step < rhs.step; }
  bool operator>(const Node &rhs) const { return step > rhs.step; }
  bool valid() const { return p.valid(); }
  void set_state(_state_t state) const { p.set_state(state); }
  _state_t get_state() const { return p.get_state(); }
};
//!
const Node move[] = {{{1, 0}, 1}, {{0, 1}, 1}, {{-1, 0}, 1}, {{0, -1}, 1}};

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
Point start, end;

//!
inline void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &__map[i][j]);
  scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);
}

inline _state_t main() {
  init();
  queue.push((Node){start, 0});
  start.set_state(__forbidden__);
  while (!queue.empty()) {
    Node now = queue.top();
    queue.pop();
    if (now.p == end) {
      //!
      return now.state;
    }
    for (auto i : move) {
      Node next = now + i;
      //!
      if (next.valid()) {
        next.set_state(__forbidden__);
        queue.push(next);
      }
    }
  }
}

}  // namespace BFS
