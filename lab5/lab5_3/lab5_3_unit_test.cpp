#include <gtest/gtest.h>
#include <cmath>
#include "./lab5_3.h"

TEST(Test, TestF)
{
    // Test for x >= 1
    EXPECT_NEAR(h(1.0), (cos(1.0) + 1) / (cos(1.0) * cos(1.0) + 1), 1e-5);
    EXPECT_NEAR(h(2.0), (cos(2.0) + 1) / (cos(2.0) * cos(2.0) + 1), 1e-5);
    EXPECT_NEAR(h(-1.0), (cos(-1.0) + 1) / (cos(-1.0) * cos(-1.0) + 1), 1e-5);

    // Test for -1 < x < 1
    EXPECT_NEAR(h(0.0), 1.0, 1e-5);
    EXPECT_NEAR(h(0.5), h(0.5), 1e-5);
    EXPECT_NEAR(h(-0.5), h(-0.5), 1e-5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
