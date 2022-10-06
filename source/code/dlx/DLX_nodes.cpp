struct Node {
  struct Node *up;
  struct Node *down;
  struct Node *left;
  struct Node *right;

  Node(Node * const _up = nullptr,
       Node * const _down = nullptr,
       Node * const _left = nullptr,
       Node * const _right = nullptr): up(_up), down(_down), left(_left), right(_right) {}
};