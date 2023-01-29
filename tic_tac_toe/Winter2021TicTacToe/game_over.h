#ifndef GAME_OVER_H
	#define GAME_OVER_H
	#include <stdbool.h>

	bool is_game_over(char** board, int dim, char blank_char);
	bool someone_won(char** board, int dim, char blank_char);
	bool won_horizontally(char** board, int dim, char blank_char);
	bool won_vertically(char** board, int dim, char blank_char);
	bool won_diagonally(char** board, int dim, char blank_char);
	bool won_right_diagonally(char** board, int dim, char blank_char);
	bool won_left_diagonally(char** board, int dim, char blank_char);
	bool tie(char** board, int dim, char blank_char);
	

#endif
