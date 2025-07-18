#ifndef MAT_UTILS_H
#define MAT_UTILS_H

#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct {
    size_t r;
    size_t c;
    double * items;
} Matrix;

void mat_init_zeros(Matrix* m, size_t r, size_t c);
void mat_init_random(Matrix *m, size_t r, size_t c);
Matrix* matmul(Matrix*, Matrix*);
void matfree(Matrix* m);
void matprint(Matrix* m);

double mean(Matrix* m);
double std(Matrix* m);

#endif
