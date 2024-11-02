

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char *s)
{
    int commaCount = 0;
    char *p = s;

    while (*p != '\0')
    {
        if (*p == ',')
        {
            commaCount++;
        }
        if (commaCount == 3)
        {
            return p - s;
        }
        p++;
    }

    return -1;
}

char *Change(char *s)
{
    size_t len = strlen(s);
    char *t = new char[len * 2 + 1];
    char *p = s;
    char *q = t;

    while (*p != '\0')
    {
        if (*p == ',')
        {
            *q++ = '*';
            *q++ = '*';
        }
        else
        {
            *q++ = *p;
        }
        p++;
    }

    *q = '\0';
    strcpy(s, t);
    return t;
}

#ifndef UNIT_TESTING

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int commaPos = Count(str);
    if (commaPos != -1)
    {
        cout << "Position of 3rd comma: " << commaPos << endl;
    }
    else
    {
        cout << "There is no 3rd comma in the string." << endl;
    }

    char *dest = Change(str);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}

#endif