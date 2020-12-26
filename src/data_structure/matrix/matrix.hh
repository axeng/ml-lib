/**
 ** @file src/data_structure/matrix/matrix.hh
 ** @brief Declaration of ml::data_structure::matrix::Matrix and related functions
 */

#pragma once

#include <array>
#include <functional>
#include <ostream>

#include "data_structure/iterator/step_iterator.hh"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ADD(a, b) ((a) + (b))

namespace ml::data_structure::matrix
{
    /// The Matrix structure
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    class Matrix
    {
    public:
        /// The type of the data container
        using data_array_t = std::array<DATA_TYPE, HEIGHT * WIDTH>;
        /// StepIterator for the columns of the matrix
        using column_step_iterator_t =
            ml::data_structure::iterator::StepIterator<typename data_array_t::iterator, WIDTH>;
        /// ConstStepIterator for the columns of the matrix
        using column_const_step_iterator_t =
            ml::data_structure::iterator::StepIterator<typename data_array_t::const_iterator, WIDTH>;

        /** @name Constructors
         ** \{ */

        /// @brief Instantiate a new matrix
        Matrix();

        /** @brief Instantiate a new matrix
         ** @param value The default value to fill the matrix with
         */
        explicit Matrix(const DATA_TYPE& value);

        /** @brief Instantiate a new matrix
         ** @param data The data to add in the matrix
         */
        explicit Matrix(const data_array_t& data);

        /** \} */

        /** @name Matrix Operations
         ** \{ */

        /** @brief Fill the matrix with one value
         ** @param value The value to fill the matrix with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill(const DATA_TYPE& value);

        /** @brief Fill a row with one value
         ** @param row_index The index of the row
         ** @param value The value to fill the row with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill_row(size_t row_index, const DATA_TYPE& value);

        /** @brief Fill a column with one value
         ** @param column_index The index of the column
         ** @param value The value to fill the column with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill_column(size_t column_index, const DATA_TYPE& value);

        /** @brief Fill the matrix using a generator
         ** @param generator The function which will be called for each value
         ** @return The reference to the current matrix
         */
        template <class Generator>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill_generator(const Generator& generator);

        /** @brief Fill a row with using a generator
         ** @param row_index The index of the row
         ** @param generator The function which will be called for each value
         ** @return The reference to the current matrix
         */
        template <class Generator>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill_row_generator(size_t row_index, const Generator& generator);

        /** @brief Fill a column using a generator
         ** @param column_index The index of the column
         ** @param generator The function which will be called for each value
         ** @return The reference to the current matrix
         */
        template <class Generator>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& fill_column_generator(size_t column_index, const Generator& generator);

        /** @brief Sort the matrix as it was a flat array in place
         ** @param compare The compare function, std::less by default
         ** @return The reference to the current matrix
         */
        template <class Compare = std::less<DATA_TYPE>>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& sort(const Compare& compare = Compare());

        /** @brief Sort the rows of the matrix in place
         ** @param compare The compare function, std::less by default
         ** @return The reference to the current matrix
         */
        template <class Compare = std::less<DATA_TYPE>>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& sort_rows(const Compare& compare = Compare());

        /** @brief Sort the columns of the matrix in place
         ** @param compare The compare function, std::less by default
         ** @return The reference to the current matrix
         */
        template <class Compare = std::less<DATA_TYPE>>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& sort_columns(const Compare& compare = Compare());

        /** @brief Transpose the matrix
         ** @return The new transposed matrix
         */
        Matrix<DATA_TYPE, WIDTH, HEIGHT> transpose() const;

        /** @brief Extract a sub matrix from the current matrix
         ** @tparam START_HEIGHT_INDEX The starting height index in the matrix
         ** @tparam START_WIDTH_INDEX The starting width index in the matrix
         ** @tparam SUB_HEIGHT The height of the sub matrix
         ** @tparam SUB_WIDTH The width of the sub matrix
         ** @return The extracted matrix
         */
        template <size_t START_HEIGHT_INDEX, size_t START_WIDTH_INDEX, size_t SUB_HEIGHT, size_t SUB_WIDTH>
        Matrix<DATA_TYPE, SUB_HEIGHT, SUB_WIDTH> sub_matrix() const;

        /** @brief Apply a function to every element in the matrix in place
         ** @param function The function to apply
         ** @return The reference to the current matrix
         */
        template <class Function>
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& apply(const Function& function);

        /** \} */

        /** @name Statistic Operations
         ** \{ */

        /** @brief Sum of all the element in the matrix
         ** @return The sum
         */
        DATA_TYPE sum() const;

        /** @brief Sum of all the columns
         ** @return The row matrix containing the sums
         */
        Matrix<DATA_TYPE, 1, WIDTH> sum_columns() const;

        /** @brief Sum of all the rows
         ** @return The column matrix containing the sums
         */
        Matrix<DATA_TYPE, HEIGHT, 1> sum_rows() const;

        /** @brief Min of all the element in the matrix
         ** @return The min
         */
        DATA_TYPE min() const;

        /** @brief Min of all the columns
         ** @return The row matrix containing the minimums
         */
        Matrix<DATA_TYPE, 1, WIDTH> min_columns() const;

        /** @brief Min of all the rows
         ** @return The column matrix containing the minimums
         */
        Matrix<DATA_TYPE, HEIGHT, 1> min_rows() const;

        /** @brief Max of all the element of the matrix
         ** @return The max
         */
        DATA_TYPE max() const;

        /** @brief Max of all the columns
         ** @return The row matrix containing the maximums
         */
        Matrix<DATA_TYPE, 1, WIDTH> max_columns() const;

        /** @brief Max of all the rows
         ** @return The column matrix containing the maximums
         */
        Matrix<DATA_TYPE, HEIGHT, 1> max_rows() const;

        /** @brief Mean of all the element of the matrix
         ** @return The mean
         */
        DATA_TYPE mean() const;

        /** @brief Mean of all the columns
         ** @return The row matrix containing the means
         */
        Matrix<DATA_TYPE, 1, WIDTH> mean_columns() const;

        /** @brief Mean of all the rows
         ** @return The column matrix containing the means
         */
        Matrix<DATA_TYPE, HEIGHT, 1> mean_rows() const;

        /** @brief Median of all the element of the matrix
         ** @return The median
         */
        DATA_TYPE median() const;

        /** @brief Median of all the columns
         ** @return The row matrix containing the medians
         */
        Matrix<DATA_TYPE, 1, WIDTH> median_columns() const;

        /** @brief Median of all the rows
         ** @return The column matrix containing the means
         */
        Matrix<DATA_TYPE, HEIGHT, 1> median_rows() const;

        /** @brief Variance of all the element of the matrix
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The variance
         */
        DATA_TYPE variance(size_t ddof = 0) const;

        /** @brief Variance of all the columns
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The row matrix containing the variances
         */
        Matrix<DATA_TYPE, 1, WIDTH> variance_columns(size_t ddof = 0) const;

        /** @brief Variance of all the rows
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The column matrix containing the variances
         */
        Matrix<DATA_TYPE, HEIGHT, 1> variance_rows(size_t ddof = 0) const;

        /** @brief Standard deviation of all the element of the matrix
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The standard deviation
         */
        DATA_TYPE standard_deviation(size_t ddof = 0) const;

        /** @brief Standard deviation of all the columns
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The row matrix containing the standard deviations
         */
        Matrix<DATA_TYPE, 1, WIDTH> standard_deviation_columns(size_t ddof = 0) const;

        /** @brief Standard deviation of all the rows
         ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
         ** @return The column matrix containing the standard deviations
         */
        Matrix<DATA_TYPE, HEIGHT, 1> standard_deviation_rows(size_t ddof = 0) const;

        /** @brief Sum-product of all the element of the matrix
         ** @return The sum-product
         */
        DATA_TYPE sum_product() const;

        /** @brief Sum-product of all the columns
         ** @return The row matrix containing the sum-products
         */
        Matrix<DATA_TYPE, 1, WIDTH> sum_product_columns() const;

        /** @brief Sum-product of all the rows
         ** @return The column matrix containing the sum-products
         */
        Matrix<DATA_TYPE, HEIGHT, 1> sum_product_rows() const;

        /** @brief Peak to peak of all the element of the matrix
         ** @return The peak to peak
         */
        DATA_TYPE peak_to_peak() const;

        /** @brief Peak to peak of all the columns
         ** @return The row matrix containing the peak to peaks
         */
        Matrix<DATA_TYPE, 1, WIDTH> peak_to_peak_columns() const;

        /** @brief Peak to peak of all the rows
         ** @return The column matrix containing the peak to peaks
         */
        Matrix<DATA_TYPE, HEIGHT, 1> peak_to_peak_rows() const;

        /** \} */

        /** @name Arithmetic Operations
         ** \{ */

        /** @brief Negate element-wise in place
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& negate();

        /** @brief Compute a classic addition in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& plus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute a classic subtraction in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& minus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise multiplication in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& multiplies(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise division in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& divides(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise modulo in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& modulus(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Addition of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& plus_scalar(const DATA_TYPE& scalar);

        /** @brief Subtraction of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& minus_scalar(const DATA_TYPE& scalar);

        /** @brief Multiplication of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& multiplies_scalar(const DATA_TYPE& scalar);

        /** @brief Division of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& divides_scalar(const DATA_TYPE& scalar);

        /** @brief Modulus of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& modulus_scalar(const DATA_TYPE& scalar);

        /** \} */

        /** @name Arithmetic Operators
         ** \{ */

        /** @brief Compute a classic addition in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator+=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute a classic subtraction in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator-=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise multiplication in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator*=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise division in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator/=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Compute an element-wise modulo in place
         ** @param rhs The other matrix to compute the operation with
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator%=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

        /** @brief Addition of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator+=(const DATA_TYPE& scalar);

        /** @brief Subtraction of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator-=(const DATA_TYPE& scalar);

        /** @brief Multiplication of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator*=(const DATA_TYPE& scalar);

        /** @brief Division of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator/=(const DATA_TYPE& scalar);

        /** @brief Modulus of each element of the matrix with a scalar in place
         ** @param scalar The scalar
         ** @return The reference to the current matrix
         */
        Matrix<DATA_TYPE, HEIGHT, WIDTH>& operator%=(const DATA_TYPE& scalar);

        /** \} */

        /** @name Accessors
         ** \{ */

        /** @brief Access an element of the matrix without bound checking
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The reference to the element
         */
        DATA_TYPE& operator()(size_t height_index, size_t width_index);

        /** @brief Return an element of the matrix without bound checking
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The element
         */
        const DATA_TYPE& operator()(size_t height_index, size_t width_index) const;

        /** @brief Access an element of the matrix with bound checking
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The reference to the element
         */
        DATA_TYPE& at(size_t height_index, size_t width_index);

        /** @brief Return an element of the matrix with bound checking
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The element
         */
        const DATA_TYPE& at(size_t height_index, size_t width_index) const;

        /** @brief Access the raw data of the matrix
         ** @return The reference to the raw data
         */
        data_array_t& data();

        /** @brief Return the raw data of the matrix
         ** @return The raw data
         */
        const data_array_t& data() const;

        /** @brief Access an element in the matrix in the frame of broadcasting
         ** @param height_index The height index of the element
         ** @param width_index The width index of the element
         ** @return The element
         */
        const DATA_TYPE& get_broadcast_value(size_t height_index, size_t width_index) const;

        /** @brief Get the height of the matrix
         ** @return The height of the matrix
         */
        static constexpr size_t get_height();

        /** @brief Get the width of the matrix
         ** @return The width of the matrix
         */
        static constexpr size_t get_width();

        /** \} */

    private:
        /// The matrix data
        data_array_t data_;
    };

