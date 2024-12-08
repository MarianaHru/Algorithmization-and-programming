#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double h(const double x);

#ifndef UNIT_TESTING

int main()
{
    double gp, gk, z;
    int n;
    cout << "gp = ";
    cin >> gp;
    cout << "gk = ";
    cin >> gk;
    cout << "n =";
    cin >> n;

    cout << fixed;
    cout << "----------------------" << endl;
    cout << "|" << setw(5) << "q" << "   |"
         << setw(10) << "z" << " |" << endl;
    cout << "----------------------" << endl;
    double dg = (gk - gp) / n;
    double q = gp;
    while (q <= gk)
    {
        z = h(q + 1) + h((q * q) + 1) + pow(h(q * q), 2);
        cout << "|" << setw(7) << setprecision(2) << q << " |"
             << setw(10) << setprecision(5) << z << " |" << endl;
        cout << "----------------------" << endl;
        q += dg;
    }
    return 0;
}

#endif

double h(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + 1) / (cos(x) * cos(x) + 1);
    else
    {
        double S = 0.0;
        int i = 0;
        double a = 1;
        S = a;
        do
        {
            i++;
            // double R = pow(x, 2 * i) / ((2 * i - 2) * (2 * i - 1) * 2 * i);
            double R = pow(x, 2 * i) / ((2 * i + 1) * (2 * i));
            S += R;
        } while (i < 6);
        return (1 / cos(x)) * S;
    }
}
