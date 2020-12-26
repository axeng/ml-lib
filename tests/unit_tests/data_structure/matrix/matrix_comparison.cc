/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_comparison.cc
 ** @brief Tests for Comparisons functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, CompareTrue)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        ASSERT_TRUE(ml::data_structure::matrix::compare(matrix_1, matrix_2));
    }

    TEST(DataStructureMatrix, CompareFalse)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 6, 4, 5, 3, 2});

        ASSERT_FALSE(ml::data_structure::matrix::compare(matrix_1, matrix_2));
    }

    TEST(DataStructureMatrix, EqualOperatorTrue)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        ASSERT_TRUE(matrix_1 == matrix_2);
    }

    TEST(DataStructureMatrix, EqualOperatorFalse)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 6, 4, 5, 3, 2});

        ASSERT_FALSE(matrix_1 == matrix_2);
    }

    TEST(DataStructureMatrix, NotEqualOperatorTrue)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 6, 4, 5, 3, 2});

        ASSERT_TRUE(matrix_1 != matrix_2);
    }

    TEST(DataStructureMatrix, NotEqualOperatorFalse)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        ASSERT_FALSE(matrix_1 != matrix_2);
    }
} // namespace tests::unit_tests
