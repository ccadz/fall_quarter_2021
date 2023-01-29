#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "read_lines.h"

void read_lines(FILE* fp, char*** lines, int* num_lines) {
  int count = 0;
  char c;

  fscanf (fp, "%c", &c);
  while (!feof(fp)) {
//      (*lines)[count] = malloc(sizeof(char) * strlen(**lines));
//      strcpy((*lines)[count], **lines);
//      count++;
      while

      counter




      malloc



      realloc


    }
    fscanf(fp, "%c", &c);

  *num_lines = count;
  if(count == 0) {
    *lines = NULL;
  }
}
