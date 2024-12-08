#include <gtest/gtest.h>
#include "lab8_1_char.h"

TEST(FindThirdCommaIndexTest, BasicTests)
{
    char str1[] = "one,two,three,four,five";
    EXPECT_EQ(FindThirdCommaIndex(str1), 13);
    char str2[] = "one,two,three";
    EXPECT_EQ(FindThirdCommaIndex(str2), -1);

    char str3[] = "one,two,three,four,five,six,seven";
    EXPECT_EQ(FindThirdCommaIndex(str3), 13);
}

TEST(ReplaceCommasTest, BasicTests)
{
    char str1[] = "one,two,three,four";
    char *result1 = ReplaceCommas(str1);
    EXPECT_STREQ(result1, "one  two  three  four");
    delete[] result1;

    char str2[] = "one,two";
    char *result2 = ReplaceCommas(str2);
    EXPECT_STREQ(result2, "one  two");
    delete[] result2;

    char str3[] = "no,commas,here";
    char *result3 = ReplaceCommas(str3);
    EXPECT_STREQ(result3, "no  commas  here");
    delete[] result3;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}