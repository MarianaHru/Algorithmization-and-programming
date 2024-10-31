// #include <iostream>
// #include <string>

// using namespace std;

// size_t MinLength(const string s)
// {
//     bool openBracket = false;
//     for(int i=0; i <= strlen(s); i++ ){
//             if(s[i]=='(')
//                 openBracket = true;
//             if(openBracket == true){

//             }

//         if
//     }

// }
// int main()
// {
//     string str;
//     cout << "Enter string:" << endl;
//     getline(cin, str);
//     cout << "Length of min groups of digits: " << MinLength(str) << endl;
//     return 0;
// }

#include <iostream>
#include <string>
#include "lab8_2.h"

using namespace std;

string RemoveBrackets(const string &s)
{
    string result;
    int bracketDepth = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (bracketDepth > 0)
            {
                cout << "Error: Nested brackets detected!" << endl;
                return "";
            }
            bracketDepth++;
        }
        else if (s[i] == ')')
        {
            if (bracketDepth == 0)
            {
                cout << "Error: Closing bracket without opening one!" << endl;
                return "";
            }
            bracketDepth--;
        }
        else if (bracketDepth == 0)
        {
            result += s[i];
        }
    }

    if (bracketDepth != 0)
    {
        cout << "Error: Unmatched opening bracket!" << endl;
        return "";
    }

    return result;
}

#ifndef UNIT_TESTING

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string modifiedStr = RemoveBrackets(str);
    if (!modifiedStr.empty())
    {
        cout << "Modified string: " << modifiedStr << endl;
    }

    return 0;
}

#endif
