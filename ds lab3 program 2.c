#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow! Cannot insert.\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;
        queue[rear] = item;
        printf("%d inserted into circular queue.\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } else {
        printf("%d deleted from circular queue.\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nCircular Queue elements are:\n");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
