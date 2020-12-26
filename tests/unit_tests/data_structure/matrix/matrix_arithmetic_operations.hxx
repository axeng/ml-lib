/**
 ** @file tests/unit_tests/data_structure/matrix/matrix_arithmetic_operations.hh
 ** @brief Implementation of templated functions for arithmetic operation tests functions of
 **ml::data_structure::matrix::Matrix
 */

namespace tests::unit_tests
{
    template <typename MATRIX_T>
    inline auto& PlusArithmeticOperation::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1.plus(matrix_2);
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto PlusArithmeticOperation::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return ml::data_structure::matrix::plus(matrix_1, matrix_2);
    }

    template <typename T>
    inline T PlusArithmeticOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 + element_2;
    }

    template <typename MATRIX_T>
    inline auto& PlusArithmeticOperationShortcut::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1 += matrix_2;
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto PlusArithmeticOperationShortcut::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return matrix_1 + matrix_2;
    }

    template <typename T>
    inline T PlusArithmeticOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 + element_2;
    }

    template <typename MATRIX_T>
    inline auto& MinusArithmeticOperation::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1.minus(matrix_2);
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto MinusArithmeticOperation::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return ml::data_structure::matrix::minus(matrix_1, matrix_2);
    }

    template <typename T>
    inline T MinusArithmeticOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 - element_2;
    }

    template <typename MATRIX_T>
    inline auto& MinusArithmeticOperationShortcut::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1 -= matrix_2;
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto MinusArithmeticOperationShortcut::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return matrix_1 - matrix_2;
    }

    template <typename T>
    inline T MinusArithmeticOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 - element_2;
    }

    template <typename MATRIX_T>
    inline auto& MultipliesArithmeticOperation::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1.multiplies(matrix_2);
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto MultipliesArithmeticOperation::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return ml::data_structure::matrix::multiplies(matrix_1, matrix_2);
    }

    template <typename T>
    inline T MultipliesArithmeticOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 * element_2;
    }

    template <typename MATRIX_T>
    inline auto& MultipliesArithmeticOperationShortcut::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1 *= matrix_2;
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto MultipliesArithmeticOperationShortcut::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return matrix_1 * matrix_2;
    }

    template <typename T>
    inline T MultipliesArithmeticOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 * element_2;
    }

    template <typename MATRIX_T>
    inline auto& DividesArithmeticOperation::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1.divides(matrix_2);
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto DividesArithmeticOperation::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return ml::data_structure::matrix::divides(matrix_1, matrix_2);
    }

    template <typename T>
    inline T DividesArithmeticOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 / element_2;
    }

    template <typename MATRIX_T>
    inline auto& DividesArithmeticOperationShortcut::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1 /= matrix_2;
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto DividesArithmeticOperationShortcut::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return matrix_1 / matrix_2;
    }

    template <typename T>
    inline T DividesArithmeticOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 / element_2;
    }

    template <typename MATRIX_T>
    inline auto& ModulusArithmeticOperation::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1.modulus(matrix_2);
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto ModulusArithmeticOperation::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return ml::data_structure::matrix::modulus(matrix_1, matrix_2);
    }

    template <typename T>
    inline T ModulusArithmeticOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 % element_2;
    }

    template <typename MATRIX_T>
    inline auto& ModulusArithmeticOperationShortcut::function_in_place(MATRIX_T& matrix_1, const MATRIX_T& matrix_2)
    {
        return matrix_1 %= matrix_2;
    }

    template <typename MATRIX_T_1, typename MATRIX_T_2>
    inline auto ModulusArithmeticOperationShortcut::function(const MATRIX_T_1& matrix_1, const MATRIX_T_2& matrix_2)
    {
        return matrix_1 % matrix_2;
    }

    template <typename T>
    inline T ModulusArithmeticOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 % element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& PlusArithmeticScalarOperation::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix.plus_scalar(scalar);
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto PlusArithmeticScalarOperation::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return ml::data_structure::matrix::plus_scalar(matrix, scalar);
    }

    template <typename T>
    inline T PlusArithmeticScalarOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 + element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& PlusArithmeticScalarOperationShortcut::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix += scalar;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto PlusArithmeticScalarOperationShortcut::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix + scalar;
    }

    template <typename T>
    inline T PlusArithmeticScalarOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 + element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& MinusArithmeticScalarOperation::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix.minus_scalar(scalar);
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto MinusArithmeticScalarOperation::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return ml::data_structure::matrix::minus_scalar(matrix, scalar);
    }

    template <typename T>
    inline T MinusArithmeticScalarOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 - element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& MinusArithmeticScalarOperationShortcut::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix -= scalar;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto MinusArithmeticScalarOperationShortcut::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix - scalar;
    }

    template <typename T>
    inline T MinusArithmeticScalarOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 - element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& MultipliesArithmeticScalarOperation::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix.multiplies_scalar(scalar);
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto MultipliesArithmeticScalarOperation::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return ml::data_structure::matrix::multiplies_scalar(matrix, scalar);
    }

    template <typename T>
    inline T MultipliesArithmeticScalarOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 * element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& MultipliesArithmeticScalarOperationShortcut::function_in_place(MATRIX_T& matrix,
                                                                                const SCALAR_T& scalar)
    {
        return matrix *= scalar;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto MultipliesArithmeticScalarOperationShortcut::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix * scalar;
    }

    template <typename T>
    inline T MultipliesArithmeticScalarOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 * element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& DividesArithmeticScalarOperation::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix.divides_scalar(scalar);
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto DividesArithmeticScalarOperation::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return ml::data_structure::matrix::divides_scalar(matrix, scalar);
    }

    template <typename T>
    inline T DividesArithmeticScalarOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 / element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& DividesArithmeticScalarOperationShortcut::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix /= scalar;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto DividesArithmeticScalarOperationShortcut::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix / scalar;
    }

    template <typename T>
    inline T DividesArithmeticScalarOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 / element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& ModulusArithmeticScalarOperation::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix.modulus_scalar(scalar);
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto ModulusArithmeticScalarOperation::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return ml::data_structure::matrix::modulus_scalar(matrix, scalar);
    }

    template <typename T>
    inline T ModulusArithmeticScalarOperation::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 % element_2;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto& ModulusArithmeticScalarOperationShortcut::function_in_place(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix %= scalar;
    }

    template <typename MATRIX_T, typename SCALAR_T>
    inline auto ModulusArithmeticScalarOperationShortcut::function(MATRIX_T& matrix, const SCALAR_T& scalar)
    {
        return matrix % scalar;
    }

    template <typename T>
    inline T ModulusArithmeticScalarOperationShortcut::operation_function(const T& element_1, const T& element_2)
    {
        return element_1 % element_2;
    }
} // namespace tests::unit_tests
