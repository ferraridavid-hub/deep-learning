#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat_utils.h"


int main() {
    Matrix m;
    mat_init_random(&m, 200, 100);
    Matrix n;
    mat_init_random(&n, 100, 100);

    Matrix* c = matmul(&m, &n);
    printf("mean: %f\n", mean(c));
    printf("std: %f\n", std(c));

    for (int i = 0; i < 1500; i++) {
        Matrix* t = c;
        c = matmul(c, &n);
        matfree(t);
        free(t);
        printf("mean: %f\n", mean(c));
        printf("std: %f\n", std(c));
    }

    //matprint(c);

    matfree(&m);
    matfree(&n);
    matfree(c);
    free(c);

}
