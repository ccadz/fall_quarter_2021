#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "board.h"
#include "game_over.h"
#include "input_validation.h"

void setup_game(int argc, char** argv, char*** board, int* dim, char* blank_char,
	 char** player_pieces, int* cur_player_turn){
	*player_pieces = calloc(2, sizeof(**player_pieces));
	(*player_pieces)[0] = 'X'; //player 1 is an X
	(*player_pieces)[1] = 'O'; //player 2 is an O
	fetch_board_parameters_from_command_line(argc, argv,
		*player_pieces, 2, dim, blank_char);
	*board = create_board(*dim, *blank_char);
	*cur_player_turn = 0; //player 1 goes first
}

void play_game(char** board, int dim, char blank_char,
							char* player_pieces, int player_turn){
	while(true){
		player_take_turn(board, dim, blank_char, player_pieces[player_turn], player_turn + 1);
		if(is_game_over(board, dim, blank_char)){
			break;
		}
		change_turn(&player_turn);
	}

	declare_results_of_game(board, dim, blank_char, player_turn + 1);
}

void player_take_turn(char** board, int dim, char blank_char, char player_piece,
											int player_id){
	int row, col;
	display_board(board, dim);
	get_move_from_player(&row, &col, board, dim, blank_char, player_id);
	make_move(board, row, col, player_piece);
}

void get_move_from_player(int* row, int* col,
	char** board, int dim, char blank_char, int player_id){
	int num_args_read;
	do{
		printf("Player %d enter your move in the form row col: ", player_id);
		num_args_read = scanf("%d %d", row, col);
	}while(!is_valid_move(num_args_read, *row, *col, board, dim, blank_char));
}

void make_move(char** board, int row, int col, char piece){
	board[row][col] = piece;
}

void change_turn(int* turn){
	//0 means its player 1's turn
	//1 means its player 2's turn
	*turn = (*turn + 1) % 2;
}

void declare_results_of_game(char** board, int dim, char blank_char, int player_turn){
	display_board(board, dim);
	if(someone_won(board, dim, blank_char)){
		printf("Player %d won!\n", player_turn);
	}else{
		printf("Tie game -_-\n");
	}
}

void cleanup_game(char** board, int dim, char* player_pieces){
	destroy_board(board, dim);
	free(player_pieces);
}
