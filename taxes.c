#include <stdio.h>
#include <math.h>

double TaxBracket1(double income) {
return income*.1;
}
double TaxBracket2(double income) {
return (income-9875)*.12;
}
double TaxBracket3(double income) {
return (income-40125)*.22;
}
double TaxBracket4(double income) {
return (income-85525)*.24;
}
double TaxBracket5(double income) {
return (income-163300)*.32;
}
double TaxBracket6(double income) {
return (income-207350)*.35;
}
double TaxBracket7(double income) {
return (income-518400)*.37;
}
int main(void) {
double income;
printf("Enter your income for the year: ");
scanf("%lf", &income);

if (income < 9875){
double taxed = TaxBracket1(income);
double flatTax = taxed/income*100;
printf("You were taxed 10.00%% on the first $%.2lf you made which is $%.2lf.\n", income, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else if (income < 40125){
double taxed = TaxBracket2(income);
double flatTax = (taxed+987.5)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $%.2lf you made which is $%.2lf.\n", income-9875, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+987.5, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else if (income < 85525){
double taxed = TaxBracket3(income);
double flatTax = (taxed+4617.5)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
printf("You were taxed 22.00%% on the next $%.2lf you made which is $%.2lf.\n", income-40125, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+4617.5, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else if (income < 163300){
double taxed = TaxBracket4(income);
double flatTax = (taxed+14605.5)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
printf("You were taxed 24.00%% on the next $%.2lf you made which is $%.2lf.\n", income-85525, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+14605.5, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else if (income < 207350){
double taxed = TaxBracket5(income);
double flatTax = (taxed+33271.5)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
printf("You were taxed 32.00%% on the next $%.2lf you made which is $%.2lf.\n", income-163300, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+33271.5, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else if (income < 518400){
double taxed = TaxBracket6(income);
double flatTax = (taxed+47367.5)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
printf("You were taxed 35.00%% on the next $%.2lf you made which is $%.2lf.\n", income-207350, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+47367.5, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
} else {
double taxed = TaxBracket7(income);
double flatTax = (taxed+156235)/income*100;
printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
printf("You were taxed 35.00%% on the next $311050.00 you made which is $108867.50.\n");
printf("You were taxed 37.00%% on the next $%.2lf you made which is $%.2lf.\n", income-518400, taxed);
printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxed+156235, income);
printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flatTax);
}
}