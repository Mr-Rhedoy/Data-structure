#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=0;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
    }
}
display()
{
    struct node *temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL");
    }
}
void dequeue()
{
    struct node *temp=front;
    if(front==0)
    {
        printf("Empty");
    }
    else
    {
        printf("Will delete %d\n",front->data);
        front=front->link;
        free(temp);

    }
}
void display2()
{
     struct node *temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");

}

}
void peek()
{
    printf("Top element is now %d\n",front->data);
}

int main()
{   printf("----Enqueue----\n");
    int i,data,n;
    printf("Enter how many data to insert= ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data);
        enqueue (data);
    }
    display();
    printf("\n");
    printf("---Dequeue---\n");
    dequeue();
    display2();
    peek();
}
