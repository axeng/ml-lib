/**
 ** @file tests/unit_tests/data_structure/iterator/step_iterator.hh
 ** @brief Declarations for step iterator tests functions of ml::data_structure::iterator::StepIterator
 */

#pragma once

#include "data_structure/iterator/step_iterator.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    /// Step iterators fixture class
    template <typename StepIterator>
    class DataStructureIteratorStepIteratorSteps : public testing::Test
    {
    public:
        /// Class constructor
        DataStructureIteratorStepIteratorSteps();

        /// Data to use for the tests
        const std::vector<int> data_;
        /// Number of step per iteration
        const typename StepIterator::difference_type step_count_;

        /// Number of element in the step iterator
        const size_t element_count_;

        /// First value in the data iterator
        const typename std::vector<int>::const_iterator iterator_first_;
        /// Last value in the data iterator
        const typename std::vector<int>::const_iterator iterator_last_;

        /// First value in the step iterator
        const StepIterator step_iterator_first_;
        /// Last value in the step iterator
        const StepIterator step_iterator_last_;
        /// First value - 1 in the step iterator
        const StepIterator step_iterator_begin_;
        /// Last value + 1 in the step iterator
        const StepIterator step_iterator_end_;
    };

    /// Types to test the step iterator step tests with
    using StepIteratorStepTypes =
        ::testing::Types<ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>,
                         ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 2>,
                         ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 3>,
                         ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 4>,
                         ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 5>>;
} // namespace tests::unit_tests

#include "unit_tests/data_structure/iterator/step_iterator.hxx"
