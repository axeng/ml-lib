/**
 ** @file src/data_structure/matrix/matrix_transpose.hxx
 ** @brief Transpose implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline Matrix<DATA_TYPE, WIDTH, HEIGHT> Matrix<DATA_TYPE, HEIGHT, WIDTH>::transpose() const
    {
        return ml::data_structure::matrix::transpose(*this);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, WIDTH, HEIGHT> transpose(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        Matrix<DATA_TYPE, WIDTH, HEIGHT> new_matrix;

        for (size_t i = 0; i < HEIGHT; i++)
        {
            for (size_t j = 0; j < WIDTH; j++)
                new_matrix(j, i) = matrix(i, j);
        }

        return new_matrix;
    }
} // namespace ml::data_structure::matrix