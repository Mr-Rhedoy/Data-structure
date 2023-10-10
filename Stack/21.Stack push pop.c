#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=0;
void push(int data)//for pussing the data;
{
    struct  node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}

void display()//function for displaying pussing elements;
{
    struct node *temp=top;
    if(temp==0)
    {
        printf("empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
    }
}


void peek()//function for  top element after pussing;
{
    printf("\n");
    if(top==0)
    {
        printf("Empty");
    }
    else
    {
        printf("Top element is %d\n\n",top->data);
    }
}
void pop()//function for poping data;
{
    struct node *temp=top;
    if(temp==0)
    {
        printf("Empty");
    }
    else
    {
        printf("Will delete %d\n",temp->data);//the data that will be deleted;
        top=top->link;//going to the 2nd last node;
        free(temp);
    }
}

void display2()//fucntion for displaying after poping ;
{
    struct node *temp=top;
    if(temp==0)
    {
        printf("empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
    }
}
void peek2()//function for displaying after poping data;
{
    printf("\n");
    if(top==0)
    {
        printf("Empty");
    }
    else
    {
        printf("Now Top element is %d\n",top->data);
    }
}

int main()
{
    push(5);//pussing elements;
    push(10);
    push(15);
    display();//Display the pussing elements;
    peek();//top element after pussing;

    pop();//deleting element;
    display2();//display after deleting;
    peek2();//new top element;
}
