#include <stdio.h>

//Try this out at https://repl.it/@mikeremerscheid/ATMSimulator#main.c

/* 1. Prompt for PIN 
   2. If pin is correct: 
   3. Display Options. 
      1. Balance Inquiry: Display balance
      2. Withdraw: Prompt amount, check available balance, debit amount, show balance
      3. Deposit: Prompt amount, show total balance after deposit
      4. Exit*/
int ATM_Transaction(); //Prototype of the functions
int showBalance();
int withdrawCash();
int depositCash();
int promptAgain();
int anotherTransaction, amountToWithdraw, amountToDeposit, pin; //Global variable
double balance = 1000; //Global variable, initial balance to be 1000 for everyone
int main(void) {
  
  printf("\n********* Welcome to the XYZ bank *********** \n");
  printf("\nEnter your PIN please:   " );
    scanf("%d", &pin);
  if (pin != 1234){
    printf("Wrong PIN. Please try again with the card.\n");
    main();
  }else{
    ATM_Transaction();
  }

  return 0;
}

int ATM_Transaction(){
  printf("\nWhat would you like to do?\n");
  printf("\n1. Balance Inquiry \n2. Withdraw Cash \n3. Deposit Cash \n4. Exit\n");
  int choice; 
  scanf("%d",&choice);
  switch (choice){
    case 1: showBalance();
    ATM_Transaction();
    break;
    case 2: withdrawCash();
    ATM_Transaction();
    break;
    case 3: depositCash();
    ATM_Transaction();
    break;
    default: 
    break;
  }
  printf("\nThank you. See you again.\n\n");
  return 0;
}

int showBalance(){
  printf("\nYour balance is $%.2f\n", balance);
  ATM_Transaction();
  return 0;

}

int withdrawCash(){
  printf("\nHow much would you like to withdraw?\n");
  float amount;
  scanf("%f", &amount);
  if (balance -amount > 0){
    balance = balance - amount;
    printf("Withdrawn $%.2f", amount);
  }else{
    printf("\nThat exceeds your current balance.\n");
  }
  showBalance();
  ATM_Transaction();
  return 0;
}

int depositCash(){
  printf("\nHow much would you like to deposit?\n");
  float amount;
  // scanf("%d", &days);
  // printf("%d", days);
  scanf(" %f",&amount);
  printf("\nDeposited $%.2f\n", amount);
  balance = balance + amount;
  showBalance();
  ATM_Transaction();
  return 0;
}