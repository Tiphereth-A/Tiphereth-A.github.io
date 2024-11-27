#include <bits/stdc++.h>
using tree_size_t = uint32_t;

class bst_tag {
protected:
  template <typename pointer>
  auto size(pointer p) const -> tree_size_t {
    return p ? p->sz : 0;
  }

  /**
   * Insert leaf node @param n to @param p
   *
   * @param root root of tree
   * @param p parent of node which will be inserted
   * @param n node which will be inserted
   * @param dir direction of n, 0: left; 1: right
   */
  template <typename pointer>
  void insert_leaf(pointer &root, pointer p, pointer n, bool dir) {
    if (!p) {
      root = n;
      return;
    }
    p->ch[dir] = n, n->fa = p;
    auto now = p;
    while (now) now->sz++, now = now->fa;
  }
  /**
   * Erase node @param n
   *
   * @param root root of tree
   * @param n node which will be deleted, must have no more than 2 child
   */
  template <typename pointer>
  void erase_branch_leaf(pointer &root, pointer n) {
    auto p = n->fa, s = n->ch[0] ? n->ch[0] : n->ch[1];
    if (s) s->fa = p;
    if (!p) {
      root = s;
      return;
    }
    p->ch[n->child_dir()] = s;
    auto now = p;
    while (now) now->sz--, now = now->fa;
  }

  /**
   * @param root root of tree
   * @param p root of subtree (may be same as @param root)
   * @param dir direction. 0: left rotate; 1: right rotate
   */
  template <typename pointer>
  auto rotate(pointer &root, pointer p, bool dir) -> pointer {
    auto g = p->fa;
    auto s = p->ch[!dir];  // new root of subtree
    assert(s);             // pointer to true node required
    s->sz = p->sz, p->sz = size(p->ch[dir]) + size(s->ch[dir]) + 1;
    auto c = s->ch[dir];
    if (c) c->fa = p;
    p->ch[!dir] = c, s->ch[dir] = p;
    p->fa = s, s->fa = g;
    if (g) g->ch[p == g->ch[1]] = s;
    else root = s;
    return s;
  }
};
class rbt_tag: protected bst_tag {
protected:
  template <typename pointer>
  auto is_red(pointer p) const -> bool {
    return p ? p->red : false;
  }

