/**
 ** @file tests/unit_tests/computation/statistic.hh
 ** @brief Declarations for statistic computation tests functions of ml::computation::statistic
 */

#pragma once

#include <vector>

#include "gtest/gtest.h"

namespace tests::unit_tests
{
    /// Sum Statistic Computation functor-like class
    class ComputationSumStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The sum
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Mean Statistic Computation functor-like class
    class ComputationMeanStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The mean
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The mean
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Median Statistic Computation functor-like class
    class ComputationMedianStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The median
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The median
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Variance Statistic Computation functor-like class
    template <size_t DDOF>
    class ComputationVarianceStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The variance
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The variance
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Standard Deviation Statistic Computation functor-like class
    template <size_t DDOF>
    class ComputationStandardDeviationStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The standard deviation
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The standard deviation
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Sum Product Statistic Computation functor-like class
    class ComputationSumProductStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The sum-product
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum-product
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Peak to Peak Statistic Computation functor-like class
    class ComputationPeakToPeakStatistic
    {
    public:
        /** @brief Function to test
         ** @param data Data to do the computation on
         ** @return The peak-to-peak
         */
        static float function(const std::vector<float>& data);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The peak-to-peak
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Computation statistic fixture class
    template <class Statistic>
    class ComputationStatistic : public testing::Test
    {};

    /// Functor-class list to use for the statistics computation tests
    using ComputationStatisticTypes = ::testing::Types<ComputationSumStatistic,
                                                       ComputationMeanStatistic,
                                                       ComputationMedianStatistic,
                                                       ComputationVarianceStatistic<0>,
                                                       ComputationStandardDeviationStatistic<0>,
                                                       ComputationVarianceStatistic<1>,
                                                       ComputationStandardDeviationStatistic<1>,
                                                       ComputationSumProductStatistic,
                                                       ComputationPeakToPeakStatistic>;

} // namespace tests::unit_tests

#include "unit_tests/computation/statistic.hxx"
