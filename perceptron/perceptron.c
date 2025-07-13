#include "perceptron.h"


void init_perceptron(Perceptron* perceptron) {
    perceptron->weight = 0;
    perceptron->bias = 0;
}


void train_perceptron(Perceptron* perceptron, TrainingSet* ts) {
    double* input = ts->input;
    bool* labels = ts->labels;
    size_t ts_size = ts->size;

    for(size_t i = 0; i < ts_size; i++) {
        double y = (perceptron->weight * input[i] + perceptron->bias) >= 0;        
        perceptron->weight = perceptron->weight + LEARNING_RATE * (labels[i] - y) * input[i];
        perceptron->bias = perceptron->bias + LEARNING_RATE * (labels[i] - y);
    }

    double threshold = round(- perceptron->bias / perceptron->weight);
    perceptron->weight = - perceptron->bias / threshold;

}


bool predict_perceptron(Perceptron* perceptron, double grade) {
    double result = perceptron->weight * grade + perceptron->bias;
    return result >= 0;
}


void print_perceptron(Perceptron* perceptron) {
    printf("Perceptron:\n\tweight: %f\n\tbias: %f\n\tthreshold: %f\n", perceptron->weight, perceptron->bias, -perceptron->bias / perceptron->weight);
}

