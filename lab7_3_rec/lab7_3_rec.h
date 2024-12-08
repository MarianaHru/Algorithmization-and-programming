
#ifndef LAB7_3_REC_H
#define LAB7_3_REC_H

void Input(int **a, const int rowCount, const int colCount);
void Print(int **a, const int rowCount, const int colCount);
int CountColumnsWithZeroRecursive(int **a, const int rowCount, const int colCount, int currentCol = 0);
bool HasZeroInColumnRecursive(int **a, const int rowCount, int col, int currentRow = 0);
int LongestSeriesInRowRecursive(int *row, const int colCount, int currentCol = 1, int currentLength = 1, int maxLength = 1);
void FindRowWithLongestSeriesRecursive(int **a, const int rowCount, const int colCount, int currentRow, int &longestRow, int &maxSeriesLength);

#endif