  /**
   * @param root root of tree
   * @param p parent of node which will be inserted
   * @param n node which will be inserted
   * @param dir direction of n, 0: left; 1: right
   */
  template <typename pointer>
  void insert_leaf(pointer &root, pointer p, pointer n, bool dir) {
    n->red = p;
    bst_tag::insert_leaf(root, p, n, dir);
    // fix double red
    while (is_red(p = n->fa)) {
      bool p_dir = p->child_dir();
      auto g = p->fa, u = g->ch[!p_dir];
      // Case 1: both p and u are red
      // clang-format off
      //      g              [g]
      //     / \             / \
      //   [p] [u]   ==>    p   u
      //   /               /
      // [n]             [n]
      // clang-format on
      if (is_red(u)) {
        p->red = u->red = false;
        g->red = true;
        n = g;
        continue;
      }
      // p is red and u is black
      // Case 2: dir of n is different with dir of p
      // clang-format off
      //    g              g
      //   / \            / \
      // [p]  u   ==>   [n]  u
      //   \            /
      //   [n]        [p]
      // clang-format on
      if (n->child_dir() != p_dir) rotate(root, p, p_dir), swap(n, p);
      // Case 3: p is red, u is black and dir of n is same as dir of p
      // clang-format off
      //      g             p
      //     / \           / \
      //   [p]  u   ==>  [n] [g]
      //   /                   \
      // [n]                    u
      // clang-format on
      p->red = false, g->red = true;
      rotate(root, g, !p_dir);
    }
    root->red = false;
  }
  /**
   * @param root root of tree
   * @param n node which will be deleted, must have no more than 2 child
   */
  template <typename pointer>
  void erase_branch_leaf(pointer &root, pointer n) {
    bool n_dir = n == root ? false : n->child_dir();
    bst_tag::erase_branch_leaf(root, n);
    auto p = n->fa;
    if (!p) {  // n is root
      if (root) root->red = false;
      return;
    } else {
      auto s = p->ch[n_dir];
      if (s) {  // n has 1 child
        // n must be black and s must be red, so we need to color s black
        s->red = false;
        return;
      }
    }
    // n is not root but leaf with black color, need to be fixup
    while (p && !n->red) {
      auto s = p->ch[!n_dir];
      // Case 1: s is red
      // clang-format off
      //    p               s
      //   / \             / \
      // |n| [s]   ==>   [p]  d
      //     / \         / \
      //    c   d      |n|  c
      // clang-format on
      if (is_red(s)) {
        s->red = false, p->red = true;
        rotate(root, p, n_dir);
        s = p->ch[!n_dir];
      }
      // s must be black
      auto c = s->ch[n_dir], d = s->ch[!n_dir];
      // Case 2: both c and d are black
      // clang-format off
      //   {p}           p
      //   / \          / \
      // |n|  s   ==> |n| [s]
      //     / \          / \
      //    c   d        c   d
      // clang-format on
      if (!is_red(c) && !is_red(d)) {
        s->red = true;
        n = p;
        goto end_erase_fixup;
      }
      // Case 3: c is red and d is black
      // clang-format off
      //   {p}          {p}
      //   / \          / \
      // |n|  s   ==> |n|  c
      //     / \            \
      //   [c]  d           [s]
      //                      \
      //                       d
      // clang-format on
      if (!is_red(d)) {
        c->red = false, s->red = true;
        rotate(root, s, !n_dir);
        s = p->ch[!n_dir], c = s->ch[n_dir], d = s->ch[!n_dir];
      }
      // Case 4: d is red
      // clang-format off
      //   {p}            {s}
      //   / \            / \
      // |n|  s   ==>    p   d
      //     / \        / \
      //   {c} [d]    |n| {c}
      // clang-format on
      s->red = p->red, p->red = d->red = false;
      rotate(root, p, n_dir), n = root;
    end_erase_fixup:
      p = n->fa;
      if (!p) break;
      n_dir = n->child_dir();
    }
    n->red = false;
  }
};

template <typename T, typename data_t>
struct balance_tree_node_t {};
template <typename data_t>
struct balance_tree_node_t<bst_tag, data_t> {
  balance_tree_node_t *fa;     // == nullptr if root of the tree
  balance_tree_node_t *ch[2];  // == nullptr if child is empty
                               // The index is:
                               // LEFT  := 0, if (key < fa->key)
                               // RIGHT := 1, if (key > fa->key)
  data_t data;
  tree_size_t sz;  // size of subtree

  /**
   * @return child direction of this non-root point
   */
  auto child_dir() const -> bool { return this == fa->ch[1]; }
};
template <typename data_t>
struct balance_tree_node_t<rbt_tag, data_t> {
  balance_tree_node_t *fa;     // == nullptr if root of the tree
  balance_tree_node_t *ch[2];  // == nullptr if child is empty
                               // The index is:
                               // LEFT  := 0, if (key < fa->key)
                               // RIGHT := 1, if (key > fa->key)
  data_t data;
  tree_size_t sz;  // size of subtree
  bool red;        // true if node is red, otherwise black

  /**
   * @return child direction of this non-root point
   */
  auto child_dir() const -> bool { return this == fa->ch[1]; }
};

template <typename key_t,
          typename tree_tag_t,
          typename compare_t = std::less<key_t>,
          template <typename> typename allocator_t = std::allocator>
struct balance_tree: public tree_tag_t {
  using node_t = balance_tree_node_t<tree_tag_t, key_t>;
  using pointer = node_t *;
  using const_pointer = const node_t *;
  using pointer_const = node_t * const;

  static constexpr compare_t compare{};
  allocator_t<node_t> alloc;
  pointer root;

  balance_tree(): tree_tag_t(), root{nullptr} {}
  ~balance_tree() {
    post_order([this](auto it) { alloc.deallocate(it, 1); });
  }

  auto size() const -> tree_size_t { return tree_tag_t::size(root); }

