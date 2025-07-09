.PHONY: edit


perceptron: main.c
	gcc main.c -o perceptron -Wall -Wextra -fsanitize=address -lm


edit: main.c
	nvim main.c

clean:
	rm perceptron
