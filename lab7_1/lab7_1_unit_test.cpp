#include <gtest/gtest.h>
#include "lab7_1.h"
#include <iostream>

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

    // Перевірка, що всі елементи в матриці в межах [Low, High]
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

    // Захоплення виводу Print
    testing::internal::CaptureStdout();
    Print(matrix, rowCount, colCount);
    std::string output = testing::internal::GetCapturedStdout();

    // Очікуване значення
    std::string expected_output = "\n   1   2   3\n   4   5   6\n\n";
    EXPECT_EQ(output, expected_output);

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

    // Заповнення матриці
    matrix[0][0] = 3;
    matrix[0][1] = 2;
    matrix[0][2] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 4;
    matrix[1][2] = 6;
    matrix[2][0] = 2;
    matrix[2][1] = 5;
    matrix[2][2] = 3;

    // Виклик сортування
    Sort(matrix, rowCount, colCount);

    // Очікуваний результат
    int expected[3][3] = {
        {1, 4, 6},
        {2, 5, 3},
        {3, 2, 1}};

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            EXPECT_EQ(matrix[i][j], expected[i][j]);
        }
    }

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

    // Заповнення матриці
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

    // Оновлені очікувані результати
    EXPECT_EQ(S, -24); // Сума негативних елементів, які не кратні 5
    EXPECT_EQ(k, 4);   // Кількість таких елементів

    // Перевіряємо, що ці елементи замінено на 0
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