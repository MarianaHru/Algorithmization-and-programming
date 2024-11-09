#include <iostream>
#include <fstream>
#include <cctype>
#include <cassert>

#define IS_ALPHABETIC(c) (isalpha(c))
#define IS_DIGIT(c) (isdigit(c))
#define IS_CONTROL(c) (iscntrl(c))
#define IS_PUNCTUATION(c) (ispunct(c))
#define PRINT_STAT(type, count) std::cout << #type << ": " << count << std::endl

void classifyAndCount(const char *filename, int minRange, int maxRange)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return;
    }

    int alphabeticCount = 0, digitCount = 0, controlCount = 0, punctuationCount = 0, otherCount = 0;
    char ch;

    while (file.get(ch))
    {
        if (IS_ALPHABETIC(ch))
        {
            alphabeticCount++;
        }
        else if (IS_DIGIT(ch))
        {
            digitCount++;
            int digitValue = ch - '0';
            assert(digitValue >= minRange && digitValue <= maxRange && "Цифра поза заданим діапазоном!");
        }
        else if (IS_CONTROL(ch))
        {
            controlCount++;
        }
        else if (IS_PUNCTUATION(ch))
        {
            punctuationCount++;
        }
        else
        {
            otherCount++;
        }
    }

    PRINT_STAT(Алфавітні символи, alphabeticCount);
    PRINT_STAT(Цифрові символи, digitCount);
    PRINT_STAT(Керуючі символи, controlCount);
    PRINT_STAT(Знаки пунктуації, punctuationCount);
    PRINT_STAT(Інші символи, otherCount);

    file.close();
}

#ifndef UNIT_TESTING

int main()
{
    const char *filename = "input.txt";
    int minRange = 2, maxRange = 8;

    classifyAndCount(filename, minRange, maxRange);

    std::cout << "Натисніть будь-яку клавішу для виходу...";
    std::cin.get();

    return 0;
}

#endif