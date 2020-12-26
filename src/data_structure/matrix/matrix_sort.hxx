/**
 ** @file src/data_structure/matrix/matrix_sort.hxx
 ** @brief Sort implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Compare>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::sort(const Compare& compare)
    {
        std::sort(this->data_.begin(), this->data_.end(), compare);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> sort(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, const Compare& compare)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.sort(compare);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Compare>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::sort_rows(const Compare& compare)
    {
        for (size_t i = 0; i < HEIGHT; i++)
        {
            std::sort(this->data_.begin() + (i * WIDTH), this->data_.begin() + ((i + 1) * WIDTH), compare);
        }

        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> sort_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const Compare& compare)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.sort_rows(compare);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Compare>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::sort_columns(const Compare& compare)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            auto first_it = this->data_.begin() + j;
            auto last_it = this->data().begin() + j + (HEIGHT - 1) * WIDTH;
            column_step_iterator_t column_begin(first_it, first_it, last_it);
            column_step_iterator_t column_end(this->data_.end(), first_it, last_it);

            std::sort(column_begin, column_end, compare);
        }

        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> sort_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                         const Compare& compare)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.sort_columns(compare);
        return matrix_result;
    }
} // namespace ml::data_structure::matrix