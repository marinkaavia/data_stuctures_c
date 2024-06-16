#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; //defenition of sstructure

int main() {
    //initialize the nodes
    struct node *head = NULL; //we will initialize it in the end
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *last = NULL;
  
    //allocate memory
    first = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));

    //inicialize the value 
    first -> value = 1;
    second -> value = 10;
    last -> value = 2;
  
    //lets connect nodes with each other
    first -> next = second;
    second -> next = last;
    last -> next = NULL;
    head = first;

    struct node* current = head;
    //lets print the values of linked listprintf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL");
    return 0;
}