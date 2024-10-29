#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int **t, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int **t, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int **t, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int **t, const int rowCount, const int colCount, int &S, int &k, int i = 0, int j = 0);

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(NULL));
    int Low = -42;
    int High = 51;

    int rowCount = 7;
    int colCount = 6;

    int **t = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
        t[i] = new int[colCount];

    Create(t, rowCount, colCount, Low, High);
    Print(t, rowCount, colCount);
    Sort(t, rowCount, colCount);
    Print(t, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(t, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(t, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] t[i];
    delete[] t;
    return 0;
}

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i == rowCount)
        return;
    t[i][j] = Low + rand() % (High - Low + 1);
    if (j + 1 < colCount)
        Create(t, rowCount, colCount, Low, High, i, j + 1);
    else
        Create(t, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int **t, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << t[i][j];
    if (j + 1 < colCount)
        Print(t, rowCount, colCount, i, j + 1);
    else
    {
        cout << endl;
        Print(t, rowCount, colCount, i + 1, 0);
    }
}

void Sort(int **t, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 == rowCount - 1)
        return;
    if (i1 == rowCount - i0 - 1)
        Sort(t, rowCount, colCount, i0 + 1, 0);
    else
    {
        if ((t[i1][0] > t[i1 + 1][0]) ||
            (t[i1][0] == t[i1 + 1][0] &&
             t[i1][1] < t[i1 + 1][1]) ||
            (t[i1][0] == t[i1 + 1][0] &&
             t[i1][1] == t[i1 + 1][1] &&
             t[i1][2] > t[i1 + 1][2]))
            Change(t, i1, i1 + 1, colCount);

        Sort(t, rowCount, colCount, i0, i1 + 1);
    }
}

void Change(int **t, const int row1, const int row2, const int colCount, int j)
{
    if (j == colCount)
        return;

    int tmp = t[row1][j];
    t[row1][j] = t[row2][j];
    t[row2][j] = tmp;

    Change(t, row1, row2, colCount, j + 1);
}

void Calc(int **t, const int rowCount, const int colCount, int &S, int &k, int i, int j)
{
    if (i == rowCount)
        return;

    if (t[i][j] < 0 && t[i][j] % 5 != 0)
    {
        S += t[i][j];
        k++;
        t[i][j] = 0;
    }

    if (j + 1 < colCount)
        Calc(t, rowCount, colCount, S, k, i, j + 1);
    else
        Calc(t, rowCount, colCount, S, k, i + 1, 0);
}

#endif