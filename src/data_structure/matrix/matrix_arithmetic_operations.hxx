/**
 ** @file src/data_structure/matrix/matrix_arithmetic_operations.hxx
 ** @brief Arithmetic operations implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Operation>
    inline static Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    arithmetic_operation_in_place(Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs,
                                  const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs,
                                  const Operation& operation)
    {
        for (size_t i = 0; i < lhs.data().size(); i++)
            operation(lhs.data()[i], rhs.data()[i]);

        return lhs;
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2, class Operation>
    static Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    arithmetic_operation(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs,
                         const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs,
                         const Operation& operation)
    {
        constexpr size_t matrix_result_height = MAX(HEIGHT_1, HEIGHT_2);
        constexpr size_t matrix_result_width = MAX(WIDTH_1, WIDTH_2);

        if constexpr (((HEIGHT_1 != matrix_result_height || (HEIGHT_2 != 1 && HEIGHT_2 != HEIGHT_1))
                       && (HEIGHT_2 != matrix_result_height || (HEIGHT_1 != 1 && HEIGHT_1 != HEIGHT_2)))
                      || ((WIDTH_1 != matrix_result_width || (WIDTH_2 != 1 && WIDTH_2 != WIDTH_1))
                          && (WIDTH_2 != matrix_result_width || (WIDTH_1 != 1 && WIDTH_1 != WIDTH_2))))
        {
            throw std::invalid_argument("The matrix are not compatible");
        }
        else
        {
            Matrix<DATA_TYPE, matrix_result_height, matrix_result_width> matrix_result;

            for (size_t i = 0; i < matrix_result_height; i++)
            {
                for (size_t j = 0; j < matrix_result_width; j++)
                    matrix_result(i, j) = operation(lhs.get_broadcast_value(i, j), rhs.get_broadcast_value(i, j));
            }

            return matrix_result;
        }
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Operation>
    inline static Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    arithmetic_scalar_operation_in_place(Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                         const DATA_TYPE& scalar,
                                         const Operation& operation)
    {
        for (auto& element : matrix.data())
            operation(element, scalar);

        return matrix;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::negate()
    {
        for (auto& element : this->data_)
            element = -element;

        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> negate(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.negate();
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator-(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return ml::data_structure::matrix::negate(matrix);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::plus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return arithmetic_operation_in_place(
            *this, rhs, [](DATA_TYPE& lhs, const DATA_TYPE& rhs) { return lhs += rhs; });
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    plus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::arithmetic_operation(lhs, rhs, std::plus<>{});
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator+=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return this->plus(rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator+(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::plus(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::minus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return arithmetic_operation_in_place(
            *this, rhs, [](DATA_TYPE& lhs, const DATA_TYPE& rhs) { return lhs -= rhs; });
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    minus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::arithmetic_operation(lhs, rhs, std::minus<>{});
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator-=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return this->minus(rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator-(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::minus(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::multiplies(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return arithmetic_operation_in_place(*this, rhs, [](DATA_TYPE& lhs, const DATA_TYPE& rhs) { return lhs *= rhs; });
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    multiplies(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::arithmetic_operation(lhs, rhs, std::multiplies<>{});
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator*=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return this->multiplies(rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator*(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::multiplies(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::divides(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return arithmetic_operation_in_place(
            *this, rhs, [](DATA_TYPE& lhs, const DATA_TYPE& rhs) { return lhs /= rhs; });
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    divides(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::arithmetic_operation(lhs, rhs, std::divides<>{});
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator/=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return this->divides(rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator/(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::divides(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::modulus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return arithmetic_operation_in_place(
            *this, rhs, [](DATA_TYPE& lhs, const DATA_TYPE& rhs) { return lhs %= rhs; });
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    modulus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::arithmetic_operation(lhs, rhs, std::modulus<>{});
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator%=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return this->modulus(rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    inline Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator%(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs)
    {
        return ml::data_structure::matrix::modulus(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::plus_scalar(const DATA_TYPE& scalar)
    {
        return arithmetic_scalar_operation_in_place(
            *this, scalar, [](DATA_TYPE& element, const DATA_TYPE& scalar) { return element += scalar; });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> plus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                        const DATA_TYPE& scalar)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.plus_scalar(scalar);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator+=(const DATA_TYPE& scalar)
    {
        return this->plus_scalar(scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator+(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const DATA_TYPE& scalar)
    {
        return ml::data_structure::matrix::plus_scalar(matrix, scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::minus_scalar(const DATA_TYPE& scalar)
    {
        return arithmetic_scalar_operation_in_place(
            *this, scalar, [](DATA_TYPE& element, const DATA_TYPE& scalar) { return element -= scalar; });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> minus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                         const DATA_TYPE& scalar)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.minus_scalar(scalar);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator-=(const DATA_TYPE& scalar)
    {
        return this->minus_scalar(scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator-(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const DATA_TYPE& scalar)
    {
        return ml::data_structure::matrix::minus_scalar(matrix, scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>&
    Matrix<DATA_TYPE, HEIGHT, WIDTH>::multiplies_scalar(const DATA_TYPE& scalar)
    {
        return arithmetic_scalar_operation_in_place(
            *this, scalar, [](DATA_TYPE& element, const DATA_TYPE& scalar) { return element *= scalar; });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> multiplies_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                              const DATA_TYPE& scalar)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.multiplies_scalar(scalar);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator*=(const DATA_TYPE& scalar)
    {
        return this->multiplies_scalar(scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator*(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const DATA_TYPE& scalar)
    {
        return ml::data_structure::matrix::multiplies_scalar(matrix, scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::divides_scalar(const DATA_TYPE& scalar)
    {
        return arithmetic_scalar_operation_in_place(
            *this, scalar, [](DATA_TYPE& element, const DATA_TYPE& scalar) { return element /= scalar; });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> divides_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                           const DATA_TYPE& scalar)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.divides_scalar(scalar);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator/=(const DATA_TYPE& scalar)
    {
        return this->divides_scalar(scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator/(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const DATA_TYPE& scalar)
    {
        return ml::data_structure::matrix::divides_scalar(matrix, scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::modulus_scalar(const DATA_TYPE& scalar)
    {
        return arithmetic_scalar_operation_in_place(
            *this, scalar, [](DATA_TYPE& element, const DATA_TYPE& scalar) { return element %= scalar; });
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> modulus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                           const DATA_TYPE& scalar)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.modulus_scalar(scalar);
        return matrix_result;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::operator%=(const DATA_TYPE& scalar)
    {
        return this->modulus_scalar(scalar);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> operator%(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                      const DATA_TYPE& scalar)
    {
        return ml::data_structure::matrix::modulus_scalar(matrix, scalar);
    }
} // namespace ml::data_structure::matrix
