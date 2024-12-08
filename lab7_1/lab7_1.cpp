
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High);
void Print(int **t, const int rowCount, const int colCount);
void Sort(int **t, const int rowCount, const int colCount);
void Change(int **t, const int row1, const int row2, const int colCount);
void Calc(int **t, const int rowCount, const int colCount, int &S, int &k);

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

#endif

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            t[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int **t, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << t[i][j];
        cout << endl;
    }
    cout << endl;
}
void Sort(int **t, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((t[i1][0] > t[i1 + 1][0]) ||
                (t[i1][0] == t[i1 + 1][0] &&
                 t[i1][1] < t[i1 + 1][1]) ||
                (t[i1][0] == t[i1 + 1][0] &&
                 t[i1][1] == t[i1 + 1][1] &&
                 t[i1][2] > t[i1 + 1][2]))
                Change(t, i1, i1 + 1, colCount);
}
void Change(int **t, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = t[row1][j];
        t[row1][j] = t[row2][j];
        t[row2][j] = tmp;
    }
}

void Calc(int **t, const int rowCount, const int colCount, int &S, int &k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(t[i][j] > 0 && t[i][j] % 5 == 0))
            {
                S += t[i][j];
                k++;
                t[i][j] = 0;
            }
}
