const std::size_t MAX_SIZE = 1e5 + 5;
const std::size_t MAX_EDGE = 5e3 + 5;

struct Node {
    std::size_t up, down, left, right;
    std::size_t row, col;

    Node(std::size_t _up = 0,
         std::size_t _down = 0,
         std::size_t _left = 0,
         std::size_t _right = 0,
         std::size_t _row = 0,
         std::size_t _col = 0): up(_up), down(_down), left(_left), right(_right), row(_row), col(_col) {}
} nodes[MAX_SIZE];
std::size_t cnt_node;

std::size_t width, height;
std::size_t cnt_col[MAX_EDGE];
