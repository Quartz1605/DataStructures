#include<stdio.h>


int square(int n){
  return n*n;
}


void main(){

  int n;
  printf("Enter the value to square ?\n");
  scanf("%d",&n);

  int val = square(n);

  printf("The value of squared number is : %d \n",val);

}