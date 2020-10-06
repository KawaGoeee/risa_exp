#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countEven(int* intArray, unsigned int n);

int main() {

  int intArray[8] = {2, 4, 6, 1, 7, 8, 5, 3};
  int numberOfEven = countEven(intArray, 8);

  printf("The number of even numbers in the int array is: %d\n", numberOfEven);
  // The number of even numbers in the int array is: 4
  return 0;
}

int countEven(int* intArray, unsigned int n) {
  return 0;
}
