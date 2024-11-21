#include "lab11_1_2.h"
#include <gtest/gtest.h>
#include <fstream>

TEST(FindThirdCommaTest, ThirdCommaExists)
{
    std::string line = "first,second,third,fourth";
    int charPosition = 0;
    EXPECT_TRUE(FindThirdComma(line, charPosition));
    EXPECT_EQ(charPosition, 19);
}

TEST(FindThirdCommaTest, NoThirdComma)
{
    std::string line = "first,second";
    int charPosition = 0;
    EXPECT_FALSE(FindThirdComma(line, charPosition));
}

TEST(ProcessFileTest, FileWithThirdComma)
{

    const std::string testFilename = "test_file_with_third_comma.txt";
    std::ofstream testFile(testFilename);
    testFile << "line1\n";
    testFile << "line2\n";
    testFile << "first,second,third,fourth\n";
    testFile.close();

    testing::internal::CaptureStdout();
    ProcessFile(testFilename);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Рядок: 3") != std::string::npos);
    EXPECT_TRUE(output.find("Позиція: 19") != std::string::npos);

    std::remove(testFilename.c_str());
}

TEST(ProcessFileTest, FileWithoutThirdComma)
{

    const std::string testFilename = "test_file_without_third_comma.txt";
    std::ofstream testFile(testFilename);
    testFile << "line1\n";
    testFile << "line2\n";
    testFile << "first,second\n";
    testFile.close();

    testing::internal::CaptureStdout();
    ProcessFile(testFilename);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("У файлі немає третьої коми.") != std::string::npos);

    std::remove(testFilename.c_str());
}
