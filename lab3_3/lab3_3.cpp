#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x; // вхідний аргумент
    double R; // вхідний параметр
    double y; // результат обчислення виразу
    const double Pi = 2 * acos(0.0);

    cout << "R=";
    cin >> R;
    cout << "x=";
    cin >> x;
    // розгалуження в повній формі
    if (x < -7 - R)
        y = R;
    else if (-7 - R <= x && -7 + R > x)
        y = sqrt((R * R) - (x + 7) * (x + 7));
    else if (-7 + R <= x && -4 > x)
        y = R;
    else if (-4 <= x && 0 > x)
        y = -(x * R) / 4.0;
    else if (0 < x && Pi > x)
        y = sin(x);
    else if (Pi <= x)
        y = x - Pi;
    cout << endl;
    cout << "y = " << y << endl;
    cin.get();
    return 0;
}