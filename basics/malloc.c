#include<stdio.h>
#include<stdlib.h>


int* createArray(int n){

  int *arr = (int*)malloc(sizeof(int)*n);

  return arr;


}

int main(){

  int n;
  printf("Enter the number of elements for the array\n");
  scanf("%d",&n);

  int *arr = (int *)malloc(sizeof(int)*n);

  printf("Enter the values for the arr \n");
  for(int i=0;i<n;i++){
    scanf("%d",arr+i);
  }

  for(int i=0;i<n;i++){
    printf("%d\t",*(arr+i));
  }

  free(arr);
}