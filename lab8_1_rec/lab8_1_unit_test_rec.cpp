// #include <gtest/gtest.h>
// #include "lab8_1_rec.h"

// TEST(CountRecursiveTest, FindsThirdComma)
// {
//     char str1[] = ", , , ";
//     EXPECT_EQ(CountRecursive(str1), 4);
// }

// TEST(CountRecursiveTest, NoThirdComma)
// {
//     char str2[] = "no commas here";
//     EXPECT_EQ(CountRecursive(str2), -1);
// }

// TEST(CountRecursiveTest, LessThanThreeCommas)
// {
//     char str3[] = "one,two";
//     EXPECT_EQ(CountRecursive(str3), -1);
// }

// TEST(CountRecursiveTest, MoreThanThreeCommas)
// {
//     char str4[] = "a,b,c,d,e";
//     EXPECT_EQ(CountRecursive(str4), 4);
// }

// TEST(ChangeRecursiveTest, ReplacesCommasWithAsterisks)
// {
//     char src1[] = "hello,world,goodbye,world";
//     char dest1[50];
//     ChangeRecursive(src1, dest1);
//     EXPECT_STREQ(dest1, "hello**world**goodbye**world");
// }

// TEST(ChangeRecursiveTest, NoCommasInString)
// {
//     char src2[] = "no commas";
//     char dest2[50];
//     ChangeRecursive(src2, dest2);
//     EXPECT_STREQ(dest2, "no commas");
// }

// TEST(ChangeRecursiveTest, EmptyString)
// {
//     char src3[] = "";
//     char dest3[5];
//     ChangeRecursive(src3, dest3);
//     EXPECT_STREQ(dest3, "");
// }

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

#include <gtest/gtest.h>
#include "lab8_1_rec.h"
#include <cstring>

TEST(CountRecursiveTest, FindsThirdCommaPosition)
{
    char testStr[] = "a,b,c,d,e";
    EXPECT_EQ(CountRecursive(testStr), 4);
}

TEST(CountRecursiveTest, LessThanThreeCommas)
{
    char testStr[] = "a,b";
    EXPECT_EQ(CountRecursive(testStr), -1);
}

TEST(CountRecursiveTest, NoCommas)
{
    char testStr[] = "abcdef";
    EXPECT_EQ(CountRecursive(testStr), -1);
}

TEST(ChangeRecursiveTest, ReplacesCommasWithAsterisks)
{
    char testStr[] = "a,b,c";
    char expectedStr[] = "a**b**c";
    char dest[201];

    ChangeRecursive(testStr, dest, 0, 0);
    EXPECT_STREQ(dest, expectedStr);
}

TEST(ChangeRecursiveTest, NoCommasToReplace)
{
    char testStr[] = "abcdef";
    char expectedStr[] = "abcdef";
    char dest[201];

    ChangeRecursive(testStr, dest, 0, 0);
    EXPECT_STREQ(dest, expectedStr);
}

TEST(ChangeRecursiveTest, EmptyString)
{
    char testStr[] = "";
    char expectedStr[] = "";
    char dest[201];

    ChangeRecursive(testStr, dest, 0, 0);
    EXPECT_STREQ(dest, expectedStr);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
