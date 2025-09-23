#include<stdio.h>
#include<stdlib.h>


struct Stack{
  int capacity;
  int *arr;
  int top;
};

struct Stack* createStack(int capacity){

  struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (int *)malloc(sizeof(int)*capacity);

  return stack;

}

void push(struct Stack* stack,int num){

  if(stack->top == stack->capacity-1){
    printf("Stack overflow bitch !\n");
  }else{
    stack->arr[++stack->top] = num;
    printf("Pushed %d successfully into the stack\n",num);
  }

}

void pop(struct Stack* stack){

  if(stack->top == -1){
    printf("Stack underflow !\n");
  }else{
    printf("Popped %d successfully into the stack \n",stack->arr[stack->top]);
    stack->top--;
    
  }
}

void peek(struct Stack* stack){
  if(stack->top == -1){
    printf("Stack is empty");
  }else{
    printf("Topomost element of the stack is %d \n",stack->arr[stack->top]);
  }
}

int main(){

  struct Stack *stack = createStack(5);
  push(stack,5);
  push(stack,6);
  push(stack,7);
  peek(stack);
  pop(stack);
  pop(stack);
  peek(stack);

  return 0;

}