  template <typename F>
  void pre_order(F callback) {
    auto f = [&](auto &&f, pointer p) {
      if (!p) return;
      callback(p), f(f, p->ch[0]), f(f, p->ch[1]);
    };
    f(f, root);
  }
  template <typename F>
  void in_order(F callback) {
    auto f = [&](auto &&f, pointer p) {
      if (!p) return;
      f(f, p->ch[0]), callback(p), f(f, p->ch[1]);
    };
    f(f, root);
  }
  template <typename F>
  void post_order(F callback) {
    auto f = [&](auto &&f, pointer p) {
      if (!p) return;
      f(f, p->ch[0]), f(f, p->ch[1]), callback(p);
    };
    f(f, root);
  }

  auto leftmost(const_pointer p) const { return most(p, 0); }
  auto rightmost(const_pointer p) const { return most(p, 1); }
  auto prev(const_pointer p) const { return neighbour(p, 0); }
  auto next(const_pointer p) const { return neighbour(p, 1); }

  auto lower_bound(const key_t &key) const -> pointer {
    const_pointer now = root, ans = nullptr;
    while (now) {
      if (!compare(now->data, key)) ans = now, now = now->ch[0];
      else now = now->ch[1];
    }
    return (pointer)ans;
  }
  auto upper_bound(const key_t &key) const -> pointer {
    const_pointer now = root, ans = nullptr;
    while (now) {
      if (compare(key, now->data)) ans = now, now = now->ch[0];
      else now = now->ch[1];
    }
    return (pointer)ans;
  }

  // Order start from 0
  auto order_of_key(const key_t &key) const -> tree_size_t {
    tree_size_t ans = 0;
    auto now = root;
    while (now) {
      if (!compare(now->data, key)) now = now->ch[0];
      else ans += tree_tag_t::size(now->ch[0]) + 1, now = now->ch[1];
    }
    return ans;
  }
  // Order start from 0
  auto find_by_order(tree_size_t order) const -> const_pointer {
    const_pointer now = root, ans = nullptr;
    while (now && now->sz >= order) {
      auto lsize = tree_tag_t::size(now->ch[0]);
      if (order < lsize) now = now->ch[0];
      else {
        ans = now;
        if (order == lsize) break;
        now = now->ch[1], order -= lsize + 1;
      }
    }
    return ans;
  }

  /**
   * @return nullptr if insert failed, otherwise pointer of inserted node
   */
  auto insert(const key_t &data) -> const_pointer {
    pointer n = alloc.allocate(1);
    n->fa = n->ch[0] = n->ch[1] = nullptr;
    n->data = data, n->sz = 1;
    pointer now = root, p = nullptr;
    bool dir = 0;
    while (now) {
      p = now;
      dir = compare(now->data, data);
      now = now->ch[dir];
    }
    tree_tag_t::insert_leaf(root, p, n, dir);
    return n;
  }
  /**
   * @return succeed or not
   */
  auto erase(const key_t &key) -> bool {
    auto p = lower_bound(key);
    if (!p || p->data != key) return false;
    erase(p);
    return true;
  }
  /**
   * @return {@code next(p)}
   */
  auto erase(pointer p) -> const_pointer {
    if (!p) return nullptr;
    pointer result;
    if (p->ch[0] && p->ch[1]) {
      auto s = leftmost(p->ch[1]);
      std::swap(s->data, p->data);
      result = p, p = s;
    } else result = next(p);
    tree_tag_t::erase_branch_leaf(root, p);
    alloc.deallocate(p, 1);
    return result;
  }

private:
  /**
   * @param dir 0: leftmost, 1: rightmost
   */
  auto most(const_pointer p, bool dir) const -> pointer {
    if (!p) return nullptr;
    while (p->ch[dir]) p = p->ch[dir];
    return (pointer)p;
  }
  /**
   * @param dir 0: prev, 1: next
   */
  auto neighbour(const_pointer p, bool dir) const -> pointer {
    if (!p) return nullptr;
    if (p->ch[dir]) return most(p->ch[dir], !dir);
    if (p == root) return nullptr;
    while (p && p->fa && !p->child_dir()) p = p->fa;
    return p ? p->fa : nullptr;
  }
};