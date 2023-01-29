#include <stdio.h>
#include <math.h>

int main(void) {
int a1;
int b1;
int a2;
int b2;
int a3;
int b3;
char letter;

printf("Enter the first complex number in the form ai + b: ");
scanf("%d%c + %d", &a1, &letter, &b1);
printf("Enter the second complex number in the form ai + b: ");
scanf("%d%c + %d", &a2, &letter, &b2);

b3 = -a1 * a2 + b1 * b2;
a3 = b1 * a2 + b2 * a1;

printf("(%d%c + %d) * (%d%c + %d) = %d%c + %d\n", a1, letter, b1, a2, letter, b2, a3, letter, b3);
}
