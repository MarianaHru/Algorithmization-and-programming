// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// // Структура для зберігання інформації про мешканців
// struct Resident
// {
//     string surname;
//     string initials;
//     int room_number;
//     bool is_single_room;
// };

// const int MAX_RESIDENTS = 100;

// // Функція для відображення всіх даних про мешканців
// void display_all_data(const Resident residents[], int count)
// {
//     if (count == 0)
//     {
//         cout << "Немає даних для виводу." << endl;
//         return;
//     }

//     cout << "\nСписок всіх записів:\n";
//     for (int i = 0; i < count; ++i)
//     {
//         cout << "Запис " << i + 1 << ":\n";
//         cout << "  Прізвище: " << residents[i].surname << "\n";
//         cout << "  Ініціали: " << residents[i].initials << "\n";
//         cout << "  Номер кімнати: " << residents[i].room_number << "\n";
//         cout << "  Тип кімнати: " << (residents[i].is_single_room ? "Одномісна" : "Двомісна") << "\n";
//     }
//     cout << endl;
// }

// // Функція для додавання нового мешканця
// void add_resident(Resident residents[], int &count, int room_number, bool is_single_room)
// {
//     if (count >= MAX_RESIDENTS)
//     {
//         cout << "Максимальна кількість мешканців досягнута." << endl;
//         return;
//     }

//     Resident resident;
//     cout << "Введіть прізвище мешканця: ";
//     cin >> resident.surname;
//     cout << "Введіть ініціали мешканця: ";
//     cin >> resident.initials;
//     resident.room_number = room_number;
//     resident.is_single_room = is_single_room;

//     residents[count++] = resident;
// }

// // Функція для видалення мешканця за прізвищем
// void remove_resident(Resident residents[], int &count, const string &surname)
// {
//     int index = -1;
//     for (int i = 0; i < count; ++i)
//     {
//         if (residents[i].surname == surname)
//         {
//             index = i;
//             break;
//         }
//     }

//     if (index != -1)
//     {
//         for (int i = index; i < count - 1; ++i)
//         {
//             residents[i] = residents[i + 1];
//         }
//         --count;
//         cout << "Мешканець з прізвищем " << surname << " видалений.\n";
//     }
//     else
//     {
//         cout << "Мешканця з таким прізвищем не знайдено.\n";
//     }
// }

// // Функція для редагування даних мешканця
// void edit_resident(Resident residents[], int count, const string &surname)
// {
//     bool found = false;
//     for (int i = 0; i < count; ++i)
//     {
//         if (residents[i].surname == surname)
//         {
//             cout << "Знайдено мешканця. Введіть нові дані.\n";
//             cout << "Нове прізвище: ";
//             cin >> residents[i].surname;
//             cout << "Нові ініціали: ";
//             cin >> residents[i].initials;
//             found = true;
//             cout << "Дані оновлено.\n";
//             break;
//         }
//     }
//     if (!found)
//     {
//         cout << "Мешканця з таким прізвищем не знайдено.\n";
//     }
// }

// // Функція для пошуку мешканця за прізвищем
// void find_resident(const Resident residents[], int count, const string &surname)
// {
//     int match_index = -1;
//     for (int i = 0; i < count; ++i)
//     {
//         if (residents[i].surname == surname)
//         {
//             match_index = i;
//             break;
//         }
//     }

//     if (match_index != -1)
//     {
//         cout << "Прізвище: " << residents[match_index].surname << "\n";
//         cout << "Ініціали: " << residents[match_index].initials << "\n";
//         cout << "Номер кімнати: " << residents[match_index].room_number << "\n";
//     }
//     else
//     {
//         cout << "Мешканця з таким прізвищем не знайдено.\n";
//     }
// }

// // Функція для відображення меню
// void display_menu()
// {
//     cout << "\nМеню:\n";
//     cout << "1. Додати мешканця\n";
//     cout << "2. Видалити мешканця\n";
//     cout << "3. Редагувати дані про мешканця\n";
//     cout << "4. Знайти мешканця за прізвищем\n";
//     cout << "5. Показати всі записи\n";
//     cout << "6. Вийти\n";
//     cout << "Виберіть пункт: ";
// }

// #include <fstream> // Для роботи з файлами

// void saveToFile(const Resident *residents, int size)
// {
//     string filename;
//     cout << "Введіть ім'я файлу для збереження: ";
//     cin >> filename;

//     ofstream file(filename, ios::out | ios::binary);
//     if (!file)
//     {
//         cout << "Помилка відкриття файлу для запису.\n";
//         return;
//     }

//     // Записуємо розмір масиву
//     file.write(reinterpret_cast<char *>(&size), sizeof(size));

