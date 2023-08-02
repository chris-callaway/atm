//
//  main.c
//  atm
//
//  Created by Chris on 12/13/15.
//  Copyright (c) 2015 Chris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int initMenu();
void getCardBack();
int numPlaces();
int rand();
void withdrawl();
void deposit();
void getBalance();
void startMenu();
void fastCash();
void closingMenu();
void clrscr();

int main(int tries) {
    // insert code here...
    int balance = rand() % 5000;
    int pin;
    int receipt;
    printf("Please enter a pin.\n");
    scanf("%d", &pin);
    if (tries < 3){
        if (numPlaces(pin) == 4){
            printf("Receipt (1 for YES and 2 for NO)\n");
            scanf("%d", &receipt);
            startMenu(balance, receipt);
        } else{
            printf("Invalid pin, try again.\n");
            main(++tries);
        }
    } else{
        printf("Sorry you can't continue, contact your bank for assistance!\n");
    }

    return 0;
}

void getCardBack(int receipt){
    if (receipt){
        printf("Please take your receipt.\n\n");
    }
    printf("Thank you for using virtual bank system goodbye!\n");
    exit;
}

void startMenu(int balance, int receipt){
    int selection = initMenu();
    int cashOut;
    switch (selection){
        case 0:
            break;
        case 1:
            getCardBack(receipt);
            break;
        case 2:
            fastCash(balance, receipt);
            break;
        case 3:
            withdrawl(balance, receipt);
            break;
        case 4:
            deposit(balance, receipt);
            break;
        case 5:
            getBalance(balance, receipt);
            break;
    }
}

void closingMenu(int balance, int receipt){
    clrscr();
    int selection;
    printf("Your balance is %d\n\n", balance);
    printf("1 --> Another Transaction          Get Card Back <-- 2\n");
    scanf("%d", &selection);
    switch (selection){
        case 1:
            startMenu(balance, receipt);
            break;
        case 2:
            getCardBack(receipt);
            break;
    }
}

void fastCash(int balance, int receipt){
    clrscr();
    int selection;
    int cashOut = 0;
    printf("Press:\n");
    printf("1 --> $20.00          $40.00 <-- 2\n");
    printf("3 --> $80.00          $100.00 <-- 4\n");
    scanf("%d", &selection);
    switch (selection){
        case 1:
            cashOut = 20;
            break;
        case 2:
            cashOut = 40;
            break;
        case 3:
            cashOut = 80;
            break;
        case 4:
            cashOut = 100;
            break;
        default:
            cashOut = 0;
    }
    if (balance >= cashOut){
        balance = balance - cashOut;
        printf("Take your cash\n");
        closingMenu(balance, receipt);
    }
    else{
        printf("Sorry not enough balance\n");
        startMenu(balance, receipt);
    }
}

void withdrawl(int balance, int receipt){
    clrscr();
    int cashOut = 0;
    printf("Enter amount (enter 0 to cancel): ");
    scanf("%d", &cashOut);
    if (cashOut == 0){
        startMenu(balance, receipt);
    } else{
        if (balance >= cashOut){
            balance = balance - cashOut;
            printf("Take your cash\n");
            closingMenu(balance, receipt);
        }
        else{
            printf("Sorry not enough balance\n");
            startMenu(balance, receipt);
        }
    }
}

void deposit(int balance, int receipt){
    clrscr();
    int cashIn = 0;
    printf("Enter amount (enter 0 to cancel): ");
    scanf("%d", &cashIn);
    if (cashIn == 0){
        startMenu(balance, receipt);
    } else{
        balance = balance + cashIn;
        closingMenu(balance, receipt);
    }
}

void getBalance(int balance, int receipt){
    closingMenu(balance, receipt);
}

int initMenu(){
    clrscr();
    int selection;
    printf("Please select from the following menu:\n");
    printf("1: Get Card Back\n");
    printf("2: Fast Cash\n");
    printf("3: Withdraw\n");
    printf("4: Deposit\n");
    printf("5: Balance\n");
    scanf("%d", &selection);
    if (selection <= 5 && selection > 0){
        return selection;
    } else{
        printf("Invalid selection, please try again.\n");
        initMenu();
        return 0;
    }
}

int numPlaces (int n) {
    if (n == 0) return 1;
    return floor (log10 (abs (n))) + 1;
}

void clrscr() {
    system("clear");
}
