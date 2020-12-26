/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_sub_matrix.cc
 ** @brief Tests for Sub Matrix functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"

#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, SubMatrix1)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::sub_matrix<1, 1, 2, 1>(matrix);

        EXPECT_EQ(4, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(1, 0));
    }

    TEST(DataStructureMatrix, SubMatrix2)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::sub_matrix<1, 0, 1, 2>(matrix);

        EXPECT_EQ(3, matrix_result(0, 0));
        EXPECT_EQ(4, matrix_result(0, 1));
    }

    TEST(DataStructureMatrix, SubMatrixWrongRow)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((ml::data_structure::matrix::sub_matrix<1, 1, 3, 1>(matrix)), std::out_of_range);
    }

    TEST(DataStructureMatrix, SubMatrixWrongCol)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((ml::data_structure::matrix::sub_matrix<1, 1, 2, 2>(matrix)), std::out_of_range);
    }

    TEST(DataStructureMatrix, SubMatrixWrongRowCol)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((ml::data_structure::matrix::sub_matrix<1, 1, 3, 2>(matrix)), std::out_of_range);
    }

    TEST(DataStructureMatrix, SubMatrix1Shortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = matrix.sub_matrix<1, 1, 2, 1>();

        EXPECT_EQ(4, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(1, 0));
    }

    TEST(DataStructureMatrix, SubMatrix2Shortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::sub_matrix<1, 0, 1, 2>(matrix);

        EXPECT_EQ(3, matrix_result(0, 0));
        EXPECT_EQ(4, matrix_result(0, 1));
    }

    TEST(DataStructureMatrix, SubMatrixWrongRowShortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((matrix.sub_matrix<1, 1, 3, 1>()), std::out_of_range);
    }

    TEST(DataStructureMatrix, SubMatrixWrongColShortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((matrix.sub_matrix<1, 1, 2, 2>()), std::out_of_range);
    }

    TEST(DataStructureMatrix, SubMatrixWrongRowColShortcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        EXPECT_THROW((matrix.sub_matrix<1, 1, 3, 2>()), std::out_of_range);
    }
} // namespace tests::unit_tests
