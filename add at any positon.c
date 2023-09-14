#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_at_pos(struct node **head, int data, int pos)
{
    struct node *ptr = *head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    if (pos == 1)
    {
        ptr2->link = ptr;
        *head = ptr2;
    }
    else
    {
        while (pos != 2)
        {
            ptr = ptr->link;
            pos--;
        }
        ptr2->link = ptr->link;
        ptr->link = ptr2;
    }
}

int main()
{
    int data, pos;
    printf("Enter the data & pos= ");
    scanf("%d %d", &data, &pos);

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

    printf("Before inserting node at a certain point\n");
    printf("%d->%d->%d->NULL", head->data, head2->data, head3->data);

    printf("\n\n");

    add_at_pos(&head, data, pos);

    printf("After inserting in any position\n");

    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL\n");

    return 0;
}
