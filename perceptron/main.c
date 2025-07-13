#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

#include "tlu_neuron.h"
#include "training_set.h"


#define TRAINING_SET_SIZE 10000000


void init_random_training_set(TrainingSet* ts, int seed) {
   srand(seed); 
   ts->input = (double**)malloc(sizeof(double*) * TRAINING_SET_SIZE);
   for (size_t i = 0; i < TRAINING_SET_SIZE; i++) {
    ts->input[i] = (double*)malloc(sizeof(double) * 2);
   }

   ts->labels = (bool*)malloc(sizeof(bool) * TRAINING_SET_SIZE);

   ts->features = 2;

   ts->size = TRAINING_SET_SIZE;

   for (size_t i = 0; i < TRAINING_SET_SIZE; i++) {
       double r = (double)rand() / RAND_MAX;
       if (r < 0.5) {
           r *= 10;
       } else {
           r = 10 + 5 * r;
       }

       double theta = (double)rand() / RAND_MAX * 2 * M_PI;

       //ts->input[i][0] = r * sin(theta);
       //ts->input[i][1] = r * cos(theta);
       ts->input[i][0] = r;
       ts->input[i][1] = theta;

       ts->labels[i] = r <= 10; 
   }
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: perceptron grade\n");
        exit(1);
    }

    TrainingSet training_set;
    init_random_training_set(&training_set, 42);
    
    print_training_set(&training_set);


    TluNeuron perceptron;
    init_tlu(&perceptron);

    train_tlu(&perceptron, &training_set);

    free_training_set(&training_set);

    print_tlu(&perceptron);

    bool* prevs = (bool*) malloc (sizeof(bool) * (argc - 1));
    int k = 0;

    while (--argc > 0) {

        double x = atof(*(++argv));
        double y = atof(*(++argv));
        double input[] = {x, y};
        bool passed = predict_tlu(&perceptron, input);
        prevs[k++] = passed;

        argc -= 2;
    }

    for (int i = 0; i < k; i++) {
        printf("%d", prevs[i]);
        if (i != k - 1) {
            putchar(' ');
        }
    }
    putchar('\n');

    free(prevs);

    free_neuron(&perceptron);

    return EXIT_SUCCESS;

}
