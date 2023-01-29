#include <stdio.h>
#include <math.h>

int main(void) {
double a;
double b;
double c;
double x1;
double x2;
double discriminant;

printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
printf("Please enter a: ");
scanf("%lf", &a);
printf("Please enter b: ");
scanf("%lf", &b);
printf("Please enter c: ");
scanf("%lf", &c);

discriminant = (b*b - 4*a*c);
if (discriminant < 0)
{
printf("There are no real solutions\n");
}
else if (discriminant == 0)
{
x1 = -b / (2*a);
printf("There is one real solution: %.2lf\n", x1);		
}
else
{
x1 = (-b + (sqrt(discriminant)))/(2*a);
x2 = (-b - (sqrt(discriminant)))/(2*a);
printf("There are 2 real solutions\n");
printf("Solution 1: %.2lf\n", x1);
printf("Solution 2: %.2lf\n", x2);
}

return 0;
}
