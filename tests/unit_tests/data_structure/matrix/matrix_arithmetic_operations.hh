/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_arithmetic_operations.hh
 ** @brief Declarations for arithmetic operation tests functions of ml::data_structure::matrix::Matrix
 */

#pragma once

#include "data_structure/matrix/matrix.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    /// Plus Arithmetic Operation functor-like class
    class PlusArithmeticOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Plus Arithmetic Operation shortcut functor-like class
    class PlusArithmeticOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Minus Arithmetic Operation functor-like class
    class MinusArithmeticOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Minus Arithmetic Operation shortcut functor-like class
    class MinusArithmeticOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Multiplies Arithmetic Operation functor-like class
    class MultipliesArithmeticOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Multiplies Arithmetic Operation shortcut functor-like class
    class MultipliesArithmeticOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Divides Arithmetic Operation functor-like class
    class DividesArithmeticOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Divides Arithmetic Operation shortcut functor-like class
    class DividesArithmeticOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Modulus Arithmetic Operation functor-like class
    class ModulusArithmeticOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Modulus Arithmetic Operation shortcut functor-like class
    class ModulusArithmeticOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T>
        static auto& function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T_1, typename MATRIX_T_2>
        static auto function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Plus Arithmetic Scalar Operation functor-like class
    class PlusArithmeticScalarOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Plus Arithmetic Scalar Operation shortcut functor-like class
    class PlusArithmeticScalarOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Minus Arithmetic Scalar Operation functor-like class
    class MinusArithmeticScalarOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Minus Arithmetic Scalar Operation shortcut functor-like class
    class MinusArithmeticScalarOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Multiplies Arithmetic Scalar Operation functor-like class
    class MultipliesArithmeticScalarOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Multiplies Arithmetic Scalar Operation shortcut functor-like class
    class MultipliesArithmeticScalarOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Divides Arithmetic Scalar Operation functor-like class
    class DividesArithmeticScalarOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Divides Arithmetic Scalar Operation shortcut functor-like class
    class DividesArithmeticScalarOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Modulus Arithmetic Scalar Operation functor-like class
    class ModulusArithmeticScalarOperation
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Modulus Arithmetic Scalar Operation shortcut functor-like class
    class ModulusArithmeticScalarOperationShortcut
    {
    public:
        /** @brief Function to test in place
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto& function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Function to test
         ** @param matrix_1 Matrix at the left of the operator
         ** @param matrix_2 Matrix at the right of the operator
         ** @return Result of the operation
         */
        template <typename MATRIX_T, typename SCALAR_T>
        static auto function(MATRIX_T& matrix, const SCALAR_T& scalar);

        /** @brief Reference function (element-wise)
         ** @param matrix_1 Element at the left of the operator
         ** @param matrix_2 Element at the right of the operator
         ** @return Result of the operation
         */
        template <typename T>
        static T operation_function(const T& element_1, const T& element_2);
    };

    /// Arithmetic Operation fixture class
    template <class ArithmeticOperation>
    class DataStructureMatrixArithmeticOperation : public testing::Test
    {};

    /// Arithmetic Scalar Operation fixture class
    template <class ArithmeticScalarOperation>
    class DataStructureMatrixArithmeticScalarOperation : public testing::Test
    {};

    /// Functor-class list to use for the arithmetic operation tests
    using ArithmeticOperations = ::testing::Types<PlusArithmeticOperation,
                                                  PlusArithmeticOperationShortcut,
                                                  MinusArithmeticOperation,
                                                  MinusArithmeticOperationShortcut,
                                                  MultipliesArithmeticOperation,
                                                  MultipliesArithmeticOperationShortcut,
                                                  DividesArithmeticOperation,
                                                  DividesArithmeticOperationShortcut,
                                                  ModulusArithmeticOperation,
                                                  ModulusArithmeticOperationShortcut>;

    /// Functor-class list to use for the arithmetic scalar operation tests
    using ArithmeticScalarOperations = ::testing::Types<PlusArithmeticScalarOperation,
                                                        PlusArithmeticScalarOperationShortcut,
                                                        MinusArithmeticScalarOperation,
                                                        MinusArithmeticScalarOperationShortcut,
                                                        MultipliesArithmeticScalarOperation,
                                                        MultipliesArithmeticScalarOperationShortcut,
                                                        DividesArithmeticScalarOperation,
                                                        DividesArithmeticScalarOperationShortcut,
                                                        ModulusArithmeticScalarOperation,
                                                        ModulusArithmeticScalarOperationShortcut>;
} // namespace tests::unit_tests

#include "unit_tests/data_structure/matrix/matrix_arithmetic_operations.hxx"
