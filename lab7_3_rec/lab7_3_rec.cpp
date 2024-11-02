#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// void Create(int **a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int **a, const int rowCount, const int colCount);
void Print(int **a, const int rowCount, const int colCount);
int CountColumnsWithZeroRecursive(int **a, const int rowCount, const int colCount, int currentCol = 0);
bool HasZeroInColumnRecursive(int **a, const int rowCount, int col, int currentRow = 0);
int LongestSeriesInRowRecursive(int *row, const int colCount, int currentCol = 1, int currentLength = 1, int maxLength = 1);
void FindRowWithLongestSeriesRecursive(int **a, const int rowCount, const int colCount, int currentRow, int &longestRow, int &maxSeriesLength);

int main()

#ifndef UNIT_TESTING

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

    int zeroColumns = CountColumnsWithZeroRecursive(a, rowCount, colCount);
    cout << "Number of columns containing at least one zero: " << zeroColumns << endl;

    int longestRow = 0;
    int maxSeriesLength = 0;
    FindRowWithLongestSeriesRecursive(a, rowCount, colCount, 0, longestRow, maxSeriesLength);
    cout << "Row with the longest series of identical elements is: " << longestRow + 1 << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
#endif

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

// Рекурсивна функція для підрахунку стовпців з нульовими елементами
int CountColumnsWithZeroRecursive(int **a, const int rowCount, const int colCount, int currentCol)
{
    if (currentCol == colCount)
        return 0;

    // Перевірка наявності нульового елемента в поточному стовпці
    if (HasZeroInColumnRecursive(a, rowCount, currentCol))
    {
        return 1 + CountColumnsWithZeroRecursive(a, rowCount, colCount, currentCol + 1);
    }
    else
    {
        return CountColumnsWithZeroRecursive(a, rowCount, colCount, currentCol + 1);
    }
}

// Рекурсивна функція для перевірки, чи є нульовий елемент у стовпці
bool HasZeroInColumnRecursive(int **a, const int rowCount, int col, int currentRow)
{
    if (currentRow == rowCount)
        return false;

    if (a[currentRow][col] == 0)
        return true;

    return HasZeroInColumnRecursive(a, rowCount, col, currentRow + 1);
}

// Рекурсивна функція для знаходження найдовшої серії однакових елементів у рядку
int LongestSeriesInRowRecursive(int *row, const int colCount, int currentCol, int currentLength, int maxLength)
{
    if (currentCol == colCount)
        return maxLength;

    if (currentCol > 0 && row[currentCol] == row[currentCol - 1])
    {
        currentLength++;
    }
    else
    {
        currentLength = 1;
    }

    if (currentLength > maxLength)
        maxLength = currentLength;

    return LongestSeriesInRowRecursive(row, colCount, currentCol + 1, currentLength, maxLength);
}

// Рекурсивна функція для пошуку рядка з найдовшою серією однакових елементів
void FindRowWithLongestSeriesRecursive(int **a, const int rowCount, const int colCount, int currentRow, int &longestRow, int &maxSeriesLength)
{
    if (currentRow == rowCount)
        return;

    int currentSeriesLength = LongestSeriesInRowRecursive(a[currentRow], colCount);

    if (currentSeriesLength > maxSeriesLength)
    {
        maxSeriesLength = currentSeriesLength;
        longestRow = currentRow;
    }
    FindRowWithLongestSeriesRecursive(a, rowCount, colCount, currentRow + 1, longestRow, maxSeriesLength);
}