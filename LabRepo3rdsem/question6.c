#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        front = -1;
        rear = -1;
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    dequeue();
    dequeue();

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}