#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
/*
Eli's Change Machine
Author: Eli Gruhlke
Last Modified: 12/14/2025
Development Environment: C99, VSCode, Windows 11
Description: 
    - A program that calculates change after given a starting dollar value
    - For example: given $11, the program would result in 1 one dollar bill and 1 ten dollar bill.
    - Make use of all common USD$ denominations
    - Calculate change using the minimum number of bills and coins necessary
    - Assume infinite amounts of each denomination in change machine
*/
// prototypes
int calculate(double dCashIn, int iDivisor);
// main
void main(){
    // local variables
    double  dCashIn;
    char    sChange[2048] = "";
    char    sToAppend[128] = "";
    char    sInput[128];
    char*   pchEnd;
    char*   asNames[] = {"Hundreds", "Fifties", "Twenties", "Tens", 
                        "Fives", "Ones", "Half-Dollars", "Quarters",
                        "Dimes", "Nickels", "Pennies"};
    int     aiValues[] = {10000, 5000, 2000, 1000, 
                            500, 100, 50, 25, 10, 5, 1};
    int     iLength = sizeof(aiValues) / sizeof(aiValues[0]);
    int     iResult = 0;
    // begin
    printf("> System: Welcome to Eli's Change Machine! To quit, enter 0 into user input.\n");
    while(1){
        sChange[0] = '\0';
        dCashIn = 0;
        errno = 0;
        printf("> System: Enter cash value (no commas).\n");
        printf("> User: $");
        if(fgets(sInput, sizeof(sInput), stdin) != NULL){
            if(strstr(sInput, " ") || strstr(sInput, ",")){
                printf("> System: Invalid input. Please enter exactly ONE monetary value (Ex. 2101.67). Quitting.\n");
                return;   
            }
            dCashIn = strtod(sInput, &pchEnd);
            if(errno == ERANGE){
                printf("> System: Error! ERANGE. Quitting.");
                return;
            }
            else if(pchEnd == sInput){
                printf("> System: Invalid input, no valid input found. Quitting.");
                return;
            }
            else if(dCashIn == 0){
                printf("> System: Goodbye.\n");
                return;
            }
            else if(dCashIn < 0){
                printf("> System: Error! Input cannot be negative. Quitting.\n");
                return;
            }
            else{
                dCashIn *= 100;   
            }
             
        }
        else{
            printf("> System: Invalid input. Please enter exactly ONE monetary value (Ex. 101.67). Quitting.\n");
            return;
        }
        for(int i = 0; i < iLength; i++){
            int iValue = aiValues[i];
            if(dCashIn >= iValue){
                char* sName = asNames[i];
                iResult = calculate(dCashIn, iValue);
                dCashIn = (double) (dCashIn - (iValue*iResult));
                sprintf(sToAppend, "[%d] %s\n", iResult, sName);
                strcat(sChange, sToAppend);
            } 
        }
        printf(sChange);
        printf("> System: Cha-ching! Your change is ready!\n\n");
    }
}
// calculate
int calculate(double dCashIn, int iDivisor){
    int iResult = (int) floor(dCashIn/(double) iDivisor);
    if(iResult >= 1){
        return iResult;
    }
    else{
        return 0;
    }
}

