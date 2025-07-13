#ifndef TRAINING_SET_H
#define TRAINING_SET_H

#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    double* input;
    bool* labels;
    size_t size;
} TrainingSet;


void free_training_set(TrainingSet* ts);


#endif
