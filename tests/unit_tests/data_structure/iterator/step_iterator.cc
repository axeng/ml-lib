/**
 ** @file tests/unit_tests/data_structure/iterator/iterator.cc
 ** @brief Tests for the ml::data_structure::iterator::StepIterator functions
 */

#include "data_structure/iterator/step_iterator.hh"

#include <cmath>

#include "gtest/gtest.h"
#include "unit_tests/data_structure/iterator/step_iterator.hh"

namespace tests::unit_tests
{
    TYPED_TEST_SUITE(DataStructureIteratorStepIteratorSteps, StepIteratorStepTypes, );

    TEST(DataStructureIteratorStepIterator, Requirements)
    {
        EXPECT_EQ(
            typeid(std::vector<int>::const_iterator::difference_type),
            typeid(ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>::difference_type));

        EXPECT_EQ(typeid(std::vector<int>::const_iterator::value_type),
                  typeid(ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>::value_type));

        EXPECT_EQ(typeid(std::vector<int>::const_iterator::reference),
                  typeid(ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>::reference));

        EXPECT_EQ(typeid(std::vector<int>::const_iterator::pointer),
                  typeid(ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>::pointer));

        EXPECT_EQ(
            typeid(std::vector<int>::const_iterator::iterator_category),
            typeid(ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1>::iterator_category));
    }

