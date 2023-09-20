#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* link;
};

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node
    struct Node* current = *head;
    while (current->link != NULL) {
        current = current->link;
    }

    // Add the new node to the end of the list
    current->link = newNode;
}

int main() {
    int n; // Number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* head = NULL; // Initialize an empty linked list

    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Display the linked list
    printf("Linked List: ");

    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");



    return 0;
}
