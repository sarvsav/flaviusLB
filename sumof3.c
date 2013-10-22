/**
 * The program must calculate the sum of n numbers, you don't
 * know how big n is, but it's >=3.
 *
 * The stop condition is that the last entered number is the
 * sum of the previous two numbers.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Function to clear input stream.
 */
//where is this used?
//and while we're at it: make it a preprocessor function macro - I want
//it for the sole purpose of making you think of gimmicks you can accomplish
//with the preprocessor
void ClearInputStream() {

  char garbage;   //garbage collector of input stream
  while((garbage = getchar()) != '\n' && garbage != EOF); //clearing stream
}

/**
 * Function to check & validate user input
 */
int InputInteger() {

  int number;
  int check = 1;
  char *myInteger;
  char value[10];
  while(check) {
    myInteger = fgets(value, 10, stdin);
    if(isdigit(myInteger[0])) {
      number = atoi(myInteger);
      check = 0;
    }
  }

  return number;

}

/**
 * Function to calculate the sum of all the integers
 * and checks for the stopping condition.
 */
int sum_calculator() {

  int prev = 0;
  int next = 0;
  int sum = 0;
  int temp = 0;
  int condition = 1;
  int count = 1;
  prev = InputInteger();
  next = InputInteger();
  sum = prev + next;
  while(condition) {
    temp = prev + next;
    prev = next;
    next = InputInteger();
    sum = sum + next;
    if(temp == next) {
      condition = 0;
    }
  }

  return sum;
}

int main(int argc,
         char *argv[]) {

  int sum = 0;
  sum = sum_calculator();
  printf("Sum is %d", sum);
  return EXIT_SUCCESS;
}

