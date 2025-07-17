mat_utils.o: mat_utils.c
	gcc -c -Wall -Wextra -fsanitize=address mat_utils.c

main: main.c mat_utils.o
	gcc -o main -Wall -Wextra -fsanitize=address mat_utils.o main.c

mat_utils.prod.o: mat_utils.c
	gcc -c -O3 -mavx mat_utils.c

prod: main.c mat_utils.prod.o
	gcc -O3 -mavx -o main mat_utils.o main.c
