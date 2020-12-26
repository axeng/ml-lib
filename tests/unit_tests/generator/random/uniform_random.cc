/**
 ** @file tests/unit_tests/generator/random/uniform_random.cc
 ** @brief Tests for the ml::generator::random::UniformRandom functions
 */

#include "generator/random/uniform_random.hh"

#include "computation/statistic.hh"
#include "gtest/gtest.h"

namespace tests::unit_tests
{
    TEST(GeneratorRandomUniformRandom, Range)
    {
        auto generator = ml::generator::random::UniformRandom<float>(0.0f, 1.0f);

        for (size_t i = 0; i < 10000; i++)
        {
            auto random_number = generator();
            EXPECT_LE(0.0f, random_number);
            EXPECT_GT(1.0f, random_number);
        }
    }

    TEST(GeneratorRandomUniformRandom, Distribution)
    {
        std::vector<float> data(100000);
        std::generate_n(data.begin(), data.size(), ml::generator::random::UniformRandom<float>(0.0f, 1.0f));

        auto mean = ml::computation::statistic::mean(data.begin(), data.end());
        mean *= 10;

        auto rounded_mean = std::roundf(mean);

        EXPECT_EQ(5, rounded_mean);
    }
} // namespace tests::unit_tests