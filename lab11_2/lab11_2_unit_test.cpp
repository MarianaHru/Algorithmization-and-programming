#include <gtest/gtest.h>
#include "lab11_2.h"
#include <fstream>

TEST(CheckNestedQuotesTest, ValidQuotes)
{
    EXPECT_TRUE(CheckNestedQuotes("Текст без дужок."));
    EXPECT_TRUE(CheckNestedQuotes("«Це правильно.»"));
    EXPECT_TRUE(CheckNestedQuotes("Перед «дужки», після «дужки»."));
    EXPECT_TRUE(CheckNestedQuotes("Декілька фраз: «раз», «два», «три»."));
}

TEST(CheckNestedQuotesTest, NestedQuotes)
{
    EXPECT_FALSE(CheckNestedQuotes("Текст «вкладені «дужки» неправильно»."));
    EXPECT_FALSE(CheckNestedQuotes("«Перша «вкладені дужки» друга»."));
}

TEST(CheckNestedQuotesTest, MismatchedQuotes)
{
    EXPECT_FALSE(CheckNestedQuotes("«Незакриті дужки."));
    EXPECT_FALSE(CheckNestedQuotes("Закриті дужки без відкриття.»"));
}

TEST(RemoveQuotesContentTest, RemoveContent)
{
    EXPECT_EQ(RemoveQuotesContent("Текст без дужок."), "Текст без дужок.");
    EXPECT_EQ(RemoveQuotesContent("Перед «видалити це» після."), "Перед  після.");
    EXPECT_EQ(RemoveQuotesContent("«Видалити все». Залишити це."), " Залишити це.");
    EXPECT_EQ(RemoveQuotesContent("«Одні» та «другі» дужки."), "  дужки.");
}

TEST(RemoveQuotesContentTest, NoQuotes)
{
    EXPECT_EQ(RemoveQuotesContent("Текст без дужок."), "Текст без дужок.");
    EXPECT_EQ(RemoveQuotesContent("Немає дужок взагалі."), "Немає дужок взагалі.");
}

TEST(ProcessFileTest, FileProcessing)
{
    const std::string inputFile = "test_input.txt";
    const std::string outputFile = "test_output.txt";

    std::ofstream input(inputFile);
    input << "Текст без дужок.\n";
    input << "Перед «видалити це» після.\n";
    input << "«Одні» та «другі» дужки.\n";
    input.close();

    ProcessFile(inputFile, outputFile);

    std::ifstream output(outputFile);
    std::string line;
    std::string result;

    while (std::getline(output, line))
    {
        result += line + "\n";
    }
    output.close();

    EXPECT_EQ(result, "Текст без дужок.\nПеред  після.\n  дужки.\n");

    remove(inputFile.c_str());
    remove(outputFile.c_str());
}
