#include "lab12_1.h"
#include <gtest/gtest.h>
#include <fstream>

std::string readFileContents(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

TEST(FileProcessorTest, CreateInputFile)
{
    std::string testFilename = "test_input.bin";
    std::ofstream testOutput(testFilename, std::ios::binary);
    ASSERT_TRUE(testOutput.is_open());
    testOutput.close();
    remove(testFilename.c_str());
}

TEST(FileProcessorTest, ProcessFile)
{
    std::string inputFilename = "test_input.bin";
    std::string outputFilename = "test_output.bin";

    std::ofstream inputFile(inputFilename, std::ios::binary);
    std::string testData = "географіягеометріяфізика";
    inputFile.write(testData.c_str(), testData.size());
    inputFile.close();

    processFile(inputFilename, outputFilename);

    std::string result = readFileContents(outputFilename);
    ASSERT_EQ(result, "географіяфізика");

    remove(inputFilename.c_str());
    remove(outputFilename.c_str());
}

TEST(FileProcessorTest, DisplayFile)
{
    std::string testFilename = "test_display.bin";
    std::string testData = "Тестовий текст";

    std::ofstream testFile(testFilename, std::ios::binary);
    testFile.write(testData.c_str(), testData.size());
    testFile.close();

    ASSERT_EQ(readFileContents(testFilename), testData);

    remove(testFilename.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
