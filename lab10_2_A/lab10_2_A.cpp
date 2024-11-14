#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric> // Для функції iota

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

    double averageGrade() const
    {
        return (ocinka_fizyka + ocinka_matematyka + ocinka_informatyka) / 3.0;
    }
};

// Функція для створення масиву студентів
void CreateStudents(Student students[], int N)
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
        students[i].specialnist = static_cast<Specialnist>(specialnist);

        // Введення оцінок
        cout << " Оцінка з фізики: ";
        cin >> students[i].ocinka_fizyka;
        cout << " Оцінка з математики: ";
        cin >> students[i].ocinka_matematyka;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].ocinka_informatyka;
    }
}

// Функція-компаратор для фізичного впорядкування
bool CompareStudents(const Student &a, const Student &b)
{
    if (a.specialnist != b.specialnist)
        return a.specialnist < b.specialnist; // Сортування за спеціальністю
    if (a.averageGrade() != b.averageGrade())
        return a.averageGrade() > b.averageGrade(); // Сортування за середнім балом у порядку спадання
    return a.prizv < b.prizv;                       // Сортування за прізвищем
}

// Функція для фізичного впорядкування студентів
void SortStudentsPhysically(Student students[], int N)
{
    sort(students, students + N, CompareStudents);
}

// Функція для створення індексного масиву
void CreateIndexArray(int indices[], const Student students[], int N)
{
    iota(indices, indices + N, 0); // Ініціалізація індексного масиву

    sort(indices, indices + N, [&](int a, int b)
         { return CompareStudents(students[a], students[b]); });
}

// Функція для виведення студентів у таблиці
void PrintStudents(const Student students[], int N)
{
    cout << "======================================================================" << endl;
    cout << "| № | Прізвище       | Курс | Спеціальність          | Фізика | Математика | Інформатика | Середній бал |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {

        cout << "|" << setw(2) << i + 1
             << " | " << setw(15) << left << students[i].prizv
             << "| " << setw(4) << right << students[i].kurs
             << " | " << setw(22) << left << specialnistStr[students[i].specialnist]
             << " | " << setw(6) << students[i].ocinka_fizyka
             << " | " << setw(10) << students[i].ocinka_matematyka
             << " | " << setw(11) << students[i].ocinka_informatyka
             << " | " << setw(11) << fixed << setprecision(2) << students[i].averageGrade() << " |" << endl;
    }
    cout << "======================================================================" << endl;
}

// Функція для бінарного пошуку студента за прізвищем та середнім балом
bool BinarySearchStudent(const Student students[], int N, const string &prizv, double avgGrade)
{
    int left = 0, right = N - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        const Student &student = students[mid];
        double studentAvg = student.averageGrade();
        if (student.prizv == prizv && studentAvg == avgGrade)
            return true;
        if (student.prizv < prizv || (student.prizv == prizv && studentAvg < avgGrade))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// Меню для роботи з програмою
void Menu()
{
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int N = 0;

    while (true)
    {
        cout << "\nМеню:" << endl;
        cout << "1. Додати студентів" << endl;
        cout << "2. Фізичне впорядкування студентів" << endl;
        cout << "3. Створити індексний масив для впорядкування" << endl;
        cout << "4. Вивести студентів" << endl;
        cout << "5. Бінарний пошук студента за прізвищем та середнім балом" << endl;
        cout << "6. Вийти" << endl;
        cout << "Виберіть дію: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Введіть кількість студентів (максимум " << MAX_STUDENTS << "): ";
            cin >> N;
            if (N > MAX_STUDENTS)
            {
                cout << "Занадто багато студентів. Введіть кількість до " << MAX_STUDENTS << "." << endl;
                continue;
            }
            CreateStudents(students, N);
        }
        else if (choice == 2)
        {
            SortStudentsPhysically(students, N);
            cout << "Студенти впорядковані фізично." << endl;
        }
        else if (choice == 3)
        {
            int indices[MAX_STUDENTS];
            CreateIndexArray(indices, students, N);
            cout << "Індексний масив створений." << endl;
            for (int i = 0; i < N; ++i)
            {
                cout << "Індекс " << i + 1 << ": " << indices[i] << endl;
            }
        }
        else if (choice == 4)
        {
            PrintStudents(students, N);
        }
        else if (choice == 5)
        {
            string prizv;
            double avgGrade;
            cout << "Введіть прізвище студента: ";
            cin >> prizv;
            cout << "Введіть середній бал: ";
            cin >> avgGrade;
            if (BinarySearchStudent(students, N, prizv, avgGrade))
            {
                cout << "Студента знайдено." << endl;
            }
            else
            {
                cout << "Студента не знайдено." << endl;
            }
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }
}

int main()
{
    Menu();
    return 0;
}
