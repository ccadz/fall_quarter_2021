#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>   
#include <stdlib.h>   
#include <time.h>   
#include <string.h>
int main() {
char word1[20];
char word2[20];
printf("Please enter the first word: ");
scanf("%s", word1);
printf("Please enter the second word: ");
scanf("%s", word2);
char copyOne[20];
strcpy(copyOne, word1);
char copyTwo[20];
strcpy(copyTwo, word2);
int length1 = strlen(word1);
int length2 = strlen(word2);
if (length1 != length2) {
printf("%s is NOT an anagram of %s", copyOne, copyTwo);
return 0;
}
for (int z = 0; z < length1; ++z) {
word1[z] = tolower(word1[z]);
}
for (int y = 0; y < length1; ++y) {
word2[y] = tolower(word2[y]);
}
char switcher;
for (int a = 0; a < length1; ++a) {
for (int b = 0; b < length1; ++b) {
if(word1[a] < word1[b]) {
switcher = word1[a];
word1[a] = word1[b];
word1[b] = switcher;
}
}
}
for (int c = 0; c < length1; ++c) {
for (int d = 0; d < length1; ++d) {
if(word2[c] < word2[d]) {
switcher = word2[c];
word2[c] = word2[d];
word2[d] = switcher;
}
}
}
for (int e = 0; e < length1; ++e) {
if (word1[e] != word2[e]) {
printf("%s is NOT an anagram of %s", copyOne, copyTwo);
return 0;
}
}
printf("%s is an anagram of %s", copyOne, copyTwo);
return 0;
}