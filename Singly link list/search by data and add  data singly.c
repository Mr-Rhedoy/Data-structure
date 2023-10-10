#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void search_data(struct node **node1,int data)
{
    struct node *temp=*node1;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=22;
    newnode->link=NULL;

    while(temp->data!=data)
    {
        temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;


    }

int main()
{
    struct node *node1=(struct node*)malloc(sizeof(struct node));
    node1->data=10;
    node1->link=NULL;

    struct node *node2=(struct node*)malloc(sizeof(struct node));
    node2->data=20;
    node2->link=NULL;

    struct node *node3=(struct node*)malloc(sizeof(struct node));
    node3->data=30;
    node3->link=NULL;

    struct node *node4=(struct node*)malloc(sizeof(struct node));
    node4->data=40;
    node4->link=NULL;

    struct node *node5=(struct node*)malloc(sizeof(struct node));
    node5->data=50;
    node5->link=NULL;

    node1->link=node2;
    node2->link=node3;
    node3->link=node4;
    node4->link=node5;
    node5->link=NULL;

    struct node *temp=node1;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");

    int data;
    printf("Enter the data= ");
    scanf("%d",&data);
    search_data(&node1,data);

    struct node *temp2=node1;
    while(temp2!=NULL)
    {
        printf("%d->",temp2->data);
        temp2=temp2->link;
    }
    printf("NULL\n");
}
