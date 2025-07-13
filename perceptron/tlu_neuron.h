#ifndef TLU_NEURON
#define TLU_NEURON_H

#include<stdio.h>
#include <stdbool.h>
#include <math.h>

#include "training_set.h"

#define LEARNING_RATE .3


typedef struct {
    double* weight;
    double bias;
    size_t n_features;
} TluNeuron;


void init_tlu(TluNeuron*);
void train_tlu(TluNeuron*, size_t, size_t, double ** input, bool* labels);
bool predict_tlu(TluNeuron*, double* input);
void print_tlu(TluNeuron*);
void free_neuron(TluNeuron*);


#endif
