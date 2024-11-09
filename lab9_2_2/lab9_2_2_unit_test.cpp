#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "lab9_2_2.h"

void createTestFile(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    file << content;
    file.close();
}

TEST(ClassifyAndCountTest, CountsCorrectlyWithinRange)
{
    const char *filename = "test_input.txt";
    createTestFile(filename, "Hello! 12345\n");

    testing::internal::CaptureStdout();
    classifyAndCount(filename, 2, 8);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Алфавітні символи: 5"), std::string::npos);
    EXPECT_NE(output.find("Цифрові символи: 5"), std::string::npos);
    EXPECT_NE(output.find("Керуючі символи: 1"), std::string::npos);
    EXPECT_NE(output.find("Знаки пунктуації: 1"), std::string::npos);
}

TEST(ClassifyAndCountTest, DigitOutOfRangeAssertion)
{
    const char *filename = "test_input_out_of_range.txt";
    createTestFile(filename, "123 0 9");

    EXPECT_DEATH(classifyAndCount(filename, 2, 8), "Цифра поза заданим діапазоном!");
}

TEST(ClassifyAndCountTest, FileNotFound)
{
    const char *filename = "non_existent_file.txt";

    testing::internal::CaptureStderr();
    classifyAndCount(filename, 2, 8);
    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_NE(output.find("Не вдалося відкрити файл!"), std::string::npos);
}
