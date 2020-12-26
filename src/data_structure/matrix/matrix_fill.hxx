/**
 ** @file src/data_structure/matrix/matrix_fill.hxx
 ** @brief Fill implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill(const DATA_TYPE& value)
    {
        std::fill(this->data_.begin(), this->data_.end(), value);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill_row(size_t row_index,
                                                                                        const DATA_TYPE& value)
    {
        std::fill(this->data_.begin() + row_index * WIDTH, this->data_.begin() + (row_index + 1) * WIDTH, value);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill_column(size_t column_index,
                                                                                           const DATA_TYPE& value)
    {
        auto first_it = this->data_.begin() + column_index;
        auto last_it = this->data().begin() + column_index + (HEIGHT - 1) * WIDTH;
        column_step_iterator_t column_begin(first_it, first_it, last_it);
        column_step_iterator_t column_end(this->data_.end(), first_it, last_it);

        std::fill(column_begin, column_end, value);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Generator>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill_generator(const Generator& generator)
    {
        std::generate(this->data_.begin(), this->data_.end(), generator);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Generator>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill_row_generator(size_t row_index, const Generator& generator)
    {
        std::generate(
            this->data_.begin() + row_index * WIDTH, this->data_.begin() + (row_index + 1) * WIDTH, generator);
        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Generator>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::fill_column_generator(size_t column_index, const Generator& generator)
    {
        auto first_it = this->data_.begin() + column_index;
        auto last_it = this->data().begin() + column_index + (HEIGHT - 1) * WIDTH;
        column_step_iterator_t column_begin(first_it, first_it, last_it);
        column_step_iterator_t column_end(this->data_.end(), first_it, last_it);

        std::generate(column_begin, column_end, generator);
        return *this;
    }
} // namespace ml::data_structure::matrix
