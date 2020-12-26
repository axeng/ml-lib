/**
 ** @file tests/unit_tests/computation/statistic.cc
 ** @brief Tests for the ml::computation::statistic functions
 */

#include "unit_tests/computation/statistic.hh"

namespace tests::unit_tests
{
    TYPED_TEST_SUITE(ComputationStatistic, ComputationStatisticTypes, );

    TYPED_TEST(ComputationStatistic, SimpleEven)
    {
        std::vector<float> data({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f});
        auto result = TypeParam::function(data);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 6.0f, 4.0f, 5.0f, 3.0f, 2.0f}), result);
    }

    TYPED_TEST(ComputationStatistic, SimpleOdd)
    {
        std::vector<float> data({4.0f, 1.0f, 6.0f, 7.0f, 5.0f, 3.0f, 2.0f});
        auto result = TypeParam::function(data);

        EXPECT_FLOAT_EQ(TypeParam::test_function({4.0f, 1.0f, 6.0f, 7.0f, 5.0f, 3.0f, 2.0f}), result);
    }

    TYPED_TEST(ComputationStatistic, SimpleSortedEven)
    {
        std::vector<float> data({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
        auto result = TypeParam::function(data);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}), result);
    }

    TYPED_TEST(ComputationStatistic, SimpleSortedOdd)
    {
        std::vector<float> data({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f});
        auto result = TypeParam::function(data);

        EXPECT_FLOAT_EQ(TypeParam::test_function({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f}), result);
    }
} // namespace tests::unit_tests
