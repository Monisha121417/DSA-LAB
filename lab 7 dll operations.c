#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    int value;
    struct Node *temp, *newNode;

    if (n <= 0) {
        printf("Invalid size\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &value);

    head = createNode(value);
    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        temp->next = newNode;
        newNode->prev = temp;

        temp = newNode;
    }
}

void insertLeft(int target, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target value not found.\n");
        free(newNode);
        return;
    }

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteValue(int target) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp == head && temp->next == NULL) {
        head = NULL;
    }
    else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    }
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, value, target;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    createList(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert to the left of a value\n");
        printf("2. Delete a value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter target value: ");
            scanf("%d", &target);
            printf("Enter new value: ");
            scanf("%d", &value);
            insertLeft(target, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &target);
            deleteValue(target);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

