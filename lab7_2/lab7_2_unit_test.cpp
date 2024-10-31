#include <gtest/gtest.h>
#include "lab7_2.h"

TEST(MatrixOperations, Create)
{
    int k = 3;
    int n = 3;
    int Low = -20;
    int High = 20;

    int **a = new int *[k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            EXPECT_GE(a[i][j], Low);
            EXPECT_LE(a[i][j], High);
        }
    }

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
}

TEST(MatrixOperations, SearchMinSum)
{
    int k = 2;
    int n = 3;

    int **a = new int *[k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Встановлюємо відомі значення для тестування
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = -1;
    a[1][1] = 5;
    a[1][2] = 4;

    EXPECT_EQ(SearchMinSum(a, k, n), 0);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}