#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data;           // Data stored in the node
    struct node *link;  // Pointer to the next node
};

// Function to insert a node at the end of the linked list
void insert_node(struct node **head, int data)
{
    // Create a new node
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;  // Assign the data to the new node
    newnode->link = NULL;  // Initialize the link to NULL

    // If the linked list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newnode;   // Set the head pointer to the new node
        return;            // Exit the function
    }
    else{

    // Otherwise, traverse the list to find the last node
    struct node *current = *head;
    while (current->link != NULL)
    {
        current = current->link;  // Move to the next node
    }

    // Add the new node to the end of the list
    current->link = newnode;
}}
int main()
{
    int n, i;
    printf("How many nodes you want to create =  ");
    scanf("%d", &n);

    struct node *head = NULL;  // Initialize an empty linked list

    for (i = 1; i <= n; i++)
    {
        int data;
        printf("Enter the data for node %d = ", i);
        scanf("%d", &data);
        insert_node(&head, data);  // Insert a new node with the given data
    }

    printf("\n");
    printf("The list is\n");

    struct node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);  // Print the data in the current node
        current = current->link;       // Move to the next node
    }
    printf("NULL\n");

    return 0;
}
