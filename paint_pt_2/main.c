#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "paint.h"

int main(int argc, char **argv) {

  char *a1;
  char *b1;
  int num1;
  int num2;

/*  char* p = argv[1];
  char* p2 = argv[2];
  if (*p>'0' && *p<'9') {
    if (*p2>'0' && *p2<'9') {
*/
            if(argc == 1) {
              num1 = 10;
              num2 = 10;
            } else if(argc == 2 || argc > 3) {
              printf("Wrong number of command line arguements entered.\n");
              printf("Usage: ./paint.out [num_rows num_cols]\n");
              printf("Making default board of 10 X 10.\n");
              num1 = 10;
              num2 = 10;
            } else {
             num1 = strtol(argv[1], &a1, 10);
             num2 = strtol(argv[2], &b1, 10);
               if (num1 < 1) {
                 printf("The number of rows is less than 1.\n");
                 printf("Making default board of 10 X 10.\n");
                 num1 = 10;
                 num2 = 10;
               } else if (num2 < 1) {
                 printf("The number of columns is less than 1.\n");
                 printf("Making default board of 10 X 10.\n");
                 num1 = 10;
                 num2 = 10;
               }
           }
           /*
     } else {
      printf("The number of columns is not an integer.\n");
      printf("Making default board of 10 X 10.\n");
      num1 = 10;
      num2 = 10;
    }

} else {
  printf("The number of rows is not an integer.\n");
  printf("Making default board of 10 X 10.\n");
  num1 = 10;
  num2 = 10;
 }
*/
  display_board(num1, num2);
  return 0;
}
