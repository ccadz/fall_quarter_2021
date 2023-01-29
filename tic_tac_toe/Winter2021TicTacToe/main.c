
#include <stdio.h>
#include "game.h"




int main(int argc, char** argv){
	char** board;
	char* player_pieces;
	int cur_player_turn;
	int dim;
	char blank_char;
	setup_game(argc,argv, &board, &dim, &blank_char, &player_pieces, &cur_player_turn);
	play_game(board, dim, blank_char,
						player_pieces, cur_player_turn);
	cleanup_game(board, dim, player_pieces);
	return 0;
}
