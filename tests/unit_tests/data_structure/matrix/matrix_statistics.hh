/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_statistics.hh
 ** @brief Declaration for statistic operation functions tests of ml::data_structure::matrix::Matrix
 */

#pragma once

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    /// Sum Statistic functor-like class
    class MatrixSumStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Sum Statistic shortcut functor-like class
    class MatrixSumStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Min Statistic functor-like class
    class MatrixMinStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The min
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Min Statistic shortcut functor-like class
    class MatrixMinStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The min matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The min
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Max Statistic functor-like class
    class MatrixMaxStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The max
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Max Statistic shortcut functor-like class
    class MatrixMaxStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The max matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The max
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Mean Statistic functor-like class
    class MatrixMeanStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The mean
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Mean Statistic shortcut functor-like class
    class MatrixMeanStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The mean matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The mean
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Median Statistic functor-like class
    class MatrixMedianStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The median
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Median Statistic shortcut functor-like class
    class MatrixMedianStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The median matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The median
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Variance Statistic functor-like class
    template <size_t DDOF>
    class MatrixVarianceStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The variance
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Variance Statistic shortcut functor-like class
    template <size_t DDOF>
    class MatrixVarianceStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The variance matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The variance
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Standard Deviation Statistic functor-like class
    template <size_t DDOF>
    class MatrixStandardDeviationStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The standard deviation
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Standard Deviation Statistic shortcut functor-like class
    template <size_t DDOF>
    class MatrixStandardDeviationStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The standard deviation matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The standard deviation
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Sum Product Statistic functor-like class
    class MatrixSumProductStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum-product
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Sum Product Statistic shortcut functor-like class
    class MatrixSumProductStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The sum-product matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The sum-product
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Peak to Peak Statistic functor-like class
    class MatrixPeakToPeakStatistic
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The peak to peak
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Peak to Peak Statistic shortcut functor-like class
    class MatrixPeakToPeakStatisticShortcut
    {
    public:
        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak
         */
        template <typename MATRIX_T>
        static auto function(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak matrix
         */
        template <typename MATRIX_T>
        static auto function_columns(const MATRIX_T& matrix);

        /** @brief Function to test
         ** @param matrix Matrix to compute the statistic from
         ** @return The peak to peak matrix
         */
        template <typename MATRIX_T>
        static auto function_rows(const MATRIX_T& matrix);

        /** @brief The reference function
         ** @param values The values to use for the computation
         ** @return The peak to peak
         */
        static float test_function(std::initializer_list<float> values);
    };

    /// Matrix Statistic fixture class
    template <class Statistic>
    class DataStructureMatrixStatistic : public testing::Test
    {};

    /// Functor-class list to use for matrix statistics tests
    using MatrixStatisticTypes = ::testing::Types<MatrixSumStatistic,
                                                  MatrixSumStatisticShortcut,
                                                  MatrixMinStatistic,
                                                  MatrixMinStatisticShortcut,
                                                  MatrixMaxStatistic,
                                                  MatrixMaxStatisticShortcut,
                                                  MatrixMeanStatistic,
                                                  MatrixMeanStatisticShortcut,
                                                  MatrixMedianStatistic,
                                                  MatrixMedianStatisticShortcut,
                                                  MatrixVarianceStatistic<0>,
                                                  MatrixVarianceStatisticShortcut<0>,
                                                  MatrixStandardDeviationStatistic<0>,
                                                  MatrixStandardDeviationStatisticShortcut<0>,
                                                  MatrixVarianceStatistic<1>,
                                                  MatrixVarianceStatisticShortcut<1>,
                                                  MatrixStandardDeviationStatistic<1>,
                                                  MatrixStandardDeviationStatisticShortcut<1>,
                                                  MatrixSumProductStatistic,
                                                  MatrixSumProductStatisticShortcut,
                                                  MatrixPeakToPeakStatistic,
                                                  MatrixPeakToPeakStatisticShortcut>;
} // namespace tests::unit_tests

#include "unit_tests/data_structure/matrix/matrix_statistics.hxx"
