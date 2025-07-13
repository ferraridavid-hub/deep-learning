#include "training_set.h"

void free_training_set(TrainingSet* ts) {
    for (size_t i = 0; i < ts->size; i++) {
        free(ts->input[i]);
    }
    free(ts->input);
    free(ts->labels);
}

