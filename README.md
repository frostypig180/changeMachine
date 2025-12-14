# Eli's Change Machine
Author: Eli Gruhlke\
Last Modified: 12/14/2025\
Development Environment: C99, VSCode, Windows 11\
Description:\
    - A program that calculates change after given a starting dollar value\
    - For example: given $11, the program would result in 1 one dollar bill and 1 ten dollar bill\
    - Make use of all common USD$ denominations\
    - Calculate change using the minimum number of bills and coins necessary\
    - Assume infinite amounts of each denomination in change machine

## How to use
Note: Operate within Terminal or Command Prompt
1. Compile C code in terminal (gcc, clang, etc.)
2. Run .exe file 
`./changeMachine`
3. When prompted, enter monetary value with no commas (ex. 2901.51)
4. Calculated change will be displayed
5. You will be prompted again
6. To exit, enter 0 into the user input

## Sample Output
```
> System: Welcome to Eli's Change Machine! To quit, enter 0 into user input.
> System: Enter cash value (no commas).
> User: $2901.51
[29] Hundreds
[1] Ones
[1] Half-Dollars
[1] Pennies
> System: Cha-ching! Your change is ready!

> System: Enter cash value (no commas).
> User: $
```


