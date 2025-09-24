#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int main(){

  int stack[MAX_SIZE];
  char string[MAX_SIZE];
  
  int top = -1;

  printf("Enter the string to reverse\n");
  scanf("%s",&string);

  int n = strlen(string);

  for(int i=0;i<n;i++){
    stack[++top] = string[i];
  }

  for(int i=0;i<n;i++){
    string[i] = stack[top--];
  }
  
  printf("The reversed string is %s",string);

  return 0;

}