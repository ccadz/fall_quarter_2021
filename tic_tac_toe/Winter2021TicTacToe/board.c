#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "util.h"


void fetch_board_parameters_from_command_line(int argc, char** argv,
	char* player_pieces, int len_player_pieces,
	int* dim, char* blank_char){
	if(argc == 3){ //correct number of args passed
		int num_args_read;
		char should_be_blank;
		num_args_read = sscanf(argv[1], "%d %c", dim, &should_be_blank);
		if(num_args_read == 1){
			if(!(*dim > 0)){
				printf("Error! the dimensions of the board must be greater 0.\n");
				printf("Ending program\n");
				exit(0);
			}
		}else{
			printf("Error! The dimensions must be a integer number\n");
			printf("Ending program\n");
			exit(0);
		}

		num_args_read = sscanf(argv[2], "%c %c", blank_char, &should_be_blank);
		if(num_args_read != 1){
			printf("Error! the blank char can only be a single character\n");
			printf("Ending program\n");
			exit(0);
		}else if(is_in(*blank_char, player_pieces, len_player_pieces)){
			printf("Error! The blank character cannot be one of the player pieces");
			printf("Ending program\n");
			exit(0);
		}
	} else{
		printf("Invalid number of arguments entered\n");
		printf("Ending program\n");
		exit(0);
	}
}


char** create_board(int dim, char blank_char){
		char** board = calloc(dim, sizeof(*board));

		for (int i = 0; i < dim; ++i) {
			board[i] = calloc(dim, sizeof(*board[i]));
			for(int j = 0; j < dim; ++j){
				board[i][j] = blank_char;
			}
		}
		return board;
}


void display_board(char** board, int dim){
	for(int i =0; i < dim; ++i){
		printf("%d ", i); //row header
		for(int j = 0; j < dim; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//column headers
	printf("  ");
	for(int i = 0; i < dim; ++i){
		printf("%d ", i);
	}
	printf("\n");
}

void destroy_board(char** board, int dim){
	for(int i =0; i < dim; ++i){
		free(board[i]);
	}
	free(board);
}
