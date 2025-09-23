#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX];
int top = -1;


void push(int num){

  if(top == MAX-1){
    printf("Stack Overflow\n");
    return;
  }else{
    arr[++top] = num;
    printf("Pushed %d into the stack \n",num);
    return;
  }

}

void pop(){

  if(top == -1){
    printf("Stack Underflow\n");
    return;
  }else{
    printf("Popped %d from the stack \n",arr[top]);
    top--;
  }

}

void peek(){
  if(top == -1){
    printf("Stack Empty");
  }else{
    printf("The topmost element of stack is %d \n",arr[top]);
  }
}

int main(){

  printf("Welcome to the stack operator \n");

  push(10);
  peek();
  push(20);
  push(30);
  peek();
  pop();
  pop();
  peek();



  return 0;
}