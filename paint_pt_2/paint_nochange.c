#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "paint.h"

Board painter;

void display_board(int given_rows, int given_cols) {
  create_board(given_rows, given_cols);
  ask_for_input(painter);
  return;

}

void create_board(int given_rows, int given_cols) {
  painter.rows = given_rows;
  painter.cols = given_cols;

  painter.the_board = (char **)calloc(given_rows, sizeof(char*));
  for(int i = 0; i < given_rows; i++) {
   painter.the_board[i] = (char *)calloc(given_cols, sizeof(char));
  }


  for(int i = painter.rows-1; i >= 0; --i)
    {
      printf("%d ", i);
      for(int j = painter.cols-1; j >= 0; --j)
        {
          painter.the_board[i][j] = '*';
          printf("%c ", painter.the_board[i][j]);
        }
        printf("\n");
    }
  printf("  ");
  for (int c = 0; c < painter.cols; ++c) {
    printf("%d ", c);
  }
  printf("\n");
}

void ask_for_input(struct board_struct painter) {
  char command[100];
  printf("Enter your command: ");
  fgets(command, 100, stdin);
  if(command[0] == 'q') {
    do_quit();
  } else if(command[0] == 'h') {
    do_help();
  } else if(command[0] == 'w') {
    do_write(command);
  } else if(command[0] == 'e') {
    do_erase(command);
  }
}

void do_quit() {
  free(painter.the_board);
    exit(0);
}

void do_help() {
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
  //print board again
  for(int i = painter.rows-1; i >= 0; --i)
    {
      printf("%d ", i);
      for(int j = painter.cols-1; j >= 0; --j)
        {
          printf("%c ", painter.the_board[i][j]);
        }
        printf("\n");
    }
  printf("  ");
  for (int c = 0; c < painter.cols; ++c) {
    printf("%d ", c);
  }
  printf("\n");
  ask_for_input(painter);
}

void do_write(char command[]) {

  // split string into separate array values (help from stackoverflow)
  char** res = NULL;
  char* p = strtok (command, " ");
  int n_spaces = 0;

  while (p) {
    res = realloc (res, sizeof (char*) * ++n_spaces);
    res[n_spaces-1] = p;
    p = strtok (NULL, " ");
  }
  res = realloc (res, sizeof (char*) * (n_spaces+1));
  res[n_spaces] = 0;

  int start_row = atoi(res[1]);
  int start_col = atoi(res[2]);
  int end_row = atoi(res[3]);
  int end_col = atoi(res[4]);

  free(res);

    if(((start_row-end_row) == (start_col-end_col)) || ((start_row-end_row) == (start_col+end_col)) || ((start_row+start_col) == (end_row+end_col)) || ((start_row+end_row) == (start_col-end_col))) {
      draw_diagonal(start_row, start_col, end_row, end_col);
    } else if (start_row == end_row) {
      draw_horizontal(start_row, start_col, end_row, end_col);
    } else if (start_col == end_col) {
      draw_vertical(start_row, start_col, end_row, end_col);
    } else {
      printf("Improper draw command.\n");
      ask_for_input(painter);
    }
  return;
}

void draw_diagonal(int start_row, int start_col, int end_row, int end_col) {

    //change values to match the real matrix values
    start_row = (painter.rows-1) - start_row;
    end_row = (painter.rows-1) - end_row;

    //forward slashes
    if(start_col > end_col && start_row < end_row) {

      for(int i = 0; i < painter.rows; i++)
        {
          printf("%d ", painter.rows-1-i);
          for(int j = 0; j < painter.cols; j++)
            {
              if(i == start_row && j == start_col && start_col >= end_col) {
                if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '/') {
                  painter.the_board[i][j] = '/';
                } else {
                painter.the_board[i][j] = '+';
                }
              }
              printf("%c ", painter.the_board[i][j]);
            }
            start_row++;
            start_col--;
            printf("\n");
        }
      printf("  ");
      for (int c = 0; c < painter.cols; ++c) {
        printf("%d ", c);
      }
      printf("7632\n");

    }
    // other way
    else if(start_col < end_col && start_row > end_row) {
      for(int i = painter.rows-1; i >= 0; --i)
        {
          printf("%d ", i);
          for(int j = painter.cols-1; j >= 0; --j)
            {
                if((i == start_row) && (j == start_col) && (start_col <= end_col)) {
                  if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '/') {
                    painter.the_board[i][j] = '/';
                  } else {
                  painter.the_board[i][j] = '+';
                  }
                }
                printf("%c ", painter.the_board[i][j]);
              }
              start_row--;
              start_col++;
              printf("\n");
          }
        printf("  ");
        for (int c = 0; c < painter.cols; ++c) {
          printf("%d ", c);
        }
        printf("\n");
    }
      //backward slashes
      else if(start_col < end_col && start_row < end_row) {

      for(int i = 0; i < painter.rows; ++i)
        {
          printf("%d ", painter.rows-1-i);
          for(int j = 0; j < painter.cols; ++j)
            {
              if(i == start_row && j == start_col && start_col <= end_col) {
                if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '\\') {
                  painter.the_board[i][j] = '\\';
                } else {
                painter.the_board[i][j] = '+';
                }
              }
              printf("%c ", painter.the_board[i][j]);
            }
            start_row++;
            start_col++;
            printf("\n");
        }
      printf("  ");
      for (int c = 0; c < painter.cols; ++c) {
        printf("%d ", c);
      }
      printf("\n");
    }
    // other way
      else if(start_col > end_col && start_row > end_row) {
        for(int i = painter.rows-1; i >= 0; --i)
          {
            printf("%d ", i);
            for(int j = painter.cols-1; j >= 0; --j)
              {
                  if((i == start_row) && (j == start_col) && (start_col >= end_col)) {
                    if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '/') {
                      painter.the_board[i][j] = '\\';
                    } else {
                    painter.the_board[i][j] = '+';
                    }
                  }
                  printf("%c ", painter.the_board[i][j]);
                }
                start_row--;
                start_col--;
                printf("\n");
            }
          printf("  ");
          for (int c = 0; c < painter.cols; ++c) {
            printf("%d ", c);
          }
          printf("\n");
      }
    ask_for_input(painter);
}

