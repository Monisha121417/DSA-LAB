#include <stdio.h>
#define SIZE 3

int stack[SIZE],top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow:Cannot push %d\n", value);
    }
    else {
        stack[++top] = value;
        printf("Pushed %d to stack.\n", value);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow:Cannot pop from empty stack.\n");
    } else {
        printf("Popped %d from stack.\n", stack[top--]);
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n.... Stack Menu ....\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
