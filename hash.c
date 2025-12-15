#include<stdio.h>
#define MAX 100

int hashTable[MAX];
int m;

int hashFunction(int key) {
    return key % m;
}

void insertKey(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % m;
    }

    hashTable[index] = key;
}

void displayHashTable() {
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t--\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    // Initialize hash table
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insertKey(key);
    }

    displayHashTable();

    return 0;
}

