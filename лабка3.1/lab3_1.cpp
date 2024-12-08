#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x; // вхідний параметр
    double y; // результат обчислення виразу
    double A; // проміжний результат - функціонально стала частина виразу
    double B; // проміжний результат - функціонально змінна частина виразу

    cout << "x = ";
    cin >> x;

    A = 2.0 / x + abs(x);

    // спосіб 1: розгалуження в скороченій формі
    if (x < 0)
        B = 1 + 4 * (x * x);
    if (0 <= x && x <= 2)
        B = ((exp(x) + abs(x)) * (exp(x) + abs(x)));
    if (x > 2)
        B = 5 * sin((x * x) + 1);
    y = A + B;
    cout << endl;
    cout << "1) y = " << y << endl;
    // спосіб 2: розгалуження в повній формі
    if (x < 0)
        B = 1 + 4 * (x * x);
    else if (x > 2)
        B = 5 * sin((x * x) + 1);
    else
        B = ((exp(x) + abs(x)) * (exp(x) + abs(x)));
    y = A + B;
    cout << "2) y = " << y << endl;
    cin.get();
    return 0;
}