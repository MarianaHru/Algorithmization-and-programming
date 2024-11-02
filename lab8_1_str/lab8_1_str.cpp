#include <string>
#include <iostream>

using namespace std;

int CountCommas(const string &str)
{
    size_t pos = 0;
    int commaCount = 0;

    while (commaCount < 3)
    {
        pos = str.find(',', pos);
        if (pos == string::npos)
        {
            return -1;
        }
        commaCount++;
        if (commaCount == 3)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

string ReplaceCommas(string &str)
{
    size_t pos = 0;
    while (pos < str.length())
    {
        pos = str.find(",", pos);
        if (pos == string::npos)
        {
            break;
        }
        str.replace(pos, 1, "**");
        pos += 2;
    }
    return str;
}

int main()
{
    string str;
    cout << "Enter a string:" << endl;
    getline(cin, str);

    int commaPos = CountCommas(str);
    if (commaPos != -1)
    {
        cout << "Position of 3rd comma: " << commaPos << endl;
    }
    else
    {
        cout << "There is no 3rd comma in the string." << endl;
    }

    string modifiedStr = ReplaceCommas(str);

    cout << "Original string          : " << str << endl;
    cout << "Modified string (result) : " << modifiedStr << endl;

    return 0;
}