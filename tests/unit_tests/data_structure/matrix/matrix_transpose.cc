/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_transpose.cc
 ** @brief Tests for Transpose functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, Transpose)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::transpose(matrix);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(0, 2));
        EXPECT_EQ(6, matrix_result(1, 2));
    }

    TEST(DataStructureMatrix, TransposeShortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = matrix.transpose();

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(0, 2));
        EXPECT_EQ(6, matrix_result(1, 2));
    }
} // namespace tests::unit_tests
