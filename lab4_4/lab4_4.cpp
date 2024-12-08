#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, xp, xk, dx, R, y;

    const double Pi = 3.141592653589793;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "--------------------------" << endl;
    cout << "|" << setw(6) << "x" << "    |"
         << setw(5) << "y" << "        |" << endl;
    cout << "--------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x < -7 - R)
            y = R;
        else if (-7 - R <= x && -7 + R > x)
            y = sqrt((R * R) - (x + 7));
        else if (-7 + R <= x && -4 > x)
            y = R;
        else if (-4 <= x && 0 > x)
            y = -(x * R) / 4.0;
        else if (0 < x && Pi > x)
            y = sin(x);
        else if (Pi <= x)
            y = 1;

        cout << "|" << setw(7) << setprecision(2) << x
             << "   |" << setw(10) << setprecision(3) << y
             << "   |" << endl;
        x += dx;
    }
    cout << "--------------------------" << endl;

    return 0;
}
