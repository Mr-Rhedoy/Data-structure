#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_at_pos(struct node **head,int pos)
{
    struct node *temp=*head;
    struct node *temp2=*head;
    if(pos==1)
    {
        *head = (*head)->link;
        free(temp);
        temp->link = NULL;

    }
    else
        while(pos !=1)
        {
            temp=temp2;
            temp2=temp2->link;
            pos--;
        }
    temp->link=temp2->link;

}
int main()
{
    int pos;
    printf("Enter the pos= ");
    scanf("%d",&pos);
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *head2=(struct node*)malloc(sizeof(struct node));
    head2->data=98;
    head2->link=NULL;

    struct node *head3=(struct node*)malloc(sizeof(struct node));
    head3->data=3;
    head3->link=NULL;

    head->link=head2;
    head2->link=head3;
    head3->link=NULL;
    printf("Before Deleting node at a certain point\n");
    printf("%d->%d->%d->NULL\n\n",head->data,head2->data,head3->data);

    del_at_pos(&head,pos);
    printf("After deleting in any position\n");
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }
    printf("NULL");
}
