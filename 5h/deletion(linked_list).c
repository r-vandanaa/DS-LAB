#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        printf("%d inserted as head.\n", new_data);
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    printf("%d inserted at end.\n", new_data);
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    int deleted = temp->data;
    *head = temp->next;
    free(temp);
    printf("Deleted first element: %d\n", deleted);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        int deleted = (*head)->data;
        free(*head);
        *head = NULL;
        printf("Deleted last (and only) element: %d\n", deleted);
        return;
    }

    struct Node* sec_last = *head;
    while (sec_last->next->next != NULL)
        sec_last = sec_last->next;

    struct Node* last_node = sec_last->next;
    int deleted = last_node->data;

    sec_last->next = NULL;
    free(last_node);
    printf("Deleted last element: %d\n", deleted);
}

void deleteSpecific(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head contains data
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        printf("Deleted element: %d\n", data);
        free(temp);
        return;
    }

    // Search for the element
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    printf("\nSingly Linked List Menu\n");
    printf("1. Insert at end\n2. Delete first element\n3. Delete last element\n4. Delete specific element\n5. Display list\n6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                display(head);
                break;

            case 2:
                deleteFirst(&head);
                display(head);
                break;

            case 3:
                deleteLast(&head);
                display(head);
                break;

            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &value);
                deleteSpecific(&head, value);
                display(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program...\n");
                while (head != NULL)
                    deleteFirst(&head);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
