#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y; // координати точки
    double R;    // радіус

    cout << "Введіть координати точки (x, y): " << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    cout << "Введіть радіус R: ";
    cin >> R;

    // Перевірка, чи знаходиться точка в квадраті
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
    cin.get();

    return 0;
}