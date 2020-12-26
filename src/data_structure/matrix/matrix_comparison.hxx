/**
 ** @file src/data_structure/matrix/matrix_comparison.hxx
 ** @brief Comparison functions implementations for ml::data_structure::matrix::Matrix
 */

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool compare(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return lhs.data() == rhs.data();
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool operator==(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return ml::data_structure::matrix::compare(lhs, rhs);
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool operator!=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs)
    {
        return !ml::data_structure::matrix::compare(lhs, rhs);
    }
} // namespace ml::data_structure::matrix
