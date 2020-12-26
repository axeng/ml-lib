/**
 ** @file tests/unit_tests/utils/statistic_utils.hh
 ** @brief Declaration of some statistic utils function for unit tests
 */

#pragma once

#include <cstddef>
#include <initializer_list>

namespace tests::unit_tests
{
    /** @brief Compute the sum of a data set
     ** @param values The data set
     ** @return The sum
     */
    float compute_sum(std::initializer_list<float> values);

    /** @brief Compute the min of a data set
     ** @param values The data set
     ** @return The min
     */
    float compute_min(std::initializer_list<float> values);

    /** @brief Compute the max of a data set
     ** @param values The data set
     ** @return The max
     */
    float compute_max(std::initializer_list<float> values);

    /** @brief Compute the mean of a data set
     ** @param values The data set
     ** @return The mean
     */
    float compute_mean(std::initializer_list<float> values);

    /** @brief Compute the median of a data set
     ** @param values The data set
     ** @return The median
     */
    float compute_median(std::initializer_list<float> values);

    /** @brief Compute the variance of a data set
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @param values The data set
     ** @return The variance
     */
    float compute_variance(size_t ddof, std::initializer_list<float> values);

    /** @brief Compute the standard deviation of a data set
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @param values The data set
     ** @return The standard deviation
     */
    float compute_standard_deviation(size_t ddof, std::initializer_list<float> values);

    /** @brief Compute the sum-product of a data set
     ** @param values The data set
     ** @return The sum-product
     */
    float compute_sum_product(std::initializer_list<float> values);

    /** @brief Compute the peak to peak of a data set
     ** @param values The data set
     ** @return The peak to peak
     */
    float compute_peak_to_peak(std::initializer_list<float> values);
} // namespace tests::unit_tests

#include "unit_tests/utils/statistic_utils.hxx"
