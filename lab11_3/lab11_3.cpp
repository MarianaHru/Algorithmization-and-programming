#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Структура для зберігання інформації про мешканців
struct Resident
{
    string surname;
    string initials;
    int room_number;
};

// Функція для завантаження мешканців із файлу
void loadResidents(const string &filename, vector<Resident> &residents)
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
    residents.clear();
    Resident resident;
    while (file >> resident.surname >> resident.initials >> resident.room_number)
    {
        residents.push_back(resident);
    }

    file.close();
    cout << "Дані успішно завантажені з файлу." << endl;
}

void findResident(const vector<Resident> &residents, const string &surname)
{
    vector<Resident> matches;
    for (const auto &resident : residents)
    {
        if (resident.surname == surname)
        {
            matches.push_back(resident);
        }
    }

    if (matches.empty())
    {
        cout << "Мешканця з прізвищем " << surname << " не знайдено." << endl;
    }
    else if (matches.size() == 1)
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
        for (const auto &resident : matches)
        {
            if (resident.initials == initials)
            {
                cout << "Прізвище: " << resident.surname << ", Ініціали: " << resident.initials
                     << ", Номер кімнати: " << resident.room_number << endl;
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

void addResident(vector<Resident> &residents)
{
    Resident resident;
    cout << "Введіть прізвище мешканця: ";
    cin >> resident.surname;
    cout << "Введіть ініціали мешканця: ";
    cin >> resident.initials;
    cout << "Введіть номер кімнати мешканця: ";
    cin >> resident.room_number;
    residents.push_back(resident);
    cout << "Мешканця додано." << endl;
}

// Функція для відображення всіх мешканців
void displayResidents(const vector<Resident> &residents)
{
    if (residents.empty())
    {
        cout << "Немає даних про мешканців." << endl;
        return;
    }

    cout << "Список мешканців готелю:" << endl;
    for (const auto &resident : residents)
    {
        cout << "Прізвище: " << resident.surname
             << ", Ініціали: " << resident.initials
             << ", Номер кімнати: " << resident.room_number << endl;
    }
}

void saveResidents(const string &filename, const vector<Resident> &residents)
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    for (const auto &resident : residents)
    {
        file << resident.surname << " " << resident.initials << " " << resident.room_number << endl;
    }

    file.close();
    cout << "Дані успішно збережені у файл." << endl;
}

#ifndef UNIT_TESTING

int main()
{
    vector<Resident> residents;
    string filename;

    cout << "Введіть ім'я файлу: ";
    cin >> filename;

    // Завантажуємо або створюємо файл
    loadResidents(filename, residents);

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
            loadResidents(filename, residents);
            break;
        case 2:
        {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            findResident(residents, surname);
            break;
        }
        case 3:
            addResident(residents);
            break;
        case 4:
            displayResidents(residents);
            break;
        case 5:
            saveResidents(filename, residents);
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