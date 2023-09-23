#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node
{
    struct node *prev;  // Pointer to the previous node
    int data;           // Data stored in the node
    struct node *link;  // Pointer to the next node
};

// Function to insert a new node at the end of the linked list
void insert_at_end(struct node *head, int data)
{
    // Create a new node
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->link = NULL;

    // Traverse the list to find the current last node
    struct node *current = head;
    while (current->link != NULL)
    {
        current = current->link;
    }

    // Update pointers to insert the new node at the end
    current->link = newnode;
    newnode->prev = current;
}

int main()
{
    // Create the head node and initialize it
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->link = NULL;

    // Create additional nodes and set their data and pointers
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->prev = NULL;
    node2->data = 20;
    node2->link = NULL;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->prev = NULL;
    node3->data = 30;
    node3->link = NULL;

    // Connect nodes to form a linked list
    head->link = node2;
    node2->link = node3;

    // Set reverse pointers to make it a doubly linked list
    node3->prev = node2;
    node2->prev = head;

    // Print the original linked list
    printf("Before inserting node at the end\n");
    printf("%d->%d->%d->NULL", head->data, node2->data, node3->data);
    printf("\n\n");

    // Insert a new node at the end of the linked list
    insert_at_end(head, 69);

    // Print the linked list from the beginning
    printf("Traversing from beginning\n\n");
    struct node *current2 = head;
    while (current2 != NULL)
    {
        printf("%d->", current2->data);
        current2 = current2->link;
    }
    printf("NULL\n");

    // Print the linked list from the end
    printf("Traversing from end\n\n");
    struct node *current3 = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        current3 = temp;
        temp = temp->link;
    }
    while (current3 != NULL)
    {
        printf("%d->", current3->data);
        current3 = current3->prev;
    }
    printf("NULL\n");

    // Free dynamically allocated memory
    free(head);
    free(node2);
    free(node3);

    return 0;
}
