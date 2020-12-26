/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_multiplies_matrix.cc
 ** @brief Tests for Multiplies Matrix functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"

#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, MultiplyMatrix)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        const auto& matrix_2 = matrix_1.transpose();

        const auto& matrix_result = ml::data_structure::matrix::multiplies_matrix(matrix_1, matrix_2);

        EXPECT_EQ(1 * 1 + 2 * 2, matrix_result(0, 0));
        EXPECT_EQ(1 * 3 + 2 * 4, matrix_result(0, 1));
        EXPECT_EQ(1 * 5 + 2 * 6, matrix_result(0, 2));
        EXPECT_EQ(3 * 1 + 4 * 2, matrix_result(1, 0));
        EXPECT_EQ(3 * 3 + 4 * 4, matrix_result(1, 1));
        EXPECT_EQ(3 * 5 + 4 * 6, matrix_result(1, 2));
        EXPECT_EQ(5 * 1 + 6 * 2, matrix_result(2, 0));
        EXPECT_EQ(5 * 3 + 6 * 4, matrix_result(2, 1));
        EXPECT_EQ(5 * 5 + 6 * 6, matrix_result(2, 2));
    }
} // namespace tests::unit_tests
