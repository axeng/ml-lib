/**
 ** @file src/data_structure/iterator/step_iterator.hh
 ** @brief Declaration of ml::data_structure::iterator::StepIterator functions
 */

#pragma once

#include <vector>

namespace ml::data_structure::iterator
{
    /// StepIterator structure, meet the requirements of a LegacyRandomAccessIterator
    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    class StepIterator
    {
    public:
        /// Iterator difference type
        using difference_type = typename std::iterator_traits<Iterator>::difference_type;
        /// Iterator value type
        using value_type = typename std::iterator_traits<Iterator>::value_type;
        /// Iterator reference type
        using reference = typename std::iterator_traits<Iterator>::reference;
        /// Iterator pointer type
        using pointer = typename std::iterator_traits<Iterator>::pointer;
        /// Iterator category type
        using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;

        /** @name Constructors
         ** \{ */

        /// Instantiate a StepIterator
        StepIterator() = default;

        /** @brief Instantiate a StepIterator
         ** @param iterator The base iterator
         ** @param first The first iterator of the container
         ** @param last The last iterator of the container
         */
        StepIterator(const Iterator& iterator, const Iterator& first, const Iterator& last);

        /** \} */

        /** @name Accessors
         ** \{ */

        /** @brief Member of pointer operator
         ** @return A pointer to the value
         */
        pointer operator->() const;

        /** @brief Indirect operator
         ** @return A reference to the value
         */
        reference operator*() const;

        /** @brief Subscript operator
         ** @param index Subscript index
         ** @return The value at the index
         */
        reference operator[](const difference_type& index) const;

        /** \} */

        /** @name Operators
         ** \{ */

        /** @brief Pre-increment operator
         ** @return A reference to the iterator
         */
        StepIterator<Iterator, STEP>& operator++();

        /** @brief Post-increment operator
         ** @return A copy to the iterator before the increment
         */
        StepIterator<Iterator, STEP> operator++(int);

        /** @brief Pre-decrement operator
         ** @return A reference to the iterator
         */
        StepIterator<Iterator, STEP>& operator--();

        /** @brief Post-decrement operator
         ** @return A copy to the iterator before the decrement
         */
        StepIterator<Iterator, STEP> operator--(int);

        /** @brief Addition assignment operator
         ** @param increment The increment
         ** @return A reference to the iterator
         */
        StepIterator<Iterator, STEP>& operator+=(difference_type increment);

        /** @brief Subtraction assignment operator
         ** @param increment The increment
         ** @return A reference to the iterator
         */
        StepIterator<Iterator, STEP>& operator-=(const difference_type& increment);

        /** @brief Addition operator
         ** @param increment The increment
         ** @return The new iterator
         */
        StepIterator<Iterator, STEP> operator+(const difference_type& increment) const;

        /** @brief Subtraction operator
         ** @param increment The increment
         ** @return The new iterator
         */
        StepIterator<Iterator, STEP> operator-(const difference_type& increment) const;

        /** @brief Distance operator
         ** @param rhs The other iterator
         ** @return The distance
         */
        difference_type operator-(const StepIterator<Iterator, STEP>& rhs) const;

        /** \} */

        /** @name Comparators
         ** \{ */

        /** @brief Equal to operator
         ** @param rhs The other iterator
         ** @return True if both iterator are equal
         */
        bool operator==(const StepIterator<Iterator, STEP>& rhs) const;

        /** @brief Not equal to operator
         ** @param rhs The other iterator
         ** @return True if both iterator are not equal
         */
        bool operator!=(const StepIterator<Iterator, STEP>& rhs) const;

        /** @brief Less than operator
         ** @param rhs The other iterator
         ** @return True if the current iterator is smaller than the other
         */
        bool operator<(const StepIterator& rhs) const;

        /** @brief Greater than operator
         ** @param rhs The other iterator
         ** @return True if the current iterator is greater than the other
         */
        bool operator>(const StepIterator& rhs) const;

        /** @brief Less than or equal operator
         ** @param rhs The other iterator
         ** @return True if the current iterator is smaller or equal than the other
         */
        bool operator<=(const StepIterator& rhs) const;

        /** @brief Greater than or equal operator
         ** @param rhs The other iterator
         ** @return True if the current iterator is greater or equal than the other
         */
        bool operator>=(const StepIterator& rhs) const;

        /** @brief Get the current step of the StepIterator
         ** @return The step
         */
        static constexpr difference_type get_step();

        /** \} */

    private:
        /// The base iterator
        Iterator iterator_;
        /// The last iterator of the container
        Iterator first_;
        /// The last iterator of the container
        Iterator last_;
    };

    /** @brief Addition operator
     ** @param increment The increment
     ** @param iterator The iterator
     ** @return The new iterator
     */
    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    StepIterator<Iterator, STEP> operator+(const typename std::iterator_traits<Iterator>::difference_type& increment,
                                           const StepIterator<Iterator, STEP>& iterator);
} // namespace ml::data_structure::iterator

#include "data_structure/iterator/step_iterator.hxx"
