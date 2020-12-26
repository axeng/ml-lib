/**
 ** @file src/data_structure/matrix/matrix_print.hxx
 ** @brief Print implementations for ml::data_structure::matrix::Matrix
 */

#include <iomanip>

namespace ml::data_structure::matrix
{
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    std::ostream& print(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, std::ostream& os)
    {
        std::ios_base::fmtflags f(os.flags());

        for (size_t i = 0; i < HEIGHT; i++)
        {
            os << "| ";

            for (size_t j = 0; j < WIDTH; j++)
                os << std::fixed << std::setw(7) << std::setprecision(4) << matrix(i, j) << " ";

            os << "|" << std::endl;
        }

        os.flags(f);

        return os;
    }

    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    inline std::ostream& operator<<(std::ostream& os, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix)
    {
        return ml::data_structure::matrix::print(matrix, os);
    }
} // namespace ml::data_structure::matrix