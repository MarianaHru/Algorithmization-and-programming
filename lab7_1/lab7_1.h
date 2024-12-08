#ifndef LAB7_1_H
#define LAB7_1_H

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High);
void Print(int **t, const int rowCount, const int colCount);
void Sort(int **t, const int rowCount, const int colCount);
void Change(int **t, const int row1, const int row2, const int colCount);
void Calc(int **t, const int rowCount, const int colCount, int &S, int &k);

#endif