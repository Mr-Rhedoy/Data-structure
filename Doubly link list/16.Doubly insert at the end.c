#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *prev;
    int data;
    struct node *link;
};
void add_end(struct node **node1,int data)
{
    struct node *temp=*node1;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->link=NULL;;


     while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    newnode->prev=temp;

    struct node *temp2=newnode;
    while(newnode!=NULL)
    {
        printf("<-%d",temp2->data);
        temp2=temp2->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *node1=(struct node*)malloc(sizeof(struct node));
    node1->prev=NULL;
    node1->data=10;
    node1->link=NULL;

    struct node *node2=(struct node*)malloc(sizeof(struct node));
    node2->prev=NULL;
    node2->data=20;
    node2->link=NULL;

    struct node *node3=(struct node*)malloc(sizeof(struct node));
    node3->prev=NULL;
    node3->data=30;
    node3->link=NULL;

    struct node *node4=(struct node*)malloc(sizeof(struct node));
    node4->prev=NULL;
    node4->data=40;
    node4->link=NULL;

    struct node *node5=(struct node*)malloc(sizeof(struct node));
    node5->prev=NULL;
    node5->data=50;
    node5->link=NULL;

    node1->link=node2;
    node2->link=node3;
    node3->link=node4;
    node4->link=node5;
    node5->link=NULL;

    node5->prev=node4;
    node4->prev=node3;
    node3->prev=node2;
    node2->prev=node1;
    node1->prev=NULL;

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

    add_end(&node1,data);
    printf("\n");
}
