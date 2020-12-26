/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_sort.cc
 ** @brief Tests for Sort functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, SortInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort();

        EXPECT_EQ(1, matrix(0, 0));
        EXPECT_EQ(2, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(5, matrix(2, 0));
        EXPECT_EQ(6, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortSortedInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        matrix.sort();

        EXPECT_EQ(1, matrix(0, 0));
        EXPECT_EQ(2, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(5, matrix(2, 0));
        EXPECT_EQ(6, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort_rows();

        EXPECT_EQ(1, matrix(0, 0));
        EXPECT_EQ(6, matrix(0, 1));
        EXPECT_EQ(4, matrix(1, 0));
        EXPECT_EQ(5, matrix(1, 1));
        EXPECT_EQ(2, matrix(2, 0));
        EXPECT_EQ(3, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsSortedInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({5, 6, 3, 4, 1, 2});
        matrix.sort_rows();

        EXPECT_EQ(5, matrix(0, 0));
        EXPECT_EQ(6, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(1, matrix(2, 0));
        EXPECT_EQ(2, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort_columns();

        EXPECT_EQ(1, matrix(0, 0));
        EXPECT_EQ(2, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(5, matrix(1, 1));
        EXPECT_EQ(4, matrix(2, 0));
        EXPECT_EQ(6, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsSortedInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({2, 1, 4, 3, 6, 5});
        matrix.sort_columns();

        EXPECT_EQ(2, matrix(0, 0));
        EXPECT_EQ(1, matrix(0, 1));
        EXPECT_EQ(4, matrix(1, 0));
        EXPECT_EQ(3, matrix(1, 1));
        EXPECT_EQ(6, matrix(2, 0));
        EXPECT_EQ(5, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort(std::greater());

        EXPECT_EQ(6, matrix(0, 0));
        EXPECT_EQ(5, matrix(0, 1));
        EXPECT_EQ(4, matrix(1, 0));
        EXPECT_EQ(3, matrix(1, 1));
        EXPECT_EQ(2, matrix(2, 0));
        EXPECT_EQ(1, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortSortedCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({6, 5, 4, 3, 2, 1});
        matrix.sort(std::greater());

        EXPECT_EQ(6, matrix(0, 0));
        EXPECT_EQ(5, matrix(0, 1));
        EXPECT_EQ(4, matrix(1, 0));
        EXPECT_EQ(3, matrix(1, 1));
        EXPECT_EQ(2, matrix(2, 0));
        EXPECT_EQ(1, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort_rows(std::greater());

        EXPECT_EQ(6, matrix(0, 0));
        EXPECT_EQ(1, matrix(0, 1));
        EXPECT_EQ(5, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(3, matrix(2, 0));
        EXPECT_EQ(2, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsSortedCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({2, 1, 4, 3, 6, 5});
        matrix.sort_rows(std::greater());

        EXPECT_EQ(2, matrix(0, 0));
        EXPECT_EQ(1, matrix(0, 1));
        EXPECT_EQ(4, matrix(1, 0));
        EXPECT_EQ(3, matrix(1, 1));
        EXPECT_EQ(6, matrix(2, 0));
        EXPECT_EQ(5, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        matrix.sort_columns(std::greater());

        EXPECT_EQ(4, matrix(0, 0));
        EXPECT_EQ(6, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(5, matrix(1, 1));
        EXPECT_EQ(1, matrix(2, 0));
        EXPECT_EQ(2, matrix(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsSortedCompareInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({5, 6, 3, 4, 1, 2});
        matrix.sort_columns(std::greater());

        EXPECT_EQ(5, matrix(0, 0));
        EXPECT_EQ(6, matrix(0, 1));
        EXPECT_EQ(3, matrix(1, 0));
        EXPECT_EQ(4, matrix(1, 1));
        EXPECT_EQ(1, matrix(2, 0));
        EXPECT_EQ(2, matrix(2, 1));
    }

    TEST(DataStructureMatrix, Sort)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort(matrix);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortSorted)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::sort(matrix);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(5, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortRows)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_rows(matrix);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 0));
        EXPECT_EQ(5, matrix_result(1, 1));
        EXPECT_EQ(2, matrix_result(2, 0));
        EXPECT_EQ(3, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsSorted)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({5, 6, 3, 4, 1, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_rows(matrix);

        EXPECT_EQ(5, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(1, matrix_result(2, 0));
        EXPECT_EQ(2, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortColumns)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_columns(matrix);

        EXPECT_EQ(1, matrix_result(0, 0));
        EXPECT_EQ(2, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(5, matrix_result(1, 1));
        EXPECT_EQ(4, matrix_result(2, 0));
        EXPECT_EQ(6, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsSorted)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({2, 1, 4, 3, 6, 5});
        const auto& matrix_result = ml::data_structure::matrix::sort_columns(matrix);

        EXPECT_EQ(2, matrix_result(0, 0));
        EXPECT_EQ(1, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(1, 1));
        EXPECT_EQ(6, matrix_result(2, 0));
        EXPECT_EQ(5, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort(matrix, std::greater());

        EXPECT_EQ(6, matrix_result(0, 0));
        EXPECT_EQ(5, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(1, 1));
        EXPECT_EQ(2, matrix_result(2, 0));
        EXPECT_EQ(1, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortSortedCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({6, 5, 4, 3, 2, 1});
        const auto& matrix_result = ml::data_structure::matrix::sort(matrix, std::greater());

        EXPECT_EQ(6, matrix_result(0, 0));
        EXPECT_EQ(5, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(1, 1));
        EXPECT_EQ(2, matrix_result(2, 0));
        EXPECT_EQ(1, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_rows(matrix, std::greater());

        EXPECT_EQ(6, matrix_result(0, 0));
        EXPECT_EQ(1, matrix_result(0, 1));
        EXPECT_EQ(5, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(3, matrix_result(2, 0));
        EXPECT_EQ(2, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortRowsSortedCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({2, 1, 4, 3, 6, 5});
        const auto& matrix_result = ml::data_structure::matrix::sort_rows(matrix, std::greater());

        EXPECT_EQ(2, matrix_result(0, 0));
        EXPECT_EQ(1, matrix_result(0, 1));
        EXPECT_EQ(4, matrix_result(1, 0));
        EXPECT_EQ(3, matrix_result(1, 1));
        EXPECT_EQ(6, matrix_result(2, 0));
        EXPECT_EQ(5, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 6, 4, 5, 3, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_columns(matrix, std::greater());

        EXPECT_EQ(4, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(5, matrix_result(1, 1));
        EXPECT_EQ(1, matrix_result(2, 0));
        EXPECT_EQ(2, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, SortColumnsSortedCompare)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({5, 6, 3, 4, 1, 2});
        const auto& matrix_result = ml::data_structure::matrix::sort_columns(matrix, std::greater());

        EXPECT_EQ(5, matrix_result(0, 0));
        EXPECT_EQ(6, matrix_result(0, 1));
        EXPECT_EQ(3, matrix_result(1, 0));
        EXPECT_EQ(4, matrix_result(1, 1));
        EXPECT_EQ(1, matrix_result(2, 0));
        EXPECT_EQ(2, matrix_result(2, 1));
    }
} // namespace tests::unit_tests
