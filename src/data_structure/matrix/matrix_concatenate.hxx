/**
 ** @file src/data_structure/matrix/matrix_concatenate.hxx
 ** @brief Concatenate implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, HEIGHT, ADD(WIDTH_1, WIDTH_2)>
    horizontal_concatenate(const Matrix<DATA_TYPE, HEIGHT, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH_2>& rhs)
    {
        Matrix<DATA_TYPE, HEIGHT, WIDTH_1 + WIDTH_2> new_matrix;

        for (size_t i = 0; i < HEIGHT; i++)
        {
            std::copy(lhs.data().begin() + (i * WIDTH_1),
                      lhs.data().begin() + ((i + 1) * WIDTH_1),
                      new_matrix.data().begin() + (i * (WIDTH_1 + WIDTH_2)));
        }

        for (size_t i = 0; i < HEIGHT; i++)
        {
            std::copy(rhs.data().begin() + (i * WIDTH_2),
                      rhs.data().begin() + ((i + 1) * WIDTH_2),
                      new_matrix.data().begin() + (i * (WIDTH_1 + WIDTH_2) + WIDTH_1));
        }

        return new_matrix;
    }

    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH>
    Matrix<DATA_TYPE, ADD(HEIGHT_1, HEIGHT_2), WIDTH>
    vertical_concatenate(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH>& rhs)
    {
        Matrix<DATA_TYPE, HEIGHT_1 + HEIGHT_2, WIDTH> new_matrix;

        std::copy(lhs.data().begin(), lhs.data().end(), new_matrix.data().begin());
        std::copy(rhs.data().begin(), rhs.data().end(), new_matrix.data().begin() + (HEIGHT_1 * WIDTH));

        return new_matrix;
    }
} // namespace ml::data_structure::matrix
