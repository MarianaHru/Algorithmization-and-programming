#include "lab7_3_rec.h"
#include <gtest/gtest.h>

TEST(CountColumnsWithZeroRecursiveTest, BasicTest)
{
    int rowCount = 3, colCount = 3;
    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        a[i] = new int[colCount];
    }

    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 0;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    EXPECT_EQ(CountColumnsWithZeroRecursive(a, rowCount, colCount), 2);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

TEST(LongestSeriesInRowRecursiveTest, BasicTest)
{
    int row[] = {1, 1, 1, 2, 2, 3};
    int colCount = 6;
    EXPECT_EQ(LongestSeriesInRowRecursive(row, colCount), 3);
}

TEST(FindRowWithLongestSeriesRecursiveTest, BasicTest)
{
    int rowCount = 3, colCount = 4;
    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        a[i] = new int[colCount];
    }

    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 2;
    a[0][3] = 3;
    a[1][0] = 4;
    a[1][1] = 4;
    a[1][2] = 4;
    a[1][3] = 5;
    a[2][0] = 6;
    a[2][1] = 7;
    a[2][2] = 8;
    a[2][3] = 8;

    int longestRow = 0;
    int maxSeriesLength = 0;
    FindRowWithLongestSeriesRecursive(a, rowCount, colCount, 0, longestRow, maxSeriesLength);

    EXPECT_EQ(longestRow, 1);
    EXPECT_EQ(maxSeriesLength, 3);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
