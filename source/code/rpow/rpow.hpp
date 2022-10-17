template <typename Tp = int64_t>
class rpow final {
private:
  uint32_t mod;
  Tp base;
  std::array<Tp, 65536> block1, block2;

public:
  rpow(const Tp &_base, const uint32_t &_mod): base(_base), mod(_mod) {
    block1[0] = block2[0] = 1;
    for (uint32_t i = 1; i < 65536; i++) block1[i] = block1[i - 1] * base % mod;
    Tp _(block1.back() * base % mod);
    for (uint32_t i = 1; i < 65536; i++) block2[i] = block2[i - 1] * _ % mod;
  }

  Tp &&get_base() { return std::move(base); }
  uint32_t &&get_mod() { return std::move(mod); }

  Tp operator()(std::make_unsigned_t<Tp> &&exponent) {
    return block1[exponent & 65535] * block2[exponent >> 16] % mod;
  }
};
