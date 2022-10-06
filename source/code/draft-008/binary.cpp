/**
 *  @brief Perform an operation on corresponding elements of two sequences.
 *  @ingroup mutating_algorithms
 *  @param  __first1     An input iterator.
 *  @param  __last1      An input iterator.
 *  @param  __first2     An input iterator.
 *  @param  __result     An output iterator.
 *  @param  __binary_op  A binary operator.
 *  @return   An output iterator equal to @p result+(last-first).
 *
 *  Applies the operator to the corresponding elements in the two
 *  input ranges and assigns the results to successive elements of the
 *  output sequence.
 *  Evaluates @p
 *  *(__result+N)=__binary_op(*(__first1+N),*(__first2+N)) for each
 *  @c N in the range @p [0,__last1-__first1).
 *
 *  @p binary_op must not alter either of its arguments.
 */
template <typename _InputIterator1, typename _InputIterator2, typename _OutputIterator, typename _BinaryOperation>
_OutputIterator
transform(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _OutputIterator __result, _BinaryOperation __binary_op);
