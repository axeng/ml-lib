/**
 ** @file src/data_structure/matrix/matrix.hxx
 ** @brief Constructors and accessors of ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::Matrix()
        : data_()
    {}

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::Matrix(const DATA_TYPE& value)
        : data_({value})
    {}

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::Matrix(const Matrix::data_array_t& data)
        : data_(data)
    {}

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator()(size_t height_index, size_t width_index)
    {
        return data_[height_index * WIDTH + width_index];
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline const DATA_TYPE& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator()(size_t height_index, size_t width_index) const
    {
        return data_[height_index * WIDTH + width_index];
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline DATA_TYPE& Matrix<DATA_TYPE, HEIGHT, WIDTH>::at(size_t height_index, size_t width_index)
    {
        if (height_index >= HEIGHT)
            throw std::out_of_range("height_index out of range");
        if (width_index >= WIDTH)
            throw std::out_of_range("width_index out of range");

        return (*this)(height_index, width_index);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline const DATA_TYPE& Matrix<DATA_TYPE, HEIGHT, WIDTH>::at(size_t height_index, size_t width_index) const
    {
        if (height_index >= HEIGHT)
            throw std::out_of_range("height_index out of range");
        if (width_index >= WIDTH)
            throw std::out_of_range("width_index out of range");

        return (*this)(height_index, width_index);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline typename Matrix<DATA_TYPE, HEIGHT, WIDTH>::data_array_t& Matrix<DATA_TYPE, HEIGHT, WIDTH>::data()
    {
        return this->data_;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline const typename Matrix<DATA_TYPE, HEIGHT, WIDTH>::data_array_t& Matrix<DATA_TYPE, HEIGHT, WIDTH>::data() const
    {
        return this->data_;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline const DATA_TYPE& Matrix<DATA_TYPE, HEIGHT, WIDTH>::get_broadcast_value(size_t height_index,
                                                                                  size_t width_index) const
    {
        if constexpr (HEIGHT == 1)
            height_index = 0;
        if constexpr (WIDTH == 1)
            width_index = 0;

        return (*this)(height_index, width_index);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline constexpr size_t Matrix<DATA_TYPE, HEIGHT, WIDTH>::get_height()
    {
        return HEIGHT;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline constexpr size_t Matrix<DATA_TYPE, HEIGHT, WIDTH>::get_width()
    {
        return WIDTH;
    }
} // namespace ml::data_structure::matrix