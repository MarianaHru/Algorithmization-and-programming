#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int l = 1, N, i;
    double S;

    cout << "N = ";
    cin >> N;
    S = 0;
    i = l;
    while (i <= N)
    {
        S += 1.0 / i + sqrt(1 + (sin(i) * sin(i)));
        i++;
    }
    cout << S << endl;
    S = 0;
    i = l;
    do
    {
        S += 1.0 / i + sqrt(1 + (sin(i) * sin(i)));
        i++;
    } while (i <= N);
    cout << S << endl;
    S = 0;
    for (i = l; i <= N; i++)
    {
        S += 1.0 / i + sqrt(1 + (sin(i) * sin(i)));
    }
    cout << S << endl;
    S = 0;
    for (i = N; i >= l; i--)
    {
        S += 1.0 / i + sqrt(1 + (sin(i) * sin(i)));
    }
    cout << S << endl;
    return 0;
}
