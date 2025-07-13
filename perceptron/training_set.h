#ifndef TRAINING_SET_H
#define TRAINING_SET_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    double** input;
    bool** labels;
    size_t n_features;
    size_t n_labels;
    size_t size;
} TrainingSet;


void print_training_set(TrainingSet* ts);
void free_training_set(TrainingSet* ts);


#endif
