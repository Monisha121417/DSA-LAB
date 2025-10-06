#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == SIZE - 1) {
        printf("\nQueue Overflow! Cannot insert.\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted into queue.\n", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } else {
        printf("%d deleted from queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Menu ---\n");
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
