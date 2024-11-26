#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

enum Specialization
{
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    ENGINEERING,
    BIOLOGY
};
string specializationStr[] = {"Комп'ютерні науки", "Математика", "Фізика", "Інженерія", "Біологія"};

struct Student
{
    string surname;
    unsigned course;
    Specialization specialization;
    int physics;
    int mathematics;
    int informatics;
};

void InputStudents(Student *students, int N);
void PrintStudents(const Student *students, int N);
double CalculateAverage(const Student &student);
void SortStudentsPhysical(Student *students, int N);
int *IndexSort(const Student *students, int N);
void PrintIndexSorted(const Student *students, int *I, int N);
bool BinarySearchStudent(const Student *students, int N, const string &surname, Specialization spec, double avgScore);

int main()
{
    int numStudents;
    cout << "Введіть кількість студентів: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];
    int menuItem;
    do
    {
        cout << "\nМеню:\n";
        cout << "1 - Введення даних студентів\n";
        cout << "2 - Вивід даних студентів\n";
        cout << "3 - Фізичне впорядкування студентів\n";
        cout << "4 - Бінарний пошук студент\n";
        cout << "5 - Індексне впорядкування студентів\n";
        cout << "0 - Вихід\n";
        cout << "Виберіть дію: ";
        cin >> menuItem;

        switch (menuItem)
        {
        case 1:
            InputStudents(students, numStudents);
            break;
        case 2:
            PrintStudents(students, numStudents);
            break;
        case 3:
            SortStudentsPhysical(students, numStudents);
            cout << "Список студентів відсортовано фізично.\n";
            break;
        case 4:
        {
            string surname;
            int spec;
            double avgScore;

            cout << "Введіть прізвище студента: ";
            cin.ignore();
            getline(cin, surname);
            cout << "Введіть спеціальність (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика, 3 - Інженерія, 4 - Біологія): ";
            cin >> spec;
            cout << "Введіть середній бал студента: ";
            cin >> avgScore;

            bool found = BinarySearchStudent(students, numStudents, surname, static_cast<Specialization>(spec), avgScore);
            if (found)
            {
                cout << "Студент знайдений.\n";
            }
            else
            {
                cout << "Студента не знайдено.\n";
            }
            break;
        }
        case 5:
        {
            int *indices = IndexSort(students, numStudents);
            PrintIndexSorted(students, indices, numStudents);
            delete[] indices;
            break;
        }

        case 0:
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (menuItem != 0);

    delete[] students;
    return 0;
}

void InputStudents(Student *students, int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":\n";
        cin.ignore();
        cout << " Прізвище: ";
        getline(cin, students[i].surname);
        cout << " Курс: ";
        cin >> students[i].course;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика, 3 - Інженерія, 4 - Біологія): ";
        cin >> spec;
        students[i].specialization = static_cast<Specialization>(spec);
        cout << " Оцінка з фізики: ";
        cin >> students[i].physics;
        cout << " Оцінка з математики: ";
        cin >> students[i].mathematics;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].informatics;
    }
}

void PrintStudents(const Student *students, int N)
{
    cout << "===================================================================================\n";
    cout << "| № | Прізвище      | Курс | Спеціальність | Фізика | Математика | Інформатика    |\n";
    cout << "-----------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << i + 1 << "| ";
        cout << setw(15) << left << students[i].surname;
        cout << "    | " << setw(4) << right << students[i].course;
        cout << " | " << setw(18) << left << specializationStr[students[i].specialization];
        cout << "        | " << setw(9) << right << students[i].physics;
        cout << "        | " << setw(10) << right << students[i].mathematics;
        cout << " | " << setw(11) << right << students[i].informatics << " |\n";
    }
    cout << "=====================================================================================\n";
}

double CalculateAverage(const Student &student)
{
    return (student.physics + student.mathematics + student.informatics) / 3.0;
}

void SortStudentsPhysical(Student *students, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            bool swap = false;
            if (students[i].specialization > students[j].specialization ||
                students[i].specialization == students[j].specialization && CalculateAverage(students[i]) > CalculateAverage(students[j]) ||
                students[i].specialization == students[j].specialization && CalculateAverage(students[i]) == CalculateAverage(students[j]) && students[i].surname > students[j].surname)
            {
                swap = true;
            }
            if (swap)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int *IndexSort(const Student *students, int N)
{
    int *I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    for (int i = 1; i < N; i++)
    {
        int value = I[i];
        int j = i - 1;

        while (j >= 0 &&
               (students[I[i]].specialization > students[I[j]].specialization ||
                students[I[i]].specialization == students[I[j]].specialization && CalculateAverage(students[I[i]]) > CalculateAverage(students[I[j]]) ||
                students[I[i]].specialization == students[I[j]].specialization && CalculateAverage(students[I[i]]) == CalculateAverage(students[I[j]]) && students[I[i]].surname > students[I[j]].surname))
        {

            I[j + 1] = I[j];
            j--;
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(const Student *students, int *I, int N)
{
    cout << "=============================================================================================\n";
    cout << "| № | Прізвище         | Курс | Спеціальність           | Фізика | Математика | Інформатика |\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        int idx = I[i];
        cout << "| " << setw(2) << i + 1 << "| ";
        cout << setw(18) << left << students[idx].surname;
        cout << "  | " << setw(4) << right << students[idx].course;
        cout << " | " << setw(25) << left << specializationStr[students[idx].specialization];
        cout << "   | " << setw(6) << right << students[idx].physics;
        cout << " | " << setw(10) << right << students[idx].mathematics;
        cout << " | " << setw(12) << right << students[idx].informatics << " |\n";
    }
    cout << "=============================================================================================\n";
}

bool BinarySearchStudent(const Student *students, int N, const string &surname, Specialization spec, double avgScore)
{
    SortStudentsPhysical(const_cast<Student *>(students), N);
    int left = 0, right = N - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        double midAvgScore = CalculateAverage(students[mid]);

        if (students[mid].specialization == spec &&
            fabs(midAvgScore - avgScore) < 0.01 &&
            students[mid].surname == surname)
        {
            return true;
        }

        if (students[mid].specialization < spec ||
            (students[mid].specialization == spec && midAvgScore < avgScore) ||
            (students[mid].specialization == spec && fabs(midAvgScore - avgScore) < 0.01 && students[mid].surname < surname))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}
