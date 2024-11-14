#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Перелік спеціальностей
enum Specialnist
{
    KN,
    INF,
    ME,
    FI,
    TN
};
string specialnistStr[] = {"Комп'ютерні науки", "Інформатика", "Економіка", "Фізика", "Трудове навчання"};

// Структура для зберігання інформації про студента
struct Student
{
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    int ocinka_informatyka;
};

// Функція для створення масиву студентів
void CreateStudents(Student *students, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << " Прізвище: ";
        cin >> students[i].prizv;
        cout << " Курс: ";
        cin >> students[i].kurs;

        int specialnist;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Економіка, 3 - Фізика, 4 - Трудове навчання): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // Введення оцінок
        cout << " Оцінка з фізики: ";
        cin >> students[i].ocinka_fizyka;
        cout << " Оцінка з математики: ";
        cin >> students[i].ocinka_matematyka;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].ocinka_informatyka;
        cout << endl;
    }
}

// Функція для виведення студентів на екран
void PrintStudents(const Student *students, const int N)
{
    cout << "==========================================================================================" << endl;
    cout << "| № | Прізвище     | Курс   | Спеціальність       | Фізика | Математика | Інформатика    |" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << i + 1
             << " | " << setw(16) << left << students[i].prizv
             << "|     " << setw(3) << right << students[i].kurs
             << " |   " << setw(26) << left << specialnistStr[students[i].specialnist]
             << " |   " << setw(6) << students[i].ocinka_fizyka
             << " |      " << setw(4) << students[i].ocinka_matematyka
             << "   | " << setw(7) << students[i].ocinka_informatyka << "     |" << endl;
    }
    cout << "==========================================================================================" << endl;
}

// Функція для виведення прізвищ студентів, які навчаються без трійок
void PrintStudentsWithoutLowGrades(const Student *students, const int N)
{
    cout << "Студенти, які вчаться без трійок (на 'відмінно' і 'добре'):" << endl;
    for (int i = 0; i < N; i++)
    {
        if (students[i].ocinka_fizyka >= 4 && students[i].ocinka_matematyka >= 4 && students[i].ocinka_informatyka >= 4)
        {
            cout << " - " << students[i].prizv << endl;
        }
    }
}

// Функція для підрахунку студентів, які отримали "5" з фізики
int CountStudentsWithExcellentPhysics(const Student *students, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (students[i].ocinka_fizyka == 5)
        {
            count++;
        }
    }
    return count;
}

#ifndef UNIT_TESTING

int main()
{
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student *students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    // Виведення прізвищ студентів, які вчаться без трійок
    PrintStudentsWithoutLowGrades(students, N);

    // Підрахунок студентів, які отримали "5" з фізики
    int excellentPhysicsCount = CountStudentsWithExcellentPhysics(students, N);
    cout << "Кількість студентів, які отримали '5' з фізики: " << excellentPhysicsCount << endl;

    delete[] students;
    return 0;
}

#endif