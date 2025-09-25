#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

  int data;
  struct Node* prev;
  struct Node* next;

}Node;

Node* createNode(int data){

  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;

}

Node* insertAtEnd(Node* top,int data){

  
  if(!top){
    Node* newNode = createNode(data);
    return newNode;
  }else{

    Node* newNode = createNode(data);
    Node* temp = top;

    while(temp->next){
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;


    return top;
  }

}

Node* mergeTwoSortedLL(Node* first,Node* second){

  
  
  if(!first) return second;
  if(!second) return first;

  
  if(first->data <= second->data){
    first->next = mergeTwoSortedLL(first->next,second);

    if(first->next){
      first->next->prev = first;
    }

    first->prev = NULL;
    return first;
  
  }else{

    second->next = mergeTwoSortedLL(first,second->next);

    if(second->next){
      second->next->prev = second;
    }

    second->prev = NULL;
    return second;

  }

}

void displayLL(Node* head){

  

  Node* temp  = head;
  
  while(temp){
    
    printf("%d <-> ",temp->data);
    temp = temp->next;
  }

  printf("NULL\n");

}

int main(){

  Node* list1 = NULL;
  Node* list2 = NULL;
  Node* sorted_ll;

  list1 = insertAtEnd(list1,2);
  list1 = insertAtEnd(list1,9);
  list1 = insertAtEnd(list1,11);

  list2 = insertAtEnd(list2,5);
  list2 = insertAtEnd(list2,7);
  list2 = insertAtEnd(list2,9);

 
  sorted_ll = mergeTwoSortedLL(list1,list2);
  

  displayLL(sorted_ll);

}