#include<stdio.h>
#include<stdlib.h>


//Stack Code

typedef struct Stack{
  int top;
  int *arr;
  int capacity;
}Stack;


//Create stack code

Stack* createStack(int capacity){
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->arr = (int *)malloc(sizeof(int)*capacity);

  return stack;
}

void push(Stack* stack,int num){

  stack->arr[++stack->top] = num;
  
}

int pop(Stack* stack){

  return stack->arr[stack->top--];
}

int peek(Stack* stack){

  return stack->arr[stack->top];

}

int isEmpty(Stack* stack){

  return stack->top == -1;
}

//Queue Code

typedef struct Queue{
  Stack* s1;
  Stack* s2;
}Queue;


Queue* createQueue(){

  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->s1 = createStack(5);
  queue->s2 = createStack(5);

  return queue;

}

void enqueue(Queue* queue,int num){

  push(queue->s1,num);
  printf("Put %d successfully into the queue\n",num);

}

void dequeue(Queue* queue){

  if(isEmpty(queue->s1) && isEmpty(queue->s2)){
    printf("Queue is empty, nothing to dequeue\n");
  }else{

    while(!isEmpty(queue->s1)){
      push(queue->s2,pop(queue->s1));
    };

    int pop_ele = pop(queue->s2);
    printf("Dequeued %d successfully from the queue\n",pop_ele);
    return;

  }
}

void onTop(Queue* queue){
  
  if(isEmpty(queue->s1) && isEmpty(queue->s2)){
    printf("Queue is empty, nothing to dequeue\n");
  }else{

    while(!isEmpty(queue->s1)){
      push(queue->s2,pop(queue->s1));
    };

    int top_ele = peek(queue->s2);
    printf("The frontmost element of the queue is %d\n",top_ele);

  }

}

void freeUpMemory(Queue* queue){
  free(queue);
  free(queue->s1);
  free(queue->s2);
}

int main(){

  Queue* q = createQueue();
  enqueue(q,5);
  enqueue(q,6);
  onTop(q);
  enqueue(q,7);

  

  dequeue(q);
  onTop(q);
  dequeue(q);

}