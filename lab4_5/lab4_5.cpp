#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, xp, xk, dx, R, y;
    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(5) << "x" << "    |"
         << setw(7) << "y" << "        |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if ((x >= -R && x <= R && y >= -R && y <= R) &&
            ((y - R) * (y - R)) >= R * R - (x + R) * (x + R) &&
            ((y + R) * (y - R)) >= R * R - (x - R) * (x - R))

        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }

        cout << "|" << setw(7) << setprecision(2) << x
             << "   |" << setw(10) << setprecision(3) << y
             << "   |" << endl;
        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}