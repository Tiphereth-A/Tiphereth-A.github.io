namespace fast_io {
namespace type_traits {
template <class Tp>
inline constexpr bool is_char_v = std::is_same_v<Tp, char> || std::is_same_v<Tp, signed char> || std::is_same_v<Tp, unsigned char>;
template <class Tp>
inline constexpr bool is_int_v = (std::is_integral_v<Tp> && std::is_signed_v<Tp> && !is_char_v<Tp>) || std::is_same_v<Tp, __int128_t>;
template <class Tp>
inline constexpr bool is_uint_v = (std::is_integral_v<Tp> && std::is_unsigned_v<Tp> && !is_char_v<Tp>) || std::is_same_v<Tp, __uint128_t>;
template <class Tp>
using make_uint_t = typename std::conditional_t<(std::is_same_v<Tp, __int128_t> || std::is_same_v<Tp, __uint128_t>), std::common_type<__uint128_t>, typename std::conditional_t<std::is_signed_v<Tp>, std::make_unsigned<Tp>, std::common_type<Tp>>>::type;
}  // namespace type_traits

//! Will enter a dead loop if EOF occured during reading
template <size_t BUFFER_SIZE>
class FastIn {
    using self = FastIn<BUFFER_SIZE>;

  protected:
    char buffer_[BUFFER_SIZE], *now_ = buffer_, *end_ = buffer_;
    FILE *file_;

  public:
    explicit FastIn(FILE *file = stdin): file_(file) {}

    inline char fetch() { return now_ == end_ && (end_ = (now_ = buffer_) + fread(buffer_, 1, BUFFER_SIZE, file_), now_ == end_) ? EOF : *(now_)++; }
    inline char visit() { return now_ == end_ && (end_ = (now_ = buffer_) + fread(buffer_, 1, BUFFER_SIZE, file_), now_ == end_) ? EOF : *(now_); }
    inline void set_file(FILE *file) {
        file_ = file;
        now_ = end_ = buffer_;
    }
    inline bool iseof() { return visit() == EOF; }

    template <class Tp, std::enable_if_t<type_traits::is_int_v<Tp>> * = nullptr>
    inline self &read(Tp &n) {
        bool is_neg = false;
        char ch = fetch();
        while (!isdigit(ch)) {
            is_neg |= ch == '-';
            ch = fetch();
        }
        n = 0;
        while (isdigit(ch)) {
            (n *= 10) += ch & 0x0f;
            ch = fetch();
        }
        if (is_neg) n = -n;
        return *this;
    }
    template <class Tp, std::enable_if_t<type_traits::is_uint_v<Tp>> * = nullptr>
    inline self &read(Tp &n) {
        char ch = fetch();
        while (!isdigit(ch)) ch = fetch();
        n = 0;
        while (isdigit(ch)) {
            (n *= 10) += ch & 0x0f;
            ch = fetch();
        }
        return *this;
    }
    //! ignore cntrl and space
    template <class Tp, std::enable_if_t<type_traits::is_char_v<Tp>> * = nullptr>
    inline self &read(Tp &n) {
        while (!isgraph(n = fetch()))
            ;
        return *this;
    }
    inline self &read(char *n) {
        char *n_ = n;
        while (!isgraph(*n_ = fetch()))
            ;
        while (isgraph(*(++n_) = fetch()))
            ;
        *n_ = '\0';
        return *this;
    }
    inline self &read(std::string &n) {
        n.clear();
        char n_;
        while (!isgraph(n_ = fetch()))
            ;
        n.push_back(n_);
        while (isgraph(n_ = fetch())) n.push_back(n_);
        return *this;
    }
    template <class Tp, class Up>
    inline self &read(std::pair<Tp, Up> &p) { return read(p.first).read(p.second); }
    template <typename... Ts>
    inline self &read(std::tuple<Ts...> &p) {
        std::apply([&](Ts &...targs) { ((read(targs)), ...); }, p);
        return *this;
    }

    inline self &getline(char *n) {
        char *n_ = n;
        while (!isprint(*n_ = fetch()))
            ;
        while (isprint(*(++n_) = fetch()))
            ;
        *n_ = '\0';
        return *this;
    }
    inline self &getline(std::string &n) {
        char n_;
        while (!isprint(n_ = fetch()))
            ;
        n.push_back(n_);
        while (isprint(n_ = fetch())) n.push_back(n_);
        return *this;
    }

    //! NOT ignore cntrl and space
    template <class Tp, std::enable_if_t<type_traits::is_char_v<Tp>> * = nullptr>
    inline self &strict_read(Tp &n) {
        n = fetch();
        return *this;
    }

    template <class Tp>
    self &operator>>(Tp &val) { return read(val); }
};

template <size_t BUFFER_SIZE, size_t INT_BUFFER_SIZE>
class FastOut {
    using self = FastOut<BUFFER_SIZE, INT_BUFFER_SIZE>;

  private:
    char int_buffer_[INT_BUFFER_SIZE], *now_ib_ = int_buffer_;

  protected:
    FILE *file_;
    char *now_, buffer_[BUFFER_SIZE];
    const char * const end_ = buffer_ + BUFFER_SIZE;

  public:
    explicit FastOut(FILE *file = stdout): file_(file), now_(buffer_) {}

    self &operator=(const self &rhs) {
        file_ = rhs.file_;
        now_ = buffer_ + (rhs.now_ - rhs.buffer_);
        memcpy(buffer_, rhs.buffer_, sizeof(*buffer_) * (rhs.now_ - rhs.buffer_));
        return *this;
    }
    FastOut(const self &rhs) { *this = rhs; }

    ~FastOut() { flush(); }

    inline void flush() {
        fwrite(buffer_, 1, now_ - buffer_, file_);
        now_ = buffer_;
    }
    inline void rebind(FILE *file) { file_ = file; }

    template <class Tp, std::enable_if_t<type_traits::is_char_v<Tp>> * = nullptr>
    inline self &write(const Tp &n) {
        if (now_ == end_) flush();
        *(now_++) = n;
        return *this;
    }
    inline self &write(const char *n) {
        size_t len = strlen(n), l_;
        const char *n_ = n;
        while (now_ + len >= end_) {
            l_ = end_ - now_;
            memcpy(now_, n_, l_);
            now_ += l_;
            n_ += l_;
            len -= l_;
            flush();
        }
        memcpy(now_, n_, len);
        now_ += len;
        return *this;
    }
    template <class Tp, std::enable_if_t<type_traits::is_int_v<Tp>> * = nullptr>
    inline self &write(Tp n) {
        if (n < 0) {
            write('-');
            n = -n;
        }
        return write(static_cast<typename type_traits::make_uint_t<Tp>>(n));
    }
    template <class Tp, std::enable_if_t<type_traits::is_uint_v<Tp>> * = nullptr>
    inline self &write(Tp n) {
        now_ib_ = int_buffer_ + INT_BUFFER_SIZE - 1;
        do { *(--(now_ib_)) = char(n % 10) | '0'; } while (n /= 10);
        return write(now_ib_);
    }
    inline self &write(const std::string &str) { return write(str.c_str()); }
    template <class Tp, class Up>
    inline self &write(const std::pair<Tp, Up> &p) { return write(p.first).space().write(p.second); }
    template <typename... Ts>
    inline self &write(const std::tuple<Ts...> &p) {
        std::apply(
            [&](Ts const &...targs) {
                std::size_t n{0};
                ((write(targs).space_if(++n != sizeof...(Ts))), ...);
            },
            p);
        return *this;
    }

    inline self &linebreak() { return write('\n'); }
    inline self &linebreak_if(bool flag) { return flag ? linebreak() : *this; }
    inline self &space() { return write(' '); }
    inline self &space_if(bool flag) { return flag ? space() : *this; }

    template <class Tp>
    self &operator<<(const Tp &val) { return write(val); }
};

const std::size_t BUFFER_SIZE = (1 << 21) + 5;
FastIn<BUFFER_SIZE> fastin;
FastOut<BUFFER_SIZE, 21> fastout;
}  // namespace fast_io
using fast_io::fastin;
using fast_io::fastout;
