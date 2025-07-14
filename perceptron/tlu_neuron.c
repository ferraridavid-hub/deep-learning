#include "tlu_neuron.h"


void init_tlu(TluNeuron* neuron) {
    neuron->weight = NULL;
    neuron->bias = 0;
    neuron->n_features = 0;
}


void train_tlu(TluNeuron* neuron, size_t n_features, size_t size, double **input, bool* labels) {
    neuron->n_features = n_features;
    neuron->weight = (double *) calloc (neuron->n_features, sizeof(double));

    printf("ruddy: %.2f\n", neuron->weight[761]);

    // for each input
    for(size_t i = 0; i < size; i++) {

        double y = predict_tlu(neuron, input[i]);

        // adjust weights for each feature
        for (size_t j = 0; j < n_features; j++) {
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
    printf("TluNeuron: \n\t");
    for (size_t i = 0; i < neuron->n_features; i++) {
        printf("\tweights: w[%zu]: %f\n",  i,  neuron->weight[i]);
    }
    printf("\tbias: %f\n", neuron->bias);
}


void free_neuron(TluNeuron* neuron) {
    free(neuron->weight);
}
