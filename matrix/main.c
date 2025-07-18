#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "mat_utils.h"
#include <sys/time.h>


int main() {
    Matrix m;
    mat_init(&m, 28 * 28, 28 * 28);
    m.items[0] = 1;
    m.items[1] = 2;
    m.items[2] = 3;
    m.items[3] = 4;
    //matprint(&m);

    struct timeval start;
    gettimeofday(&start, NULL);
    Matrix *c = matmul(&m, &m);
    struct timeval end;
    gettimeofday(&end, NULL);

    uint64_t us_start = start.tv_usec + start.tv_sec * 1000000;
    uint64_t us_end = end.tv_usec + end.tv_sec * 1000000;

    //matprint(c);

    printf("difftime: %zu\n", us_end - us_start);


    matfree(&m);
    matfree(c);

    free(c);

}
