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
double getValidDouble(const char* prompt){
double num;
const int numArgsNeeded = 1;
int numArgsRead;
do {
printf("%s", prompt);
numArgsRead = scanf(" %lf", &num); //waffles\n
} while(!isValidFormat(numArgsRead, numArgsNeeded));
return num;
}
double getPosDouble(const char* prompt){
double num;
do{
num = getValidDouble(prompt);
}while(!(num > 0));
return num;
}
int main() {
double eachMonth = getPosDouble("Enter how much money you will be putting towards loans/retirement each month: ");
double loanTotal = getPosDouble("Enter how much you owe in loans: ");
double loanInterest = getPosDouble("Enter the annual interest rate of the loans: ");
double minMonthly = getPosDouble("Enter your minimum monthly loan payment: ");
if (minMonthly > eachMonth) {
printf("You didn't set aside enough money to pay off our loans. Ending program.");
return 0;
}
double currAge = getPosDouble("Enter your current age: ");
double retireAge;
do {
retireAge = getPosDouble("Enter the age you plan to retire at: ");
} while (retireAge <= currAge);
double invROR = getPosDouble("Enter the annual rate of return you predict for your investments: ");
double monInterest = loanInterest / 12;
double monROR = invROR / 12;
double availInv = eachMonth - minMonthly;
double invTotal = 0;
int i, totalMonths;
totalMonths = retireAge * 12 - currAge * 12;
double loanTotal2 = loanTotal;
double invTotal2 = 0;
for (i = 0; i < totalMonths; ++i) {
if (loanTotal - minMonthly > 0) {
loanTotal = loanTotal + loanTotal * monInterest;
invTotal = invTotal + invTotal * monROR;
loanTotal = loanTotal - minMonthly;
invTotal = invTotal + availInv;
} else {
loanTotal = loanTotal + loanTotal * monInterest;
invTotal = invTotal + invTotal * monROR;
invTotal = invTotal + eachMonth - loanTotal;
loanTotal = 0;
}
}
double payAfter = invTotal;
for (i = 0; i < totalMonths; ++i) {
loanTotal2 = loanTotal2 * monInterest + loanTotal2;
if (loanTotal2 - eachMonth >= 0) {
loanTotal2 = loanTotal2 - eachMonth;
} else {
invTotal2 = invTotal2 + invTotal2 * monROR;
invTotal2 = invTotal2 + eachMonth - loanTotal2;
loanTotal2 = 0;
}
}
double payFirst = invTotal2;
if(loanTotal > 0) {
printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loanTotal);
}
if (payAfter > payFirst) {
printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", payAfter, payFirst);
} else {
printf("You should apply all $%.2lf towards your loan before making any investments.\n", eachMonth);
printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", payFirst, payAfter);
}
return 0;
}