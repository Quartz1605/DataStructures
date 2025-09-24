#include<stdio.h>
#include<stdlib.h>


//Node Structure
typedef struct Node{

  int data;
  struct Node* next;

}Node;

Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Node* push(Node* top,int data){
  
  Node* newNode = createNode(data);
  newNode->next = top;
  top = newNode;
  printf("Successfully pushed %d into the node\n",data);

  return top;

}

int isEmpty(Node* top){
  return top->next == NULL;
}

Node* pop(Node* top){

  if(isEmpty(top)){
    printf("Stack underflow");
  }else{
    Node* temp = top;
    top = top->next;
    printf("Popped %d from the stack\n",temp->data);
    free(temp);
  }

  return top;

}

void peek(Node* top){
  
  if(isEmpty(top)){
    printf("");
  }

  printf("Topmost element of the stack is %d\n",top->data);

}

int main(){

  Node* top = NULL;

  top = push(top,4);
  top = push(top,3);
  top = push(top,6);

  peek(top);

  top = pop(top);
  top = pop(top);

  peek(top);


  return 0;
}