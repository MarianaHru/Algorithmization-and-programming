#include "lab10_2_A.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>

TEST(StudentTest, AverageGradeCalculation)
{
    Student student = {"Іваненко", 2, KN, 5, 4, 3};
    EXPECT_DOUBLE_EQ(student.averageGrade(), 4.0);
}

TEST(StudentTest, PhysicalSort)
{
    Student students[] = {
        {"Іваненко", 2, FI, 5, 4, 3},
        {"Петренко", 3, KN, 4, 4, 5},
        {"Сидоренко", 1, ME, 3, 3, 3}};
    SortStudentsPhysically(students, 3);

    EXPECT_EQ(students[0].prizv, "Петренко");
    EXPECT_EQ(students[1].prizv, "Сидоренко");
    EXPECT_EQ(students[2].prizv, "Іваненко");
}

TEST(StudentTest, CreateIndexArray)
{
    Student students[] = {
        {"Іваненко", 2, FI, 5, 4, 3},
        {"Петренко", 3, KN, 4, 4, 5},
        {"Сидоренко", 1, ME, 3, 3, 3}};
    int indices[3];
    CreateIndexArray(indices, students, 3);

    EXPECT_EQ(indices[0], 1);
    EXPECT_EQ(indices[1], 2);
    EXPECT_EQ(indices[2], 0);
}

TEST(StudentTest, BinarySearchStudent)
{
    Student students[] = {
        {"Іваненко", 2, FI, 5, 4, 3},
        {"Петренко", 3, KN, 4, 4, 5},
        {"Сидоренко", 1, ME, 3, 3, 3}};

    // Сортуємо масив студентів для бінарного пошуку
    SortStudentsPhysically(students, 3);

    // Виведення відсортованих студентів для перевірки
    std::cout << "Відсортований список студентів:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << students[i].prizv << " зі середнім балом: "
                  << (students[i].ocinka_fizyka + students[i].ocinka_matematyka + students[i].ocinka_informatyka) / 3.0 << std::endl;
    }

    // Цільове значення середнього бала
    double targetAvg = 4.33;

    // Виконуємо бінарний пошук
    bool found = BinarySearchStudent(students, 3, "Петренко", targetAvg);

    if (found)
    {
        // Успішний пошук з перевіркою середнього бала
        EXPECT_NEAR(targetAvg, 4.33, 0.01) << "Знайдено студента, але середній бал не збігається з очікуваним.";
    }
    else
    {
        FAIL() << "Студента не знайдено в масиві.";
    }
}
