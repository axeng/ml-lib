/**
 ** @file src/computation/statistic.hxx
 ** @brief Implementation of ml::computation::statistic templated functions
 */

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace ml::computation::statistic
{
    template <class Iterator, typename DATA_TYPE>
    inline DATA_TYPE sum(const Iterator& begin, const Iterator& end)
    {
        return std::accumulate<Iterator, DATA_TYPE>(begin, end, 0);
    }

    template <class Iterator, typename DATA_TYPE>
    DATA_TYPE mean(const Iterator& begin, const Iterator& end)
    {
        auto mean = ml::computation::statistic::sum(begin, end);
        auto count = end - begin;

        mean /= count;
        return mean;
    }

    template <class Iterator, typename DATA_TYPE>
    DATA_TYPE median(const Iterator& begin, const Iterator& end)
    {
        auto count = end - begin;

        std::vector<DATA_TYPE> data(count);
        size_t i = 0;
        for (auto it = begin; it < end; ++it)
            data[i++] = *it;

        if (count > 2)
            std::sort(data.begin(), data.end());

        auto mid = count / 2;

        if (count % 2 == 0)
        {
            auto median = data[mid - 1];
            median += data[mid];
            median /= 2;
            return median;
        }

        return data[mid];
    }

    template <class Iterator, typename DATA_TYPE>
    DATA_TYPE variance(const Iterator& begin, const Iterator& end, size_t ddof)
    {
        auto mean = ml::computation::statistic::sum(begin, end);
        auto count = end - begin;
        mean /= count;

        DATA_TYPE error_sum = 0;

        for (auto it = begin; it < end; ++it)
            error_sum += std::pow(*it - mean, 2);

        count -= ddof;
        error_sum /= count;
        return error_sum;
    }

    template <class Iterator, typename DATA_TYPE>
    inline DATA_TYPE standard_deviation(const Iterator& begin, const Iterator& end, size_t ddof)
    {
        auto variance = ml::computation::statistic::variance(begin, end, ddof);
        return std::sqrt(variance);
    }

    template <class Iterator, typename DATA_TYPE>
    inline DATA_TYPE sum_product(const Iterator& begin, const Iterator& end)
    {
        return std::accumulate<Iterator, DATA_TYPE>(begin, end, 1, std::multiplies<DATA_TYPE>());
    }

    template <class Iterator, typename DATA_TYPE>
    inline DATA_TYPE peak_to_peak(const Iterator& begin, const Iterator& end)
    {
        const auto [min, max] = std::minmax_element(begin, end);
        return *max - *min;
    }
} // namespace ml::computation::statistic
