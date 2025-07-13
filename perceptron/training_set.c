#include "training_set.h"

void free_training_set(TrainingSet* ts) {
    for (size_t i = 0; i < ts->size; i++) {
        free(ts->input[i]);
    }

    for (size_t i = 0; i < ts->n_labels; i++) {
        free(ts->labels[i]);
    }

    free(ts->input);
    free(ts->labels);
}


void print_training_set(TrainingSet* ts) {
    for (size_t i = 0; i < ts->size; i++) {
        for (size_t j = 0; j < ts->n_features; j++) {
            printf("%.2f\t| ", ts->input[i][j]);
        }

        for (size_t j = 0; j < ts->n_labels; j++) {
            printf("%d\t| ", ts->labels[j][i]);
        }

        putchar('\n');
    }
}

