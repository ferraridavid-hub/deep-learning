#include "training_set.h"

void free_training_set(TrainingSet* ts) {
    free(ts->input);
    free(ts->labels);
}

