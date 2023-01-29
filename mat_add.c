#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>   
#include <stdlib.h>   
#include <time.h>   
#include <string.h>   
int main() {
int rows, columns; 
printf("Please enter the number of rows: ");
scanf("%d", &rows);
printf("Please enter the number of columns: ");
scanf("%d", &columns);
int matrixA[rows][columns];
int matrixB[rows][columns];
int matrixC[rows][columns];
printf("Enter Matrix A\n");
for (int a = 0; a < rows; a++) {
for (int b = 0; b < columns; b++) {
scanf("%d", &matrixA[a][b]);
}
}	
printf("Enter Matrix B\n");
for (int c = 0; c < rows; c++) {
for (int d = 0; d < columns; d++) {
scanf("%d", &matrixB[c][d]);
}
}
printf("A + B =\n");
for (int e = 0; e < rows; e++) {
for (int f = 0; f < columns; f++) {
matrixC[e][f] = matrixA[e][f] + matrixB[e][f];
printf("%d ", matrixC[e][f]);
}
printf("\n");
}
return 0;
}