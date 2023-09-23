#include <stdio.h>
#include <stdlib.h>


struct node
{
    struct node *prev;
    int data;
    struct node *link;
};

void del_last(struct node *head)
{
   struct node *temp=head;
   struct node *temp2=head;
   while(temp2->link!=NULL)
   {
       temp=temp2;
       temp2=temp2->link;
   }
    temp->link=NULL;
    free(temp2);
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->link = NULL;


    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->prev = NULL;
    node2->data = 20;
    node2->link = NULL;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->prev = NULL;
    node3->data = 30;
    node3->link = NULL;


    head->link = node2;
    node2->link = node3;


    node3->prev = node2;
    node2->prev = head;

    printf("Before deleting node at the end\n");
    printf("%d->%d->%d->NULL", head->data, node2->data, node3->data);
    printf("\n\n");


    del_last(head);

    printf("Traversing from end(after deleting end)\n\n");
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

    free(head);
    free(node2);
    free(node3);

    return 0;
}
