#ifndef lab7_2_h
#define lab7_2_h

void Create(int **a, const int k, const int n, const int Low, const int High);
void Print(int **a, const int k, const int n);
void Sort(int **a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Calc(int **a, const int rowCount, const int colCount, int &S, int &k, int i = 0, int j = 0);
int SearchMinSum(int **a, int rows, int cols);
#endif