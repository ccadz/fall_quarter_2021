#ifndef BOARD_H
	#define BOARD_H

void fetch_board_parameters_from_command_line(int argc, char** argv,
	char* player_pieces, int len_player_pieces,
	int* dim, char* blank_char);
char** create_board(int dim, char blank_char);
void display_board(char** board, int dim);
void destroy_board(char** board, int dim);

#endif
