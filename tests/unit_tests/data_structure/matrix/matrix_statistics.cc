/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_statistics.cc
 ** @brief Tests for statistic operation functions of ml::data_structure::matrix::Matrix
 */

#include "unit_tests/data_structure/matrix/matrix_statistics.hh"

#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TYPED_TEST_SUITE(DataStructureMatrixStatistic, MatrixStatisticTypes, );

    TYPED_TEST(DataStructureMatrixStatistic, SimpleEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f});
        auto max = TypeParam::function(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f}), max);
    }

    TYPED_TEST(DataStructureMatrixStatistic, ColumnsEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f});
        const auto& matrix_result = TypeParam::function_columns(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 4.0f, 3.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({6.0f, 5.0f, 2.0f}), matrix_result(0, 1));
    }

    TYPED_TEST(DataStructureMatrixStatistic, RowsEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f});
        const auto& matrix_result = TypeParam::function_rows(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 6.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({4.0f, 5.0f}), matrix_result(1, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({3.0f, 2.0f}), matrix_result(2, 0));
    }

    TYPED_TEST(DataStructureMatrixStatistic, SimpleOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 9.0f, 6.0f, 4.0f, 8.0f, 5.0f, 3.0f, 2.0f, 7.0f});
        auto max = TypeParam::function(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 9.0f, 6.0f, 4.0f, 8.0f, 5.0f, 3.0f, 2.0f, 7.0f}), max);
    }

    TYPED_TEST(DataStructureMatrixStatistic, ColumnsOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 9.0f, 6.0f, 4.0f, 8.0f, 5.0f, 3.0f, 2.0f, 7.0f});
        const auto& matrix_result = TypeParam::function_columns(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 4.0f, 3.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({9.0f, 8.0f, 2.0f}), matrix_result(0, 1));
        EXPECT_FLOAT_EQ(TypeParam::test_function({6.0f, 5.0f, 7.0f}), matrix_result(0, 2));
    }

    TYPED_TEST(DataStructureMatrixStatistic, RowsOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 9.0f, 6.0f, 4.0f, 8.0f, 5.0f, 3.0f, 2.0f, 7.0f});
        const auto& matrix_result = TypeParam::function_rows(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 9.0f, 6.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({4.0f, 8.0f, 5.0f}), matrix_result(1, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({3.0f, 2.0f, 7.0f}), matrix_result(2, 0));
    }

    TYPED_TEST(DataStructureMatrixStatistic, SimpleSortedEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        auto max = TypeParam::function(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}), max);
    }

    TYPED_TEST(DataStructureMatrixStatistic, ColumnsSortedEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        const auto& matrix_result = TypeParam::function_columns(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 3.0f, 5.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({2.0f, 4.0f, 6.0f}), matrix_result(0, 1));
    }

    TYPED_TEST(DataStructureMatrixStatistic, RowsSortedEven)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        const auto& matrix_result = TypeParam::function_rows(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 2.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({3.0f, 4.0f}), matrix_result(1, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({5.0f, 6.0f}), matrix_result(2, 0));
    }

    TYPED_TEST(DataStructureMatrixStatistic, SimpleSortedOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
        auto max = TypeParam::function(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 9.0f, 6.0f, 4.0f, 8.0f, 5.0f, 3.0f, 2.0f, 7.0f}), max);
    }

    TYPED_TEST(DataStructureMatrixStatistic, ColumnsSortedOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
        const auto& matrix_result = TypeParam::function_columns(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 4.0f, 7.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({2.0f, 5.0f, 8.0f}), matrix_result(0, 1));
        EXPECT_FLOAT_EQ(TypeParam::test_function({3.0f, 6.0f, 9.0f}), matrix_result(0, 2));
    }

    TYPED_TEST(DataStructureMatrixStatistic, RowsSortedOdd)
    {
        ml::data_structure::matrix::Matrix<float, 3, 3> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
        const auto& matrix_result = TypeParam::function_rows(matrix);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 2.0f, 3.0f}), matrix_result(0, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({4.0f, 5.0f, 6.0f}), matrix_result(1, 0));
        EXPECT_FLOAT_EQ(TypeParam::test_function({7.0f, 8.0f, 9.0f}), matrix_result(2, 0));
    }
} // namespace tests::unit_tests
