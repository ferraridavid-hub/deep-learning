.PHONY: edit

training_set.o: training_set.c
	gcc -c -Wall -Wextra -fsanitize=address training_set.c

tlu_neuron.o: tlu_neuron.c
	gcc -c -Wall -Wextra -fsanitize=address tlu_neuron.c

all: tlu_neuron.o training_set.o
	gcc main.c training_set.o tlu_neuron.o -o main -Wall -Wextra -fsanitize=address -lm 


edit: main.c
	nvim main.c

clean:
	rm *.o main
