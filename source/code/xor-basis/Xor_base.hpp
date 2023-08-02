template <std::size_t N = 64>
class XorBasis {
  using self = XorBasis<N>;
  using field_t = bool;
  using vector_t = std::bitset<N>;
  using reference = self &;
  using iterator = vector_t *;
  using const_iterator = vector_t *;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

protected:
  vector_t base[N];

public:
  constexpr XorBasis() { this->clear(); }
  constexpr XorBasis(std::initializer_list<vector_t> _list): XorBasis() {
    for (auto &&i : _list) this->insert(i);
  }

  constexpr void clear() {
    for (size_t i = 0; i < size(); ++i) base[i].reset();
  }

  constexpr size_t size() const { return N; }

  constexpr vector_t &operator[](size_t index) { return this->base[index]; }
  constexpr vector_t &operator[](size_t index) const {
    return const_cast<self * const>(this)->base[index];
  }

  constexpr iterator begin() { return this->base; }
  constexpr const_iterator begin() const {
    return const_cast<vector_t * const>(this->base);
  }

  constexpr iterator end() { return this->begin() + this->size(); }
  constexpr const_iterator end() const { return this->begin() + this->size(); }

  reverse_iterator rbegin() { return reverse_iterator(this->end()); }
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(this->end());
  }

  reverse_iterator rend() { return reverse_iterator(this->begin()); }
  const_reverse_iterator rend() const {
    return const_reverse_iterator(this->begin());
  }

  constexpr bool insert(vector_t x) {
    bool status = false;
    for (size_t i = size() - 1; ~i; --i) {
      if (!(x[i])) continue;
      if (base[i][i]) x ^= base[i];
      else {
        for (size_t j = 0; j < i; ++j)
          if (x[j]) x ^= base[j];
        for (size_t j = i + 1; j < size(); ++j)
          if (base[j][i]) base[j] ^= x;
        base[i] = x;
        status = true;
        break;
      }
    }
    return status;
  }

  constexpr vector_t max_span() const {
    vector_t ret;
    for (const auto &i : *this) ret ^= i;
    return ret;
  }

  constexpr size_t rank() const {
    size_t res = 0;
    for (size_t i = 0; i < size(); ++i) res += base[i][i];
    return res;
  }

  // @return std::nullopt if x is linear independent with current basis, else
  // return the solution
  constexpr std::optional<vector_t> coordinate(vector_t x) {
    vector_t res;
    for (size_t i = size() - 1; ~i; --i) {
      if (x[i] && !base[i][i]) return std::nullopt;
      if (x[i] && base[i][i]) {
        res.set(i);
        x ^= base[i];
      }
    }
    return res;
  }
};