#ifndef LAB7_2_rec_H
#define LAB7_2_rec_H

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int **a, const int rowCount, const int colCount, int i, int j);
int SearchMinSum(int **a, const int rowCount, const int colCount, int i, int j, int s, int tmp);

#endif