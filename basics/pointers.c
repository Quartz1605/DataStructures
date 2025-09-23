#include<stdio.h>

int sum_of_arr(int *p,int *n){

  int sum = 0;

  for(int i=0;i<*n;i++){
    sum += *(p+i);
  }

  return sum;
  
  
}


int main(){

  int arr[4] = {1,2,3,16};

  
  int n = 4;

  int sum = sum_of_arr(&arr[0],&n);

  printf("The sum of the array is %d",sum);

}