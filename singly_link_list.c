#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node* next;
};

//inserting at the end
void pushEnd(struct node** head_ref,int new_data) {

     struct node* new_node= (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = NULL;
     struct node* last = *head_ref;
     if (*head_ref == NULL){
          *head_ref = new_node;
     }
     else {
          while(last->next != NULL) {
               last = last->next;
          }
          last->next = new_node;
     }
     return;
}

// inserting at the beginning
void pushStart(struct node** head_ref, int new_data) {

     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = *head_ref;

     *head_ref = new_node;

}

// inserting after a particular node
void insertAfter(struct node* prev_node, int new_data) {

     if(prev_node == NULL) {
          printf("\nThe previous node cannot be null\n");
          return;
     }

     struct node* new_node = (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = prev_node->next;

     prev_node->next = new_node;
}

//inserting before a particular new_node
void insertBefore(struct node** head_ref,struct node* next_node, int new_data) {
     if( next_node == NULL) {
          printf("\nThe next node cannot be null\n");
          return;
     }
     if (next_node == *head_ref) {
          struct node* new_node = (struct node*)malloc(sizeof(struct node));

          new_node->data = new_data;

          new_node->next = *head_ref;

          *head_ref = new_node;
     }
     else {
          struct node* prev_node = *head_ref;
          while (prev_node->next != next_node) {
               prev_node = prev_node->next;
          }
          struct node* new_node = (struct node*)malloc(sizeof(struct node));

          new_node->data = new_data;

          new_node->next = next_node;

          prev_node->next = new_node;
     }

}

//to print the list
void printlist(struct node* node) {
     printf("\n");
     while(node != NULL) {
          printf(" %d ", node->data);
          if (node->next != NULL)
               printf("->");
          node = node->next;
     }
     printf("\n");
     return;
}

int main() {

     struct node* head = NULL;
     int value;
     printf("\nEnter the any number to insert at the end : ");
     scanf("%d", &value);
     pushEnd(&head,value); //inserting 5 at the end
     printf("\nInserting %d at the End : ",value);
     printlist(head);

     printf("\nEnter the any number to insert at the start : ");
     scanf("%d", &value);
     pushStart(&head,value); //inserting 4 at the  beginning
     printf("\nInserting %d at the beginning :",value);
     printlist(head);

     printf("\nEnter the any number to insert at the start : ");
     scanf("%d", &value);
     pushStart(&head,value); // inserting 1 at the beginning
     printf("\nInserting %d at the beginning : ",value);
     printlist(head);

     printf("\nEnter the any number to insert after the fisrt element : ");
     scanf("%d", &value);
     insertAfter(head,value); // inserting 3 after the fisrt element.
     printf("\nInserting %d after the fisrt element :",value);
     printlist(head);

     printf("\nEnter the any number to insert before the second element : ");
     scanf("%d", &value);
     insertBefore(&head,head->next,value); // inserting 2 before the second element
     printf("\nInserting %d before the second element :", value);
     printlist(head);
     printf("\n");

     return 0;
}
