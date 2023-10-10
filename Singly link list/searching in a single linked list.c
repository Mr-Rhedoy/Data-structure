#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void search_value(struct node *head,int data)
{
    struct node *temp=head;
    int position=1;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            printf("%d is found in pos %d\n",data,position);
        }

        temp=temp->link;
        position++;
    }

}
int main()
{
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

    printf("\n");
    int data;
    printf("Enter the data to search= ");
    scanf("%d",&data);
    search_value(head,data);
}

