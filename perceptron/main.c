#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>


#define LEARNING_RATE .3
#define TRAINING_SET_SIZE 10000000


typedef struct {
    double* input;
    bool* labels;
    size_t size;
} TrainingSet;


typedef struct {
    double weight;
    double bias;
} Perceptron;


void init_random_training_set(TrainingSet* ts, size_t size, int seed) {
   srand(seed); 
   ts->input = (double*)malloc(sizeof(double) * size);
   ts->labels = (bool*)malloc(sizeof(bool) * size);
   ts->size = size;

   for (size_t i = 0; i < size; i++) {
       ts->input[i] = (double) rand() / RAND_MAX * 110.0;
       ts->labels[i] = ts->input[i] >= 66.0;
   }
}

void print_training_set(TrainingSet* ts) {
    printf("Grade\t\t\tPassed\n");
    for (size_t i = 0; i < ts->size; i++) {
        printf("%f\t\t\t%d\n", ts->input[i], ts->labels[i]);
    }
}


void free_training_set(TrainingSet* ts) {
    free(ts->input);
    free(ts->labels);
}


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


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: perceptron grade\n");
        exit(1);
    }

    TrainingSet training_set;
    init_random_training_set(&training_set, TRAINING_SET_SIZE, 42);

    Perceptron perceptron;
    init_perceptron(&perceptron);
    train_perceptron(&perceptron, &training_set);
    free_training_set(&training_set);

    print_perceptron(&perceptron);

    bool* prevs = (bool*) malloc (sizeof(bool) * (argc - 1));
    int k = 0;

    while (--argc > 0) {

        double grade = atof(*(++argv));
        bool passed = predict_perceptron(&perceptron, grade);
        prevs[k++] = passed;
    }

    for (int i = 0; i < k; i++) {
        printf("%d", prevs[i]);
        if (i != k - 1) {
            putchar(' ');
        }
    }

    putchar('\n');

    free(prevs);

    return EXIT_SUCCESS;

}
