#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

typedef struct Stack{
  TreeNode** arr;
  int top;
  int capacity;
}Stack;


Stack* createStack(int capacity){

  Stack* stack = (Stack*)malloc(sizeof(Stack));
  
  stack->top = -1;
  stack->capacity = capacity;
  stack->arr = (TreeNode**)malloc(sizeof(TreeNode*)*capacity);

  return stack;

}

int isEmpty(Stack* stack){
  return stack->top == -1;
}

void push(Stack* stack,TreeNode* node){
  stack->arr[++stack->top] = node;
}

TreeNode* pop(Stack* stack){
  return stack->arr[stack->top--];
}

TreeNode* createNode(int val){

  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->left = NULL;
  node->right = NULL;
  node->val =  val;

  return node;

}

void zigzagTraversal(TreeNode* root){

  
  if(!root) return;

  

  Stack* currentLevel = createStack(100);
  Stack* nextLevel = createStack(100);

  int LeftToRight = 1;

  push(currentLevel,root);

  while(!isEmpty(currentLevel)){

    TreeNode* node = pop(currentLevel);
    printf("%d ",node->val);


    if(LeftToRight){
      
      if(node->left){
        push(nextLevel,node->left);
      }
      
      if(node->right){
        push(nextLevel,node->right);
      }
    
    }else{

      if(node->right){
        push(nextLevel,node->right);
      }
      
      if(node->left){
        push(nextLevel,node->left);
      }
    }

    if(isEmpty(currentLevel)){
      
      printf("\n");
      Stack* temp = currentLevel;
      currentLevel = nextLevel;
      nextLevel = temp;

      LeftToRight = !LeftToRight;

    }



  }
}


int main(){


  TreeNode* root = createNode(3);
  
  root->left = createNode(9);
  
  root->right = createNode(20);

  root->right->left = createNode(15);
  root->right->right = createNode(7);

  zigzagTraversal(root);


  return 0;

}




