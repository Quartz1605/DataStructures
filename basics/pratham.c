#include<stdio.h>

int main(){
  
  int arr[10];
  printf("Enter array elements\n");

  for(int i=0;i<9;i++){
    scanf("%d\n",&arr[i]);
  }

  printf("The elements of the array are \n");
  for(int i=0;i<10;i++){
    printf("%d\t",arr[i]);
  }
  
  

  return 0;

}
