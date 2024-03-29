namespace TexasHoldemPoker {
constexpr int bsr(int a) { return 31 - __builtin_clz(a); }
// Returns the submask containing highest k bits set
// Returns -1 instead if popcnt(a) < k
constexpr int hbits(int a, int k) {
  int b = 0;
  for (int i = 0; i < k; ++i) {
    if (!a) return -1;
    a &= ~(b |= 1 << bsr(a));
  }
  return b;
}
class Card {
protected:
  int data = 0;

public:
  constexpr static char RANKS[16] = "0123456789TJQKA";
  constexpr static char SUITS[5] = "CDHS";
  Card() = default;
  Card(char rank, char suit) { encode(rank, suit); }
  explicit Card(const std::string &str): Card(str[0], str[1]) {
    assert(str.size() == 2);
  }
  // Parses a card in a format as "2C"
  // @return: 4 * (rank - 2) + suit  (2 <= rank <= 14)
  constexpr void encode(char rank, char suit) {
    int r = 2, s = 0;
    for (; r < 15; ++r)
      if (RANKS[r] == rank) break;
    assert(r < 15);
    for (; s < 4; ++s)
      if (SUITS[s] == suit) break;
    assert(s < 4);
    data = (r - 2) << 2 | s;
  }
  constexpr int get_rank() const { return (data >> 2) + 2; }
  constexpr int get_suit() const { return data & 3; }
  // @return: {rank_char, suit_char}
  constexpr std::pair<char, char> decode() const {
    return {RANKS[get_rank()], SUITS[get_suit()]};
  }
  friend std::istream &operator>>(std::istream &is, Card &card) {
    char rk, st;
    is >> rk >> st;
    card.encode(rk, st);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Card &card) {
    auto &&_ = card.decode();
    return os << _.first << _.second;
  }
};
enum Category {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH
};
constexpr static char CATEGORY_STR[9][20] = {"HIGH_CARD",
                                             "ONE_PAIR",
                                             "TWO_PAIR",
                                             "THREE_OF_A_KIND",
                                             "STRAIGHT",
                                             "FLUSH",
                                             "FULL_HOUSE",
                                             "FOUR_OF_A_KIND",
                                             "STRAIGHT_FLUSH"};
class Hand {
protected:
  std::vector<Card> cds;
  // ranks for all
  int rka = 0;
  // suit -> rank
  int mps[4] = {};
  // rank -> count
  int cnt[15] = {};
  // count -> rank
  int mpc[5] = {};

public:
  Hand() = default;
  // Set first 5 element as hand _
  Hand &reset(const std::vector<Card> &_) {
    assert(_.size() >= 5);
    cds.clear();
    for (size_t i = 0; i < 5; ++i) cds.push_back(_[i]);
    for (auto &&card : cds) {
      auto r = card.get_rank(), s = card.get_suit();
      rka |= mps[s] |= 1 << r;
      ++cnt[r];
    }
    for (int r = 2; r < 15; ++r) mpc[cnt[r]] |= 1 << r;
    return *this;
  }
  // Returns the best poker hand with the tie-breaker in [0, 2^20)
  std::pair<Category, int> parse() const {
    assert(cds.size() == 5);
    //! The judger of all the categories
    const static std::function<std::tuple<bool, Category, int>(const Hand &)>
      checks[8] = {
        // 8. STRAIGHT_FLUSH: highest (5 for A2345)
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          int f = 0;
          for (int s = 0; s < 4; ++s)
            f |= h.mps[s] & h.mps[s] << 1 & h.mps[s] << 2 & h.mps[s] << 3 &
                 (h.mps[s] << 4 | h.mps[s] >> 14 << 5);
          return {!!f, STRAIGHT_FLUSH, bsr(f)};
        },
        // 7. FOUR_OF_A_KIND: quadruple, other card
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          if (!h.mpc[4]) return {false, FOUR_OF_A_KIND, 0};
          const int r4 = bsr(h.mpc[4]);
          return {true, FOUR_OF_A_KIND, r4 << 4 | bsr(h.rka ^ 1 << r4)};
        },
        // 6. FULL_HOUSE: triple, pair
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          if (!h.mpc[3]) return {false, FULL_HOUSE, 0};
          const int r3 = bsr(h.mpc[3]), d = (h.mpc[3] ^ 1 << r3) | h.mpc[2];
          if (!d) return {false, FULL_HOUSE, 1};
          const int r2 = bsr(d);
          return {true, FULL_HOUSE, r3 << 4 | r2};
        },
        // 5. FLUSH: 5 highest cards
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          int flush = -1;
          for (int s = 0, _; s < 4; ++s)
            if (flush < (_ = hbits(h.mps[s], 5))) flush = _;
          return {flush >= 0, FLUSH, flush};
        },
        // 4. STRAIGHT: highest (5 for A2345)
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          const int f = h.rka & h.rka << 1 & h.rka << 2 & h.rka << 3 &
                        (h.rka << 4 | h.rka >> 14 << 5);
          return {!!f, STRAIGHT, bsr(f)};
        },
        // 3. THREE_OF_A_KIND: triple, 2 highest other cards
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          if (!h.mpc[3]) return {false, THREE_OF_A_KIND, 0};
          const int r3 = bsr(h.mpc[3]);
          return {true, THREE_OF_A_KIND, r3 << 16 | hbits(h.rka ^ 1 << r3, 2)};
        },
        // 2. TWO_PAIR: larger pair, smaller pair, other card
        // 1. ONE_PAIR: pair, 3 highest other cards
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          if (!h.mpc[2]) return {false, ONE_PAIR, 0};
          const int r2 = bsr(h.mpc[2]);
          const int d = h.mpc[2] ^ 1 << r2;
          if (!d) return {true, ONE_PAIR, r2 << 16 | hbits(h.rka ^ 1 << r2, 3)};
          const int r22 = bsr(d);
          return {true,
                  TWO_PAIR,
                  r2 << 8 | r22 << 4 | bsr(h.rka ^ 1 << r2 ^ 1 << r22)};
        },
        // 0. HIGH_CARD: 5 highest cards
        [](const Hand &h) -> std::tuple<bool, Category, int> {
          return {true, HIGH_CARD, hbits(h.rka, 5)};
        }};
    for (auto &&func : checks) {
      auto ret = func(*this);
      if (std::get<0>(ret)) return {std::get<1>(ret), std::get<2>(ret)};
    }
    //? Should be never reached
    exit(114);
  }
  friend std::ostream &operator<<(std::ostream &os, const Hand &hands) {
    for (size_t i = 0; i < 5 - 1; ++i) os << hands.cds[i] << ' ';
    return os << hands.cds[5 - 1];
  }
};
}  // namespace TexasHoldemPoker
using TexasHoldemPoker::Card;
using TexasHoldemPoker::Category;
using TexasHoldemPoker::Hand;