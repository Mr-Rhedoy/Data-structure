#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_beginning(struct node **head,int data)
{
    struct node *ptr=*head;
    struct node *ptr2= (struct node*)malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=ptr;
    *head=ptr2;

}
int main()
{
    int data;
    printf("Enter the data= ");
    scanf("%d",&data);
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *head2=(struct node*)malloc(sizeof(struct node));
    head2->data=98;
    head2->link=NULL;

    struct node *head3=(struct node*)malloc(sizeof(struct node));
    head3->data=45;
    head3->link=NULL;

    head->link=head2;
    head2->link=head3;
    head3->link=NULL;
    printf("Before inserting node at a  beginning\n");
    printf("%d->%d->%d->NULL\n\n",head->data,head2->data,head3->data);

    add_at_beginning(&head,data);
    printf("After inserting at beginnig\n");
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }
    printf("NULL");
}
