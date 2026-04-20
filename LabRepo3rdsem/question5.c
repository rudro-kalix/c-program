#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("Pushed: %d\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped: %d\n", stack[top]);
    top--;
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display();

    pop();
    pop();
    pop();

    display();

    pop();
    pop();
    pop();

    return 0;
}