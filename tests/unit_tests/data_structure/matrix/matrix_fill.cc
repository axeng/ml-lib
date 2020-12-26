/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_fill.cc
 ** @brief Tests for Fill functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "generator/random/uniform_random.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, Fill)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill(0.0f);

        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 2; j++)
                EXPECT_FLOAT_EQ(0.0f, matrix(i, j));
        }
    }

    TEST(DataStructureMatrix, FillRow)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill_row(1, 0.0f);

        for (size_t j = 0; j < 2; j++)
            EXPECT_FLOAT_EQ(0.0f, matrix(1, j));

        EXPECT_FLOAT_EQ(1.0f, matrix(0, 0));
        EXPECT_FLOAT_EQ(2.0f, matrix(0, 1));
        EXPECT_FLOAT_EQ(5.0f, matrix(2, 0));
        EXPECT_FLOAT_EQ(6.0f, matrix(2, 1));
    }

    TEST(DataStructureMatrix, FillColumn)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill_column(1, 0.0f);

        for (size_t i = 0; i < 3; i++)
            EXPECT_FLOAT_EQ(0.0f, matrix(i, 1));

        EXPECT_FLOAT_EQ(1.0f, matrix(0, 0));
        EXPECT_FLOAT_EQ(3.0f, matrix(1, 0));
        EXPECT_FLOAT_EQ(5.0f, matrix(2, 0));
    }

    TEST(DataStructureMatrix, FillGenerator)
    {
        auto generator = ml::generator::random::UniformRandom<float>(0.0f, 1.0f);
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill_generator(generator);

        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                EXPECT_LE(0.0f, matrix(i, j));
                EXPECT_GT(1.0f, matrix(i, j));
            }
        }
    }

    TEST(DataStructureMatrix, FillRowGenerator)
    {
        auto generator = ml::generator::random::UniformRandom<float>(0.0f, 1.0f);
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill_row_generator(1, generator);

        for (size_t j = 0; j < 2; j++)
        {
            EXPECT_LE(0.0f, matrix(1, j));
            EXPECT_GT(1.0f, matrix(1, j));
        }

        EXPECT_FLOAT_EQ(1.0f, matrix(0, 0));
        EXPECT_FLOAT_EQ(2.0f, matrix(0, 1));
        EXPECT_FLOAT_EQ(5.0f, matrix(2, 0));
        EXPECT_FLOAT_EQ(6.0f, matrix(2, 1));
    }

    TEST(DataStructureMatrix, FillColumnGenerator)
    {
        auto generator = ml::generator::random::UniformRandom<float>(0.0f, 1.0f);
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        matrix.fill_column_generator(1, generator);

        for (size_t i = 0; i < 3; i++)
        {
            EXPECT_LE(0.0f, matrix(i, 1));
            EXPECT_GT(1.0f, matrix(i, 1));
        }

        EXPECT_FLOAT_EQ(1.0f, matrix(0, 0));
        EXPECT_FLOAT_EQ(3.0f, matrix(1, 0));
        EXPECT_FLOAT_EQ(5.0f, matrix(2, 0));
    }
} // namespace tests::unit_tests
