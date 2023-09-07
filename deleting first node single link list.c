#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void del_fist(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->link;
    free(temp);
    temp->link = NULL;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2->data = 98;
    head2->link = NULL;

    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    head3->data = 45;
    head3->link = NULL;

    head->link = head2;
    head2->link = head3;
    head3->link = NULL;

    printf("Before deleting first node\n");
    printf("%d->%d->%d->NULL\n\n", head->data, head2->data, head3->data);

    del_fist(&head);
    printf("After deleting first node\n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL");

    return 0;
}
