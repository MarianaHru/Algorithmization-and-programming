// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>

// using namespace std;

// int Count(char *str)
// {
//     int k = 0;
//     for (int i = 0; i <= strlen(str); i++)
//     {
//         if (str[i] == ',')
//             k++;
//         if (k == 3)
//             return i;
//     }
// }

// char *Change(char *str)
// {
//     size_t len = strlen(str);
//     for (int i = 0; i <= strlen(str); i++)
//     {
//         if (str[i] == ',')
//             str[i] = '**';
//     }
// }
// int main()
// {
//     char str[101];
//     cout << "Enter string:" << endl;
//     cin.getline(str, 100);
//     cout << "номер 3 коми: " << Count(str) << endl;
//     char *dest = new char[151];
//     dest = Change(str);
//     cout << "Modified string (param) : " << str << endl;
//     cout << "Modified string (result): " << dest << endl;
//     return 0;
// }

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "lab8_1_it.h"

using namespace std;

int Count(const char *str)
{
    int commaCount = 0;
    // for (int i = 0; i < strlen(str); i++)
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
            commaCount++;
        if (commaCount == 3)
            return i;
    }
    return -1;
}

char *Change(const char *str)
{
    size_t len = strlen(str);

    char *result = new char[len * 2 + 1];
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ',')
        {
            result[j++] = '*';
            result[j++] = '*';
        }
        else
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}

#ifndef UNIT_TESTING

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int commaPos = Count(str);
    if (commaPos != -1)
        cout << "Position of 3rd comma: " << commaPos << endl;
    else
        cout << "There is no 3rd comma in the string." << endl;

    char *dest = Change(str);

    cout << "Original string          : " << str << endl;
    cout << "Modified string (result) : " << dest << endl;

    delete[] dest;
    return 0;
}

#endif
