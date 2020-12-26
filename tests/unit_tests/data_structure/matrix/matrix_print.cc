/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_print.cc
 ** @brief Tests for Print functions of ml::data_structure::matrix::Matrix
 */

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(DataStructureMatrix, Print)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});

        std::stringstream string_stream;
        ml::data_structure::matrix::print(matrix, string_stream);
        string_stream << 1;

        EXPECT_EQ("|  1.0000  2.0000 |\n|  3.0000  4.0000 |\n|  5.0000  6.0000 |\n1", string_stream.str());
    }

    TEST(DataStructureMatrix, PrintShortcut)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});

        std::stringstream string_stream;
        string_stream << matrix << 1;

        EXPECT_EQ("|  1.0000  2.0000 |\n|  3.0000  4.0000 |\n|  5.0000  6.0000 |\n1", string_stream.str());
    }

    TEST(DataStructureMatrix, PrintWithNegative)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, -3.0f, 4.0f, 5.0f, -6.0f});

        std::stringstream string_stream;
        ml::data_structure::matrix::print(matrix, string_stream);
        string_stream << 1;

        EXPECT_EQ("|  1.0000  2.0000 |\n| -3.0000  4.0000 |\n|  5.0000 -6.0000 |\n1", string_stream.str());
    }

    TEST(DataStructureMatrix, PrintWithNegativeShortcut)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({1.0f, 2.0f, -3.0f, 4.0f, 5.0f, -6.0f});

        std::stringstream string_stream;
        string_stream << matrix << 1;

        EXPECT_EQ("|  1.0000  2.0000 |\n| -3.0000  4.0000 |\n|  5.0000 -6.0000 |\n1", string_stream.str());
    }

    TEST(DataStructureMatrix, PrintWithFloat)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({4.0f / 3.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});

        std::stringstream string_stream;
        ml::data_structure::matrix::print(matrix, string_stream);
        string_stream << 1;

        EXPECT_EQ("|  1.3333  2.0000 |\n|  3.0000  4.0000 |\n|  5.0000  6.0000 |\n1", string_stream.str());
    }

    TEST(DataStructureMatrix, PrintWithFloatShortcut)
    {
        ml::data_structure::matrix::Matrix<float, 3, 2> matrix({4.0f / 3.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});

        std::stringstream string_stream;
        string_stream << matrix << 1;

        EXPECT_EQ("|  1.3333  2.0000 |\n|  3.0000  4.0000 |\n|  5.0000  6.0000 |\n1", string_stream.str());
    }
} // namespace tests::unit_tests
