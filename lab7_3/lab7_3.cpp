#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// void Create(int **a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int **a, const int rowCount, const int colCount);
void Print(int **a, const int rowCount, const int colCount);
int CountColumnsWithZero(int **a, const int rowCount, const int colCount);
void FindRowWithLongestSeries(int **a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 10;

    int rowCount, colCount;
    cout << "Enter row count (k): ";
    cin >> rowCount;
    cout << "Enter column count (n): ";
    cin >> colCount;

    int **a = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int zeroColumns = CountColumnsWithZero(a, rowCount, colCount);
    cout << "Number of columns containing at least one zero: " << zeroColumns << endl;

    FindRowWithLongestSeries(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// void Create(int **a, const int rowCount, const int colCount, const int Low, const int High)
// {
//     for (int i = 0; i < rowCount; i++)
//         for (int j = 0; j < colCount; j++)
//             a[i][j] = Low + rand() % (High - Low + 1);
// }

void Input(int **a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int **a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// 1
int CountColumnsWithZero(int **a, const int rowCount, const int colCount)
{
    int count = 0;
    for (int j = 0; j < colCount; j++)
    {
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][j] == 0)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void FindRowWithLongestSeries(int **a, const int rowCount, const int colCount)
{
    int maxSeriesLength = 0;
    int rowIndex = -1;

    for (int i = 0; i < rowCount; i++)
    {
        int currentSeriesLength = 1;
        int maxCurrentSeries = 1;

        for (int j = 1; j < colCount; j++)
        {
            if (a[i][j] == a[i][j - 1])
            {
                currentSeriesLength++;
            }
            else
            {
                if (currentSeriesLength > maxCurrentSeries)
                    maxCurrentSeries = currentSeriesLength;
                currentSeriesLength = 1;
            }
        }
        if (currentSeriesLength > maxCurrentSeries)
            maxCurrentSeries = currentSeriesLength;

        if (maxCurrentSeries > maxSeriesLength)
        {
            maxSeriesLength = maxCurrentSeries;
            rowIndex = i;
        }
    }

    if (rowIndex != -1)
        cout << "Row with the longest series of identical elements is: " << rowIndex + 1 << endl;
    else
        cout << "No identical elements series found." << endl;
}