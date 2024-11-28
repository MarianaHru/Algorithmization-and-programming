#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура для зберігання даних мешканця
struct Resident
{
    char surname[50];
    char initials[10];
    int room_number;
    bool is_single_room;
};

// Функція для додавання мешканця до файлу
void addResident(const string &filename)
{
    Resident resident;
    cout << "Введіть прізвище мешканця: ";
    cin >> resident.surname;
    cout << "Введіть ініціали мешканця: ";
    cin >> resident.initials;
    cout << "Введіть номер кімнати (1-15): ";
    cin >> resident.room_number;

    while (resident.room_number < 1 || resident.room_number > 15)
    {
        cout << "Номер кімнати має бути в межах 1-15. Спробуйте ще раз: ";
        cin >> resident.room_number;
    }

    cout << "Чи одномісна кімната? (1 - так, 0 - ні): ";
    cin >> resident.is_single_room;

    ofstream file(filename, ios::binary | ios::app);
    if (!file)
    {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    file.write(reinterpret_cast<const char *>(&resident), sizeof(Resident));
    file.close();
    cout << "Мешканця успішно додано!" << endl;
}

// Функція для перегляду всіх мешканців
void displayResidents(const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    Resident resident;
    cout << "\nСписок мешканців:\n";
    while (file.read(reinterpret_cast<char *>(&resident), sizeof(Resident)))
    {
        cout << "Прізвище: " << resident.surname
             << ", Ініціали: " << resident.initials
             << ", Номер кімнати: " << resident.room_number
             << ", Тип кімнати: " << (resident.is_single_room ? "Одномісна" : "Двомісна") << endl;
    }
    file.close();
}

// Функція для пошуку мешканця за прізвищем
bool findResident(const string &filename, const string &surname, Resident &result)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return false;
    }

    Resident resident;
    int match_count = 0;
    Resident temp_resident;

    while (file.read(reinterpret_cast<char *>(&resident), sizeof(Resident)))
    {
        if (surname == resident.surname)
        {
            match_count++;
            temp_resident = resident;
        }
    }
    file.close();

    if (match_count == 0)
    {
        cout << "Мешканця з прізвищем " << surname << " не знайдено!" << endl;
        return false;
    }
    else if (match_count == 1)
    {
        result = temp_resident;
        return true;
    }
    else
    {
        cout << "Знайдено кілька мешканців із прізвищем " << surname << ". Введіть ініціали для уточнення: ";
        string initials;
        cin >> initials;

        ifstream file_again(filename, ios::binary);
        while (file_again.read(reinterpret_cast<char *>(&resident), sizeof(Resident)))
        {
            if (surname == resident.surname && initials == resident.initials)
            {
                result = resident;
                file_again.close();
                return true;
            }
        }
        file_again.close();
        cout << "Мешканця з такими ініціалами не знайдено!" << endl;
        return false;
    }
}

// Функція для редагування даних мешканця
void editResident(const string &filename, const string &surname)
{
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Помилка відкриття файлу для редагування!" << endl;
        return;
    }

    Resident resident;
    bool found = false;
    int pos = 0;

    while (file.read(reinterpret_cast<char *>(&resident), sizeof(Resident)))
    {
        if (surname == resident.surname)
        {
            cout << "Введіть нові дані для мешканця.\n";
            cout << "Нове прізвище: ";
            cin >> resident.surname;
            cout << "Нові ініціали: ";
            cin >> resident.initials;
            cout << "Новий номер кімнати: ";
            cin >> resident.room_number;
            cout << "Чи одномісна кімната? (1 - так, 0 - ні): ";
            cin >> resident.is_single_room;

            file.seekp(pos * sizeof(Resident), ios::beg);
            file.write(reinterpret_cast<const char *>(&resident), sizeof(Resident));
            found = true;
            cout << "Дані успішно оновлено!" << endl;
            break;
        }
        pos++;
    }
    if (!found)
    {
        cout << "Мешканця з прізвищем " << surname << " не знайдено!" << endl;
    }
    file.close();
}

// Функція для видалення мешканця
void deleteResident(const string &filename, const string &surname)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    Resident resident;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&resident), sizeof(Resident)))
    {
        if (surname == resident.surname && !found)
        {
            found = true; // Пропускаємо першого знайденого мешканця для видалення
        }
        else
        {
            tempFile.write(reinterpret_cast<const char *>(&resident), sizeof(Resident));
        }
    }
    file.close();
    tempFile.close();

    if (found)
    {
        remove(filename.c_str());
        rename("temp.dat", filename.c_str());
        cout << "Мешканця успішно видалено!" << endl;
    }
    else
    {
        cout << "Мешканця з прізвищем " << surname << " не знайдено!" << endl;
        remove("temp.dat");
    }
}

#ifndef UNIT_TESTING

int main()
{
    string filename;
    cout << "Введіть ім'я файлу для роботи: ";
    cin >> filename;

    bool running = true;
    while (running)
    {
        cout << "\nМеню:\n";
        cout << "1. Додати мешканця\n";
        cout << "2. Відобразити список мешканців\n";
        cout << "3. Знайти мешканця за прізвищем\n";
        cout << "4. Редагувати дані мешканця\n";
        cout << "5. Видалити мешканця\n";
        cout << "6. Вийти\n";
        cout << "Виберіть дію: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addResident(filename);
            break;
        case 2:
            displayResidents(filename);
            break;
        case 3:
        {
            string surname;
            Resident result;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            if (findResident(filename, surname, result))
            {
                cout << "Прізвище: " << result.surname
                     << ", Ініціали: " << result.initials
                     << ", Номер кімнати: " << result.room_number
                     << ", Тип кімнати: " << (result.is_single_room ? "Одномісна" : "Двомісна") << endl;
            }
            break;
        }
        case 4:
        {
            string surname;
            cout << "Введіть прізвище мешканця для редагування: ";
            cin >> surname;
            editResident(filename, surname);
            break;
        }
        case 5:
        {
            string surname;
            cout << "Введіть прізвище мешканця для видалення: ";
            cin >> surname;
            deleteResident(filename, surname);
            break;
        }
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