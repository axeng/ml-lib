/**
 ** @file tests/unit_tests/data_structure/iterator/step_iterator.hxx
 ** @brief Implementation of templated and inline functions for step iterator tests of
 **ml::data_structure::iterator::StepIterator
 */

namespace tests::unit_tests
{
    template <typename StepIterator>
    DataStructureIteratorStepIteratorSteps<StepIterator>::DataStructureIteratorStepIteratorSteps()
        : data_({1, 2, 3, 4, 5, 6})
        , step_count_(StepIterator::get_step())
        , element_count_(std::ceil((float)this->data_.size() / this->step_count_))
        , iterator_first_(this->data_.cbegin())
        , iterator_last_(this->data_.cbegin() + (this->element_count_ - 1) * this->step_count_)
        , step_iterator_first_(this->iterator_first_, this->iterator_first_, this->iterator_last_)
        , step_iterator_last_(this->iterator_last_, this->iterator_first_, this->iterator_last_)
        , step_iterator_begin_(this->iterator_first_ - 1, this->iterator_first_, this->iterator_last_)
        , step_iterator_end_(this->iterator_last_ + 1, this->iterator_first_, this->iterator_last_)
    {}
} // namespace tests::unit_tests
