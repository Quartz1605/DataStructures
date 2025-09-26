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

// Function to insert node at the end

Node* insertNode(Node* head,int data){

  Node* newNode = createNode(data);

  if(!head) return newNode;

  Node* temp = head;
  while(temp->next){
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;

  return head;

}

Node* mergeSortedLL(Node* first,Node* second){

  if(!first) return second;
  if(!second) return first;

  if(first->data <= second->data){
    first->next = mergeSortedLL(first->next,second);

    if(first->next){
      first->next->prev = first;
    }

    first->prev = NULL;
    return first;
  
  }else{
    
    second->next = mergeSortedLL(first,second->next);

    if(second->next){
      second->next->prev = second;
    }

    second->prev = NULL;
    return second;
  }

}

void displayMergedLL(Node* head){
  
  Node* temp = head;

  while(temp){
    printf("%d <-> ",temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}

int main(){


  Node* list1 = NULL;
  Node* list2 = NULL;

  list1 = insertNode(list1,1);
  list1 = insertNode(list1,3);
  list1 = insertNode(list1,5);

  list2 = insertNode(list2, 2);
  list2 = insertNode(list2, 4);
  list2 = insertNode(list2, 6);

  Node* sortedList = mergeSortedLL(list1,list2);

  displayMergedLL(sortedList);


}

