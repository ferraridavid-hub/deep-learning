#include "training_set.h"

void free_training_set(TrainingSet* ts) {
    for (size_t i = 0; i < ts->size; i++) {
        free(ts->input[i]);
    }
    free(ts->input);
    free(ts->labels);
}


void print_training_set(TrainingSet* ts) {
    for (size_t i = 0; i < ts->size; i++) {
        for (size_t j = 0; j < ts->features; j++) {
            printf("%.2f\t| ", ts->input[i][j]);
        }
        printf("%b\n", ts->labels[i]);
    }
}