    /** @brief Sort a matrix
     ** @param matrix The matrix to sort
     ** @param compare The compare function, std::less by default
     ** @return The new sorted matrix
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare = std::less<DATA_TYPE>>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> sort(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                          const Compare& compare = Compare());

    /** @brief Sort the rows of a matrix
     ** @param matrix The matrix to sort
     ** @param compare The compare function, std::less by default
     ** @return The new sorted matrix
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare = std::less<DATA_TYPE>>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> sort_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                               const Compare& compare = Compare());

    /** @brief Sort the columns of a matrix
     ** @param matrix The matrix to sort
     ** @param compare The compare function, std::less by default
     ** @return The new sorted matrix
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Compare = std::less<DATA_TYPE>>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> sort_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                  const Compare& compare = Compare());

    /** @brief Transpose a matrix
     ** @param matrix The matrix
     ** @return The new transposed matrix
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, WIDTH, HEIGHT> transpose(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Extract a sub matrix from a matrix
     ** @tparam START_HEIGHT_INDEX The starting height index in the matrix
     ** @tparam START_WIDTH_INDEX The starting width index in the matrix
     ** @tparam SUB_HEIGHT The height of the sub matrix
     ** @tparam SUB_WIDTH The width of the sub matrix
     ** @param matrix The matrix to extract from
     ** @return The extracted matrix
     */
    template <size_t START_HEIGHT_INDEX,
              size_t START_WIDTH_INDEX,
              size_t SUB_HEIGHT,
              size_t SUB_WIDTH,
              typename DATA_TYPE,
              size_t HEIGHT,
              size_t WIDTH>
    Matrix<DATA_TYPE, SUB_HEIGHT, SUB_WIDTH> sub_matrix(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Apply a function to every element in a matrix
     ** @param matrix The matrix
     ** @param function The function to apply
     ** @return The matrix with the new elements
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH, class Function>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> apply(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, const Function& function);

    /** @brief Concatenate two matrix horizontally
     ** @param lhs The first matrix (will be at the left)
     ** @param rhs The second matrix (will be at the right)
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, HEIGHT, ADD(WIDTH_1, WIDTH_2)>
    horizontal_concatenate(const Matrix<DATA_TYPE, HEIGHT, WIDTH_1>& lhs,
                           const Matrix<DATA_TYPE, HEIGHT, WIDTH_2>& rhs);

    /** @brief Concatenate two matrix vertically
     ** @param lhs The first matrix (will be on top)
     ** @param rhs The second matrix (will be on bottom)
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH>
    Matrix<DATA_TYPE, ADD(HEIGHT_1, HEIGHT_2), WIDTH>
    vertical_concatenate(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH>& rhs);

    /** @brief Sum of all the element in a matrix
     ** @param matrix The matrix
     ** @return The sum
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE sum(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Sum of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the sums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> sum_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Sum of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the sums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> sum_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Min of all the element in a matrix
     ** @param matrix The matrix
     ** @return The min
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE min(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Min of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the minimums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> min_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Min of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the minimums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> min_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Max of all the element in a matrix
     ** @param matrix The matrix
     ** @return The max
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE max(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Max of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the maximums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> max_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Max of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the maximums
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> max_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Mean of all the element in a matrix
     ** @param matrix The matrix
     ** @return The mean
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE mean(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Mean of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the means
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> mean_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Mean of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the means
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> mean_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Median of all the element in a matrix
     ** @param matrix The matrix
     ** @return The median
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE median(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Median of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the medians
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> median_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Median of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the medians
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> median_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Variance of all the element in a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The variance
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE variance(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof = 0);

    /** @brief Variance of all the columns of a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The row matrix containing the variances
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> variance_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof = 0);

    /** @brief Variance of all the rows of a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The column matrix containing the variances
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> variance_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof = 0);

    /** @brief Standard deviation of all the element in a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The standard deviation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE standard_deviation(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, size_t ddof = 0);

    /** @brief Standard deviation of all the columns of a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The row matrix containing the standard deviations
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> standard_deviation_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                           size_t ddof = 0);

    /** @brief Standard deviation of all the rows of a matrix
     ** @param matrix The matrix
     ** @param ddof The divisor used in the calculation is N - ddof, 0 by default
     ** @return The column matrix containing the standard deviations
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> standard_deviation_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                         size_t ddof = 0);

    /** @brief Sum-product of all the element in a matrix
     ** @param matrix The matrix
     ** @return The sum-product
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE sum_product(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Sum-product of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the sum-products
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> sum_product_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Sum-product of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the sum-products
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> sum_product_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Peak to peak of all the element in a matrix
     ** @param matrix The matrix
     ** @return The peak to peak
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    DATA_TYPE peak_to_peak(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Peak to peak of all the columns of a matrix
     ** @param matrix The matrix
     ** @return The row matrix containing the peak to peaks
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, 1, WIDTH> peak_to_peak_columns(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Peak to peak of all the rows of a matrix
     ** @param matrix The matrix
     ** @return The column matrix containing the peak to peaks
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, 1> peak_to_peak_rows(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Negate a matrix
     ** @param matrix The matrix
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> negate(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Compute a classic matrix addition, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    plus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute a classic matrix subtraction, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    minus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise multiplication, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    multiplies(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise division, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    divides(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise division, modulo implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    modulus(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Addition of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> plus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                 const DATA_TYPE& scalar);

    /** @brief Subtraction of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> minus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                  const DATA_TYPE& scalar);

    /** @brief Multiplication of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> multiplies_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                       const DATA_TYPE& scalar);

    /** @brief Division of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> divides_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                    const DATA_TYPE& scalar);

    /** @brief Modulus of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> modulus_scalar(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix,
                                                    const DATA_TYPE& scalar);

    /** @brief Compute a classic multiplication of two matrix
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t M, size_t N, size_t P>
    Matrix<DATA_TYPE, M, P> multiplies_matrix(const Matrix<DATA_TYPE, M, N>& lhs, const Matrix<DATA_TYPE, N, P>& rhs);

    /** @brief Negate a matrix
     ** @param matrix The matrix
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> operator-(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);

    /** @brief Compute a classic matrix addition, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator+(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute a classic matrix subtraction, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator-(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise multiplication, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator*(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise division, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator/(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Compute an element-wise modulus, broadcasting implemented
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT_1, size_t HEIGHT_2, size_t WIDTH_1, size_t WIDTH_2>
    Matrix<DATA_TYPE, MAX(HEIGHT_1, HEIGHT_2), MAX(WIDTH_1, WIDTH_2)>
    operator%(const Matrix<DATA_TYPE, HEIGHT_1, WIDTH_1>& lhs, const Matrix<DATA_TYPE, HEIGHT_2, WIDTH_2>& rhs);

    /** @brief Multiplication of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> operator*(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, const DATA_TYPE& scalar);

    /** @brief Division of each element of a matrix with a scalar
     ** @param matrix The matrix
     ** @param scalar The scalar
     ** @return The new matrix containing the result of the operation
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    Matrix<DATA_TYPE, HEIGHT, WIDTH> operator/(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, const DATA_TYPE& scalar);

    /** @brief Compare matrix, check element by element if the matrix are equals
     ** @param lhs The first matrix
     ** @param rhs The second matrix
     ** @return True if the matrix contain the same elements, false otherwise
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool compare(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

    /** @brief Equal operator, check element by element if the matrix are equals
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return True if the matrix contain the same elements, false otherwise
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool operator==(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

    /** @brief Not equal operator, check element by element if the matrix are not equals
     ** @param lhs The matrix at the left of the operator
     ** @param rhs The matrix at the right of the operator
     ** @return False if the matrix contain the same elements, true otherwise
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    bool operator!=(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& lhs, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& rhs);

    /** @brief Print a matrix
     ** @param matrix The matrix to print
     ** @param os The stream to print on
     ** @return The reference to the stream
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    std::ostream& print(const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix, std::ostream& os);

    /** @brief Print a matrix
     ** @param os The stream to print on
     ** @param matrix The matrix to print
     ** @return The reference to the stream
     */
    template <typename DATA_TYPE, size_t HEIGHT, size_t WIDTH>
    std::ostream& operator<<(std::ostream& os, const Matrix<DATA_TYPE, HEIGHT, WIDTH>& matrix);
} // namespace ml::data_structure::matrix

#include "data_structure/matrix/matrix.hxx"
#include "data_structure/matrix/matrix_apply.hxx"
#include "data_structure/matrix/matrix_arithmetic_operations.hxx"
#include "data_structure/matrix/matrix_comparison.hxx"
#include "data_structure/matrix/matrix_concatenate.hxx"
#include "data_structure/matrix/matrix_fill.hxx"
#include "data_structure/matrix/matrix_multiplies_matrix.hxx"
#include "data_structure/matrix/matrix_print.hxx"
#include "data_structure/matrix/matrix_sort.hxx"
#include "data_structure/matrix/matrix_statistics.hxx"
#include "data_structure/matrix/matrix_sub_matrix.hxx"
#include "data_structure/matrix/matrix_transpose.hxx"
