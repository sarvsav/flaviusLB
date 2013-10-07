/*
** Program to calculate sum of 3 numbers,
** iff sum of first 2 is equal to third.
*/
#include "sumof3.h"

/* Function to check and validate the user input */
int InputInteger(int count) {

  int number = 0;
  char garbage;
  while(1) {
    printf("Enter %d integer",count);
    if(scanf("%d",&number) != 0 && count != 0) {
      break;
    }
    else {
      while((garbage = getchar()) != '\n' && garbage != EOF)
        ;                   /* clearing input stream */
      printf("Please enter a valid integer\n");
    }
  }
  return number;
}

int main(int argc,
         char *argv[]) {

  int sum = 0;
  int i;
  int noOfIntegers = 2;    /*
                           ** (total integers -1), as we calculate the last by
                           ** adding previous numbers
                           */
  int count = 1;
  while(count) {
    for(i=0;i<noOfIntegers;i++) {
      sum += InputInteger(count);
      count++;
    }
    if(sum == InputInteger(count)) {
      count = 0;
    }
    else {
      printf("Last number must be sum of previous integers\n");
      sum = 0;
      count = 1;
    }
  }
  sum = sum<<1;
  printf("Sum is %d",sum);

  return 0;
}
