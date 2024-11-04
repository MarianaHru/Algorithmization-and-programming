#ifndef LAB7_3_H
#define LAB7_3_H

// void Input(int **a, const int rowCount, const int colCount);
// void Print(int **a, const int rowCount, const int colCount);
int CountColumnsWithZero(int **a, const int rowCount, const int colCount);
void FindRowWithLongestSeries(int **a, const int rowCount, const int colCount);

void Calc(int **a, int rowCount, int colCount, int &result1, int &result2, int param1, int param2);
void Sort(int **a, int rowCount, int colCount, int param1, int param2);
void Print(int **a, int rowCount, int colCount, int param1, int param2);
void Create(int **a, int rowCount, int colCount, int param1, int param2, int param3, int param4);

#endif
