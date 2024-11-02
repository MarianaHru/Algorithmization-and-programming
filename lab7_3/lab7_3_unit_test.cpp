#include <gtest/gtest.h>
#include "lab7_3.h"

int **CreateMatrix(int rowCount, int colCount)
{
    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        a[i] = new int[colCount];
    }
    return a;
}

void DeleteMatrix(int **a, int rowCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

TEST(Lab7_3Test, CountColumnsWithZero)
{
    int rowCount = 3, colCount = 3;
    int **a = CreateMatrix(rowCount, colCount);

    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[1][2] = 0;
    a[2][0] = 0;
    a[2][1] = 5;
    a[2][2] = 6;

    EXPECT_EQ(CountColumnsWithZero(a, rowCount, colCount), 3);

    DeleteMatrix(a, rowCount);
}

TEST(Lab7_3Test, FindRowWithLongestSeries)
{
    int rowCount = 3, colCount = 5;
    int **a = CreateMatrix(rowCount, colCount);

    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 2;
    a[0][3] = 2;
    a[0][4] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[1][2] = 4;
    a[1][3] = 4;
    a[1][4] = 5;
    a[2][0] = 6;
    a[2][1] = 6;
    a[2][2] = 6;
    a[2][3] = 6;
    a[2][4] = 6;

    testing::internal::CaptureStdout();
    FindRowWithLongestSeries(a, rowCount, colCount);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Row with the longest series of identical elements is: 3"), std::string::npos);

    DeleteMatrix(a, rowCount);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
