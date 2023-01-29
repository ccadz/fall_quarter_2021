
#include <stdbool.h>
#include <stdlib.h>
#include "game_over.h"
#include "util.h"

bool is_game_over(char** board, int dim, char blank_char){
	return someone_won(board, dim, blank_char) || tie(board, dim, blank_char);
}

bool someone_won(char** board, int dim, char blank_char){
	return won_horizontally(board, dim, blank_char) ||
				 won_vertically(board, dim, blank_char) ||
				 won_diagonally(board, dim, blank_char);
}

bool won_horizontally(char** board, int dim, char blank_char){
	for(int i =0; i < dim; ++i){ //go through rows
		if(board[i][0] != blank_char && all_same(board[i], dim)){
			return true;
		}
	}
	return false;
}

bool won_vertically(char** board, int dim, char blank_char){
	char* column = calloc(dim, sizeof(*column));
	for(int i =0; i < dim; ++i){ //go through columns
		if(board[0][i] != blank_char){
			//copy the elements into the column
			for(int j = 0; j < dim; ++j){ //go through the elements of the column
				column[j] = board[j][i];
				}
			if(all_same(column, dim)){
				free(column);
				return true;
			}
		}
	}
	free(column);
	return false;
}

bool won_diagonally(char** board, int dim, char blank_char){
	return won_right_diagonally(board, dim, blank_char) ||
	 won_left_diagonally(board, dim, blank_char);
}

bool won_right_diagonally(char** board, int dim, char blank_char){
	/*
		X
		 X
		  X
	*/
	if(board[0][0] == blank_char){
		return false;
	}else{
		for(int i =0; i < dim; ++i){
			if(board[i][i] != board[0][0]){
				return false;
			}
		}
	}
	return true;
}

bool won_left_diagonally(char** board, int dim, char blank_char){
	/*
		   X
		 X
	 X
	*/
	if(board[0][dim-1] == blank_char){
		return false;
	}else{
		for(int i =0; i < dim; ++i){
			if(board[i][dim - 1 - i] != board[0][dim-1]){
				return false;
			}
		}
	}
	return true;
}

bool tie(char** board, int dim, char blank_char){
	//before calling this function first check if a win has happened
	for(int i =0; i < dim; ++i){
		for(int j = 0; j <dim; ++j){
			if(board[i][j] == blank_char){
				return false;
			}
		}
	}
	return true;
}
