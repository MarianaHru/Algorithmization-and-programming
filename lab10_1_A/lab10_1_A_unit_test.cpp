#include "lab10_1_A.h"
#include <gtest/gtest.h>
#include <vector>
#include <sstream>

Student createStudent(const string &prizv, int kurs, Specialnist specialnist, int physics, int math, int info)
{
    Student student;
    student.prizv = prizv;
    student.kurs = kurs;
    student.specialnist = specialnist;
    student.ocinka_fizyka = physics;
    student.ocinka_matematyka = math;
    student.ocinka_informatyka = info;
    return student;
}

TEST(StudentTests, PrintStudentsWithoutLowGrades_NoLowGrades)
{
    Student students[] = {
        createStudent("Ivanov", 2, KN, 5, 4, 5),
        createStudent("Petrenko", 3, INF, 4, 4, 4),
        createStudent("Shevchenko", 1, ME, 5, 5, 5)};
    std::ostringstream oss;
    std::streambuf *oldCout = std::cout.rdbuf(oss.rdbuf());
    PrintStudentsWithoutLowGrades(students, 3);
    std::cout.rdbuf(oldCout);
    EXPECT_NE(oss.str().find("Ivanov"), std::string::npos);
    EXPECT_NE(oss.str().find("Petrenko"), std::string::npos);
    EXPECT_NE(oss.str().find("Shevchenko"), std::string::npos);
}

TEST(StudentTests, CountStudentsWithExcellentPhysics_CorrectCount)
{
    Student students[] = {
        createStudent("Ivanov", 2, KN, 5, 4, 5),
        createStudent("Petrenko", 3, INF, 3, 4, 4),
        createStudent("Shevchenko", 1, ME, 5, 5, 5)};
    int count = CountStudentsWithExcellentPhysics(students, 3);
    EXPECT_EQ(count, 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
