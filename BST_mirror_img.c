#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int key) {
     struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inOrder(struct node* node) {
     if(node != NULL) {
          inOrder(node->left);
          printf("   %d", node->key);
          inOrder(node->right);
     }
}


void mirror(struct node* node) {
     if(node == NULL) {
          return;
     }
     else {
          mirror(node->left);
          mirror(node->right);

          struct node* temp;

          temp = node->left;
          node->left = node->right;
          node->right = temp;
     }
}

int main() {

     struct node* root = NULL;
     int value, flag = 1;
     printf("\nEnter value to insert(-1 to stop) : ");
     scanf("%d", &value);
     if(value == -1) {
          flag = 0;
     }
     else {
          root = insert(root, value);
     }
     while(flag) {
          printf("\nEnter value to insert(-1 to stop) : ");
          scanf("%d", &value);
          if(value == -1) {
               break;
          }
          insert(root, value);
     }

     printf("\nOriginal BST (INORDER form) : \n");
     inOrder(root);

     mirror(root);
     printf("\n\nMirror BST (INORDER form) : \n");
     inOrder(root);

     printf("\n\n");
     return 0;
}
