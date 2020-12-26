/**
 ** @file src/data_structure/iterator/step_iterator.hh
 ** @brief Implementation of ml::data_structure::iterator::StepIterator functions
 */

#include <stdexcept>

namespace ml::data_structure::iterator
{
    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    StepIterator<Iterator, STEP>::StepIterator(const Iterator& iterator, const Iterator& first, const Iterator& last)
        : iterator_(iterator > last ? last + 1 : (iterator < first ? first - 1 : iterator))
        , first_(first)
        , last_(last)
    {
        if ((last - first) % STEP != 0)
        {
            throw std::invalid_argument(
                "The first and last elements must corresponds to the first and last element of the container.");
        }
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline typename StepIterator<Iterator, STEP>::pointer StepIterator<Iterator, STEP>::operator->() const
    {
        return this->iterator_.operator->();
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline typename StepIterator<Iterator, STEP>::reference StepIterator<Iterator, STEP>::operator*() const
    {
        return *this->iterator_;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline typename StepIterator<Iterator, STEP>::reference
    StepIterator<Iterator, STEP>::operator[](const difference_type& index) const
    {
        return this->iterator_[index * STEP];
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP>& StepIterator<Iterator, STEP>::operator++()
    {
        return *this += 1;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP> StepIterator<Iterator, STEP>::operator++(int)
    {
        StepIterator<Iterator, STEP> copy = *this;
        *this += 1;
        return copy;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP>& StepIterator<Iterator, STEP>::operator--()
    {
        return *this -= 1;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP> StepIterator<Iterator, STEP>::operator--(int)
    {
        StepIterator<Iterator, STEP> copy = *this;
        *this -= 1;
        return copy;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    StepIterator<Iterator, STEP>& StepIterator<Iterator, STEP>::operator+=(difference_type increment)
    {
        if (increment > 0 && this->iterator_ < this->first_)
        {
            this->iterator_ = this->first_;
            increment -= 1;
        }
        else if (increment < 0 && this->iterator_ > this->last_)
        {
            this->iterator_ = this->last_;
            increment += 1;
        }

        this->iterator_ += increment * STEP;

        if (this->iterator_ > this->last_)
            this->iterator_ = this->last_ + 1;
        else if (this->iterator_ < this->first_)
            this->iterator_ = this->first_ - 1;

        return *this;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP>& StepIterator<Iterator, STEP>::operator-=(const difference_type& increment)
    {
        return *this += -increment;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP>
    operator+(const typename std::iterator_traits<Iterator>::difference_type& increment,
              const StepIterator<Iterator, STEP>& iterator)
    {
        return iterator + increment;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP> StepIterator<Iterator, STEP>::operator+(const difference_type& increment) const
    {
        StepIterator<Iterator, STEP> copy = *this;
        copy += increment;
        return copy;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline StepIterator<Iterator, STEP> StepIterator<Iterator, STEP>::operator-(const difference_type& increment) const
    {
        StepIterator<Iterator, STEP> copy = *this;
        copy -= increment;
        return copy;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline typename StepIterator<Iterator, STEP>::difference_type
    StepIterator<Iterator, STEP>::operator-(const StepIterator<Iterator, STEP>& rhs) const
    {
        auto total_count = std::distance(rhs.iterator_, this->iterator_);

        auto count = total_count / STEP;
        if (total_count % STEP != 0)
            count += 1;

        return count;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator==(const StepIterator<Iterator, STEP>& rhs) const
    {
        return this->iterator_ == rhs.iterator_;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator!=(const StepIterator<Iterator, STEP>& rhs) const
    {
        return !(*this == rhs);
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator<(const StepIterator& rhs) const
    {
        return this->iterator_ < rhs.iterator_;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator>(const StepIterator& rhs) const
    {
        return rhs < *this;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator<=(const StepIterator& rhs) const
    {
        return *this < rhs || *this == rhs;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline bool StepIterator<Iterator, STEP>::operator>=(const StepIterator& rhs) const
    {
        return *this > rhs || *this == rhs;
    }

    template <class Iterator, typename std::iterator_traits<Iterator>::difference_type STEP>
    inline constexpr typename StepIterator<Iterator, STEP>::difference_type StepIterator<Iterator, STEP>::get_step()
    {
        return STEP;
    }
} // namespace ml::data_structure::iterator