//     // Записуємо дані про мешканців
//     file.write(reinterpret_cast<char *>(const_cast<Resident *>(residents)), sizeof(Resident) * size);

//     file.close();
//     cout << "Дані збережено у файл.\n";
// }

// void loadFromFile(Resident* residents, int& size) {
//     string filename;
//     cout << "Введіть ім'я файлу для зчитування: ";
//     cin >> filename;

//     ifstream file(filename, ios::in | ios::binary);
//     if (!file) {
//         cout << "Помилка відкриття файлу для зчитування.\n";
//         return;
//     }

//     file.read(reinterpret_cast<char*>(&size), sizeof(size));
//     file.read(reinterpret_cast<char*>(residents), sizeof(Resident) * size);
//     file.close();

//     cout << "Дані зчитано з файлу.\n";
// }

// #ifndef UNIT_TESTING

// int main()
// {
//     Resident residents[MAX_RESIDENTS];
//     int resident_count = 0;

//     bool running = true;
//     while (running)
//     {
//         display_menu();
//         int choice;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             int room_number;
//             bool is_single_room;
//             cout << "Введіть номер кімнати (1-5 для одномісних, 6-15 для двомісних): ";
//             cin >> room_number;
//             if (room_number >= 1 && room_number <= 5)
//             {
//                 is_single_room = true;
//             }
//             else if (room_number >= 6 && room_number <= 15)
//             {
//                 is_single_room = false;
//             }
//             else
//             {
//                 cout << "Неправильний номер кімнати.\n";
//                 break;
//             }
//             add_resident(residents, resident_count, room_number, is_single_room);
//             break;
//         }
//         case 2:
//         {
//             string surname;
//             cout << "Введіть прізвище мешканця для видалення: ";
//             cin >> surname;
//             remove_resident(residents, resident_count, surname);
//             break;
//         }
//         case 3:
//         {
//             string surname;
//             cout << "Введіть прізвище мешканця для редагування: ";
//             cin >> surname;
//             edit_resident(residents, resident_count, surname);
//             break;
//         }
//         case 4:
//         {
//             string surname;
//             cout << "Введіть прізвище для пошуку мешканця: ";
//             cin >> surname;
//             find_resident(residents, resident_count, surname);
//             break;
//         }
//         case 5:
//             display_all_data(residents, resident_count);
//             break;
//         case 6:
//             running = false;
//             break;
//         default:
//             cout << "Неправильний вибір. Спробуйте ще раз." << endl;
//         }
//     }
//     return 0;
// }

// #endif

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Структура для зберігання інформації про мешканців
struct Resident
{
    string surname;
    string initials;
    int room_number;
    bool is_single_room;
};

const int MAX_RESIDENTS = 100;

// Функція для відображення всіх даних про мешканців
void display_all_data(const Resident residents[], int count)
{
    if (count == 0)
    {
        cout << "Немає даних для виводу." << endl;
        return;
    }

    cout << "\nСписок всіх записів:\n";
    for (int i = 0; i < count; ++i)
    {
        cout << "Запис " << i + 1 << ":\n";
        cout << "  Прізвище: " << residents[i].surname << "\n";
        cout << "  Ініціали: " << residents[i].initials << "\n";
        cout << "  Номер кімнати: " << residents[i].room_number << "\n";
        cout << "  Тип кімнати: " << (residents[i].is_single_room ? "Одномісна" : "Двомісна") << "\n";
    }
    cout << endl;
}

// Функція для додавання нового мешканця
void add_resident(Resident residents[], int &count, int room_number, bool is_single_room)
{
    if (count >= MAX_RESIDENTS)
    {
        cout << "Максимальна кількість мешканців досягнута." << endl;
        return;
    }

    Resident resident;
    cout << "Введіть прізвище мешканця: ";
    cin >> resident.surname;
    cout << "Введіть ініціали мешканця: ";
    cin >> resident.initials;
    resident.room_number = room_number;
    resident.is_single_room = is_single_room;

    residents[count++] = resident;
}

// Функція для видалення мешканця за прізвищем
void remove_resident(Resident residents[], int &count, const string &surname)
{
    int index = -1;
    for (int i = 0; i < count; ++i)
    {
        if (residents[i].surname == surname)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < count - 1; ++i)
        {
            residents[i] = residents[i + 1];
        }
        --count;
        cout << "Мешканець з прізвищем " << surname << " видалений.\n";
    }
    else
    {
        cout << "Мешканця з таким прізвищем не знайдено.\n";
    }
}

