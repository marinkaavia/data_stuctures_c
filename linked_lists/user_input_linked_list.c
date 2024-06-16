#include <stdio.h>
#include <stdlib.h>
//implimentation of linked list using preassigned values
struct node {
    int value;
    struct node *next; 
};

int FindByIndex(struct node* p, int index) {
    for (int i = 0; i<index; i++) {
        p = p->next;
    }
    return p->value;
}

struct node* takeInpurLinkedList(int number_of_elements) {
    struct node *first_node = NULL;
    struct node *current_node = NULL; //current element 
    for (int i = 0; i<number_of_elements; i++) { //repeat this action number_of_elements times
        int value_of_adding_node;
        printf("enter the value of element with index %d: ", i);
        scanf("%d", &value_of_adding_node);
        //now we know information. lets create new node
        struct node *new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed");
            break;
        }
        new_node -> value = value_of_adding_node;
        new_node -> next = NULL;
        if (i==0) { //if it is first element, we have to assign as 1st element
            first_node = new_node;
            current_node = first_node;
        }
        else {
            current_node -> next = new_node;
            current_node = new_node;
            new_node -> next = NULL;
        }
    }
    return first_node;
}


int main() {
    int number_of_elements;
    printf("Print an number of elements in linked list (initially): ");
    scanf("%d", &number_of_elements);
    struct node *first_node = takeInpurLinkedList(number_of_elements); //creating linked list
    printf("Print the index which you want to find: ");
    int index;
    scanf("%d", &index);
    int rez_index;
    if (index >number_of_elements) {
        printf("give another input");
    }
    else {
        rez_index = FindByIndex(first_node, index);
        printf("%d", rez_index);
    }
    return 0;
}