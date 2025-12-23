#include <stdio.h>

#define MAX 20
int hashtable[MAX];
int m;

void insert(int key) {
    int index = key % m;

    int i = 0;
    while (hashtable[(index + i) % m] != -1) {
        i++;
        if (i == m) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashtable[(index + i) % m] = key;
}

void display() {
    printf("\n--- Hash Table Contents ---\n");
    for (int i = 0; i < m; i++) {
        if (hashtable[i] != -1)
            printf("Address %d: %d\n", i, hashtable[i]);
        else
            printf("Address %d: Empty\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (max %d): ", MAX);
    scanf("%d", &m);

    for (int i = 0; i < MAX; i++) {
        hashtable[i] = -1;
    }

    printf("Enter number to insert: ");
    scanf("%d", &n);

    if (n > m) {
        printf("Warning: Number of records exceeds table size.\n");
    }

    printf("Enter %d keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
