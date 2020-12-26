/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_arithmetic_operations.cc
 ** @brief Tests for arithmetic operation functions of ml::data_structure::matrix::Matrix
 */

#include "unit_tests/data_structure/matrix/matrix_arithmetic_operations.hh"

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TYPED_TEST_SUITE(DataStructureMatrixArithmeticOperation, ArithmeticOperations, );
    TYPED_TEST_SUITE(DataStructureMatrixArithmeticScalarOperation, ArithmeticScalarOperations, );

    TEST(DataStructureMatrix, NegateInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        matrix.negate();

        EXPECT_EQ(-1, matrix(0, 0));
        EXPECT_EQ(-2, matrix(0, 1));
        EXPECT_EQ(-3, matrix(1, 0));
        EXPECT_EQ(-4, matrix(1, 1));
        EXPECT_EQ(-5, matrix(2, 0));
        EXPECT_EQ(-6, matrix(2, 1));
    }

    TEST(DataStructureMatrix, Negate)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = ml::data_structure::matrix::negate(matrix);

        EXPECT_EQ(-1, matrix_result(0, 0));
        EXPECT_EQ(-2, matrix_result(0, 1));
        EXPECT_EQ(-3, matrix_result(1, 0));
        EXPECT_EQ(-4, matrix_result(1, 1));
        EXPECT_EQ(-5, matrix_result(2, 0));
        EXPECT_EQ(-6, matrix_result(2, 1));
    }

    TEST(DataStructureMatrix, NegateShorcut)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});
        const auto& matrix_result = -matrix;

        EXPECT_EQ(-1, matrix_result(0, 0));
        EXPECT_EQ(-2, matrix_result(0, 1));
        EXPECT_EQ(-3, matrix_result(1, 0));
        EXPECT_EQ(-4, matrix_result(1, 1));
        EXPECT_EQ(-5, matrix_result(2, 0));
        EXPECT_EQ(-6, matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, SameSizeInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        TypeParam::function_in_place(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_1(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_1(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 3), matrix_1(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 4), matrix_1(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 5), matrix_1(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 6), matrix_1(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, SameSize)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 3), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 4), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 5), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 6), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, LeftRow)
    {
        ml::data_structure::matrix::Matrix<int, 1, 2> matrix_1({1, 2});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 3), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 4), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 5), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 6), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, LeftColumn)
    {
        ml::data_structure::matrix::Matrix<int, 3, 1> matrix_1({1, 2, 3});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(2, 3), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 4), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 5), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(3, 6), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, LeftScalar)
    {
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix_1({1});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 3), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(1, 4), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 5), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(1, 6), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, RightRow)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 1, 2> matrix_2({1, 2});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 1), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 2), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 1), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 2), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, RightColumn)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 1> matrix_2({1, 2, 3});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(2, 1), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(3, 2), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 2), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 3), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 3), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, RightScalar)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 1, 1> matrix_2({1});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 1), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 1), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 1), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 1), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 1), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, LeftRowRightColumn)
    {
        ml::data_structure::matrix::Matrix<int, 1, 2> matrix_1({1, 2});
        ml::data_structure::matrix::Matrix<int, 3, 1> matrix_2({1, 2, 3});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 1), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(1, 3), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 3), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, LeftColumnRightRow)
    {
        ml::data_structure::matrix::Matrix<int, 3, 1> matrix_1({1, 2, 3});
        ml::data_structure::matrix::Matrix<int, 1, 2> matrix_2({1, 2});

        const auto& matrix_result = TypeParam::function(matrix_1, matrix_2);

        EXPECT_EQ(TypeParam::operation_function(1, 1), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(2, 1), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 1), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(3, 2), matrix_result(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongLeftRow)
    {
        ml::data_structure::matrix::Matrix<int, 2, 2> matrix_1({1, 2, 3, 4});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongLeftColumn)
    {
        ml::data_structure::matrix::Matrix<int, 3, 3> matrix_1({1, 2, 3, 4, 5, 6, 7, 8});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongLeft)
    {
        ml::data_structure::matrix::Matrix<int, 2, 3> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_2({1, 2, 3, 4, 5, 6});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongRightRow)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 2, 2> matrix_2({1, 2, 3, 4});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongRightColumn)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 3, 3> matrix_2({1, 2, 3, 4, 5, 6, 7, 8});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticOperation, WrongRight)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix_1({1, 2, 3, 4, 5, 6});
        ml::data_structure::matrix::Matrix<int, 2, 3> matrix_2({1, 2, 3, 4, 5, 6});

        EXPECT_THROW(TypeParam::function(matrix_1, matrix_2), std::invalid_argument);
    }

    TYPED_TEST(DataStructureMatrixArithmeticScalarOperation, ScalarInPlace)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        TypeParam::function_in_place(matrix, 2);

        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 2), matrix(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 2), matrix(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 2), matrix(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 2), matrix(2, 1));
    }

    TYPED_TEST(DataStructureMatrixArithmeticScalarOperation, Scalar)
    {
        ml::data_structure::matrix::Matrix<int, 3, 2> matrix({1, 2, 3, 4, 5, 6});

        const auto& matrix_result = TypeParam::function(matrix, 2);

        EXPECT_EQ(TypeParam::operation_function(1, 2), matrix_result(0, 0));
        EXPECT_EQ(TypeParam::operation_function(2, 2), matrix_result(0, 1));
        EXPECT_EQ(TypeParam::operation_function(3, 2), matrix_result(1, 0));
        EXPECT_EQ(TypeParam::operation_function(4, 2), matrix_result(1, 1));
        EXPECT_EQ(TypeParam::operation_function(5, 2), matrix_result(2, 0));
        EXPECT_EQ(TypeParam::operation_function(6, 2), matrix_result(2, 1));
    }
} // namespace tests::unit_tests
