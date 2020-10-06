#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char* str_compute_sum(const char* num1, const char* num2);

int main() {

  // test1---------------------
  char* str2 = "1";
  char* str1 = "1999";
  // output == "2000"


  // test2---------------------
  // char* str1 = "123530124";
  // char* str2 = "981252430004";
  // output == "981375960128"


  char* sum = str_compute_sum(str1, str2);

  for(int i=0; i<5; i++) {
    printf("%c", sum[i]);
  }
  printf("\n");

  if (sum && strcmp(sum, "2000") == 0)  { // checks sum != NULL and the value is correct
    printf("Q5-2 ok\n");
    free(sum);
  }
  else  {
    printf("Q5-2 ERROR\n");
    free(sum);
  }

  return 0;
}


// num1 + num2 = sum
char* str_compute_sum(const char* num1, const char* num2) {

  int index1=0, index2=0, addup=0;
  int len, len1, len2, lenBigger, lenSmaller;

  char* sum;

  // count the length of array1
  while(*(num1+index1) != '\0') {
    index1++;
  }
  len1 = index1+1;

  // count the length of array2
  while(*(num2+index2) != '\0') {
    index2++;
  }
  len2 = index2+1;

  // set variables for bigger array and smaller array
  if(len1>=len2) {
    lenBigger = len1;
    lenSmaller = len2;
  }else {
    lenBigger = len2;
    lenSmaller = len1;
  }


  // reserve memory enough for array of length bigger array
  len=lenBigger+1;
  sum = malloc(sizeof(char)*len);
  *sum = '0';
  *(sum+len-1) = '\0';
  char intBigger, intSmaller;
  char elementSum;


  // add elements starting from end of both arrays
  for(int i=0; i<len-1; i++) {

    if(i==len-2) {
      if(addup==1) {
        *sum = '1';
      }else {
        *sum = '0';
      }
      // printf("*sum = %c\n", *sum);

    }else if(i>=lenSmaller-1) {

      if(len1>=len2) {
        intBigger = *( num1+(lenBigger-2)-i);
      }else {
        intBigger = *( num2+(lenBigger-2)-i);
      }
      intSmaller = '0' - 48;
      // printf("[%d] %c+%d  +%d\n", len-2-i, intBigger, intSmaller, addup);


      elementSum = intBigger + intSmaller + addup;
      // printf("elementSum:%d\n", elementSum);

      if(elementSum>'9') {
        *( sum+(len-2)-(i) ) = elementSum - 10;
        addup=1;
      }else {
        *( sum+(len-2)-(i) ) = elementSum;
        addup=0;
      }

    }else {
      if(len1>=len2) {
        intBigger = *( num1+(lenBigger-2)-i);
        intSmaller = *(num2+(lenSmaller-2)-i) - 48;
      }else {
        intBigger = *( num2+(lenBigger-2)-i);
        intSmaller = *(num1+(lenSmaller-2)-i) - 48;
      }
      // printf("[%d] %c+%d  +%d\n", len-2-i, intBigger, intSmaller, addup);


      elementSum = intBigger + intSmaller + addup;
      // printf("elementSum:%d\n", elementSum);

      if(elementSum>'9') {
        *( sum+(len-2)-i ) = elementSum - 10;
        addup=1;
      }else {
        *( sum+(len-2)-i ) = elementSum;
        addup=0;
      }
      
    }
  }
  
  
  // if 0 remains in first element, shift element
  if(*sum=='0') {
    for(int i=0; i<len-1; i++) {
      sum[i] = sum[i+1];
    }
    sum = realloc(sum, sizeof(char) * (len-1));
  }

  return sum;
}
