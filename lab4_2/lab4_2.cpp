#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, xp, xk, dx, A, B, y;
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
        if (x < 0)
            B = 1 + 4 * (x * x);
        else if (x > 2)
            B = 5 * sin((x * x) + 1);
        else
            B = (exp(x) + abs(x) * exp(x) + abs(x));
        y = A + B;

        cout << "|" << setw(7) << setprecision(2) << x
             << "   |" << setw(10) << setprecision(3) << y
             << "    |" << endl;
        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}
