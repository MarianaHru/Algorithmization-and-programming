
// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// void createInputFile(const string &filename)
// {
//     ofstream outFile(filename, ios::binary);
//     if (!outFile)
//     {
//         cerr << "Помилка відкриття файлу для запису." << endl;
//         return;
//     }
//     string data;
//     cout << "Введіть символи для запису в файл (без пробілів): ";
//     cin >> data;                              // Зчитуємо символи, які користувач хоче записати у файл
//     outFile.write(data.c_str(), data.size()); // Записуємо символи у файл
//     outFile.close();
// }

// void processFile(const string &inputFilename, const string &outputFilename)
// {
//     ifstream inFile(inputFilename, ios::binary);
//     if (!inFile)
//     {
//         cerr << "Помилка відкриття файлу для читання." << endl;
//         return;
//     }

//     ofstream outFile(outputFilename, ios::binary);
//     if (!outFile)
//     {
//         cerr << "Помилка відкриття файлу для запису." << endl;
//         return;
//     }

//     string exclude = "геометрія";
//     char ch;

//     size_t excludeIndex = 0;

//     while (inFile.read(&ch, sizeof(ch)))
//     {
//         if (ch == exclude[excludeIndex])
//         {
//             excludeIndex++;
//             if (excludeIndex == exclude.size())
//             {
//                 excludeIndex = 0;
//             }
//         }
//         else
//         {

//             if (excludeIndex > 0)
//             {
//                 outFile.write(exclude.c_str(), excludeIndex);
//                 excludeIndex = 0;
//             }
//             outFile.write(&ch, sizeof(ch));
//         }
//     }

//     if (excludeIndex > 0)
//     {
//         outFile.write(exclude.c_str(), excludeIndex);
//     }

//     inFile.close();
//     outFile.close();
// }

// // Функція для виведення вмісту файлу на екран
// void displayFile(const string &filename)
// {
//     ifstream inFile(filename, ios::binary);
//     if (!inFile)
//     {
//         cerr << "Помилка відкриття файлу для читання." << endl;
//         return;
//     }

//     cout << "Вміст файлу \"" << filename << "\": ";
//     char ch;
//     while (inFile.read(&ch, sizeof(ch)))
//     {
//         cout << ch;
//     }
//     cout << endl;

//     inFile.close();
// }

// #ifndef UNIT_TESTING

// int main()
// {
//     string inputFilename = "input.bin";   // Назва вхідного файлу
//     string outputFilename = "output.bin"; // Назва вихідного файлу

//     createInputFile(inputFilename);             // Створюємо вхідний файл
//     processFile(inputFilename, outputFilename); // Обробляємо файл
//     displayFile(outputFilename);                // Виводимо вміст вихідного файлу на екран

//     return 0;
// }

// #endif
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInputFile(const string &filename)
{
    ofstream outFile(filename, ios::out); // Відкриваємо файл у текстовому режимі
    if (!outFile)
    {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }
    string data;
    cout << "Введіть символи для запису в файл (без пробілів): ";
    cin >> data;     // Зчитуємо символи, які користувач хоче записати у файл
    outFile << data; // Записуємо символи у файл
    outFile.close();
}

void processFile(const string &inputFilename, const string &outputFilename)
{
    ifstream inFile(inputFilename, ios::in); // Відкриваємо файл для читання в текстовому режимі
    if (!inFile)
    {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    ofstream outFile(outputFilename, ios::out); // Відкриваємо файл для запису в текстовому режимі
    if (!outFile)
    {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    string exclude = "геометрія";
    char ch;

    while (inFile.get(ch))
    {

        if (exclude.find(ch) == string::npos)
        {
            outFile.put(ch);
        }
    }

    inFile.close();
    outFile.close();
}

// Функція для виведення вмісту файлу на екран
void displayFile(const string &filename)
{
    ifstream inFile(filename, ios::in); // Відкриваємо файл для читання в текстовому режимі
    if (!inFile)
    {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    cout << "Вміст файлу \"" << filename << "\": ";
    char ch;
    while (inFile.get(ch)) // Читаємо символи по одному
    {
        cout << ch; // Виводимо символи на екран
    }
    cout << endl;

    inFile.close();
}

#ifndef UNIT_TESTING

int main()
{
    string inputFilename = "input.txt";   // Назва вхідного файлу
    string outputFilename = "output.txt"; // Назва вихідного файлу

    createInputFile(inputFilename);             // Створюємо вхідний файл
    processFile(inputFilename, outputFilename); // Обробляємо файл
    displayFile(outputFilename);                // Виводимо вміст вихідного файлу на екран

    return 0;
}

#endif
