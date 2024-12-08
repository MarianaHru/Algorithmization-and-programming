
#include "lab8_1_str.h"
#include <gtest/gtest.h>

TEST(CountTest, NoThirdComma)
{
    EXPECT_EQ(Count("Hello, world!"), -1);
}

TEST(CountTest, FindThirdComma)
{
    EXPECT_EQ(Count("a,b,c,d"), 5);
}

TEST(CountTest, ExactThreeCommas)
{
    EXPECT_EQ(Count("x,y,z,"), 5);
}

TEST(ChangeTest, ReplaceCommas)
{
    EXPECT_EQ(Change("Hello, world!"), "Hello** world!");
    EXPECT_EQ(Change("a,b,c,d"), "a**b**c**d");
    EXPECT_EQ(Change("No commas"), "No commas");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
