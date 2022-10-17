/**
 *  @brief Perform an operation on a sequence.
 *  @ingroup mutating_algorithms
 *  @param  __first     An input iterator.
 *  @param  __last      An input iterator.
 *  @param  __result    An output iterator.
 *  @param  __unary_op  A unary operator.
 *  @return   An output iterator equal to @p __result+(__last-__first).
 *
 *  Applies the operator to each element in the input range and assigns
 *  the results to successive elements of the output sequence.
 *  Evaluates @p *(__result+N)=unary_op(*(__first+N)) for each @c N in the
 *  range @p [0,__last-__first).
 *
 *  @p unary_op must not alter its argument.
 */
template <typename _InputIterator,
          typename _OutputIterator,
          typename _UnaryOperation>
_OutputIterator transform(_InputIterator __first,
                          _InputIterator __last,
                          _OutputIterator __result,
                          _UnaryOperation __unary_op);
