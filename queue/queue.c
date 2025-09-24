#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{

  int top;
  int *arr;
  int capacity;

}Stack;


Stack* createStack(int capacity){

  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (int *)malloc(sizeof(int)*capacity);

  return stack;

}

void push(Stack *stack,int num){

  if(stack->top == stack->capacity-1){
    printf("Stack Overflow\n");
    return;
  }else{
    stack->arr[++stack->top] = num;
    printf("Pushed %d intop the stack.\n",num);
  }

}

void pop(Stack *stack){
  if(stack->top == -1){
    printf("Stack Underflow\n");
    return;
  }else{
    printf("Popped %d from the stack\n",stack->arr[stack->top]);
    stack->top--;
  }
}

void peek(Stack *stack){
  if(stack->top == -1){
    printf("Stack empty");
  }else{
    printf("Element at the top of the stack is %d\n",stack->arr[stack->top]);
  }
}

void freeMemory(Stack* stack){
  free(stack->arr);
  free(stack);
}

int main(){

  printf("Welcome to the stack simulator\n");
  Stack *stack = createStack(5);
  push(stack,5);
  push(stack,4);
  peek(stack);
  push(stack,2);
  pop(stack);
  peek(stack);
  

}




