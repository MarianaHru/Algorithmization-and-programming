#include "lab8_2.h"
#include <gtest/gtest.h>

TEST(RemoveBracketsTest, RegularString)
{
    EXPECT_EQ(RemoveBrackets("Hello (world)!"), "Hello !");
}

TEST(RemoveBracketsTest, NoBrackets)
{
    EXPECT_EQ(RemoveBrackets("No brackets here"), "No brackets here");
}

TEST(RemoveBracketsTest, NestedBrackets)
{
    EXPECT_EQ(RemoveBrackets("Hello ((world))!"), "");
}

TEST(RemoveBracketsTest, UnmatchedOpeningBracket)
{
    EXPECT_EQ(RemoveBrackets("Hello (world!"), "");
}

TEST(RemoveBracketsTest, UnmatchedClosingBracket)
{
    EXPECT_EQ(RemoveBrackets("Hello world)"), "");
}

TEST(RemoveBracketsTest, EmptyString)
{
    EXPECT_EQ(RemoveBrackets(""), "");
}

TEST(RemoveBracketsTest, MultipleBracketGroups)
{
    EXPECT_EQ(RemoveBrackets("Text (to remove) remains (more removal)"), "Text  remains ");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
