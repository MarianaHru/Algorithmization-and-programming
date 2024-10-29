#ifndef lab7_1_rec_h
#define lab7_1_rec_h

void Create(int **t, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int **t, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int **t, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int **t, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int **t, const int rowCount, const int colCount, int &S, int &k, int i = 0, int j = 0);

#endif