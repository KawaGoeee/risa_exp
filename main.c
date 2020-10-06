#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countEven(int* intArray, unsigned int n);

int main() {

  // int intArray[8] = {2, 4, 6, 1, 7, 5, 5, 2};
  int intArray[1] = {1};
  int numberOfEven = countEven(intArray, 1);

  printf("The number of even numbers in the int array is: %d\n", numberOfEven);
  // The number of even numbers in the int array is: 4
  return 0;
}

int countEven(int* intArray, unsigned int n) {
  int count=0;

  // increment count if number *(intArray+i) is even
  for(int i=0; i<n; i++) {
    if(*(intArray+i) % 2 == 0) {
      count++;
    }
  }
  return count;
}
