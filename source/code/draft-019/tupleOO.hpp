#ifndef TUPLE_OO_HPP_
#define TUPLE_OO_HPP_

#include <tuple>
#include <type_traits>


#define TPL_SIZE_(Tuple) std::tuple_size_v<std::remove_reference_t<Tuple>>


template <class Tuple, class BinOp, std::size_t... Is>
constexpr auto apply2_impl_(BinOp &&f, Tuple &&lhs, Tuple &&rhs, std::index_sequence<Is...>) {
    return std::make_tuple(std::forward<BinOp>(f)(std::get<Is>(lhs), std::get<Is>(rhs))...);
}

template <class Tuple, class BinOp>
constexpr auto apply2(BinOp &&f, Tuple &&lhs, Tuple &&rhs) {
    return apply2_impl_(f, lhs, rhs, std::make_index_sequence<TPL_SIZE_(Tuple)>());
}


#define OO_TUPLE_(oper)                                                                        \
    template <class... Ts>                                                                     \
    constexpr auto operator oper(std::tuple<Ts...> const &lhs, std::tuple<Ts...> const &rhs) { \
        return apply2([](auto &&l, auto &&r) { return l oper r; }, lhs, rhs);                  \
    }

#define OO_TUPLE_EQ_(op)   \
    OO_TUPLE_(op)          \
    template <class... Ts> \
    constexpr auto operator oper##=(std::tuple<Ts...> &lhs, const std::tuple<Ts...> &rhs) { return lhs = lhs oper rhs; }


OO_TUPLE_EQ_(+)
OO_TUPLE_EQ_(-)
OO_TUPLE_EQ_(*)
OO_TUPLE_EQ_(/)
OO_TUPLE_EQ_(%)
OO_TUPLE_EQ_(&)
OO_TUPLE_EQ_(|)
OO_TUPLE_EQ_(^)
OO_TUPLE_EQ_(<<)
OO_TUPLE_EQ_(>>)
OO_TUPLE_(==)
OO_TUPLE_(!=)
OO_TUPLE_(<)
OO_TUPLE_(<=)
OO_TUPLE_(>)
OO_TUPLE_(>=)


#undef OO_TUPLE_EQ_
#undef OO_TUPLE_
#undef TPL_SIZE_


#endif