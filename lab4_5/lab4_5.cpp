#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
    double x, y, R;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        cout << "R = ";
        cin >> R;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        if ((x >= -R && x <= R && y >= -R && y <= R) || ((x + R) * (x + R) + (y - R) * (y - R) <= R * R) || (x - R) * (x - R) + (y + R) * (y + R) <= R * R)

            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    cout << endl
         << fixed;

    cout << "------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << "  |"
         << setw(10) << "y" << " |"
         << setw(10) << "R" << " |"
         << setw(10) << "yes/no" << " |" << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        R = rand() * 20.0 / RAND_MAX;
        x = -2 * R + rand() * (2 * R - (-2 * R)) / RAND_MAX;
        y = -2 * R + rand() * (2 * R - (-2 * R)) / RAND_MAX;
        if ((x >= -R && x <= R && y >= -R && y <= R) || ((x + R) * (x + R) + (y - R) * (y - R) <= R * R) || (x - R) * (x - R) + (y + R) * (y + R) <= R * R)

            cout << "|" << setw(10) << x << "|"
                 << setw(10) << y << " |"
                 << setw(10) << R << " |"
                 << setw(10) << "yes" << " |" << endl;
        else
            cout << "|" << setw(10) << x << "|"
                 << setw(10) << y << " |"
                 << setw(10) << R << " |"
                 << setw(10) << "no" << " |" << endl;
    }
    cout << "------------------------------------------------" << endl;
    return 0;
}