#ifndef PAINT_C
  #define PAINT_C
  #include <stdlib.h>
  #include <stdbool.h>
  #include <stdio.h>
  #include <string.h>

  typedef struct board_struct {
      char** the_board;
      int rows;
      int cols;
  }Board;

  void display_board(int given_rows, int given_cols);
  void create_board(int given_rows, int given_cols);
  void ask_for_input(struct board_struct painter);
  void print_board(struct board_struct painter);
  void do_quit();
  void do_help();
  void do_write(char command[]);
  void do_erase(char command[]);
  void do_add(char command[]);
  void do_resize(char command[]);
  void do_save(char command[]);
  void do_delete(char command[]);
  void draw_diagonal(int start_row, int start_col, int end_row, int end_col);
  void draw_forwardslash(int start_row, int start_col, int end_row, int end_col);
  void draw_backslash(int start_row, int start_col, int end_row, int end_col);
  void draw_horizontal(int start_row, int start_col, int end_row, int end_col);
  void draw_vertical(int start_row, int start_col, int end_row, int end_col);

#endif
