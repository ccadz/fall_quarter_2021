#include <stdio.h>
#include <ctype.h>

void count(char* file_name) {
  FILE* file = fopen(file_name, "r");
  char c;
  int count = 0;

  fscanf(file, "%c", &c);
  while(!feof(file)){
    if (c == ' ' || c == '\n') {
      count++;
    }
    fscanf(file, "%c", &c);
  }
  printf("There are %d word(s).", count);
}
int main(int argc, char** argv) {
  count(argv[1]);
  return 0;
}
