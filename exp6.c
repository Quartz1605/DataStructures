#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;


typedef struct Stack {
    Node* arr[100];
    int top;
} Stack;

// Utility functions
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, Node* node) {
    s->arr[++(s->top)] = node;
}

Node* pop(Stack* s) {
    return s->arr[(s->top)--];
}

// Build expression tree from postfix
Node* constructTree(char* postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            
            push(&s, createNode(c));
        } else {
            
            Node* node = createNode(c);

            
            node->right = pop(&s);
            node->left = pop(&s);

            push(&s, node);
        }
    }

    // Final node is root
    return pop(&s);
}


void inorder(Node* root) {
    if (root == NULL) return;

    if (root->left || root->right) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->left || root->right) printf(")");
}

int main() {
    char postfix[] = "ab+c*";

    Node* root = constructTree(postfix);

    printf("Inorder Expression: ");
    inorder(root); // prints ((a+b)*c)

    return 0;
}
