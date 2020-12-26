/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_statistics.hxx
 ** @brief Implementation of templated and inline functions for statistic operation tests of
 **ml::data_structure::matrix::Matrix
 */

#include "unit_tests/utils/statistic_utils.hh"

namespace tests::unit_tests
{
    template <typename MATRIX_T>
    inline auto MatrixSumStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum_rows(matrix);
    }

    inline float MatrixSumStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_sum(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.sum();
    }

    template <typename MATRIX_T>
    inline auto MatrixSumStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.sum_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixSumStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.sum_rows();
    }

    inline float MatrixSumStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_sum(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::min(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::min_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::min_rows(matrix);
    }

    inline float MatrixMinStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_min(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.min();
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.min_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixMinStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.min_rows();
    }

    inline float MatrixMinStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_min(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::max(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::max_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::max_rows(matrix);
    }

    inline float MatrixMaxStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_max(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.max();
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.max_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixMaxStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.max_rows();
    }

    inline float MatrixMaxStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_max(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::mean(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::mean_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::mean_rows(matrix);
    }

    inline float MatrixMeanStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_mean(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.mean();
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.mean_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixMeanStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.mean_rows();
    }

    inline float MatrixMeanStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_mean(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::median(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::median_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::median_rows(matrix);
    }

    inline float MatrixMedianStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_median(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.median();
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.median_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixMedianStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.median_rows();
    }

    inline float MatrixMedianStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_median(values);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatistic<DDOF>::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::variance(matrix, DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatistic<DDOF>::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::variance_columns(matrix, DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatistic<DDOF>::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::variance_rows(matrix, DDOF);
    }

    template <size_t DDOF>
    inline float MatrixVarianceStatistic<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_variance(DDOF, values);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatisticShortcut<DDOF>::function(const MATRIX_T& matrix)
    {
        return matrix.variance(DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatisticShortcut<DDOF>::function_columns(const MATRIX_T& matrix)
    {
        return matrix.variance_columns(DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixVarianceStatisticShortcut<DDOF>::function_rows(const MATRIX_T& matrix)
    {
        return matrix.variance_rows(DDOF);
    }

    template <size_t DDOF>
    inline float MatrixVarianceStatisticShortcut<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_variance(DDOF, values);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatistic<DDOF>::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::standard_deviation(matrix, DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatistic<DDOF>::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::standard_deviation_columns(matrix, DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatistic<DDOF>::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::standard_deviation_rows(matrix, DDOF);
    }

    template <size_t DDOF>
    inline float MatrixStandardDeviationStatistic<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_standard_deviation(DDOF, values);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatisticShortcut<DDOF>::function(const MATRIX_T& matrix)
    {
        return matrix.standard_deviation(DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatisticShortcut<DDOF>::function_columns(const MATRIX_T& matrix)
    {
        return matrix.standard_deviation_columns(DDOF);
    }

    template <size_t DDOF>
    template <typename MATRIX_T>
    inline auto MatrixStandardDeviationStatisticShortcut<DDOF>::function_rows(const MATRIX_T& matrix)
    {
        return matrix.standard_deviation_rows(DDOF);
    }

    template <size_t DDOF>
    inline float MatrixStandardDeviationStatisticShortcut<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_standard_deviation(DDOF, values);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum_product(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum_product_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::sum_product_rows(matrix);
    }

    inline float MatrixSumProductStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_sum_product(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.sum_product();
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.sum_product_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixSumProductStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.sum_product_rows();
    }

    inline float MatrixSumProductStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_sum_product(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatistic::function(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::peak_to_peak(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatistic::function_columns(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::peak_to_peak_columns(matrix);
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatistic::function_rows(const MATRIX_T& matrix)
    {
        return ml::data_structure::matrix::peak_to_peak_rows(matrix);
    }

    inline float MatrixPeakToPeakStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_peak_to_peak(values);
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatisticShortcut::function(const MATRIX_T& matrix)
    {
        return matrix.peak_to_peak();
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatisticShortcut::function_columns(const MATRIX_T& matrix)
    {
        return matrix.peak_to_peak_columns();
    }

    template <typename MATRIX_T>
    inline auto MatrixPeakToPeakStatisticShortcut::function_rows(const MATRIX_T& matrix)
    {
        return matrix.peak_to_peak_rows();
    }

    inline float MatrixPeakToPeakStatisticShortcut::test_function(std::initializer_list<float> values)
    {
        return compute_peak_to_peak(values);
    }
} // namespace tests::unit_tests
