.PHONY: edit

training_set.o: training_set.c
	gcc -c -Wall -Wextra -fsanitize=address training_set.c

perceptron.o: perceptron.c
	gcc -c -Wall -Wextra -fsanitize=address perceptron.c

all: perceptron.o training_set.o
	gcc main.c training_set.o perceptron.o -o main -Wall -Wextra -fsanitize=address -lm 


edit: main.c
	nvim main.c

clean:
	rm *.o main
