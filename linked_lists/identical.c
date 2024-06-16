#include <stdio.h>
#include <stdlib.h>

//find the linked list are identical linked list or not 

struct node {
    int value;
    struct node *next;
};

struct node* input_from_user(int number_of_evelements) {
    struct node *first_node = NULL;
    struct node *current_node = NULL;
    for (int i = 0; i<number_of_evelements; i++) {
        int value_of_current;
        printf("enter the value of element with index %d ", i);
        scanf("%d", &value_of_current);
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        if (new_node==NULL) {
            printf("allocation failed");
            break;
        }
        new_node -> value = value_of_current;

        if (i==0) {
            first_node = new_node;
            current_node = new_node;
        }
        else {
            current_node -> next = new_node;
            current_node = new_node;
            new_node -> next = NULL;
        }
    }
    return first_node;
}

int identical_check(struct node* p1, int number_of_elements1, struct node* p2, int number_of_elements2)  {
    int rez = 1;
    if (number_of_elements1!= number_of_elements2) {
        rez = 0;
        return rez; //0 means non-identical 
    }
    else {
        int n = number_of_elements1;
        for (int i = 0; i < n; i++) {
            if (p1->value == p2->value) {
                rez = 1;
            }
            else {
                rez = 0;
                return rez;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return rez;
    }
}

int main() {
    printf("provde an information about 1 LINKED LIST\n");
    int number_of_elements1;
    printf("Print an number of elements in 1 linked list (initially): ");
    scanf("%d", &number_of_elements1);
    struct node* first_list = input_from_user(number_of_elements1); //create linked list 1

    printf("provde an information about 2 LINKED LIST\n");
    int number_of_elements2;
    printf("Print an number of elements in 2 linked list (initially): ");
    scanf("%d", &number_of_elements2);
    struct node* second_list = input_from_user(number_of_elements2); //create linked list 2

    int rez = identical_check(first_list, number_of_elements1, second_list, number_of_elements2);
    if (rez == 1) {
        printf("The linked-lists are identical");
    }
    else {
        printf("The linked-lists are NOT identical");
    }
    return 0;
}