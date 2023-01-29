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
  char command[1000];
  printf("Enter your command: ");
  fgets(command, 100, stdin);
  if(command[0] == 'q') {
    if(command[2] != 0){
      printf("Unrecognized command. Type h for help.\n");
      print_board(painter);
      ask_for_input(painter);
    } else {
      do_quit();;
    }
  } else if(command[0] == 'h') {
    if(command[2] != 0){
      printf("Unrecognized command. Type h for help.\n");
      print_board(painter);
      ask_for_input(painter);
    } else {
      do_help();
    }
  } else if(command[0] == 'w') {
    do_write(command);
  } else if(command[0] == 'e') {
    do_erase(command);
  } else if(command[0] == 'a') {
    do_add(command);
  } else if(command[0] == 'r') {
    do_resize(command);
  } else if(command[0] == 's') {
     do_save(command);
   } else if(command[0] == 'd') {
      do_delete(command);
  } else {
    printf("Unrecognized command. Type h for help.\n");
    print_board(painter);
    ask_for_input(painter);
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
  print_board(painter);
  ask_for_input(painter);
}

void print_board(struct board_struct painter) {
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
}

void do_write(char command[]) {

  // split string into separate array values
  char** res = NULL;
  char* p = strtok (command, " ");
  int a = 0;

  while (p) {
    res = realloc (res, sizeof (char*) * ++a);
    res[a-1] = p;
    p = strtok (NULL, " ");
  }
  res = realloc (res, sizeof (char*) * (a+1));
  res[a] = 0;

  //store array values as integers
  int start_row = atoi(res[1]);
  int start_col = atoi(res[2]);
  int end_row = atoi(res[3]);
  int end_col = atoi(res[4]);

  free(res);

    if (start_row < 0 || start_row > painter.rows || start_col < 0 || start_col > painter.rows || end_row < 0 || end_row > painter.rows || end_col < 0 || end_col > painter.rows) {
      printf("Improper draw command.\n");
      print_board(painter);
      ask_for_input(painter);
    }
    else if (start_row == end_row) {
      draw_horizontal(start_row, start_col, end_row, end_col);
    }
    else if (start_col == end_col) {
      draw_vertical(start_row, start_col, end_row, end_col);
    }
    else if(((start_row-end_row) == (start_col-end_col)) || ((start_row-end_row) == (start_col+end_col)) || ((start_row+start_col) == (end_row+end_col)) || ((start_row+end_row) == (start_col-end_col))) {
      draw_diagonal(start_row, start_col, end_row, end_col);
    }
    else {
      printf("Cannot draw the line as it is not straight.\n");
      print_board(painter);
      ask_for_input(painter);
    }
  return;
}

void draw_diagonal(int start_row, int start_col, int end_row, int end_col) {
    // check if forward slashes or backward slashes
    if(start_row > end_row && start_col > end_col) {
      draw_forwardslash(start_row, start_col, end_row, end_col);
    } else if (start_row < end_row && start_col < end_col) {
      //change to draw top to bottom
      int temp = start_row;
      start_row = end_row;
      end_row = temp;
      int temp2 = start_col;
      start_col = end_col;
      end_col = temp2;
      draw_forwardslash(start_row, start_col, end_row, end_col);
    } else if (start_row > end_row && start_col < end_col) {
      draw_backslash(start_row, start_col, end_row, end_col);
    } else if (start_row < end_row && start_col > end_col) {
      //change to draw top to bottom
      int temp = start_row;
      start_row = end_row;
      end_row = temp;
      int temp2 = start_col;
      start_col = end_col;
      end_col = temp2;
      draw_backslash(start_row, start_col, end_row, end_col);
    }
    ask_for_input(painter);
}

void draw_forwardslash(int start_row, int start_col, int end_row, int end_col) {
  //change row values to the actual matrix values
  start_row = (painter.rows-1) - start_row;
  end_row = (painter.rows-1) - end_row;

  for(int i = start_row; i < painter.rows; i++)
    {
      for(int j = start_col; j < painter.cols; j++)
        {
          if(i == start_row && j == start_col && start_col >= end_col) {
            if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '/') {
              painter.the_board[i][j] = '/';
            } else {
            painter.the_board[i][j] = '+';
            }
          }
        }
        start_row++;
        start_col--;
    }
    print_board(painter);
    ask_for_input(painter);
}

