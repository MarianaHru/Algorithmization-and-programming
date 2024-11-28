#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Resident
{
    string surname;
    string initials;
    int room_number;
};

const int MAX_RESIDENTS = 100;

// Функція для завантаження мешканців із файлу
void loadResidents(const string &filename, Resident residents[], int &count)
{
    ifstream file(filename);

    // Якщо файл не існує, створюємо його
    if (!file)
    {
        cout << "Файл " << filename << " не знайдено. Створюємо новий файл." << endl;
        ofstream newFile(filename);
        if (!newFile)
        {
            cout << "Помилка створення файлу." << endl;
            return;
        }

        newFile << "Ivanov I.I. 1\n";
        newFile << "Petrov P.P. 6\n";
        newFile << "Sidorov S.S. 10\n";
        newFile.close();
        return;
    }

    // Завантажуємо дані з файлу
    count = 0;
    while (file >> residents[count].surname >> residents[count].initials >> residents[count].room_number)
    {
        count++;
        if (count >= MAX_RESIDENTS)
        {
            cout << "Досягнуто максимального розміру масиву мешканців." << endl;
            break;
        }
    }

    file.close();
    cout << "Дані успішно завантажені з файлу." << endl;
}

void findResident(const Resident residents[], int count, const string &surname)
{
    Resident matches[MAX_RESIDENTS];
    int matchCount = 0;

    for (int i = 0; i < count; i++)
    {
        if (residents[i].surname == surname)
        {
            matches[matchCount++] = residents[i];
        }
    }

    if (matchCount == 0)
    {
        cout << "Мешканця з прізвищем " << surname << " не знайдено." << endl;
    }
    else if (matchCount == 1)
    {
        cout << "Прізвище: " << matches[0].surname << ", Ініціали: " << matches[0].initials
             << ", Номер кімнати: " << matches[0].room_number << endl;
    }
    else
    {
        cout << "Знайдено кілька мешканців із прізвищем " << surname << "." << endl;
        cout << "Введіть ініціали для уточнення: ";
        string initials;
        cin >> initials;
        bool found = false;
        for (int i = 0; i < matchCount; i++)
        {
            if (matches[i].initials == initials)
            {
                cout << "Прізвище: " << matches[i].surname << ", Ініціали: " << matches[i].initials
                     << ", Номер кімнати: " << matches[i].room_number << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Мешканця з такими ініціалами не знайдено." << endl;
        }
    }
}

void appendResidentToFile(const string &filename, const Resident &resident)
{
    ofstream file(filename, ios::app); // Відкриваємо файл у режимі доповнення
    if (!file)
    {
        cout << "Помилка відкриття файлу для доповнення." << endl;
        return;
    }

    file << resident.surname << " "
         << resident.initials << " "
         << resident.room_number << endl;

    file.close();
    cout << "Мешканця успішно додано до файлу." << endl;
}

void addResident(Resident residents[], int &count, const string &filename)
{
    if (count >= MAX_RESIDENTS)
    {
        cout << "Досягнуто максимального розміру масиву мешканців." << endl;
        return;
    }

    Resident resident;
    cout << "Введіть прізвище мешканця: ";
    cin >> resident.surname;
    cout << "Введіть ініціали мешканця: ";
    cin >> resident.initials;
    cout << "Введіть номер кімнати мешканця: ";
    cin >> resident.room_number;

    residents[count++] = resident;
    appendResidentToFile(filename, resident); // Додаємо мешканця до файлу
}

// Функція для відображення всіх мешканців
void displayResidents(const Resident residents[], int count)
{
    if (count == 0)
    {
        cout << "Немає даних про мешканців." << endl;
        return;
    }

    cout << "Список мешканців готелю:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Прізвище: " << residents[i].surname
             << ", Ініціали: " << residents[i].initials
             << ", Номер кімнати: " << residents[i].room_number << endl;
    }
}

// Функція для збереження всіх мешканців у файл
void saveResidents(const string &filename, const Resident residents[], int count)
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << residents[i].surname << " " << residents[i].initials << " " << residents[i].room_number << endl;
    }

    file.close();
    cout << "Дані успішно збережені у файл." << endl;
}

#ifndef UNIT_TESTING

int main()
{
    Resident residents[MAX_RESIDENTS];
    int residentCount = 0;
    string filename;

    cout << "Введіть ім'я файлу: ";
    cin >> filename;

    // Завантажуємо або створюємо файл
    loadResidents(filename, residents, residentCount);

    bool running = true;
    while (running)
    {
        cout << "\nМеню:\n";
        cout << "1. Завантажити дані з файлу\n";
        cout << "2. Знайти мешканця за прізвищем\n";
        cout << "3. Додати нового мешканця\n";
        cout << "4. Відобразити список мешканців\n";
        cout << "5. Зберегти дані у файл\n";
        cout << "6. Вийти\n";
        cout << "Виберіть дію: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            loadResidents(filename, residents, residentCount);
            break;
        case 2:
        {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            findResident(residents, residentCount, surname);
            break;
        }
        case 3:
            addResident(residents, residentCount, filename);
            break;
        case 4:
            displayResidents(residents, residentCount);
            break;
        case 5:
            saveResidents(filename, residents, residentCount);
            break;
        case 6:
            running = false;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}

#endif
