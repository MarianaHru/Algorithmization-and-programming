#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// Функція для перевірки вкладеності дужок
bool CheckNestedQuotes(const string &line)
{
    stack<string> brackets;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line.substr(i, 2) == "«")
        {
            if (!brackets.empty())
            {
                return false; // Вкладені дужки
            }
            brackets.push("«");
            i++; // Пропускаємо наступний байт
        }
        else if (line.substr(i, 2) == "»")
        {
            if (brackets.empty() || brackets.top() != "«")
            {
                return false; // Невідповідність дужок
            }
            brackets.pop();
            i++; // Пропускаємо наступний байт
        }
    }

    return brackets.empty(); // Перевірка на незакриті дужки
}

// Функція для видалення тексту між дужками
string RemoveQuotesContent(const string &line)
{
    string result;
    bool insideQuotes = false;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line.substr(i, 2) == "«")
        {
            insideQuotes = true;
            i++; // Пропускаємо наступний байт
        }
        else if (line.substr(i, 2) == "»")
        {
            insideQuotes = false;
            i++; // Пропускаємо наступний байт
        }
        else if (!insideQuotes)
        {
            result += line[i];
        }
    }

    return result;
}

// Основна функція обробки файлу
void ProcessFile(const string &inputFile, const string &outputFile)
{
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open())
    {
        cout << "Не вдалося відкрити вхідний файл: " << inputFile << endl;
        return;
    }

    if (!output.is_open())
    {
        cout << "Не вдалося відкрити вихідний файл: " << outputFile << endl;
        return;
    }

    string line;
    while (getline(input, line))
    {
        if (!CheckNestedQuotes(line))
        {
            cout << "Помилка: Вкладені дужки або неправильна пара дужок у рядку: " << line << endl;
            output.close();
            input.close();
            return;
        }

        string processedLine = RemoveQuotesContent(line);
        output << processedLine << endl;
    }

    input.close();
    output.close();
    cout << "Обробка завершена. Результат записано у файл: " << outputFile << endl;
}
#ifndef UNIT_TESTING
int main()
{
    string inputFile, outputFile;

    // Запит на введення імен файлів
    cout << "Введіть назву вхідного файлу (t1): ";
    cin >> inputFile;

    cout << "Введіть назву вихідного файлу (t2): ";
    cin >> outputFile;

    // Обробка файлу
    ProcessFile(inputFile, outputFile);

    return 0;
}
#endif