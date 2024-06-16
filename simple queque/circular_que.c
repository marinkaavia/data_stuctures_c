#include <stdio.h>
#define size 5
//create a circular que
int que[size], front = -1, rear = -1;

int is_full() {
  if ((front == rear + 1) || (front == 0 && rear == size - 1)) {
    //printf("queue is full\n");
    return 1; // 1 means that queue is full
  }
  else {
    //printf("queue is not full\n");
    return 0; //0 means that queue is not full
  }
}

int is_empty() {
  if (front == -1) {
    //printf("queue is emptty\n"); 
    return 1; //1 - queue is empty
  }
  else {
    //printf("queue is not empty\n"); 
    return 0; //0 - queue is NOT empty
  }
}

// Adding an element
void enQueue(int element) {
  if (is_full())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    que[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (is_empty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = que[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % size;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

//function to display queueu 
void display() {
  int i;
  if (is_empty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", que[i]);
    }
    printf("%d ", que[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  // Fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;
}