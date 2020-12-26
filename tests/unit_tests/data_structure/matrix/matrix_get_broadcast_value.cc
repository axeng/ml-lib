/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_get_broadcast_value.cc
 ** @brief Tests for Get Broadcast Value functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, GetBroadcastValueNormal)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_EQ(1, matrix.get_broadcast_value(0, 0));
        EXPECT_EQ(2, matrix.get_broadcast_value(0, 1));
        EXPECT_EQ(3, matrix.get_broadcast_value(1, 0));
        EXPECT_EQ(4, matrix.get_broadcast_value(1, 1));
        EXPECT_EQ(5, matrix.get_broadcast_value(2, 0));
        EXPECT_EQ(6, matrix.get_broadcast_value(2, 1));
    }

    TEST(DataStructureMatrix, GetBroadcastValueRow)
    {
        ml::data_structure::matrix::Matrix<int, 1, 2> matrix({1, 2});

        EXPECT_EQ(1, matrix.get_broadcast_value(0, 0));
        EXPECT_EQ(2, matrix.get_broadcast_value(0, 1));
        EXPECT_EQ(1, matrix.get_broadcast_value(1, 0));
        EXPECT_EQ(2, matrix.get_broadcast_value(1, 1));
        EXPECT_EQ(1, matrix.get_broadcast_value(2, 0));
        EXPECT_EQ(2, matrix.get_broadcast_value(2, 1));
    }

    TEST(DataStructureMatrix, GetBroadcastValueColumn)
    {
        ml::data_structure::matrix::Matrix<int, 3, 1> matrix({1, 2, 3});

        EXPECT_EQ(1, matrix.get_broadcast_value(0, 0));
        EXPECT_EQ(1, matrix.get_broadcast_value(0, 1));
        EXPECT_EQ(2, matrix.get_broadcast_value(1, 0));
        EXPECT_EQ(2, matrix.get_broadcast_value(1, 1));
        EXPECT_EQ(3, matrix.get_broadcast_value(2, 0));
        EXPECT_EQ(3, matrix.get_broadcast_value(2, 1));
    }

    TEST(DataStructureMatrix, GetBroadcastValueScalar)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix({1});

        EXPECT_EQ(1, matrix.get_broadcast_value(0, 0));
        EXPECT_EQ(1, matrix.get_broadcast_value(0, 1));
        EXPECT_EQ(1, matrix.get_broadcast_value(1, 0));
        EXPECT_EQ(1, matrix.get_broadcast_value(1, 1));
        EXPECT_EQ(1, matrix.get_broadcast_value(2, 0));
        EXPECT_EQ(1, matrix.get_broadcast_value(2, 1));
    }
} // namespace tests::unit_tests
