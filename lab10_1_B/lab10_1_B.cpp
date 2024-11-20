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

// Об'єднання для зберігання оцінок залежно від спеціальності
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

// Структура для зберігання інформації про студента
struct Student
{
    string prizv;
    int kurs;
    Specialnist specialnist;
    Grades grades;
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

        // Введення оцінок залежно від спеціальності
        if (students[i].specialnist == KN || students[i].specialnist == INF)
        {
            cout << " Оцінка з фізики: ";
            cin >> students[i].grades.kn_inf.ocinka_fizyka;
            cout << " Оцінка з математики: ";
            cin >> students[i].grades.kn_inf.ocinka_matematyka;
            cout << " Оцінка з програмування: ";
            cin >> students[i].grades.kn_inf.ocinka_programming;
        }
        else if (students[i].specialnist == ME)
        {
            cout << " Оцінка з фізики: ";
            cin >> students[i].grades.me.ocinka_fizyka;
            cout << " Оцінка з математики: ";
            cin >> students[i].grades.me.ocinka_matematyka;
            cout << " Оцінка з чисельних методів: ";
            cin >> students[i].grades.me.ocinka_chiselni_metody;
        }
        else if (students[i].specialnist == FI || students[i].specialnist == TN)
        {
            cout << " Оцінка з фізики: ";
            cin >> students[i].grades.fi_tn.ocinka_fizyka;
            cout << " Оцінка з математики: ";
            cin >> students[i].grades.fi_tn.ocinka_matematyka;
            cout << " Оцінка з педагогіки: ";
            cin >> students[i].grades.fi_tn.ocinka_pedagogika;
        }
        cout << endl;
    }
}

// Функція для виведення студентів на екран у вигляді таблиці
void PrintStudents(const Student *students, const int N)
{
    cout << "=============================================================================================================" << endl;
    cout << "| № | Прізвище      | Курс    | Спеціальність       | Фізика | Математика | Програмування|Методи|Педагогіка |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << i + 1
             << " | " << setw(15) << left << students[i].prizv
             << "  |   " << setw(5) << right << students[i].kurs
             << "   |    " << setw(27) << left << specialnistStr[students[i].specialnist];

        // Виведення оцінок залежно від спеціальності
        if (students[i].specialnist == KN || students[i].specialnist == INF)
        {
            cout << "| " << setw(7) << students[i].grades.kn_inf.ocinka_fizyka
                 << "| " << setw(10) << students[i].grades.kn_inf.ocinka_matematyka
                 << "| " << setw(10) << students[i].grades.kn_inf.ocinka_programming;
        }
        else if (students[i].specialnist == ME)
        {
            cout << "| " << setw(7) << students[i].grades.me.ocinka_fizyka
                 << "| " << setw(10) << students[i].grades.me.ocinka_matematyka
                 << "| " << setw(10) << students[i].grades.me.ocinka_chiselni_metody;
        }
        else if (students[i].specialnist == FI || students[i].specialnist == TN)
        {
            cout << "| " << setw(7) << students[i].grades.fi_tn.ocinka_fizyka
                 << "| " << setw(10) << students[i].grades.fi_tn.ocinka_matematyka
                 << "|   " << setw(10) << students[i].grades.fi_tn.ocinka_pedagogika;
        }
        cout << "                      |"
             << endl;
    }
    cout << "=============================================================================================================" << endl;
}

// Функція для виведення прізвищ студентів, які навчаються без трійок

void PrintStudentsWithoutLowGrades(const Student *students, const int N)
{
    cout << "студенти, які навчаються без трійок:" << endl;
    bool hasExcellent = false; // Змінна для перевірки, чи є хоч один відмінник

    for (int i = 0; i < N; i++)
    {
        bool isExcellent = (students[i].grades.kn_inf.ocinka_programming >= 4 && students[i].grades.me.ocinka_chiselni_metody >= 4 && students[i].grades.fi_tn.ocinka_pedagogika >= 4);

        if (isExcellent)
        {
            cout << " - " << students[i].prizv << endl;
            hasExcellent = true;
        }
    }

    if (!hasExcellent)
    {
        cout << "Немає студентів, які вчаться на відмінно." << endl;
    }
}

// Функція для підрахунку студентів, які отримали "5" з фізики

int CountStudentsWithExcellentPhysics(const Student *students, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (students[i].grades.kn_inf.ocinka_fizyka == 5)
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