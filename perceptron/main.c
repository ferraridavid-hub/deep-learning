#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

#include "perceptron.h"
#include "training_set.h"


#define TRAINING_SET_SIZE 10000000


void init_random_training_set(TrainingSet* ts, size_t size, int seed) {
   srand(seed); 
   ts->input = (double**)malloc(sizeof(double*) * size);
   for (size_t i = 0; i < size; i++) {
    ts->input[i] = (double*)malloc(sizeof(double));
   }

   ts->labels = (bool*)malloc(sizeof(bool) * size);

   ts->features = 1;

   ts->size = size;

   for (size_t i = 0; i < size; i++) {
       ts->input[i][0] = (double) rand() / RAND_MAX * 30.0;
       ts->labels[i] = ts->input[i][0] >= 18.0;
   }
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
        double input[] = {grade};
        bool passed = predict_perceptron(&perceptron, input);
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

    free_perceptron(&perceptron);

    return EXIT_SUCCESS;

}
