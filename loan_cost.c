#include <stdio.h>
#include <math.h>

int main(void) {
double total;
double interest;
int numPayments;
double borrowed;
double monthlyPayments;
double loanCost;

printf("Please enter the amount of money you borrowed: $");
scanf("%lf", &borrowed);
printf("Please enter the annual interest rate: ");
scanf("%lf", &interest);
printf("Please enter the number of payments to be made: ");
scanf("%d", &numPayments);

monthlyPayments = (interest/12*borrowed)/(1-pow(1+interest/12, -1*numPayments));
total = monthlyPayments*numPayments;
loanCost = total - borrowed;
printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf.\n", borrowed, interest, numPayments, monthlyPayments);
printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", total, loanCost);
}
