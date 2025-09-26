#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;


Node* createNode(int data){

  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  return node;
}

int isEmpty(Node* top){
  return top->next == NULL;
}

Node* push(Node* top,int data){

  Node* newNode = createNode(data);
  newNode->next = top;
  top = newNode;
  printf("Pushed %d into the stack\n",data);
  
  return top;

}

Node* pop(Node* top){
  
  if(isEmpty(top)){
    printf("Stack Underflow\n");
    return top;
  }

  Node* temp = top;
  printf("Popped %d from the stack\n",top->data);
  top = top->next;
  free(temp);

  return top;
}

void peek(Node* top){
  
  if(isEmpty(top)){
    printf("Stack empty\n");
    return;
  }

  printf("Element at the top of the stack is %d\n",top->data);

}

int main(){

  Node* top = NULL;
  top = push(top,5);
  top = push(top,6);
  top = push(top,7);

  peek(top);

  top = pop(top);
  top = pop(top);

  peek(top);

  
  

}


