#include "mat_utils.h"


void mat_init(Matrix* m, size_t r, size_t c) {
    m->r = r;
    m->c = c;
    m->items = (double**) malloc(sizeof(double) * r);
    for (size_t i = 0; i < r; i++) {
        m->items[i] = (double*) calloc(c, sizeof(double));
    }
}

Matrix* matmul(Matrix* a, Matrix* b) {
    assert(a->c == b->r); 

    Matrix* c = (Matrix*) malloc(sizeof(Matrix));
    mat_init(c, a->r, b->c);

    for (size_t i = 0; i < a->r; i++) {
        for(size_t k = 0; k < a->c; k++) {
            for (size_t j = 0; j < b->c; j++) {
                c->items[i][j] += a->items[i][k] * b->items[k][j];
            }
        }
    }

    return c;
}


void matfree(Matrix* m) {
    for (size_t i = 0; i < m->r; i++) {
        free(m->items[i]);
    }
    free(m->items);
}


void matprint(Matrix* m) {
    for (size_t i = 0; i < m->r; i++) {
        for(size_t j = 0; j < m->c; j++) {
            printf("%f ", m->items[i][j]);
        }
        putchar('\n');
    }
}
