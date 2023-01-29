paint.out: paint.o main.o
	gcc -g -Wall -Werror -o paint.out paint.o main.o

main.o: main.c paint.h
	gcc -g -Wall -Werror -c -o main.o main.c

paint.o: paint.c paint.h
	gcc -g -Wall -Werror -c -o paint.o paint.c

clean:
	rm -f *.out *.o