void draw_backslash(int start_row, int start_col, int end_row, int end_col) {
  //change row values to the actual matrix values
  start_row = (painter.rows-1) - start_row;
  end_row = (painter.rows-1) - end_row;

  for(int i = start_row; i < painter.rows; i++)
    {
      for(int j = start_col; j < painter.cols; j++)
        {
          if(i == start_row && j == start_col && start_col <= end_col) {
            if(painter.the_board[i][j] == '*' || painter.the_board[i][j] == '\\') {
              painter.the_board[i][j] = '\\';
            } else {
            painter.the_board[i][j] = '+';
            }
          }
        }
        start_row++;
        start_col++;
    }
    print_board(painter);
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
  // split string into separate array values
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

  if(row >= 0 && row <= painter.rows-1 && col >= 0 && col <= painter.cols-1) {
    row = (painter.rows-1)-row;
    painter.the_board[row][col] = '*';
  } else {
    printf("Improper erase command.\n");
  }
  print_board(painter);
  ask_for_input(painter);
}

void do_add(char command[]) {
  // split string into separate array values
  char** res = NULL;
  char* p = strtok (command, " ");
  int a = 0;

  while (p) {
    res = realloc (res, sizeof (char*) * ++a);
    res[a-1] = p;
    p = strtok (NULL, " ");
  }
  res = realloc (res, sizeof (char*) * (a+1));
  res[a] = 0;

  if(strlen(res[1])==1) {

  //store array values
  char row_or_col = *res[1];
  int placer = atoi(res[2]);

  if (placer >= 0 && placer <= painter.rows) {

    if (row_or_col == 'r') {
      placer = painter.rows-placer;

      painter.the_board[painter.rows] = (char*)calloc(painter.cols, sizeof(char));
      painter.rows++;
        for(int i = painter.rows-1; i > placer; --i)
          {
            for(int j = 0; j < painter.cols; ++j)
            {
              painter.the_board[i][j] = painter.the_board[i-1][j];
            }
          }
        //fill w *
        for(int a = 0; a < painter.cols; ++a)
        {
          painter.the_board[placer][a] = '*';
        }
      } else if (row_or_col == 'c') {

    //    placer = painter.cols-placer;

        for(int b = 0; b < painter.rows; ++b) {
          char* temp = malloc(sizeof(char));
          painter.the_board[b][painter.cols] = *temp;
          free(temp);
          temp = NULL;
        }
        painter.cols++;

          for(int i = painter.rows-1; i > placer; --i)
            {
              for(int j = 0; j < painter.cols; j++)
              {
                painter.the_board[i][j] = painter.the_board[i-1][j];
              }
            }
          //fill w *
          for(int a = 0; a < painter.cols; a++)
          {
            painter.the_board[a][placer] = '*';
          }
          for(int a = 0; a < painter.cols; a++)
          {
            painter.the_board[a][painter.cols-1] = '*';
          }
      }
    } else {
      printf("Improper add command.\n");
    }
} else {
  printf("Improper add command.\n");
}
print_board(painter);
ask_for_input(painter);
}

void do_resize(char command[]) {
  // split string into separate array values


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

  int new_rows = atoi(res[1]);
  int new_cols = atoi(res[2]);
/*
  //check for if new row and new col is less or greater or mix

  //new row and new col greater

  if(new_rows >= painter.rows && new_cols >= painter.cols) {

    // reallocate more space
    painter.rows = new_rows;
    painter.cols = new_cols;

    painter.the_board = realloc(painter.the_board, painter.rows * sizeof(char*));
      for(int i = 0; i < painter.rows; i++) {
        painter.the_board[i] = (char *)calloc(painter.cols, sizeof(char));
      }

    // now that the board is right size change the values


    printf("\n");
    ask_for_input(painter);

  }
  // both less
//  else if (new_rows <= painter.rows && new_cols <= painter) {

//  }


*/

  if (new_rows <= 0 || new_rows > painter.rows || new_cols <= 0 || new_cols > painter.rows) {
    printf("Improper resize command.\n");
  }

  print_board(painter);
  ask_for_input(painter);

}

void do_save(char command[]) {
    print_board(painter);
    ask_for_input(painter);
}

void do_delete(char command[]){
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

    int new_rows = atoi(res[1]);
    int new_cols = atoi(res[2]);

      if (new_rows <= 0 || new_rows > painter.rows || new_cols <= 0 || new_cols > painter.rows) {
        printf("Improper delete command.\n");
      }

    print_board(painter);
    ask_for_input(painter);
}
