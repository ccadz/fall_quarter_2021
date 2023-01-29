#include <stdio.h>

int main(void) {
int level, a, b, num;
num = 1;
printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
scanf("%d", &level);
for(a = 0; a < level; ++a) {
for(b = 0; b <= a; ++b) {
if (a == 0 || b == 0) {
num = 1;
} else {
num = num * (a - b + 1)/b;
}
printf("%d ", num);
}
printf("\n"); 
}

return 0;
}