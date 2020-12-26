/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_at.cc
 ** @brief Tests for At functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, At)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);
        int& value = matrix.at(0, 0);

        EXPECT_EQ(1, value);
    }

    TEST(DataStructureMatrix, AtWrongHeight)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);

        EXPECT_THROW(([&] {
                         int& value = matrix.at(1, 0);
                         return value;
                     }()),
                     std::out_of_range);
    }

    TEST(DataStructureMatrix, AtWrongWidth)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);

        EXPECT_THROW(([&] {
                         int& value = matrix.at(0, 1);
                         return value;
                     }()),
                     std::out_of_range);
    }

    TEST(DataStructureMatrix, AtConst)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);
        int value = matrix.at(0, 0);

        EXPECT_EQ(1, value);
    }

    TEST(DataStructureMatrix, AtConstWrongHeight)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);

        EXPECT_THROW(([&] {
                         int value = matrix.at(1, 0);
                         return value;
                     }()),
                     std::out_of_range);
    }

    TEST(DataStructureMatrix, AtConstWrongWidth)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix(1);

        EXPECT_THROW(([&] {
                         int value = matrix.at(0, 1);
                         return value;
                     }()),
                     std::out_of_range);
    }
} // namespace tests::unit_tests
