#include <stdio.h>
#include <stdlib.h>
//implimentation of linked list using preassigned values
struct node {
    int value;
    struct node *next; 
};

void prinLinedList(struct node* p) {
    printf("all linked list values is: ");
    while (p!=NULL) {
        printf("%d ", p-> value);
        p = p->next;
    }
}

void print_one_element(struct node* p) {
    printf("the value of element from linked list is: ");
    if (p!=NULL) {
        printf("%d ", p-> value);
    }
}

int main() {
    //initialization of nodes
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *last = NULL;

    //alocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));

    /*assign value 
    one->value = 1;
    two -> value = 2;
    last -> value = 3; */

    //ask value from the user
    printf("enter the value of 1st node: ");
    scanf("%d", &one->value);
    printf("enter the value of 2nd node: ");
    scanf("%d", &two->value);
    printf("enter the value of 3rd node: ");
    scanf("%d", &three->value);
    printf("enter the value of 4rd node: ");
    scanf("%d", &last->value);
    
    

    //lets connect nodes
    one -> next = two;
    two -> next = three;
    three -> next = last;
    last -> next = NULL;
    head = one;
    
    //printing 
    printf("\n");
    prinLinedList(head);
    printf("\n");
    print_one_element(last);
    
    return 0;
}