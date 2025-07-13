#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdbool.h>
#include <math.h>

#include "training_set.h"

#define LEARNING_RATE .3


typedef struct {
    double weight;
    double bias;
} Perceptron;


void init_perceptron(Perceptron*);
void train_perceptron(Perceptron*, TrainingSet*);
bool predict_perceptron(Perceptron*, double test);
void print_perceptron(Perceptron*);


#endif
