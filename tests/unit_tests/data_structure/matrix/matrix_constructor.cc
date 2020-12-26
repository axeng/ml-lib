/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_constructor.cc
 ** @brief Tests for Constructor functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, EmptyConstructorSize)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix;

        EXPECT_EQ(6, matrix.data().size());
    }

    TEST(DataStructureMatrix, ValueConstructorSize)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix(0);

        EXPECT_EQ(6, matrix.data().size());
    }

    TEST(DataStructureMatrix, ValueConstructorValues)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix(0);

        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 2; j++)
                EXPECT_EQ(0, matrix(i, j));
        }
    }

    TEST(DataStructureMatrix, ArrayConstructorSize)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_EQ(6, matrix.data().size());
    }

    TEST(DataStructureMatrix, ArrayConstructorValues)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_EQ(1, matrix(0, 0));
        EXPECT_EQ(2, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(5, matrix(2, 0));
        EXPECT_EQ(6, matrix(2, 1));
    }
} // namespace tests::unit_tests
