#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>   
#include <stdlib.h>   
#include <time.h>   

// from class
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
bool formatIsGood = numArgsRead == numArgsNeed;
char character;
do {
scanf("%c", &character); //45  bob  \n
if (!isspace(character)) { //found a non whitespace character on the way to the end of the line
formatIsGood = false;
}
} while(character != '\n'); //read characters until the end of the line
return formatIsGood;
}

int getValidInt(const char* prompt){
int num;
const int numArgsNeeded = 1;
int numArgsRead;
do {
printf("%s", prompt);
numArgsRead = scanf(" %d", &num); //waffles\n
} while(!isValidFormat(numArgsRead, numArgsNeeded));
return num;
}

int getPosInt(){
	int num;
  do{
    num = getValidInt("Enter the number of iterations to run: ");
  }while(!(num > 0));

  return num;
}

int main() {
double piVal, count;
int i;
double x, y;
count = 0;

int seed = getValidInt("Enter the seed for the random number generator: ");
int iterations = getPosInt();
srand(seed);

for (i = 0; i < iterations; ++i) {
x = -1 + ((double) rand()) / (((double) RAND_MAX) / (2));
y = -1 + ((double) rand()) / (((double) RAND_MAX) / (2));
if (x*x + y*y <= 1) {
count++;
}
}
piVal = count/((double) iterations)*4;
printf("The value of pi is %.3lf.\n", piVal);
return 0;
}
