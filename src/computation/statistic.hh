/**
 ** @file src/computation/container/statistic.hh
 ** @brief Declaration of ml::computation::statistic functions
 */

#pragma once

#include <cstddef>
#include <iterator>

namespace ml::computation::statistic
{
    /** @brief Compute the sum of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @return The sum
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE sum(const Iterator& begin, const Iterator& end);

    /** @brief Compute the mean of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @return The mean
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE mean(const Iterator& begin, const Iterator& end);

    /** @brief Compute the median of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @return The median
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE median(const Iterator& begin, const Iterator& end);

    /** @brief Compute the variance of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The variance
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE variance(const Iterator& begin, const Iterator& end, size_t ddof = 0);

    /** @brief Compute the standard deviation of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The standard deviation
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE standard_deviation(const Iterator& begin, const Iterator& end, size_t ddof = 0);

    /** @brief Compute the sum-product of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @return The sum-product
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE sum_product(const Iterator& begin, const Iterator& end);

    /** @brief Compute the peak to peak of the container
     ** @param begin Begin iterator of the container
     ** @param end End iterator of the container
     ** @return The peak to peak
     */
    template <class Iterator, typename DATA_TYPE = typename std::iterator_traits<Iterator>::value_type>
    DATA_TYPE peak_to_peak(const Iterator& begin, const Iterator& end);
} // namespace ml::computation::statistic

#include "computation/statistic.hxx"
