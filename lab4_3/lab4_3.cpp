#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, xp, xk, dx, a, b, c, F;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "-----------------------" << endl;
    cout << "|" << setw(5) << "x" << "      |"
         << setw(7) << "F" << "  |" << endl;
    cout << "-----------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (a < 0 && c != 0)
            F = a * (x * x) + b * x + c;
        else if (a > 0 && c == 0)
            F = (-a) / (x - b);
        else
            F = a * (x + c);

        cout << "|" << setw(10) << setprecision(1) << x
             << " |" << setw(8) << setprecision(1) << F
             << " |" << endl;
        x += dx;
    }
    cout << "-----------------------" << endl;

    return 0;
}