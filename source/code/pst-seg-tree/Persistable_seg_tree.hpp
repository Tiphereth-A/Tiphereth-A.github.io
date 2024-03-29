namespace Persistable_seg_tree {
#define _TRAITS(expression, __...) \
  std::enable_if_t<expression, ##__> * = nullptr
#define _CONVERTIBLE(Tp, Up) std::is_convertible<Tp, Up>::value

template <typename Tp, std::size_t Memory_rate = 24, Tp Zero = 0>
class persistable_seg_tree {
public:
  using self = persistable_seg_tree<Tp, Memory_rate, Zero>;
  using data_t = Tp;

protected:
  struct node_t {
    data_t data;
    typename std::vector<node_t>::iterator l, r;

    node_t(const data_t &_data = Zero): data(_data) {}
  };
  using pointer = typename std::vector<node_t>::iterator;
  using index_t = std::size_t;

  using nodes_t = std::vector<node_t>;
  using roots_t = std::vector<pointer>;

  constexpr void
  _init(index_t &&l, index_t &&r, const data_t * const a, pointer &now) {
    nodes.emplace_back();
    now = nodes.end() - 1;
    if (l == r) {
      now->data = a[l];
      return;
    }
    index_t mid = l + ((r - l) >> 1);
    _init(std::move(l), std::move(mid), a, now->l);
    _init(mid + 1, std::move(r), a, now->r);
  }

  constexpr void _modify(index_t &&l,
                         index_t &&r,
                         pointer &now,
                         const pointer &pre,
                         index_t &&pos,
                         const data_t &k) {
    nodes.push_back(*pre);
    now = nodes.end() - 1;
    if (l == r) {
      now->data = k;
      return;
    }
    index_t mid = l + ((r - l) >> 1);
    if (pos <= mid)
      _modify(std::move(l), std::move(mid), now->l, pre->l, std::move(pos), k);
    else _modify(mid + 1, std::move(r), now->r, pre->r, std::move(pos), k);
  }

  constexpr data_t &
  _query(const pointer &now, index_t &&l, index_t &&r, index_t &&pos) const {
    if (l == r) return now->data;
    index_t mid = l + ((r - l) >> 1);
    if (pos <= mid)
      return _query(now->l, std::move(l), std::move(mid), std::move(pos));
    else return _query(now->r, mid + 1, std::move(r), std::move(pos));
  }

public:
  constexpr persistable_seg_tree() = default;
  constexpr explicit persistable_seg_tree(index_t &&_size): data_size(_size) {
    this->nodes.reserve(this->data_size * Memory_rate);
    this->nodes.emplace_back();
    this->roots.push_back(nodes.begin());
  }

  constexpr persistable_seg_tree(const data_t * const data_array,
                                 index_t &&_size)
    : persistable_seg_tree(std::move(_size)) {
    this->_init(1, std::move(this->data_size), data_array, this->roots.back());
  }

  template <class Up, _TRAITS(_CONVERTIBLE(Up, self &))>
  constexpr persistable_seg_tree(Up &&rhs)
    : data_size(std::forward(rhs).data_size), nodes(std::forward(rhs).nodes),
      roots(std::forward(rhs).roots) {}

  constexpr self &clear() {
    this->nodes.clear();
    this->roots.clear();
    return *this;
  }

  constexpr index_t &&get_data_size() const {
    return std::move(const_cast<self * const>(this)->data_size);
  }
  constexpr index_t &&get_node_size() const { return this->nodes.size(); }
  constexpr index_t &&get_version_size() const { return this->roots.size(); }

  constexpr nodes_t &data_nodes() const { return this->nodes; }
  constexpr roots_t &data_roots() const { return this->roots; }

  constexpr self &init(const data_t * const data_array, index_t &&_size) {
    this->data_size = std::move(_size);
    this->nodes.reserve(this->data_size * Memory_rate);
    this->nodes.emplace_back();
    this->roots.push_back(nodes.begin());
    this->_init(1, std::move(this->data_size), data_array, this->roots.back());
    return *this;
  }

  template <class Up, _TRAITS(_CONVERTIBLE(Up, data_t &))>
  constexpr self &modify(index_t &&version, index_t &&pos, Up &&data) {
    this->roots.push_back(this->nodes.begin());
    this->_modify(1,
                  std::move(this->data_size),
                  this->roots.back(),
                  this->roots[version],
                  std::move(pos),
                  std::forward<data_t>(data));
    return *this;
  }

  constexpr data_t &query(index_t &&version, index_t &&pos) {
    this->roots.push_back(this->roots[version]);
    return this->_query(
      this->roots.back(), 1, std::move(this->data_size), std::move(pos));
  }

  // for debug
  constexpr size_t memory_used() const {
    return sizeof(node_t) * nodes.capacity() +
           sizeof(pointer) * roots.capacity();
  }

protected:
  index_t data_size;
  nodes_t nodes;
  roots_t roots;
};

#undef _TRAITS
}  // namespace Persistable_seg_tree
using Persistable_seg_tree::persistable_seg_tree;
