#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "lab8_1_str.h"

using namespace std;

int Count(const char *str)
{
    int commaCount = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ',')
            commaCount++;
        if (commaCount == 3)
            return i;
    }
    return -1;
}

string Change(const char *str)
{
    string result;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ',')
        {
            result += "**";
        }
        else
        {
            result += str[i];
        }
    }
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

    string dest = Change(str);

    cout << "Original string          : " << str << endl;
    cout << "Modified string (result) : " << dest << endl;

    return 0;
}
#endif