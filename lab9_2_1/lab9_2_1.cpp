#include <iostream>
#include <cmath>

#define z 2

#define ABS(x) ((x) < 0 ? -(x) : (x)) // макрос для обчислення модуля
#define SQR(x) ((x) * (x))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define PRINTI(w)           \
    puts("control output"); \
    printf(#w "=%d\n", w)
#define PRINTR(w)     \
    puts("result :"); \
    printf(#w "=%f\n", (float)w)

#ifndef UNIT_TESTING

int main()
{

    puts("Lab 13.2. Using macros and preprocessing directive");

    int x, y;
    float w;
    char ch;

    do
    {
        puts("Input integer values for x and y:");
        std::cin >> x >> y;

#if 1 < z && z < 3
        w = MAX(ABS(x) + ABS(y) + ABS(z), SQR(z));
#elif z >= 3
        w = MIN(2 * x + y, SQR(y - z));
#else
        puts("Invalid range for z. Please ensure z is either within 1 < z < 3 or z >= 3.");
        w = 0;
#endif

        PRINTR(w);

        puts("Repeat? y/n ");
        std::cin >> ch;
    } while (ch == 'y');

    return 0;
}

#endif
