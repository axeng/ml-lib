/**
 ** @file src/data_structure/matrix/matrix_statistics.hxx
 ** @brief Statistic functions implementations for ml::data_structure::matrix::Matrix
 */

#include "computation/statistic.hh"

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Function>
    static DATA_TYPE statistic(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, const Function& function)
    {
        return function(matrix.data().cbegin(), matrix.data().cend());
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Function>
    static Matrix<DATA_TYPE, 1, WIDTH> statistic_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                         const Function& function)
    {
        Matrix<DATA_TYPE, 1, WIDTH> row_matrix;

        for (size_t j = 0; j < WIDTH; j++)
        {
            auto first_it = matrix.data().cbegin() + j;
            auto last_it = matrix.data().cbegin() + j + (HEIGHT - 1) * WIDTH;
            typename Matrix<DATA_TYPE, HEIGHT, WIDTH>::column_const_step_iterator_t column_begin(
                first_it, first_it, last_it);
            typename Matrix<DATA_TYPE, HEIGHT, WIDTH>::column_const_step_iterator_t column_end(
                matrix.data().cend(), first_it, last_it);

            row_matrix(0, j) = function(column_begin, column_end);
        }

        return row_matrix;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Function>
    static Matrix<DATA_TYPE, HEIGHT, 1> statistic_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                       const Function& function)
    {
        Matrix<DATA_TYPE, HEIGHT, 1> column_matrix;

        for (size_t i = 0; i < HEIGHT; i++)
        {
            column_matrix(i, 0) =
                function(matrix.data().cbegin() + (i * WIDTH), matrix.data().cbegin() + ((i + 1) * WIDTH));
        }

        return column_matrix;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum() const
    {
        return ml::data_structure::matrix::sum(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE sum(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::sum(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum_columns() const
    {
        return ml::data_structure::matrix::sum_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> sum_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::sum(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum_rows() const
    {
        return ml::data_structure::matrix::sum_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> sum_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::sum(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::min() const
    {
        return ml::data_structure::matrix::min(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE min(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(matrix, [](const auto& begin, const auto& end) { return *std::min_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::min_columns() const
    {
        return ml::data_structure::matrix::min_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> min_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(matrix,
                                 [](const auto& begin, const auto& end) { return *std::min_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::min_rows() const
    {
        return ml::data_structure::matrix::min_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> min_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(matrix, [](const auto& begin, const auto& end) { return *std::min_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::max() const
    {
        return ml::data_structure::matrix::max(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE max(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(matrix, [](const auto& begin, const auto& end) { return *std::max_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::max_columns() const
    {
        return ml::data_structure::matrix::max_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> max_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(matrix,
                                 [](const auto& begin, const auto& end) { return *std::max_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::max_rows() const
    {
        return ml::data_structure::matrix::max_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> max_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(matrix, [](const auto& begin, const auto& end) { return *std::max_element(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::mean() const
    {
        return ml::data_structure::matrix::mean(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE mean(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::mean(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::mean_columns() const
    {
        return ml::data_structure::matrix::mean_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> mean_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::mean(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::mean_rows() const
    {
        return ml::data_structure::matrix::mean_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> mean_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::mean(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::median() const
    {
        return ml::data_structure::matrix::median(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE median(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::median(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::median_columns() const
    {
        return ml::data_structure::matrix::median_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> median_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::median(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::median_rows() const
    {
        return ml::data_structure::matrix::median_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> median_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(
            matrix, [](const auto& begin, const auto& end) { return ml::computation::statistic::median(begin, end); });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::variance(size_t ddof) const
    {
        return ml::data_structure::matrix::variance(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE variance(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof)
    {
        return statistic(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::variance(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::variance_columns(size_t ddof) const
    {
        return ml::data_structure::matrix::variance_columns(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> variance_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof)
    {
        return statistic_columns(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::variance(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::variance_rows(size_t ddof) const
    {
        return ml::data_structure::matrix::variance_rows(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> variance_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof)
    {
        return statistic_rows(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::variance(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::standard_deviation(size_t ddof) const
    {
        return ml::data_structure::matrix::standard_deviation(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE standard_deviation(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof)
    {
        return statistic(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::standard_deviation(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::standard_deviation_columns(size_t ddof) const
    {
        return ml::data_structure::matrix::standard_deviation_columns(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> standard_deviation_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                                  size_t ddof)
    {
        return statistic_columns(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::standard_deviation(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::standard_deviation_rows(size_t ddof) const
    {
        return ml::data_structure::matrix::standard_deviation_rows(*this, ddof);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> standard_deviation_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                                size_t ddof)
    {
        return statistic_rows(matrix, [ddof](const auto& begin, const auto& end) {
            return ml::computation::statistic::standard_deviation(begin, end, ddof);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum_product() const
    {
        return ml::data_structure::matrix::sum_product(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE sum_product(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::sum_product(begin, end);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum_product_columns() const
    {
        return ml::data_structure::matrix::sum_product_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> sum_product_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::sum_product(begin, end);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::sum_product_rows() const
    {
        return ml::data_structure::matrix::sum_product_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> sum_product_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::sum_product(begin, end);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE Matrix<DATA_TYPE, HEIGHT, WIDTH>::peak_to_peak() const
    {
        return ml::data_structure::matrix::peak_to_peak(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE peak_to_peak(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::peak_to_peak(begin, end);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::peak_to_peak_columns() const
    {
        return ml::data_structure::matrix::peak_to_peak_columns(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, 1, WIDTH> peak_to_peak_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_columns(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::peak_to_peak(begin, end);
        });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> Matrix<DATA_TYPE, HEIGHT, WIDTH>::peak_to_peak_rows() const
    {
        return ml::data_structure::matrix::peak_to_peak_rows(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, 1> peak_to_peak_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return statistic_rows(matrix, [](const auto& begin, const auto& end) {
            return ml::computation::statistic::peak_to_peak(begin, end);
        });
    }
} // namespace ml::data_structure::matrix
