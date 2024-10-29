#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int **a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else if (i < rowCount - 1)
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
    else
        cout << endl
             << endl;
}

// int SearchMinSum(int** a, const int rowCount, const int colCount, int i, int j, int s, int tmp)
// {
// if (i >= rowCount)
// return s;
// if (j < colCount)
// {
// if (a[i][j] > tmp)
// tmp = a[i][j];
// return SearchMinSum(a, rowCount, colCount, i, j + 1, s, tmp);
// }
// else
// {
// s += tmp;
// if (i + 1 < rowCount)
// tmp = a[i + 1][0];
// return SearchMinSum(a, rowCount, colCount, i + 1, 0, s, tmp);
// }
// }

int SearchMinSum(int **a, const int rowCount, const int colCount, int i, int j, int s, int tmp)
{
    if (i >= rowCount)
        return s;

    if (j < colCount)
    {
        if (a[i][j] < tmp)
            tmp = a[i][j];
        return SearchMinSum(a, rowCount, colCount, i, j + 1, s, tmp);
    }
    else
    {
        s += tmp;
        if (i + 1 < rowCount)
            tmp = a[i + 1][0];
        return SearchMinSum(a, rowCount, colCount, i + 1, 0, s, tmp);
    }
}

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(NULL));
    int k;
    int n;
    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;
    cout << endl;
    int **a = new int *[k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];
    int Low = -20, High = 20;
    Create(a, k, n, Low, High, 0, 0);
    Print(a, k, n, 0, 0);
    int minSum = SearchMinSum(a, k, n, 0, 0, 0, a[0][0]);
    cout << "Minimum sum = " << minSum << endl;
    for (int i = 0; i < k; i++)
        delete[] a[i];

    delete[] a;
    return 0;
}

#endif