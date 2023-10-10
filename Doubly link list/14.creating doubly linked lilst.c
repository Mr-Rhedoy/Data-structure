#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node
{
    struct node *prev; // Pointer to the previous node
    int data;         // Data stored in the node
    struct node *link; // Pointer to the next node
};

int main()
{
    // Create the head node and initialize it
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL; // The head node has no previous node
    head->data = 10;   // Set data in the head node to 10
    head->link = NULL; // Initialize the link to NULL since there's only one node for now

    // Create the second node (node2) and initialize it
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->prev = NULL; // The previous pointer will be set later
    node2->data = 20;   // Set data in node2 to 20
    node2->link = NULL; // Initialize the link to NULL for now

    // Create the third node (node3) and initialize it
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->prev = NULL; // The previous pointer will be set later
    node3->data = 30;   // Set data in node3 to 30
    node3->link = NULL; // There are no more nodes after node3

    // Establish the forward links between nodes
    head->link = node2; // Head points to node2
    node2->link = node3; // Node2 points to node3

    // Establish the backward links between nodes
    node3->prev = node2; // Node3 points back to node2
    node2->prev = head; // Node2 points back to the head

    // Traverse the doubly linked list and print its contents in the forward direction
    struct node *current = head; // Start at the head
    while (current != NULL)
    {
        printf("%d->", current->data); // Print the data in the current node
        current = current->link;       // Move to the next node
    }
    printf("NULL\n");

    // Traverse the doubly linked list and print its contents in the backward direction
    struct node *current2 = node3; // Start at the last node
    while (current2 != NULL)
    {
        printf("%d->", current2->data); // Print the data in the current node
        current2 = current2->prev;       // Move to the previous node
    }
    printf("NULL\n"); // Print NULL to indicate the end of the list

    // Free the memory allocated for the nodes (not shown in the code, but it's a good practice)
    free(head);
    free(node2);
    free(node3);

    return 0;
}
