#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: perceptron grade\n");
        exit(1);
    }

    double grade = atof(argv[1]);

    if (grade >= 18) {
        printf("Passed\n");
    }

    return EXIT_SUCCESS;
}
