#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};


int FindByIndex(int n, struct node *p) {
    int counter = 0;
    while (p!=n) {
        p = p->next; //go to the next element
        counter++;
    }
    return counter;
}

int main() {
    int n;
    //scanf("%d", &n); //this index we are looking for
    //part to create our liked list

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

    //lets inicialize the value 
    one->value = 11;
    two -> value = 22;
    three -> value = 33; 
    last -> value = 44; 

    
    //lets connect nodes
    one -> next = two;
    two -> next = three;
    three -> next = last;
    last -> next = NULL;
    head = one;
    
    //int rezult = FindByIndex(n, one);
    //printf("%d", rezult);
    printf("%d", one -> value);
}