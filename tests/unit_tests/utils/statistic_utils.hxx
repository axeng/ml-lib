/**
 ** @file tests/unit_tests/utils/statistic_utils.cc
 ** @brief Implementation of some statistic utils function for unit tests
 */

#include <algorithm>
#include <cmath>
#include <numeric>

namespace tests::unit_tests
{
    inline float compute_sum(std::initializer_list<float> values)
    {
        return std::accumulate(values.begin(), values.end(), 0.0f);
    }

    inline float compute_min(std::initializer_list<float> values)
    {
        return std::min(values);
    }

    inline float compute_max(std::initializer_list<float> values)
    {
        return std::max(values);
    }

    inline float compute_mean(std::initializer_list<float> values)
    {
        return compute_sum(values) / values.size();
    }

    inline float compute_median(std::initializer_list<float> values)
    {
        std::vector<float> data(values.size());
        for (size_t i = 0; i < values.size(); i++)
            data[i] = values.begin()[i];

        if (data.size() > 2)
            std::sort(data.begin(), data.end());

        auto mid = data.size() / 2;

        if (data.size() % 2 == 0)
            return (data.begin()[mid - 1] + data.begin()[mid]) / 2;

        return data.begin()[mid];
    }

    inline float compute_variance(size_t ddof, std::initializer_list<float> values)
    {
        float mean_val = compute_mean(values);

        float error_sum = 0.0f;
        for (const auto& value : values)
            error_sum += std::pow(value - mean_val, 2);

        return error_sum / (float)(values.size() - ddof);
    }

    inline float compute_standard_deviation(size_t ddof, std::initializer_list<float> values)
    {
        return std::sqrt(compute_variance(ddof, values));
    }

    inline float compute_sum_product(std::initializer_list<float> values)
    {
        return std::accumulate(values.begin(), values.end(), 1.0f, std::multiplies<float>{});
    }

    inline float compute_peak_to_peak(std::initializer_list<float> values)
    {
        const auto [min, max] = std::minmax_element(values.begin(), values.end());
        return *max - *min;
    }
} // namespace tests::unit_tests
