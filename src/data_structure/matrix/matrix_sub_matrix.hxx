/**
 ** @file src/data_structure/matrix/matrix_sub_matrix.hxx
 ** @brief Sub Matrix implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    template <size_t START_HEIGHT_INDEX, size_t START_WIDTH_INDEX, size_t SUB_HEIGHT, size_t SUB_WIDTH>
    inline Matrix<DATA_TYPE, SUB_HEIGHT, SUB_WIDTH> Matrix<DATA_TYPE, HEIGHT, WIDTH>::sub_matrix() const
    {
        return ml::data_structure::matrix::sub_matrix<START_HEIGHT_INDEX, START_WIDTH_INDEX, SUB_HEIGHT, SUB_WIDTH>(
            *this);
    }

    template <size_t START_HEIGHT_INDEX,
              size_t START_WIDTH_INDEX,
              size_t SUB_HEIGHT,
              size_t SUB_WIDTH,
              typename DATA_TYPE,
              size_t HEIGHT,
              size_t WIDTH>
    Matrix<DATA_TYPE, SUB_HEIGHT, SUB_WIDTH> sub_matrix(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        if constexpr (START_HEIGHT_INDEX + SUB_HEIGHT > HEIGHT || START_WIDTH_INDEX + SUB_WIDTH > WIDTH)
        {
            throw std::out_of_range("The sub matrix size is invalid");
        }
        else
        {
            Matrix<DATA_TYPE, SUB_HEIGHT, SUB_WIDTH> matrix_result;

            for (size_t i = 0; i < SUB_HEIGHT; i++)
            {
                std::copy(matrix.data().begin() + ((i + START_HEIGHT_INDEX) * WIDTH) + START_WIDTH_INDEX,
                          matrix.data().begin() + ((i + START_HEIGHT_INDEX) * WIDTH) + START_WIDTH_INDEX + SUB_WIDTH,
                          matrix_result.data().begin() + (i * SUB_WIDTH));
            }

            return matrix_result;
        }
    }
} // namespace ml::data_structure::matrix
