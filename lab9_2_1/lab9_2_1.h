#pragma once
#include <cmath>


#define ABS(x) ((x) < 0 ? -(x) : (x))       
#define SQR(x) ((x) * (x))                  
#define MAX(x, y) (((x) > (y)) ? (x) : (y)) 
#define MIN(x, y) (((x) < (y)) ? (x) : (y)) 


inline float calculateW(int x, int y, int z) {
    float w;
    if (1 < z && z < 3) {
        w = MAX(ABS(x) + ABS(y) + ABS(z), SQR(z));
    } else if (z >= 3) {
        w = MIN(2 * x + y, SQR(y - z));
    } else {
        w = 0; 
    }
    return w;
}

