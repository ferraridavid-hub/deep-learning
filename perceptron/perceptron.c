#include "perceptron.h"


void init_perceptron(Perceptron* perceptron) {
    perceptron->weight = NULL;
    perceptron->bias = 0;
    perceptron->n_features = 0;
}


void train_perceptron(Perceptron* perceptron, TrainingSet* ts) {
    double** input = ts->input;
    bool* labels = ts->labels;
    size_t ts_features = ts->features;
    size_t ts_size = ts->size;

    perceptron->n_features = ts_features;
    perceptron->weight = (double *) malloc (sizeof(double) * perceptron->n_features);

    // for each input
    for(size_t i = 0; i < ts_size; i++) {

        double y = predict_perceptron(perceptron, input[i]);

        // adjust weights for each feature
        for (size_t j = 0; j < ts_features; j++) {
            perceptron->weight[j] = perceptron->weight[j] + LEARNING_RATE * (labels[i] - y) * input[i][j];
        }

        // adjust bias
        perceptron->bias = perceptron->bias + LEARNING_RATE * (labels[i] - y);
    }

}


bool predict_perceptron(Perceptron* perceptron, double* input) {
    double result = 0;
    for (size_t i = 0; i < perceptron->n_features; i++) {
        result += perceptron->weight[i] * input[i];
    }
    result += perceptron->bias;

    return result >= 0;
}


void print_perceptron(Perceptron* perceptron) {
    printf("Perceptron:\n\tweight: %f\n\tbias: %f\n\tthreshold: %f\n", perceptron->weight[0], perceptron->bias, -perceptron->bias / perceptron->weight[0]);
}


void free_perceptron(Perceptron* p) {
    free(p->weight);
}
