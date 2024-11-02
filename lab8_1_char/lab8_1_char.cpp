#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int FindThirdCommaIndex(char s[])
{
    int count = 0;
    char *pos = s;

    while ((pos = strchr(pos, ',')) != nullptr)
    {
        count++;
        if (count == 3)
        {
            return pos - s;
        }
        pos++;
    }
    return -1;
}

void ReplaceCommas(char s[])
{
    // char temp[201] = "";
    char *result = new char[strlen(s) * 2 + 1];
    char *pos = s;
    char *commaPos;

    while ((commaPos = strchr(pos, ',')) != nullptr)
    {
        strncat(result, pos, commaPos - pos);
        strcat(result, "**");
        pos = commaPos + 1;
    }
    strcat(result, pos);

    strcpy(s, result);
}

int main()
{
    char str[101];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 100);

    int thirdCommaIndex = FindThirdCommaIndex(str);
    if (thirdCommaIndex != -1)
    {
        cout << "Індекс третьої коми: " << thirdCommaIndex << endl;
    }
    else
    {
        cout << "У рядку менше трьох ком." << endl;
    }

    ReplaceCommas(str);
    cout << "Модифікований рядок: " << str << endl;

    return 0;
}