void draw_horizontal(int start_row, int start_col, int end_row, int end_col) {

  //change values to match the real matrix values
  start_row = (painter.rows-1) - start_row;
  end_row = (painter.rows-1) - end_row;

  if(start_col < end_col) {

    for(int i = 0; i < painter.rows; ++i)
      {
        printf("%d ", painter.rows-1-i);
        for(int j = 0; j < painter.cols; ++j)
          {
            if(i == start_row && j == start_col && start_col <= end_col) {
              if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '-') {
                painter.the_board[i][j] = '-';
              } else {
              painter.the_board[i][j] = '+';
              }
              start_col++;
            }
            printf("%c ", painter.the_board[i][j]);
          }
          printf("\n");
      }
    printf("  ");
    for (int c = 0; c < painter.cols; ++c) {
      printf("%d ", c);
    }
    printf("\n");
  } else if(start_col > end_col) {

    int temp = start_col;
    start_col = end_col;
    end_col = temp;
    for(int i = 0; i < painter.rows; ++i)
      {
        printf("%d ", painter.rows-1-i);
        for(int j = 0; j < painter.cols; ++j)
          {
            if(i == start_row && j == start_col && start_col <= end_col) {
              if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '-') {
                painter.the_board[i][j] = '-';
              } else {
              painter.the_board[i][j] = '+';
              }
              start_col++;
            }
            printf("%c ", painter.the_board[i][j]);
          }
          printf("\n");
      }
    printf("  ");
    for (int c = 0; c < painter.cols; ++c) {
      printf("%d ", c);
    }
    printf("\n");
  }
  ask_for_input(painter);
}

void draw_vertical(int start_row, int start_col, int end_row, int end_col) {

  //change values to match the real matrix values
  start_row = (painter.rows-1) - start_row;
  end_row = (painter.rows-1) - end_row;

  if(start_row < end_row) {

    for(int i = 0; i < painter.rows; ++i)
      {
        printf("%d ", painter.rows-1-i);
        for(int j = 0; j < painter.cols; ++j)
          {
            if(i == start_row && j == start_col && start_row <= end_row) {
              if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '|') {
                painter.the_board[i][j] = '|';
              } else {
              painter.the_board[i][j] = '+';
              }
              start_row++;
            }
            printf("%c ", painter.the_board[i][j]);
          }
          printf("\n");
      }
    printf("  ");
    for (int c = 0; c < painter.cols; ++c) {
      printf("%d ", c);
    }
    printf("\n");
  } else if(start_row > end_row) {

    int temp = start_row;
    start_row = end_row;
    end_row = temp;

    for(int i = 0; i < painter.rows; ++i)
      {
        printf("%d ", painter.rows-1-i);
        for(int j = 0; j < painter.cols; ++j)
          {
            if(i == start_row && j == start_col && start_row <= end_row) {
              if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '|') {
                painter.the_board[i][j] = '|';
              } else {
              painter.the_board[i][j] = '+';
              }
              start_row++;
            }
            printf("%c ", painter.the_board[i][j]);
          }
          printf("\n");
      }
    printf("  ");
    for (int c = 0; c < painter.cols; ++c) {
      printf("%d ", c);
    }
    printf("\n");
  }
  ask_for_input(painter);
}

void do_erase(char command[]) {
  // split string into separate array values (help from stackoverflow)
  char** res = NULL;
  char* p = strtok (command, " ");
  int n_spaces = 0;

  while (p) {
    res = realloc (res, sizeof (char*) * ++n_spaces);
    res[n_spaces-1] = p;
    p = strtok (NULL, " ");
  }
  res = realloc (res, sizeof (char*) * (n_spaces+1));
  res[n_spaces] = 0;

  int row = atoi(res[1]);
  int col = atoi(res[2]);
  row = painter.rows-1-row;
  painter.the_board[row][col] = '*';

  for(int i = 0; i < painter.rows; i++)
    {
      printf("%d ", painter.rows-1-i);
      for(int j = 0; j < painter.cols; j++)
        {

          printf("%c ", painter.the_board[i][j]);
        }
        printf("\n");
    }
  printf("  ");
  for (int c = 0; c < painter.cols; ++c) {
    printf("%d ", c);
  }
  printf("\n");
  ask_for_input(painter);
}
