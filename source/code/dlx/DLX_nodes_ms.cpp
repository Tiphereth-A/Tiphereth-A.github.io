const std::size_t MAX_SIZE = 1e5 + 5;
struct Node {
    std::size_t up, down, left, right;

    Node(std::size_t _up = 0,
         std::size_t _down = 0,
         std::size_t _left = 0,
         std::size_t _right = 0):
        up(_up),
        down(_down), left(_left), right(_right) {}
} nodes[MAX_SIZE];
std::size_t cnt_node;
