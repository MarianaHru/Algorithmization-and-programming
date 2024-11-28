// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// // Function to create the input file with given data
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
//     cin >> data;
//     outFile.write(data.c_str(), data.size());
//     outFile.close();
// }

// // Function to process the file and create the output file without characters from the word "геометрія"
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
//             // If the character did not match the sequence, write all matched characters so far
//             if (excludeIndex > 0)
//             {
//                 outFile.write(exclude.c_str(), excludeIndex);
//                 excludeIndex = 0;
//             }
//             outFile.write(&ch, sizeof(ch));
//         }
//     }

//     // Write any remaining matched characters that were not part of the full sequence
//     if (excludeIndex > 0)
//     {
//         outFile.write(exclude.c_str(), excludeIndex);
//     }

//     inFile.close();
//     outFile.close();
// }

// // Function to display the contents of a file
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

// int main()
// {
//     string inputFilename = "input.bin";
//     string outputFilename = "output.bin";

//     createInputFile(inputFilename);
//     processFile(inputFilename, outputFilename);
//     displayFile(outputFilename);

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInputFile(const string &filename)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }
    string data;
    cout << "Введіть символи для запису в файл (без пробілів): ";
    cin >> data;                              // Зчитуємо символи, які користувач хоче записати у файл
    outFile.write(data.c_str(), data.size()); // Записуємо символи у файл
    outFile.close();
}

// Функція для обробки файлу та створення вихідного файлу без символів зі слова "геометрія"
void processFile(const string &inputFilename, const string &outputFilename)
{
    ifstream inFile(inputFilename, ios::binary);
    if (!inFile)
    {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    ofstream outFile(outputFilename, ios::binary);
    if (!outFile)
    {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    string exclude = "геометрія"; // Слово, символи якого потрібно виключити
    char ch;
    size_t excludeIndex = 0; // Індекс для відстеження послідовності збігів символів

    while (inFile.read(&ch, sizeof(ch)))
    {
        if (ch == exclude[excludeIndex])
        {
            excludeIndex++; // Перевіряємо, чи наступний символ відповідає послідовності
            if (excludeIndex == exclude.size())
            {
                excludeIndex = 0; // Якщо знайдено всю послідовність, скидаємо індекс
            }
        }
        else
        {
            // Якщо символ не відповідає послідовності, записуємо всі співпалі символи
            if (excludeIndex > 0)
            {
                outFile.write(exclude.c_str(), excludeIndex); // Записуємо часткову послідовність
                excludeIndex = 0;
            }
            outFile.write(&ch, sizeof(ch)); // Записуємо символ, що не збігся
        }
    }

    // Записуємо залишкові співпалі символи, які не утворили повну послідовність
    if (excludeIndex > 0)
    {
        outFile.write(exclude.c_str(), excludeIndex);
    }

    inFile.close();
    outFile.close();
}

// Функція для виведення вмісту файлу на екран
void displayFile(const string &filename)
{
    ifstream inFile(filename, ios::binary);
    if (!inFile)
    {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    cout << "Вміст файлу \"" << filename << "\": ";
    char ch;
    while (inFile.read(&ch, sizeof(ch)))
    {
        cout << ch; // Виводимо символи файлу на екран
    }
    cout << endl;

    inFile.close();
}

#ifndef UNIT_TESTING

int main()
{
    string inputFilename = "input.bin";   // Назва вхідного файлу
    string outputFilename = "output.bin"; // Назва вихідного файлу

    createInputFile(inputFilename);             // Створюємо вхідний файл
    processFile(inputFilename, outputFilename); // Обробляємо файл
    displayFile(outputFilename);                // Виводимо вміст вихідного файлу на екран

    return 0;
}

#endif