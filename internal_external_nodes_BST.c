#include <stdio.h>
#include <stdlib.h>

int Inode = 0;
int Enode = 0;

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

void no_of_Inodes(struct node* node) {

     if(node == NULL) {
          return;
     }
     no_of_Inodes(node->left);
     if(node->left != NULL || node->right != NULL) {
          Inode++;
     }

     no_of_Inodes(node->right);
}

void no_of_Enodes(struct node* node) {
     if(node == NULL) {
          return;
     }
     no_of_Enodes(node->left);
     if(node->left == NULL && node->right == NULL) {
          Enode++;
     }
     no_of_Enodes(node->right);
}

void inOrder(struct node* node) {
     if(node != NULL) {
          inOrder(node->left);
          printf("   %d", node->key);
          inOrder(node->right);
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

     printf("\n  Binary Search Tree in INORDER form : \n");
     inOrder(root);

     no_of_Inodes(root);
     no_of_Enodes(root);

     printf("\nNo. of Internal nodes : %d\n", Inode);
     printf("\nNo. of External nodes : %d\n", Enode);

     return 0;
}
