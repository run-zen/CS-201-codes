#include<stdio.h>
#include<stdlib.h>

struct node {
     int data;
     struct node* next;
     struct node* prev;
};

void push(struct node** head_ref, int new_data) {
     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = (*head_ref);
     new_node->prev = NULL;

     if ((*head_ref) != NULL) {
          (*head_ref)->prev = new_node;
     }
     (*head_ref) = new_node;
}

void insertAfter(struct node* prev_node,int new_data) {
     if (prev_node == NULL) {
          printf("\nThe previous node cannot be null\n");
          return;
     }

     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = prev_node->next;
     prev_node->next = new_node;
     new_node->prev = prev_node;
     if (new_node->next != NULL) {
          new_node->next->prev = new_node;
     }

     return;
}

void insertBefore(struct node** head_ref,struct node* next_node, int new_data) {
     if (next_node == NULL) {
          printf("\nThe next node cannot be null\n");
          return;
     }

     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->prev = next_node->prev;
     next_node->prev = new_node;
     new_node->next = next_node;

     if (new_node->prev != NULL) {
          new_node->prev->next = new_node;
     }
     else
     {
          *head_ref = new_node;
     }

     return;
}

void append(struct node** head_ref,int new_data) {
     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     struct node* last = *head_ref;

     new_node->data = new_data;

     new_node->next = NULL;

     if(*head_ref == NULL) {
          new_node->prev = NULL;
          *head_ref = new_node;
     }
     else {
          while(last->next != NULL) {
               last = last->next;
          }
          last->next = new_node;
          new_node->prev = last;
     }

     return;
}

void printlist(struct node* node) {
     struct node* last;
     printf("\nTransverse forward :\n");
     while(node != NULL) {
          printf("%d  ", node->data);
          last = node;
          node = node->next;
     }

     printf("\nTransverse backward :\n");
     while (last != NULL) {
          printf("%d  ", last->data);
          last = last->prev;
     }

     return;
}

int main() {
     struct node* mylist = NULL;

     append(&mylist, 6);

     push(&mylist, 5);

     push(&mylist, 2);

     append(&mylist, 7);

     insertAfter(mylist, 4);

     insertBefore(&mylist, mylist->next, 3);

     printf("\nCreated list is :\n");
     printlist(mylist);


     return 0;
}
