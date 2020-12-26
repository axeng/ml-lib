/**
 ** @file src/data_structure/matrix/matrix_apply.hxx
 ** @brief Apply implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <class Function>
    Matrix<DATA_TYPE, HEIGHT, WIDTH>& Matrix<DATA_TYPE, HEIGHT, WIDTH>::apply(const Function& function)
    {
        for (auto& element : this->data_)
            element = function(element);

        return *this;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Function>
    inline Matrix<DATA_TYPE, HEIGHT, WIDTH> apply(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                  const Function& function)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH> matrix_result = matrix;
        matrix_result.apply(function);
        return matrix_result;
    }
} // namespace ml::data_structure::matrix