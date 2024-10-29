#include "lab7_2_rec.h"
#include <gtest/gtest.h>

// Test Create function to ensure matrix values are within bounds
TEST(MatrixTestRec, CreateMatrixWithinBounds)
{
    int rowCount = 3, colCount = 4;
    int Low = -10, High = 10;

    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);

    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            EXPECT_GE(a[i][j], Low) << "Value is below Low limit";
            EXPECT_LE(a[i][j], High) << "Value is above High limit";
        }
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

// Test SearchMinSum function for correct minimum sum
TEST(MatrixTestRec, CorrectMinSum)
{
    int rowCount = 3, colCount = 4;
    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    // Manually set matrix values for testing
    a[0][0] = 5;
    a[0][1] = 8;
    a[0][2] = -3;
    a[0][3] = 7;
    a[1][0] = 6;
    a[1][1] = -5;
    a[1][2] = 0;
    a[1][3] = 2;
    a[2][0] = 3;
    a[2][1] = 4;
    a[2][2] = -1;
    a[2][3] = -4;

    int minSum = SearchMinSum(a, rowCount, colCount, 0, 0, 0, a[0][0]);
    EXPECT_EQ(minSum, -12) << "The min sum is incorrect"; // Expected sum = -3 + -5 + -4

    // Free the dynamically allocated memory
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

// Test empty matrix case
TEST(MatrixTestRec, EmptyMatrix)
{
    int **a = nullptr;
    EXPECT_EQ(SearchMinSum(a, 0, 0, 0, 0, 0, 0), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}