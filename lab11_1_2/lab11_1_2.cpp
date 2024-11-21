#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для пошуку позиції третьої коми
bool FindThirdComma(const string &line, int &charPosition)
{
    int commaCount = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            commaCount++;
            if (commaCount == 3)
            {
                charPosition = static_cast<int>(i + 1); // Позиція третьої коми (1-based index)
                return true;                            // Знайдено
            }
        }
    }
    return false; // Не знайдено
}

// Основна функція для обробки файлу
void ProcessFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Не вдалося відкрити файл: " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    int foundLine = 0;
    int charPosition = 0;

    // Зчитування рядків файлу
    while (getline(file, line))
    {
        lineNumber++;
        if (FindThirdComma(line, charPosition))
        {
            foundLine = lineNumber;
            break;
        }
    }

    file.close();

    if (foundLine > 0)
    {
        cout << "Третя кома знайдена:" << endl;
        cout << "Рядок: " << foundLine << ", Позиція: " << charPosition << endl;
    }
    else
    {
        cout << "У файлі немає третьої коми." << endl;
    }
}
#ifndef UNIT_TESTING
int main()
{
    string filename;

    // Запитати користувача про назву файлу
    cout << "Введіть назву текстового файлу (з повним шляхом, якщо файл не в поточній директорії): ";
    cin >> filename;

    // Обробка файлу
    ProcessFile(filename);

    return 0;
}
#endif