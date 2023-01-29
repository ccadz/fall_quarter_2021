#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Temperature Functions

double SameInputs(double tempInput) {
return tempInput;
}
double Fahrenheit2Celsius(double tempInput) {
return (tempInput - 32) * 5 / 9;
}
double Fahrenheit2Kelvin(double tempInput) {
return (tempInput - 32) * 5 / 9 + 273.15;
}
double Celsius2Fahrenheit(double tempInput) {
return (tempInput * 9 / 5) + 32;
}
double Celsius2Kelvin(double tempInput) {
return tempInput + 273.15;
}
double Kelvin2Fahrenheit(double tempInput) {
return (tempInput - 273.15) * 9 / 5 + 32;
}
double Kelvin2Celsius(double tempInput) {
return tempInput - 273.15;
}

//Distance Functions

double Inches2Feet(double tempInput) {
return tempInput/12;
}
double Inches2Yards(double tempInput) {
return tempInput/36;
}
double Inches2Miles(double tempInput) {
return tempInput/63360;
}
double Feet2Inches(double tempInput) {
return tempInput*12;
}
double Feet2Yards(double tempInput) {
return tempInput/3;
}
double Feet2Miles(double tempInput) {
return tempInput/5280;
}
double Yards2Inches(double tempInput) {
return tempInput*36;
}
double Yards2Feet(double tempInput) {
return tempInput*3;
}
double Yards2Miles(double tempInput) {
return tempInput/1760;
}
double Miles2Inches(double tempInput) {
return tempInput*63360;
}
double Miles2Feet(double tempInput) {
return tempInput*5280;
}
double Miles2Yards(double tempInput) {
return tempInput*1760;
}

