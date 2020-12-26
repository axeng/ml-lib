/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_concatenation.cc
 ** @brief Tests for Concatenation functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, HorizontalConcatenate1)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = ml::data_structure::matrix::horizontal_concatenate(matrix_1, matrix_2);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(1, matrix_result(0, 2));
        EXPECT_EQ(2, matrix_result(0, 3));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(3, matrix_result(1, 2));
        EXPECT_EQ(4, matrix_result(1, 3));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
        EXPECT_EQ(5, matrix_result(2, 2));
        EXPECT_EQ(6, matrix_result(2, 3));
    }

    TEST(DataStructureMatrix, HorizontalConcatenate2)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({6, 5, 4, 3, 2, 1});

        const auto& matrix_result = ml::data_structure::matrix::horizontal_concatenate(matrix_1, matrix_2);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(6, matrix_result(0, 2));
        EXPECT_EQ(5, matrix_result(0, 3));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(4, matrix_result(1, 2));
        EXPECT_EQ(3, matrix_result(1, 3));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
        EXPECT_EQ(2, matrix_result(2, 2));
        EXPECT_EQ(1, matrix_result(2, 3));
    }

    TEST(DataStructureMatrix, VerticalConcatenate1)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({6, 5, 4, 3, 2, 1});

        const auto& matrix_result = ml::data_structure::matrix::vertical_concatenate(matrix_1, matrix_2);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
        EXPECT_EQ(6, matrix_result(3, 0));
        EXPECT_EQ(5, matrix_result(3, 1));
        EXPECT_EQ(4, matrix_result(4, 0));
        EXPECT_EQ(3, matrix_result(4, 1));
        EXPECT_EQ(2, matrix_result(5, 0));
        EXPECT_EQ(1, matrix_result(5, 1));
    }

    TEST(DataStructureMatrix, VerticalConcatenate2)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = ml::data_structure::matrix::vertical_concatenate(matrix_1, matrix_2);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
        EXPECT_EQ(1, matrix_result(3, 0));
        EXPECT_EQ(2, matrix_result(3, 1));
        EXPECT_EQ(3, matrix_result(4, 0));
        EXPECT_EQ(4, matrix_result(4, 1));
        EXPECT_EQ(5, matrix_result(5, 0));
        EXPECT_EQ(6, matrix_result(5, 1));
    }
} // namespace tests::unit_tests
