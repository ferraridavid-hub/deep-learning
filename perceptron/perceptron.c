#include "perceptron.h"

void init_perceptron(Perceptron* p) {
    p->output_layer = NULL;
    p->labels = 0;
}

void train_perceptron(Perceptron* p, TrainingSet* ts) {
    p->labels = ts->n_labels;
    p->output_layer = (TluNeuron *) malloc(sizeof(TluNeuron) * p->labels);

    for (size_t i = 0; i < p->labels; i++) {
        train_tlu(
            p->output_layer + i,
            ts->n_features,
            ts->size,
            ts->input,
            ts->labels[i]);
    } 
}


bool * predict_perceptron(Perceptron *p, double* input) {
    bool * prediction = (bool *) malloc(sizeof(bool) * p->labels);
    for (size_t i = 0; i < p->labels; i++) {
        prediction[i] = predict_tlu(p->output_layer + i, input);
    }

    return prediction;
}


void print_perceptron(Perceptron *p) {
    for (size_t i = 0; i < p->labels; i++) {
        print_tlu(p->output_layer + i);
    }
}


void free_perceptron(Perceptron* p) {
    for (size_t i = 0; i < p->labels; i++) {
        free_neuron(p->output_layer + i);
    }
    free(p->output_layer);
}