#include "tlu_neuron.h"


void init_tlu(TluNeuron* neuron) {
    neuron->weight = NULL;
    neuron->bias = 0;
    neuron->n_features = 0;
}


void train_tlu(TluNeuron* neuron, TrainingSet* ts) {
    double** input = ts->input;
    bool* labels = ts->labels;
    size_t ts_features = ts->features;
    size_t ts_size = ts->size;

    neuron->n_features = ts_features;
    neuron->weight = (double *) malloc (sizeof(double) * neuron->n_features);

    // for each input
    for(size_t i = 0; i < ts_size; i++) {

        double y = predict_tlu(neuron, input[i]);

        // adjust weights for each feature
        for (size_t j = 0; j < ts_features; j++) {
            neuron->weight[j] = neuron->weight[j] + LEARNING_RATE * (labels[i] - y) * input[i][j];
        }

        // adjust bias
        neuron->bias = neuron->bias + LEARNING_RATE * (labels[i] - y);
    }

}


bool predict_tlu(TluNeuron* neuron, double* input) {
    double result = 0;
    for (size_t i = 0; i < neuron->n_features; i++) {
        result += neuron->weight[i] * input[i];
    }
    result += neuron->bias;

    return result >= 0;
}


void print_tlu(TluNeuron* neuron) {
    printf("TluNeuron:\n\tweights: w1: %f\tw2: %f\n\tbias: %f\n", neuron->weight[0], neuron->weight[1], neuron->bias);
}


void free_neuron(TluNeuron* neuron) {
    free(neuron->weight);
}
