#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "tlu_neuron.h"
#include "training_set.h"
#include "stdlib.h"

typedef struct {
    TluNeuron * output_layer;
    size_t labels;
} Perceptron;


void init_perceptron(Perceptron *);
void train_perceptron(Perceptron *, TrainingSet *);
bool* predict_perceptron(Perceptron*, double input[]);
void print_perceptron(Perceptron*);
void free_perceptron(Perceptron*);


#endif
