/**
 ** @file tests/unit_tests/main.cc
 ** @brief Main function for the unit tests
 */

#include "gtest/gtest.h"

namespace tests::unit_tests
{
    int main(int argc, char** argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
} // namespace tests::unit_tests
