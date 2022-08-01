#ifndef TUPLE_SUB_HPP_
#define TUPLE_SUB_HPP_

#include <tuple>
#include <type_traits>


#define TPL_SIZE_(Tuple) std::tuple_size_v<std::remove_reference_t<Tuple>>


template <std::size_t Begin, class Tuple, std::size_t... Is>
constexpr auto subtuple_impl_(Tuple &&t, std::index_sequence<Is...>) {
    return std::make_tuple(std::get<Is + Begin>(t)...);
}

template <std::size_t Begin, std::size_t Len, class Tuple>
constexpr auto subtuple(Tuple &&t) {
    static_assert(Begin <= TPL_SIZE_(Tuple) && Len <= TPL_SIZE_(Tuple) && Begin + Len <= TPL_SIZE_(Tuple), "Out of range");

    return subtuple_impl_<Begin>(t, std::make_index_sequence<Len>());
}


template <std::size_t Pos, class Tp, class Tuple>
constexpr auto tuple_push(Tp &&v, Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");

    return std::tuple_cat(subtuple<0, Pos>(t), std::make_tuple(v), subtuple<Pos, TPL_SIZE_(Tuple) - Pos>(t));
}

template <class Tp, class Tuple>
constexpr auto tuple_push_front(Tp &&v, Tuple &&t) {
    return tuple_push<0>(v, t);
}

template <class Tp, class Tuple>
constexpr auto tuple_push_back(Tp &&v, Tuple &&t) {
    return tuple_push<TPL_SIZE_(Tuple)>(v, t);
}


template <std::size_t Pos, class Tuple>
constexpr auto tuple_pop(Tuple &&t) {
    static_assert(TPL_SIZE_(Tuple) > 0, "Pop from empty tuple");

    return std::tuple_cat(subtuple<0, Pos>(t), subtuple<Pos + 1, TPL_SIZE_(Tuple) - Pos - 1>(t));
}

template <class Tuple>
constexpr auto tuple_pop_front(Tuple &&t) {
    return tuple_pop<0>(t);
}

template <class Tuple>
constexpr auto tuple_pop_back(Tuple &&t) {
    return tuple_pop<TPL_SIZE_(Tuple) - 1>(t);
}


#undef TPL_SIZE_


#endif