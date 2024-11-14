#ifndef LAB10_1_B_H
#define LAB10_1_B_H

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

union Grades
{
    struct
    {
        int ocinka_fizyka;
        int ocinka_matematyka;
        int ocinka_programming;
    } kn_inf;
    struct
    {
        int ocinka_fizyka;
        int ocinka_matematyka;
        int ocinka_chiselni_metody;
    } me;
    struct
    {
        int ocinka_fizyka;
        int ocinka_matematyka;
        int ocinka_pedagogika;
    } fi_tn;
};

struct Student
{
    string prizv;
    int kurs;
    Specialnist specialnist;
    Grades grades;
};

void CreateStudents(Student *students, const int N);
void PrintStudents(const Student *students, const int N);
void PrintStudentsWithoutLowGrades(const Student *students, const int N);
int CountStudentsWithExcellentPhysics(const Student *students, const int N);

#endif
