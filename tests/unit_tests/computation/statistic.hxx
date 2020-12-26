/**
 ** @file tests/unit_tests/computation/statistic.hxx
 ** @brief Implementation of templated and inline functions for statistic computation tests ml::computation::statistic
 */

#include "computation/statistic.hh"
#include "unit_tests/utils/statistic_utils.hh"

namespace tests::unit_tests
{
    float ComputationSumStatistic::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::sum(data.cbegin(), data.cend());
    }

    float ComputationSumStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_sum(values);
    }

    float ComputationMeanStatistic::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::mean(data.cbegin(), data.cend());
    }

    float ComputationMeanStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_mean(values);
    }

    float ComputationMedianStatistic::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::median(data.cbegin(), data.cend());
    }

    float ComputationMedianStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_median(values);
    }

    template <size_t DDOF>
    float ComputationVarianceStatistic<DDOF>::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::variance(data.cbegin(), data.cend(), DDOF);
    }

    template <size_t DDOF>
    float ComputationVarianceStatistic<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_variance(DDOF, values);
    }

    template <size_t DDOF>
    float ComputationStandardDeviationStatistic<DDOF>::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::standard_deviation(data.cbegin(), data.cend(), DDOF);
    }

    template <size_t DDOF>
    float ComputationStandardDeviationStatistic<DDOF>::test_function(std::initializer_list<float> values)
    {
        return compute_standard_deviation(DDOF, values);
    }

    float ComputationSumProductStatistic::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::sum_product(data.cbegin(), data.cend());
    }

    float ComputationSumProductStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_sum_product(values);
    }

    float ComputationPeakToPeakStatistic::function(const std::vector<float>& data)
    {
        return ml::computation::statistic::peak_to_peak(data.cbegin(), data.cend());
    }

    float ComputationPeakToPeakStatistic::test_function(std::initializer_list<float> values)
    {
        return compute_peak_to_peak(values);
    }
} // namespace tests::unit_tests
