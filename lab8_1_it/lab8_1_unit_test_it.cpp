#include <gtest/gtest.h>
#include "lab8_1_it.h"

TEST(CountTest, FindsThirdComma)
{
    char str1[] = ", , , ";
    EXPECT_EQ(Count(str1), 4);
}

TEST(CountTest, NoThirdComma)
{
    char str2[] = "no commas here";
    EXPECT_EQ(Count(str2), -1);
}

TEST(CountTest, LessThanThreeCommas)
{
    char str3[] = "one,two";
    EXPECT_EQ(Count(str3), -1);
}

TEST(CountTest, MoreThanThreeCommas)
{
    char str5[] = "a,b,c,d,e";
    EXPECT_EQ(Count(str5), 5);
}

TEST(ChangeTest, ReplacesCommasWithAsterisks)
{
    char src1[] = "hello,world,goodbye,world";
    char *dest1 = Change(src1);
    EXPECT_STREQ(dest1, "hello**world**goodbye**world");
    delete[] dest1;
}

TEST(ChangeTest, NoCommasInString)
{
    char src2[] = "no commas";
    char *dest2 = Change(src2);
    EXPECT_STREQ(dest2, "no commas");
    delete[] dest2;
}

TEST(ChangeTest, EmptyString)
{
    char src3[] = "";
    char *dest3 = Change(src3);
    EXPECT_STREQ(dest3, "");
    delete[] dest3;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}