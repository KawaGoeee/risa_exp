#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char* str_compute_sum(const char* num1, const char* num2);

int main() {

  // char* str2 = "1";
  // char* str1 = "1999";
  char* str1 = "123530124";
  char* str2 = "981252430004";
  char* sum = str_compute_sum(str1, str2);

  for(int i=0; i<12; i++) {
    printf("%c", sum[i]);
  }
  printf("\n");

  if (sum && strcmp(sum, "981375960128") == 0)  { // checks sum != NULL and the value is correct
    printf("Q5-2 ok\n");
    free(sum);
    // sum=NULL;
    return true;
  }
  else  {
    printf("Q5-2 ERROR\n");
    free(sum);
    return false;
  }

  return 0;
}


// num1 + num2 = num3
char* str_compute_sum(const char* num1, const char* num2) {
  int index1=0, index2=0;
  int len, len1, len2;
  int pos1=1, pos2=1;
  int addup=0;

  char* num3;

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


  if(len1>=len2) {
    // reserve memory enough for array of length longer than bigger num
    len=len1+1;
    num3 = malloc(sizeof(char)*len);
    *num3 = '0';
    *(num3+len-1) = '\0';
    char int1, int2;

    // add elements starting from end of both arrays
    for(int i=0; i<len-1; i++) {
      char sum;

      if(i==len-2) {
        if(addup==1) {
          sum = '1';
          *num3 = sum;
        }else {
          sum = '0';
          *num3 = sum;
        }
        // printf("*num3 = %c\n", *num3);

      }else if(i>=len2-1) {

        int1 = *( num1+(len1-2)-i);
        int2 = '0' - 48;
        // printf("[%d] %c+%d  +%d\n", len-2-i, int1, int2, addup);

        // if(addup==1) {
        sum = int1 + int2 + addup;
        // }else {
        //   sum = int1 + int2;
        // }

        // printf("sum:%d\n", sum);

        if(sum>'9') {
          *( num3+(len-2)-(i) ) = sum - 10;
          addup=1;

        }else {
          *( num3+(len-2)-(i) ) = sum;
          addup=0;
          
        }
      }else {
        int1 = *( num1+(len1-2)-i);
        int2 = *(num2+(len2-2)-i) - 48;
        // printf("[%d] %c+%d  +%d\n", len-2-i, int1, int2, addup);

        sum = int1 + int2 + addup;
        // printf("sum:%d\n", sum);

        if(sum>'9') {
          *( num3+(len-2)-i ) = sum - 10;
          addup=1;
        }else {
          *( num3+(len-2)-i ) = sum;
          addup=0;
        }
        
      }
    }

  }else {
    // reserve memory enough for array of length longer than bigger num
    len=len2+1;
    num3 = malloc(sizeof(char)*len);
    *num3 = '0';
    *(num3+len-1) = '\0';
    char int1, int2;

    // add elements starting from end of both arrays
    for(int i=0; i<len-1; i++) {
      char sum;

      if(i==len-2) {
        if(addup==1) {
          sum = '1';
          *num3 = sum;
        }else {
          sum = '0';
          *num3 = sum;
        }
        // printf("*num3 = %c\n", *num3);

      }else if(i>=len1-1) {

        int1 = '0' - 48;
        int2 = *( num2+(len2-2)-i);
        // printf("[%d] %c+%d  +%d\n", len-2-i, int1, int2, addup);

        // if(addup==1) {
        sum = int1 + int2 + addup;
        // }else {
        //   sum = int1 + int2;
        // }

        // printf("sum:%d\n", sum);

        if(sum>'9') {
          *( num3+(len-2)-(i) ) = sum - 10;
          addup=1;

        }else {
          *( num3+(len-2)-(i) ) = sum;
          addup=0;
          
        }
      }else {
        int1 = *( num1+(len1-2)-i) - 48;
        int2 = *(num2+(len2-2)-i);
        // printf("[%d] %c+%d  +%d\n", len-2-i, int1, int2, addup);

        sum = int1 + int2 + addup;
        // printf("sum:%d\n", sum);

        if(sum>'9') {
          *( num3+(len-2)-i ) = sum - 10;
          addup=1;
        }else {
          *( num3+(len-2)-i ) = sum;
          addup=0;
        }
        
      }
    }
  }
  
  // if addup=0 at the end and 0 remains in first element, shift pointer
  if(*num3=='0') {
    num3++;
  }
  return num3;
}
