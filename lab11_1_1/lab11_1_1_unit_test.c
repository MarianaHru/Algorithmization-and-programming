#include "lab11_1_1.h"
#include <gtest/gtest.h>
#include <fstream>
#include <string>

TEST(FindThirdCommaTest, NoCommas)
{
    const char *line = "This line has no commas.";
    int position = 0;
    EXPECT_FALSE(FindThirdComma(line, &position));
}

TEST(FindThirdCommaTest, LessThanThreeCommas)
{
    const char *line = "One, two.";
    int position = 0;
    EXPECT_FALSE(FindThirdComma(line, &position));
}

TEST(FindThirdCommaTest, ExactlyThreeCommas)
{
    const char *line = "First, second, third, fourth.";
    int position = 0;
    EXPECT_TRUE(FindThirdComma(line, &position));
    EXPECT_EQ(position, 22);
}

TEST(FindThirdCommaTest, MoreThanThreeCommas)
{
    const char *line = "One, two, three, four, five.";
    int position = 0;
    EXPECT_TRUE(FindThirdComma(line, &position));
    EXPECT_EQ(position, 14);
}

class ProcessFileTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

        std::ofstream testFile("test_file.txt");
        testFile << "Line without commas\n";
        testFile << "Line, with, less, commas\n";
        testFile << "Line, with, three, commas\n";
        testFile << "Another, line, with, multiple, commas\n";
        testFile.close();
    }

    void TearDown() override
    {

        std::remove("test_file.txt");
    }
};

TEST_F(ProcessFileTest, FileWithThirdComma)
{
    EXPECT_EQ(ProcessFile("test_file.txt"), 3);
}

TEST_F(ProcessFileTest, FileWithoutThirdComma)
{

    std::ofstream testFile("test_file_no_comma.txt");
    testFile << "Line without commas\n";
    testFile << "Line, with, less commas\n";
    testFile.close();

    EXPECT_EQ(ProcessFile("test_file_no_comma.txt"), 0);

    std::remove("test_file_no_comma.txt");
}
