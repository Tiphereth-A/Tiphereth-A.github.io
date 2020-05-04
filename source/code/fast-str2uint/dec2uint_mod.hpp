//! only works properly on little-endian CPU, such as Intel CPU
//! works better on 64-bit CPU
inline constexpr uint64_t dec2uint_mod(const char * const num,
                                       const uint64_t mod) {
  size_t len = strlen(num);
  if (len == 0) return 0;
  __uint128_t ans = 0;
  for (size_t i = 0; i + 8 <= len; i += 8) {
    uint64_t res = *((uint64_t *)(num + i));
    res = (res & 0x0F0F0F0F0F0F0F0F) * 2561 >> 8;
    res = (res & 0x00FF00FF00FF00FF) * 6553601 >> 16;
    res = (res & 0x0000FFFF0000FFFF) * 42949672960001 >> 32;
    ans = (ans * 100000000 + res) % mod;
  }
  for (auto pch = num + (len / 8 * 8); pch < num + len;)
    ans = (ans * 10 + (*(pch++) & '\x0f')) % mod;
  return ans;
}
