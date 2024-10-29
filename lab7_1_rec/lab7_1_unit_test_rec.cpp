#include <gtest/gtest.h>
#include <iostream>
#include "./lab7_1_rec.h"

TEST(MatrixOperations, Create)
{
    int rowCount = 3;
    int colCount = 4;
    int Low = -10;
    int High = 10;

    int **matrix = new int *[rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    Create(matrix, rowCount, colCount, Low, High);

    // Check if all elements are within the specified range
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            EXPECT_GE(matrix[i][j], Low);
            EXPECT_LE(matrix[i][j], High);
        }
    }

    for (int i = 0; i < rowCount; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(MatrixOperations, Print)
{
    int rowCount = 2;
    int colCount = 3;

    int **matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    testing::internal::CaptureStdout();
    Print(matrix, rowCount, colCount);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "   1   2   3\n   4   5   6\n\n");

    for (int i = 0; i < rowCount; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(MatrixOperations, Sort)
{
    int rowCount = 3;
    int colCount = 3;

    int **matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    matrix[0][0] = 2;
    matrix[0][1] = 5;
    matrix[0][2] = 9;
    matrix[1][0] = 1;
    matrix[1][1] = 4;
    matrix[1][2] = 8;
    matrix[2][0] = 3;
    matrix[2][1] = 6;
    matrix[2][2] = 7;

    Sort(matrix, rowCount, colCount);

    EXPECT_EQ(matrix[0][0], 1);
    EXPECT_EQ(matrix[1][0], 2);
    EXPECT_EQ(matrix[2][0], 3);

    for (int i = 0; i < rowCount; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(MatrixOperations, Calc)
{
    int rowCount = 3;
    int colCount = 3;

    int **matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    matrix[0][0] = -1;
    matrix[0][1] = -2;
    matrix[0][2] = -5;
    matrix[1][0] = -7;
    matrix[1][1] = -10;
    matrix[1][2] = 5;
    matrix[2][0] = 8;
    matrix[2][1] = -14;
    matrix[2][2] = 0;

    int S = 0;
    int k = 0;

    Calc(matrix, rowCount, colCount, S, k);

    EXPECT_EQ(S, -24); // Сума негативних елементів, що не кратні 5
    EXPECT_EQ(k, 4);   // Кількість таких елементів

    // Перевіряємо, що ці елементи були замінені на 0
    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[0][1], 0);
    EXPECT_EQ(matrix[1][0], 0);
    EXPECT_EQ(matrix[2][1], 0);

    for (int i = 0; i < rowCount; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}