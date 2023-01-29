#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>   
#include <stdlib.h>   
#include <time.h>   
int main() {
double totalCards, cardCopies, initHand, cardsMulled, drawTurns, stepOne, stepTwo, stepThree, probTotal;
printf("Enter how many total cards there are in the deck: ");
scanf("%lf", &totalCards);
printf("Enter how many copies of the card that you are looking for are in the deck: ");
scanf("%lf", &cardCopies);
printf("Enter your initial hand size: ");
scanf("%lf", &initHand);
printf("Enter how many cards you are mulliganing: ");
scanf("%lf", &cardsMulled);
printf("Enter what turn you want to draw the card by: ");
scanf("%lf", &drawTurns);
stepOne = 1 - cardCopies / totalCards;
for (int a = 1; a < initHand; ++a) {
stepOne = stepOne * (1 - (cardCopies / (totalCards - a)));
}
stepTwo = 1 - (cardCopies / (totalCards - initHand));
for (int b = 1; b < cardsMulled; ++b) {
stepTwo = stepTwo * (1 - (cardCopies / (totalCards - initHand - b)));
}
stepThree = 1 - (cardCopies / (totalCards - initHand));
for(int c = 1; c < drawTurns; ++c) {
stepThree = stepThree * (1 - (cardCopies / (totalCards - initHand - c)));
}
if (cardsMulled == 0 && drawTurns == 0) {
probTotal = stepOne;
} else if (drawTurns == 0) {
probTotal = stepOne * stepTwo;
} else if (cardsMulled == 0) {
probTotal = stepOne * stepThree;
} else {
probTotal = stepOne * stepTwo * stepThree;
}
printf("The probability of drawing at least one of the cards by turn %.lf given you mulliganed %.lf cards is %.2lf\n", drawTurns, cardsMulled, 1-probTotal);
return 0;
}