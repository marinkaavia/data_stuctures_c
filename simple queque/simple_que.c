#include <stdio.h>
#define size 5
//create a queue as a gloabal variables
int que[size], front = -1, rear = -1;

//enque function
void enqueue(int value) {
    if (rear+1 == size) {
        printf("queue is overflow\n");
        return;
    }
    else {
        if (front == -1) {
            front = 0; //if queue was esmpty, now front shows on the index 0, not -1
        }
        rear++;
        que[rear] = value;
        for (int i = 0; i <= rear; i++) {
            printf("%d<-", que[i]);
        }
        printf("\n");
    }
}

//deque function
void dequeue() {
    if (rear==-1) {
        printf("queue is empty, nothing to delete\n");
        return;
    }
    else if (rear==0) {
        rear--;
        printf("last element was deleted, now queue is empty\n");
    }
    else {
        rear--;
        for (int i = front; i <= rear; i++) {
            que[i] = que[i+1];
        }
        for (int i = front; i <= rear; i++) {
            printf("%d<-", que[i]);
        }
        printf("\n");
    }
}

void dispay_front() {
    if (rear == -1) {
        printf("queque is emty, nothing to display");
        return;
    }
    else {
        printf("first element is queue %d\n", que[front]);
    }

}

void traverse() {
    if (rear == -1) {
        printf("queque is emty, nothing to display");
        return;
    }
    else {
        printf("right now queque is:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d<-", que[i]);
        }
        printf("\n");
    }
}


int main() {
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(2222); //this should give overflow

    dequeue();
    dequeue();
    dequeue();
    
    dispay_front();

    enqueue(8);
    dequeue();
    dispay_front();

    return 0;
}



