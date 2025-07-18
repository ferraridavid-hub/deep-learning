#include "distribution.h"

double gauss() {
    double u = (double) arc4random_uniform(UINT32_MAX) / UINT32_MAX;
    double v = (double) arc4random_uniform(UINT32_MAX) / UINT32_MAX;

    double x = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);

    return x;
}
