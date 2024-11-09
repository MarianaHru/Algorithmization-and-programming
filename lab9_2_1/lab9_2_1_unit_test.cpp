#include "lab9_2_1.h"
#include <gtest/gtest.h>

TEST(Lab9_2_1Tests, CalculateWForZInRange1To3)
{
    int x = 1;
    int y = 2;
    int z = 2;
    EXPECT_FLOAT_EQ(calculateW(x, y, z), MAX(ABS(x) + ABS(y) + ABS(z), SQR(z)));
}

TEST(Lab9_2_1Tests, CalculateWForZGreaterThanOrEqualTo3)
{
    int x = 1;
    int y = 2;
    int z = 5;
    EXPECT_FLOAT_EQ(calculateW(x, y, z), MIN(2 * x + y, SQR(y - z)));
}

TEST(Lab9_2_1Tests, CalculateWForOutOfRangeZ)
{
    int x = 1;
    int y = 2;
    int z = 0;
    EXPECT_FLOAT_EQ(calculateW(x, y, z), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
