#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


#define LEARNING_RATE .5
#define TRAINING_SET_SIZE 10196 * 4


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
       ts->input[i] = (double) rand() / RAND_MAX * 30.0;
       ts->labels[i] = ts->input[i] >= 18.0;
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
        double y = (perceptron->weight * input[i] + perceptron->bias) > 0;        
        perceptron->weight = perceptron->weight + LEARNING_RATE * (labels[i] - y) * input[i];
        perceptron->bias = perceptron->bias + LEARNING_RATE * (labels[i] - y);
    }
}


bool predict_perceptron(Perceptron* perceptron, double grade) {
    return (perceptron->weight * grade + perceptron->bias) > 0;
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: perceptron grade\n");
        exit(1);
    }

    double grade = atof(argv[1]);

    TrainingSet training_set;
    init_random_training_set(&training_set, TRAINING_SET_SIZE, 42);
    //print_training_set(&training_set);

    Perceptron perceptron;
    init_perceptron(&perceptron);
    train_perceptron(&perceptron, &training_set);
    free_training_set(&training_set);

    bool passed = predict_perceptron(&perceptron, grade);

    if (passed) {
        printf("Passed\n");
    } else {
        printf("Not passed\n");
    }    

    return EXIT_SUCCESS;
}
