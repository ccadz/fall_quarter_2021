#include <stdio.h>
#include <math.h>

int main(void) {

  int money;
  int hundreds;
  int fiftys;
  int twentys;
  int tens;
  int fives;
  int ones;

  printf("Please enter the amount of money you wish to withdraw: ");
  scanf("%d", &money);

  hundreds = money / 100;
  fiftys = money % 100 / 50;
  twentys = money % 100 % 50 / 20;
  tens = money % 100 % 50 % 20 / 10;
  fives = money % 100 % 50 % 20 % 10 / 5;
  ones = money % 100 % 50 % 20 % 10 % 5 / 1;

  printf("You received %d hundred(s)\n", hundreds);
  printf("You received %d fifty(s)\n", fiftys);
  printf("You received %d twenty(s)\n", twentys);
  printf("You received %d ten(s)\n", tens);
  printf("You received %d five(s)\n", fives);
  printf("You received %d one(s)\n", ones);

}