// Функція для редагування даних мешканця
void edit_resident(Resident residents[], int count, const string &surname)
{
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (residents[i].surname == surname)
        {
            cout << "Знайдено мешканця. Введіть нові дані.\n";
            cout << "Нове прізвище: ";
            cin >> residents[i].surname;
            cout << "Нові ініціали: ";
            cin >> residents[i].initials;
            found = true;
            cout << "Дані оновлено.\n";
            break;
        }
    }
    if (!found)
    {
        cout << "Мешканця з таким прізвищем не знайдено.\n";
    }
}

// Функція для пошуку мешканця за прізвищем
void find_resident(const Resident residents[], int count, const string &surname)
{
    int match_index = -1;
    for (int i = 0; i < count; ++i)
    {
        if (residents[i].surname == surname)
        {
            match_index = i;
            break;
        }
    }

    if (match_index != -1)
    {
        cout << "Прізвище: " << residents[match_index].surname << "\n";
        cout << "Ініціали: " << residents[match_index].initials << "\n";
        cout << "Номер кімнати: " << residents[match_index].room_number << "\n";
    }
    else
    {
        cout << "Мешканця з таким прізвищем не знайдено.\n";
    }
}

// Функція для відображення меню
void display_menu()
{
    cout << "\nМеню:\n";
    cout << "1. Додати мешканця\n";
    cout << "2. Видалити мешканця\n";
    cout << "3. Редагувати дані про мешканця\n";
    cout << "4. Знайти мешканця за прізвищем\n";
    cout << "5. Показати всі записи\n";
    cout << "6. Зберегти дані у файл\n";
    cout << "7. Завантажити дані з файлу\n";
    cout << "8. Вийти\n";
    cout << "Виберіть пункт: ";
}

// Функція для збереження даних у текстовий файл
void saveToFile(const Resident *residents, int size)
{
    string filename;
    cout << "Введіть ім'я файлу для збереження: ";
    cin >> filename;

    ofstream file(filename);
    if (!file)
    {
        cout << "Помилка відкриття файлу для запису.\n";
        return;
    }

    file << size << endl; // Записуємо кількість мешканців
    for (int i = 0; i < size; ++i)
    {
        file << residents[i].surname << " "
             << residents[i].initials << " "
             << residents[i].room_number << " "
             << (residents[i].is_single_room ? "Одномісна" : "Двомісна") << endl;
    }
    file.close();

    cout << "Дані збережено у файл.\n";
}

// Функція для завантаження даних з текстового файлу
void loadFromFile(Resident *residents, int &size)
{
    string filename;
    cout << "Введіть ім'я файлу для зчитування: ";
    cin >> filename;

    ifstream file(filename);
    if (!file)
    {
        cout << "Помилка відкриття файлу для зчитування.\n";
        return;
    }

    file >> size;  // Читаємо кількість мешканців
    file.ignore(); // Ігноруємо символ нового рядка після числа

    for (int i = 0; i < size; ++i)
    {
        getline(file, residents[i].surname);
        getline(file, residents[i].initials);
        file >> residents[i].room_number;
        string room_type;
        file.ignore();
        getline(file, room_type); // Читаємо тип кімнати (Одномісна / Двомісна)
        residents[i].is_single_room = (room_type == "Одномісна");
    }

    file.close();
    cout << "Дані зчитано з файлу.\n";
}

#ifndef UNIT_TESTING

int main()
{
    Resident residents[MAX_RESIDENTS];
    int resident_count = 0;

    bool running = true;
    while (running)
    {
        display_menu();
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int room_number;
            bool is_single_room;
            cout << "Введіть номер кімнати (1-5 для одномісних, 6-15 для двомісних): ";
            cin >> room_number;
            if (room_number >= 1 && room_number <= 5)
            {
                is_single_room = true;
            }
            else if (room_number >= 6 && room_number <= 15)
            {
                is_single_room = false;
            }
            else
            {
                cout << "Неправильний номер кімнати.\n";
                break;
            }
            add_resident(residents, resident_count, room_number, is_single_room);
            break;
        }
        case 2:
        {
            string surname;
            cout << "Введіть прізвище мешканця для видалення: ";
            cin >> surname;
            remove_resident(residents, resident_count, surname);
            break;
        }
        case 3:
        {
            string surname;
            cout << "Введіть прізвище мешканця для редагування: ";
            cin >> surname;
            edit_resident(residents, resident_count, surname);
            break;
        }
        case 4:
        {
            string surname;
            cout << "Введіть прізвище для пошуку мешканця: ";
            cin >> surname;
            find_resident(residents, resident_count, surname);
            break;
        }
        case 5:
            display_all_data(residents, resident_count);
            break;
        case 6:
            saveToFile(residents, resident_count);
            break;
        case 7:
            loadFromFile(residents, resident_count);
            break;
        case 8:
            running = false;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }
    return 0;
}

#endif
