#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked list
struct n {
    int v; // value
    struct n* p; // previous
    struct n* t; // next
};

int main() {
    // Initialize the nodes
    struct n *h = NULL; // head
    struct n *b = NULL; // first node
    struct n *c = NULL; // second node
    struct n *d = NULL; // third node
    struct n *w = NULL; // tail

    // Allocate memory for the nodes
    b = malloc(sizeof(struct n));
    c = malloc(sizeof(struct n));
    d = malloc(sizeof(struct n));

    // Initialize the values
    b->v = 10;
    c->v = 20;
    d->v = 30;

    // Connect nodes with each other
    b->t = c;
    c->t = d;
    d->t = NULL;
    d->p = c;
    c->p = b;
    b->p = NULL;

    // Set head and tail
    h = b;
    w = d;

    // Print the values of the linked list from the first to last
    printf("Initial linked list: ");
    struct n* current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    // Print the values of the linked list from last to first
    struct n* new_current = w;
    printf("\nIf we go from the end to the beginning: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Insert at the beginning
    struct n *o = malloc(sizeof(struct n));
    o->v = 100;
    o->t = b;
    o->p = NULL;
    b->p = o;
    h = o;

    // Print the values after insertion at the beginning
    printf("\n\nAfter insertion at the beginning: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after insertion at the beginning: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Insert in the middle
    struct n *l = malloc(sizeof(struct n));
    l->v = 11;
    b->t = l;
    l->t = c;
    c->p = l;
    l->p = b;

    // Print the values after insertion in the middle
    printf("\n\nAfter insertion in the middle: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after insertion in the middle: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Insert at the end
    struct n *z = malloc(sizeof(struct n));
    z->v = 50;
    d->t = z;
    z->t = NULL;
    z->p = d;
    w = z;

    // Print the values after insertion at the end
    printf("\n\nAfter insertion at the end: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after insertion at the end: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Delete at the beginning
    h = b;
    b->p = NULL;

    // Print the values after deletion at the beginning
    printf("\n\nAfter deletion at the beginning: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after deletion at the beginning: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Delete in the middle (delete element with value 11)
    b->t = c;
    c->p = b;

    // Print the values after deletion in the middle
    printf("\n\nAfter deletion in the middle: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after deletion in the middle: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Delete at the end (value 50)
    d->t = NULL;
    w = d;

    // Print the values after deletion at the end
    printf("\n\nAfter deletion at the end: ");
    current = h;
    while (current != NULL) {
        printf("%d -> ", current->v);
        current = current->t;
    }

    new_current = w;
    printf("\nIf we go from the end to the beginning after deletion at the end: ");
    while (new_current != NULL) {
        printf("%d -> ", new_current->v);
        new_current = new_current->p;
    }

    // Search for the g-th element from the beginning
    current = h;
    int u = 0; // size of the double linked list
    while (current != NULL) {
        u++;
        current = current->t;
    }

    int g; // looking for g-th element
    printf("\n\nThe size of double-linked list now is: %d ", u);
    printf("\nIf you want to search for g-th element in the double-linked list, give this number (index+1): ");
    scanf("%d", &g);

    struct n *q = h; // result will be q
    if (g > u) {
        printf("The size of linked list is smaller than the index you gave!\n");
    } else {
        for (int f = 1; f < g; f++) {
            q = q->t;
        }
        printf("The %dth from the beginning element of the double-linked list is %d", g, q->v);
    }

    // Search for node with value e from the beginning
    printf("\n\nAs input, give a value that you want to look for in double-linked list: ");
    int r;
    scanf("%d", &r); // we are looking for element with value r
    int r1 = 0; // result number
    int r2 = 0; // checker exists or not

    q = h; // start search from the head
    while (q->t != NULL) { // check all except last
        r1++;
        if (q->v == r) {
            printf("The element of double-linked list with the required value has number (index+1) - %d", r1);
            r2 = 1;
            break;
        }
        q = q->t;
    }

    if (w->v == r) {
        printf("The element of double-linked list with the required value has number (index+1) - %d", r1 + 1);
        r2 = 1;
    }

    if (r2 == 0) {
        printf("The element with this value does not exist");
    }

    // Free allocated memory (clean up)
    free(o);
    free(l);
    free(z);
    free(b);
    free(c);
    free(d);

    return 0;
}
