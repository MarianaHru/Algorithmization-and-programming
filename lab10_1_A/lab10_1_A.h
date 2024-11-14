#ifndef LAB10_1_A.H
#define LAB10_1_A .H

#include <string>
using namespace std;

enum Specialnist
{
    KN,
    INF,
    ME,
    FI,
    TN
};

struct Student
{
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    int ocinka_informatyka;
};

void CreateStudents(Student *students, const int N);
void PrintStudents(const Student *students, const int N);
void PrintStudentsWithoutLowGrades(const Student *students, const int N);
int CountStudentsWithExcellentPhysics(const Student *students, const int N);

#endif
