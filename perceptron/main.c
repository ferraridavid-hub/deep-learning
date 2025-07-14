#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "perceptron.h"
#include "training_set.h"

#define TRAINING_SET_SIZE 100000000

void init_random_training_set(TrainingSet *ts)
{

    double **input = (double **) malloc(sizeof(double) * 256);
    bool **label = (bool **)malloc(sizeof(bool*));
    label[0] = (bool *) malloc(sizeof(bool) * 256);

    size_t i = 0;
    size_t m_cap = 256;

    FILE *fp = fopen("data/nmist_5.txt", "r");
    char *line = NULL;
    size_t n = 0;

    while (getline(&line, &n, fp) != -1)
    {

        input[i] = (double *)malloc(sizeof(double) * 256);

        size_t k = 0;
        size_t cap = 256;

        char *ptr = line;
        for (;;)
        {
            char *prev = ptr;
            double d = strtod(ptr, &ptr);
            if (prev == ptr)
            {
                if (k > 0)
                {
                    label[0][i] = input[i][--k];
                }
                break;
            }

            input[i][k++] = d;

            if (k == cap)
            {
                cap *= 2;
                input[i] = realloc(input[i], cap * sizeof(double));
            }

        }

        ts->n_features = k;
        ts->n_labels = 1;

        i++;
        
        if (i == m_cap) {
            m_cap *= 2;
            input = realloc(input, m_cap * sizeof(double *));
            label[0] = realloc(label[0], m_cap * sizeof(bool));
        }

        free(line);
        line = NULL;
    }
    free(line);

    ts->input = input;
    ts->labels = label;
    ts->size = i;
}

int main(int argc, char *argv[])
{
     if (argc < 2) {
         fprintf(stderr, "usage: perceptron grade\n");
         exit(1);
     }

     TrainingSet training_set;
     init_random_training_set(&training_set);


    //  print_training_set(&training_set);


    Perceptron perceptron;
    init_perceptron(&perceptron);

    train_perceptron(&perceptron, &training_set);

    free_training_set(&training_set);

    print_perceptron(&perceptron);

     argv++;

    // bool** prevs = (bool**) malloc (sizeof(bool*) * (argc - 1) / 2);
    // int k = 0;

    // while (argc > 1) {

    //     double x = atof(*(++argv));
    //     double y = atof(*(++argv));
    //     double input[] = {x, y};
    //     bool* passed = predict_perceptron(&perceptron, input);
    //     prevs[k++] = passed;

    //     argc -= 2;
    // }

    // printf("Previsions (k=%d):\n", k);
    // printf("==================================\n");
    // for (int i = 0; i < k; i++) {
    //     printf("label1: %d\tlabel2: %d", prevs[i][0], prevs[i][1]);
    //     putchar('\n');
    //     free(prevs[i]);
    // }

    // free(prevs);

    free_perceptron(&perceptron);

    return EXIT_SUCCESS;
}
