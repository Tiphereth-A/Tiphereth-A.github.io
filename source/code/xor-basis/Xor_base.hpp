template <std::size_t N = 64>
class Xor_basis {
    using self = Xor_basis<N>;
    using data_t = std::bitset<N>;
    using reference = self &;
    using iterator = data_t *;
    using const_iterator = data_t *;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  protected:
    data_t base[N];

  public:
    constexpr Xor_basis() { this->clear(); }
    constexpr Xor_basis(std::initializer_list<data_t> _list): Xor_basis() {
        for (auto &&i : _list) this->insert(i);
    }

    constexpr void clear() {
        for (size_t i = 0; i < size(); ++i) base[i].reset();
    }

    constexpr size_t size() const { return N; }

    constexpr data_t operator[](size_t index) { return this->base[index]; }
    constexpr data_t operator[](size_t index) const { return const_cast<self * const>(this)->base[index]; }

    constexpr iterator begin() { return this->base; }
    constexpr const_iterator begin() const { return const_cast<data_t * const>(this->base); }

    constexpr iterator end() { return this->begin() + this->size(); }
    constexpr const_iterator end() const { return this->begin() + this->size(); }

    inline reverse_iterator rbegin() { return reverse_iterator(this->end()); }
    inline const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

    inline reverse_iterator rend() { return reverse_iterator(this->begin()); }
    inline const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

    constexpr bool insert(data_t x) {
        bool status = false;
        for (size_t i = size() - 1; ~i; --i) {
            if (!(x[i])) continue;
            if (base[i][i])
                x ^= base[i];
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

    constexpr data_t max_span() const {
        data_t ret;
        for (const auto &i : *this) ret ^= i;
        return ret;
    }

    constexpr size_t rank() const {
        size_t res = 0;
        for (size_t i = 0; i < size(); ++i) res += base[i][i];
        return res;
    }

    // @return std::nullopt if x is linear independent with current basis, else return the solution
    constexpr std::optional<std::bitset<N>> coordinate(vector_t x) {
        std::bitset<N> res;
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