    TEST(DataStructureIteratorStepIterator, Constructor)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});
        EXPECT_NO_THROW(([&] {
            ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
                data.cbegin(), data.cbegin(), data.cend() - 1);
        }()));
    }

    TEST(DataStructureIteratorStepIterator, ConstructorAfterLast)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
            data.cend(), data.cbegin(), data.cbegin() + 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_end(
            data.cbegin() + 2, data.cbegin(), data.cbegin() + 1);

        EXPECT_EQ(step_iterator_end, step_iterator);
    }

    TEST(DataStructureIteratorStepIterator, ConstructorBeforeFirst)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
            data.cbegin(), data.cbegin() + 2, data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_begin(
            data.cbegin() + 1, data.cbegin() + 2, data.cend() - 1);

        EXPECT_EQ(step_iterator_begin, step_iterator);
    }

    TEST(DataStructureIteratorStepIterator, MemberOfPointerOperator)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        for (auto it = data.cbegin(); it < data.cend(); ++it)
        {
            ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
                it, data.cbegin(), data.cend() - 1);
            EXPECT_EQ(it.operator->(), step_iterator.operator->());
        }
    }

    TEST(DataStructureIteratorStepIterator, IndirectOperator)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        for (auto it = data.cbegin(); it < data.cend(); ++it)
        {
            ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
                it, data.cbegin(), data.cend() - 1);
            EXPECT_EQ(*it, *step_iterator);
        }
    }

    TEST(DataStructureIteratorStepIterator, IndirectOperatorModifyValue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        for (size_t i = 0; i < data.size(); i++)
        {
            ml::data_structure::iterator::StepIterator<std::vector<int>::iterator, 1> step_iterator(
                data.begin() + i, data.begin(), data.end() - 1);
            *step_iterator += 1;

            EXPECT_EQ(i + 2, data[i]);
        }
    }

    TEST(DataStructureIteratorStepIterator, SubscriptOperator)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        for (auto it = data.cbegin(); it < data.cend(); ++it)
        {
            ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator(
                it, data.cbegin(), data.cend() - 1);

            for (long count_left = 0; count_left < data.cend() - it; count_left++)
            {
                EXPECT_EQ(it[count_left], step_iterator[count_left]);
            }
        }
    }

    TEST(DataStructureIteratorStepIterator, SubscriptOperatorModifyValue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        for (size_t i = 0; i < data.size(); i++)
        {
            ml::data_structure::iterator::StepIterator<std::vector<int>::iterator, 1> step_iterator(
                data.begin() + i, data.begin(), data.end() - 1);
            step_iterator[0] += 1;

            EXPECT_EQ(i + 2, data[i]);
        }
    }

    TEST(DataStructureIteratorStepIterator, EqualOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first == step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, EqualOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first == step_iterator_last);
    }

    TEST(DataStructureIteratorStepIterator, NotEqualOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first != step_iterator_last);
    }

    TEST(DataStructureIteratorStepIterator, NotEqualOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first != step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first < step_iterator_last);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_last < step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOperatorFalseSame)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first < step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_last > step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first > step_iterator_last);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOperatorFalseSame)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first > step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOrEqualOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first <= step_iterator_last);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOrEqualOperatorTrueSame)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first <= step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, LessThanOrEqualOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_last <= step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOrEqualOperatorTrue)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_last >= step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOrEqualOperatorTrueSame)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);

        ASSERT_TRUE(step_iterator_first >= step_iterator_first);
    }

    TEST(DataStructureIteratorStepIterator, GreaterThanOrEqualOperatorFalse)
    {
        std::vector<int> data({1, 2, 3, 4, 5, 6});

        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_first(
            data.cbegin(), data.cbegin(), data.cend() - 1);
        ml::data_structure::iterator::StepIterator<std::vector<int>::const_iterator, 1> step_iterator_last(
            data.cend() - 1, data.cbegin(), data.cend() - 1);

        ASSERT_FALSE(step_iterator_first >= step_iterator_last);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PreIncrementOperator)
    {
        auto iterator = this->iterator_first_;
        auto step_iterator = this->step_iterator_first_;

        for (size_t i = 0; i < this->element_count_; i++)
        {
            EXPECT_EQ(*iterator, *step_iterator);

            iterator += this->step_count_;
            const auto& step_iterator_increment = ++step_iterator;

            EXPECT_EQ(step_iterator, step_iterator_increment);
        }

        EXPECT_EQ(this->step_iterator_end_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PreIncrementOperatorFromBegin)
    {
        auto step_iterator_begin = this->step_iterator_begin_;
        const auto& step_iterator_increment = ++step_iterator_begin;

        EXPECT_EQ(this->step_iterator_first_, step_iterator_begin);
        EXPECT_EQ(step_iterator_begin, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PostIncrementOperator)
    {
        auto iterator = this->iterator_first_;
        auto step_iterator = this->step_iterator_first_;

        for (size_t i = 0; i < this->element_count_; i++)
        {
            const auto copy_step_iterator = step_iterator;

            EXPECT_EQ(*iterator, *step_iterator);

            iterator += this->step_count_;
            const auto& step_iterator_increment = step_iterator++;

            EXPECT_EQ(copy_step_iterator, step_iterator_increment);
        }

        EXPECT_EQ(this->step_iterator_end_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PostIncrementOperatorFromBegin)
    {
        auto step_iterator_begin = this->step_iterator_begin_;
        const auto& step_iterator_increment = step_iterator_begin++;

        EXPECT_EQ(this->step_iterator_first_, step_iterator_begin);
        EXPECT_EQ(this->step_iterator_begin_, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PreDecrementOperator)
    {
        auto iterator = this->iterator_last_;
        auto step_iterator = this->step_iterator_last_;

        for (size_t i = 0; i < this->element_count_; i++)
        {
            EXPECT_EQ(*iterator, *step_iterator);

            iterator -= this->step_count_;
            const auto& step_iterator_increment = --step_iterator;

            EXPECT_EQ(step_iterator, step_iterator_increment);
        }

        EXPECT_EQ(this->step_iterator_begin_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PreDecrementOperatorFromEnd)
    {
        auto step_iterator_end = this->step_iterator_end_;
        const auto& step_iterator_increment = --step_iterator_end;

        EXPECT_EQ(this->step_iterator_last_, step_iterator_end);
        EXPECT_EQ(step_iterator_end, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PostDecrementOperator)
    {
        auto iterator = this->iterator_last_;
        auto step_iterator = this->step_iterator_last_;

        for (size_t i = 0; i < this->element_count_; i++)
        {
            const auto copy_step_iterator = step_iterator;

            EXPECT_EQ(*iterator, *step_iterator);

            iterator -= this->step_count_;
            const auto& step_iterator_increment = step_iterator--;

            EXPECT_EQ(copy_step_iterator, step_iterator_increment);
        }

        EXPECT_EQ(this->step_iterator_begin_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, PostDecrementOperatorFromEnd)
    {
        auto step_iterator_end = this->step_iterator_end_;
        const auto& step_iterator_increment = step_iterator_end--;

        EXPECT_EQ(this->step_iterator_last_, step_iterator_end);
        EXPECT_EQ(this->step_iterator_end_, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionAssignmentOperator)
    {
        for (size_t i = 0; i < this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_first_;
            const auto& step_iterator_increment = step_iterator += i;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * i), *step_iterator);
            EXPECT_EQ(step_iterator, step_iterator_increment);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionAssignmentOperatorToEnd)
    {
        auto step_iterator = this->step_iterator_first_;
        const auto& step_iterator_increment = step_iterator += (this->element_count_ + 1);

        EXPECT_EQ(this->step_iterator_end_, step_iterator);
        EXPECT_EQ(step_iterator, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionAssignmentOperatorFromBegin)
    {
        for (size_t i = 1; i <= this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_begin_;
            const auto& step_iterator_increment = step_iterator += i;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * (i - 1)), *step_iterator);
            EXPECT_EQ(step_iterator, step_iterator_increment);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionAssignmentOperator)
    {
        for (size_t i = 0; i < this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_last_;
            const auto& step_iterator_increment = step_iterator -= i;

            EXPECT_EQ(*(this->iterator_last_ - this->step_count_ * i), *step_iterator);
            EXPECT_EQ(step_iterator, step_iterator_increment);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionAssignmentOperatorToBegin)
    {
        auto step_iterator = this->step_iterator_last_;
        const auto& step_iterator_increment = step_iterator -= (this->element_count_ + 1);

        EXPECT_EQ(this->step_iterator_begin_, step_iterator);
        EXPECT_EQ(step_iterator, step_iterator_increment);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionAssignmentOperatorFromEnd)
    {
        for (size_t i = 1; i <= this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_end_;
            const auto& step_iterator_increment = step_iterator -= i;

            EXPECT_EQ(*(this->iterator_last_ - this->step_count_ * (i - 1)), *step_iterator);
            EXPECT_EQ(step_iterator, step_iterator_increment);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionOperator)
    {
        for (size_t i = 0; i < this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_first_;
            const auto& step_iterator_increment = step_iterator + i;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * i), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_first_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionOperatorToEnd)
    {
        auto step_iterator = this->step_iterator_first_;
        const auto& step_iterator_increment = step_iterator + (this->element_count_ + 1);

        EXPECT_EQ(this->step_iterator_end_, step_iterator_increment);
        EXPECT_EQ(this->step_iterator_first_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, AdditionOperatorFromBegin)
    {
        for (size_t i = 1; i <= this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_begin_;
            const auto& step_iterator_increment = step_iterator + i;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * (i - 1)), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_begin_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, ReverseAdditionOperator)
    {
        for (size_t i = 0; i < this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_first_;
            const auto& step_iterator_increment = i + step_iterator;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * i), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_first_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, ReverseAdditionOperatorToEnd)
    {
        auto step_iterator = this->step_iterator_first_;
        const auto& step_iterator_increment = (this->element_count_ + 1) + step_iterator;

        EXPECT_EQ(this->step_iterator_end_, step_iterator_increment);
        EXPECT_EQ(this->step_iterator_first_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, ReverseAdditionOperatorFromBegin)
    {
        for (size_t i = 1; i <= this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_begin_;
            const auto& step_iterator_increment = i + step_iterator;

            EXPECT_EQ(*(this->iterator_first_ + this->step_count_ * (i - 1)), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_begin_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionOperator)
    {
        for (size_t i = 0; i < this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_last_;
            const auto& step_iterator_increment = step_iterator - i;

            EXPECT_EQ(*(this->iterator_last_ - this->step_count_ * i), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_last_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionOperatorToBegin)
    {
        auto step_iterator = this->step_iterator_last_;
        const auto& step_iterator_increment = step_iterator - (this->element_count_ + 1);

        EXPECT_EQ(this->step_iterator_begin_, step_iterator_increment);
        EXPECT_EQ(this->step_iterator_last_, step_iterator);
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, SubtractionOperatorFromEnd)
    {
        for (size_t i = 1; i <= this->element_count_; i++)
        {
            auto step_iterator = this->step_iterator_end_;
            const auto& step_iterator_increment = step_iterator - i;

            EXPECT_EQ(*(this->iterator_last_ - this->step_count_ * (i - 1)), *step_iterator_increment);
            EXPECT_EQ(this->step_iterator_end_, step_iterator);
        }
    }

    TYPED_TEST(DataStructureIteratorStepIteratorSteps, DistanceOperator)
    {
        auto step_iterator = this->step_iterator_first_;
        for (int i = this->element_count_; i >= 0; i--)
        {
            EXPECT_EQ(i, this->step_iterator_end_ - step_iterator);
            ++step_iterator;
        }
    }
} // namespace tests::unit_tests
