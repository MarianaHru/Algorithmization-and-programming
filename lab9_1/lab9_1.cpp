
#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.cpp"
#include "sum.cpp"
#include "var.cpp"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

#ifndef UNIT_TESTING

int main()
{

     cout << "x_p = ";
     cin >> x_p;
     cout << "x_k = ";
     cin >> x_k;
     cout << "dx = ";
     cin >> dx;
     cout << "e = ";
     cin >> e;

     cout << endl;
     cout << fixed;

     cout << "-----------------------------------------" << endl;
     cout << "|" << setw(5) << "x" << " .  |"
          << setw(10) << "exp(x) " << " |"
          << setw(7) << "S " << "    |"
          << setw(5) << "n " << " |"
          << endl;
     cout << "-----------------------------------------" << endl;
     x = x_p;
     while (x <= x_k)
     {
          sum();
          cout << "|" << setw(7) << setprecision(2) << x << " |"
               << setw(10) << exp(x) << " |"
               << setw(10) << setprecision(5) << s << " |"
               << setw(5) << n << " |"
               << endl;
          x += dx;
     }
     cin.get();
     cout << "-----------------------------------------" << endl;
     return 0;
}

#endif
