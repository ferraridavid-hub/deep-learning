#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

#include "perceptron.h"
#include "training_set.h"


#define TRAINING_SET_SIZE 100000000


void init_random_training_set(TrainingSet* ts, int seed) {
   srand(seed); 
   ts->input = (double**)malloc(sizeof(double*) * TRAINING_SET_SIZE);
   for (size_t i = 0; i < TRAINING_SET_SIZE; i++) {
    ts->input[i] = (double*)malloc(sizeof(double) * 2);
   }

   ts->labels = (bool**)malloc(sizeof(bool*) * 2);
   for (size_t i = 0; i < 2; i++) {
    ts->labels[i] = (bool*) malloc(sizeof(bool) * TRAINING_SET_SIZE);
   }

   ts->n_features = 2;
   ts->n_labels = 2;
   ts->size = TRAINING_SET_SIZE;

   for (size_t i = 0; i < TRAINING_SET_SIZE; i++) {
       double r = (double)rand() / RAND_MAX * 20;

       double theta = (double)rand() / RAND_MAX * 2 * M_PI;

       //ts->input[i][0] = r * sin(theta);
       //ts->input[i][1] = r * cos(theta);
       ts->input[i][0] = r;
       ts->input[i][1] = theta;

       ts->labels[0][i] = (r < 5); 
       ts->labels[1][i] = (r >= 10);
   }
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: perceptron grade\n");
        exit(1);
    }

    TrainingSet training_set;
    init_random_training_set(&training_set, 42);
    
    // print_training_set(&training_set);

    Perceptron perceptron;
    init_perceptron(&perceptron);

    train_perceptron(&perceptron, &training_set);

    free_training_set(&training_set);

    bool** prevs = (bool**) malloc (sizeof(bool*) * (argc - 1) / 2);
    int k = 0;

    while (argc > 1) {

        double x = atof(*(++argv));
        double y = atof(*(++argv));
        double input[] = {x, y};
        bool* passed = predict_perceptron(&perceptron, input);
        prevs[k++] = passed;

        argc -= 2;
    }

    printf("Previsions (k=%d):\n", k);
    printf("==================================\n");
    for (int i = 0; i < k; i++) {
        printf("label1: %d\tlabel2: %d", prevs[i][0], prevs[i][1]);
        putchar('\n');
        free(prevs[i]);
    }

    free(prevs);

    free_perceptron(&perceptron);

    return EXIT_SUCCESS;

}
