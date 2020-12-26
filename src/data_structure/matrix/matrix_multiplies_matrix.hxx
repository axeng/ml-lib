/**
 ** @file src/data_structure/matrix/matrix_multiplies_matrix.hxx
 ** @brief Multiplies Matrix implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t M, size_t N, size_t P>
    Matrix<DATA_TYPE, M, P> multiplies_matrix(const Matrix<DATA_TYPE, M, N>& lhs, const Matrix<DATA_TYPE, N, P>& rhs)
    {
        Matrix<DATA_TYPE, M, P> new_matrix(0);

        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < P; j++)
            {
                for (size_t k = 0; k < N; k++)
                    new_matrix(i, j) += lhs(i, k) * rhs(k, j);
            }
        }

        return new_matrix;
    }
} // namespace ml::data_structure::matrix
