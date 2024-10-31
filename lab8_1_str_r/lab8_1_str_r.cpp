#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int CountRecursive(const char *str, int index = 0, int commaCount = 0)
{
    if (str[index] == '\0')
        return -1;
    if (str[index] == ',')
        commaCount++;
    if (commaCount == 3)
        return index;
    return CountRecursive(str, index + 1, commaCount);
}

string ChangeRecursive(const char *str, int index = 0)
{
    if (str[index] == '\0')
        return "";

    if (str[index] == ',')
        return "**" + ChangeRecursive(str, index + 1);
    else
        return str[index] + ChangeRecursive(str, index + 1);
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

    string dest = ChangeRecursive(str);

    cout << "Original string          : " << str << endl;
    cout << "Modified string (result) : " << dest << endl;

    return 0;
}
