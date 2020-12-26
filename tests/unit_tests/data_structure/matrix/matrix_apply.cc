/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_apply.cc
 ** @brief Tests for Apply functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, ApplyInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        matrix.apply([](const int& element) { return element * 2; });

        EXPECT_EQ(1 * 2, matrix(0, 0));
        EXPECT_EQ(2 * 2, matrix(0, 1));
        EXPECT_EQ(3 * 2, matrix(1, 0));
        EXPECT_EQ(4 * 2, matrix(1, 1));
        EXPECT_EQ(5 * 2, matrix(2, 0));
        EXPECT_EQ(6 * 2, matrix(2, 1));
    }

    TEST(DataStructureMatrix, Apply)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result =
            ml::data_structure::matrix::apply<int, 3, 2>(matrix, [](const int& element) { return element * 2; });

        EXPECT_EQ(1 * 2, matrix_result(0, 0));
        EXPECT_EQ(2 * 2, matrix_result(0, 1));
        EXPECT_EQ(3 * 2, matrix_result(1, 0));
        EXPECT_EQ(4 * 2, matrix_result(1, 1));
        EXPECT_EQ(5 * 2, matrix_result(2, 0));
        EXPECT_EQ(6 * 2, matrix_result(2, 1));
    }
} // namespace tests::unit_tests
