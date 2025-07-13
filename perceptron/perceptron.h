#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<stdio.h>
#include <stdbool.h>
#include <math.h>

#include "training_set.h"

#define LEARNING_RATE .3


typedef struct {
    double* weight;
    double bias;
    size_t n_features;
} Perceptron;


void init_perceptron(Perceptron*);
void train_perceptron(Perceptron*, TrainingSet*);
bool predict_perceptron(Perceptron*, double* input);
void print_perceptron(Perceptron*);
void free_perceptron(Perceptron*);


#endif
