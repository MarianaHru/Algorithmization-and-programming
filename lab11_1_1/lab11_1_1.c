#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Функція для пошуку позиції третьої коми
int FindThirdComma(const char *line, int *charPosition)
{
    int commaCount = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ',')
        {
            commaCount++;
            if (commaCount == 3)
            {
                *charPosition = i + 1; // Позиція третьої коми (1-based index)
                return 1;              // Знайдено
            }
        }
    }
    return 0;
}

void ProcessFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Не вдалося відкрити файл: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int foundLine = 0;
    int charPosition = 0;

    // Зчитування рядків файлу
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        lineNumber++;
        if (FindThirdComma(line, &charPosition))
        {
            foundLine = lineNumber;
            break;
        }
    }

    fclose(file);

    if (foundLine > 0)
    {
        printf("Третя кома знайдена:\nРядок: %d, Позиція: %d\n", foundLine, charPosition);
    }
    else
    {
        printf("У файлі немає третьої коми.\n");
    }
}
#ifndef UNIT_TESTING
int main()
{
    char filename[MAX_LINE_LENGTH];

    printf("Введіть назву текстового файлу (з повним шляхом, якщо файл не в поточній директорії): ");
    scanf("%s", filename);

    ProcessFile(filename);

    return 0;
}
#endif