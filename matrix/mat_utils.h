#ifndef MAT_UTILS_H
#define MAT_UTILS_H
#include<stddef.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

typedef struct {
    size_t r;
    size_t c;
    double * items;
} Matrix;

void mat_init(Matrix* m, size_t r, size_t c);
Matrix* matmul(Matrix*, Matrix*);
void matfree(Matrix* m);
void matprint(Matrix* m);

#endif
