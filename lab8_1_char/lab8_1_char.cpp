#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int CountRecursive(char *str, int index = 0, int commaCount = 0)
{
    if (str[index] == '\0')
        return -1;
    if (str[index] == ',')
        commaCount++;
    if (commaCount == 3)
        return index;
    return CountRecursive(str, index + 1, commaCount);
}

void ChangeRecursive(char *src, char *dest, int srcIndex = 0, int destIndex = 0)
{
    if (src[srcIndex] == '\0')
    {
        dest[destIndex] = '\0';
        return;
    }

    if (src[srcIndex] == ',')
    {
        dest[destIndex] = '*';
        dest[destIndex + 1] = '*';
        ChangeRecursive(src, dest, srcIndex + 1, destIndex + 2);
    }
    else
    {
        dest[destIndex] = src[srcIndex];
        ChangeRecursive(src, dest, srcIndex + 1, destIndex + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int commaPos = CountRecursive(str);
    if (commaPos != -1)
        cout << "Position of 3rd comma: " << commaPos << endl;
    else
        cout << "There is no 3rd comma in the string." << endl;

    char *dest = new char[201];
    ChangeRecursive(str, dest);

    cout << "Original string          : " << str << endl;
    cout << "Modified string (result) : " << dest << endl;

    delete[] dest;
    return 0;
}
