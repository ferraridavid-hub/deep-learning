#include "mat_utils.h"


void mat_init_zeros(Matrix* m, size_t r, size_t c) {
    m->r = r;
    m->c = c;
    m->items = (double*) calloc(r * c, sizeof(double));
}


void mat_init_random(Matrix* m, size_t r, size_t c) {
    m->r = r;
    m->c = c;
    m->items = (double*) malloc(r * c * sizeof(double));
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            m->items[i * r + j] = (double) rand() / RAND_MAX;
        }
    }
}


Matrix* matmul(Matrix* a, Matrix* b) {
    assert(a->c == b->r); 

    Matrix* c = (Matrix*) malloc(sizeof(Matrix));
    mat_init_zeros(c, a->r, b->c);

    for (size_t i = 0; i < a->r; i++) {
        for(size_t k = 0; k < a->c; k++) {
            for (size_t j = 0; j < b->c; j++) {
                c->items[i * a->r + j] += a->items[i * a->r + k] * b->items[k * b->r + j];
            }
        }
    }

    return c;
}


void matfree(Matrix* m) {
    free(m->items);
}


void matprint(Matrix* m) {
    for (size_t i = 0; i < m->r; i++) {
        for(size_t j = 0; j < m->c; j++) {
            printf("%f ", m->items[i * m->r + j]);
        }
        putchar('\n');
    }
}
