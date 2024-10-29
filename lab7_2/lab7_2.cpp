#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int **a, const int k, const int n, const int Low, const int High);
void Print(int **a, const int k, const int n);
int SearchMinSum(int **a, const int k, const int n);

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(NULL));

    int Low = -20;
    int High = 20;

    int n;
    int k;

    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int **a = new int *[k];

    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int minSum = SearchMinSum(a, k, n);
    cout << "Minimum sum = " << minSum << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];

    delete[] a;
    return 0;
}

void Create(int **a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int **a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SearchMinSum(int **a, const int k, const int n)
{
    int s = 0;
    for (int i = 0; i < k; i++)
    {
        int tmp = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < tmp)
                tmp = a[i][j];
        }
        s += tmp;
    }
    return s;
}

#endif