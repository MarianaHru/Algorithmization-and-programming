#ifndef LAB10_2_A_H
#define LAB10_2_A_H

#include <string>

enum Specialnist
{
    KN,
    INF,
    ME,
    FI,
    TN
};
extern const std::string specialnistStr[];

struct Student
{
    std::string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    int ocinka_informatyka;

    double averageGrade() const;
};

void CreateStudents(Student students[], int N);
void SortStudentsPhysically(Student students[], int N);
void CreateIndexArray(int indices[], const Student students[], int N);
bool BinarySearchStudent(const Student students[], int N, const std::string &prizv, double avgGrade);

#endif