int main() {
char conType;
double tempInput;
char suffOne;
char suffTwo;
double convertedOutput;


printf("Pick the type of conversion that you would like to do.\n");
printf("T or t for temperature\n" );
printf("D or d for distance\n" );
printf("Enter your choice: " );
scanf("%c", &conType);

if (conType == 't' || conType == 'T') {
printf("Enter the temperature followed by its suffix (F, C, or K): ");
scanf("%lf %c", &tempInput, &suffOne);
if (!(suffOne == 'f' || suffOne == 'F' || suffOne == 'c' || suffOne == 'C' || suffOne == 'k' || suffOne == 'K')) {
printf("%c is not a valid temperature type. Ending program.\n", suffOne);
} else {
printf("Enter the new unit type (F, C, or K): ");
scanf(" %c", &suffTwo);

if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfF is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'c' || suffTwo == 'C')) {
convertedOutput = Fahrenheit2Celsius(tempInput);
printf("%.2lfF is %.2lfC", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'k' || suffTwo == 'K')) {
convertedOutput = Fahrenheit2Kelvin(tempInput);
printf("%.2lfF is %.2lfK", tempInput, convertedOutput);
} else if ((suffOne == 'c' || suffOne == 'C') && (suffTwo == 'f' || suffTwo == 'F')) {
convertedOutput = Celsius2Fahrenheit(tempInput);
printf("%.2lfC is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'c' || suffOne == 'C') && (suffTwo == 'c' || suffTwo == 'C')) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfC is %.2lfC", tempInput, convertedOutput);
} else if ((suffOne == 'c' || suffOne == 'C') && (suffTwo == 'k' || suffTwo == 'K')) {
convertedOutput = Celsius2Kelvin(tempInput);
printf("%.2lfC is %.2lfK", tempInput, convertedOutput);
} else if ((suffOne == 'k' || suffOne == 'K') && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = Kelvin2Fahrenheit(tempInput);
printf("%.2lfK is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'k' || suffOne == 'K') && (suffTwo == 'c' || suffTwo == 'C')) {
convertedOutput = Kelvin2Celsius(tempInput);
printf("%.2lfK is %.2lfC", tempInput, convertedOutput);
} else if ((suffOne == 'k' || suffOne == 'K') && (suffTwo == 'k' || suffTwo == 'K')) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfK is %.2lfK", tempInput, convertedOutput);
} else {
printf("%c is not a valid temperature type. Ending program.\n", suffTwo);
}
}
} else if (conType == 'd' || conType == 'D') {

printf("Enter the distance followed by its suffix (I,F,Y,M): ");
scanf("%lf %c", &tempInput, &suffOne);
if (!(suffOne == 'i' || suffOne == 'I' || suffOne == 'f' || suffOne == 'F' || suffOne == 'y' || suffOne == 'Y' || suffOne == 'm' || suffOne == 'M')) {
printf("%c is not a valid distance type. Ending program.\n", suffOne);
} else {
printf("Enter the new unit type (I,F,Y,M): ");
scanf(" %c", &suffTwo);


if ((suffOne == 'i' || suffOne == 'I') && (suffTwo == 'i' || suffTwo == 'I')) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfI is %.2lfI", tempInput, convertedOutput);
} else if ((suffOne == 'i' || suffOne == 'I') && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = Inches2Feet(tempInput);
printf("%.2lfI is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'i' || suffOne == 'I') && (suffTwo == 'y' || suffTwo == 'Y')) {
convertedOutput = Inches2Yards(tempInput);
printf("%.2lfI is %.2lfY", tempInput, convertedOutput);
} else if ((suffOne == 'i' || suffOne == 'I') && (suffTwo == 'm' || suffTwo == 'M')) {
convertedOutput = Inches2Miles(tempInput);
printf("%.2lfI is %.2lfM", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'i' || suffTwo == 'I')){
convertedOutput = Feet2Inches(tempInput);
printf("%.2lfF is %.2lfI", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'y' || suffTwo == 'Y')) {
convertedOutput = Feet2Yards(tempInput);
printf("%.2lfF is %.2lfY", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfF is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'f' || suffOne == 'F' ) && (suffTwo == 'm' || suffTwo == 'M')) {
convertedOutput = Feet2Miles(tempInput);
printf("%.2lfF is %.2lfM", tempInput, convertedOutput);
} else if ((suffOne == 'y' || suffOne == 'Y') && (suffTwo == 'i' || suffTwo == 'I')) {
convertedOutput = Yards2Inches(tempInput);
printf("%.2lfY is %.2lfI", tempInput, convertedOutput);
} else if ((suffOne == 'y' || suffOne == 'Y') && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = Yards2Feet(tempInput);
printf("%.2lfY is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'y' || suffOne == 'Y') && (suffTwo == 'm' || suffTwo == 'M')) {
convertedOutput = Yards2Miles(tempInput);
printf("%.2lfY is %.2lfM", tempInput, convertedOutput);
} else if ((suffOne == 'y' || suffOne == 'Y') && (suffTwo == 'y' || suffTwo == 'Y')) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfY is %.2lfY", tempInput, convertedOutput);
} else if ((suffOne == 'm' || suffOne == 'M') && (suffTwo == 'i' || suffTwo == 'I')) {
convertedOutput = Miles2Inches(tempInput);
printf("%.2lfM is %.2lfI", tempInput, convertedOutput);
} else if ((suffOne == 'm' || suffOne == 'M') && (suffTwo == 'f' || suffTwo == 'F' )) {
convertedOutput = Miles2Feet(tempInput);
printf("%.2lfM is %.2lfF", tempInput, convertedOutput);
} else if ((suffOne == 'm' || suffOne == 'M') && (suffTwo == 'y' || suffTwo == 'Y')) {
convertedOutput = Miles2Yards(tempInput);
printf("%.2lfM is %.2lfY", tempInput, convertedOutput);
} else if ((suffOne == 'm' || suffOne == 'M') && (suffTwo == 'm' || suffTwo == 'M')) {
convertedOutput = SameInputs(tempInput);
printf("%.2lfM is %.2lfM", tempInput, convertedOutput);
} else {
printf("%c is not a valid distance type. Ending program.\n", suffTwo);
}
}
} else {
printf("Unknown conversion type %c chosen. Ending program.\n", conType);
}
}