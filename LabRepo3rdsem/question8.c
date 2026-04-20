#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtBeginning() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Deleted %d from beginning.\n", head->data);
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Initial ");
    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    deleteAtBeginning();
    display();

    return 0;
}
