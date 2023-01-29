tic_tac_toe.out: board.o game_over.o game.o input_validation.o main.o util.o
	gcc -g -Wall -Werror -o tic_tac_toe.out board.o game_over.o game.o input_validation.o main.o util.o

board.o: board.c board.h util.h
	gcc -g -Wall -Werror -c board.c

game_over.o: game_over.c game_over.h util.h
	gcc -g -Wall -Werror -c game_over.c

game.o: game.c game.h game_over.h board.h input_validation.h
	gcc -g -Wall -Werror -c game.c

input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

main.o: main.c game.h
	gcc -g -Wall -Werror -c main.c

util.o: util.c util.h
	gcc -g -Wall -Werror -c util.c

clean:
	rm -f *.o *.out 
