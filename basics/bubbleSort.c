#include<stdio.h>


int main(){

  int arr[6];

  printf("Enter your elements for the array\n");
  for(int i=0;i<6;i++){
    scanf("%d",&arr[i]);
  }

  int temp;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<6-i-1;j++){
      if(arr[j]>arr[j+1]){

        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("The sorted array is \n");
  for(int i=0;i<6;i++){
    printf("%d\t",arr[i]);
  }

}