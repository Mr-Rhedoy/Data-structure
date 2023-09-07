#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link
    };
void print_data(struct node *head)//using a function for counting;
{
    int count=0;
    if(head==NULL)//if head is null
    {
        printf("Linked List Is Empty");
    }

    while(head!=NULL)//if head is not null it will count;
    {
        printf("%d\n",head->data);
        head=head->link;//if head is not null than it will go to second list and will match with the condition;
    }

}
int main()
{
    struct node *head= (struct node*)malloc(sizeof (struct node));// allocating memory;
    head->data=45;//assigning data;
    head->link=NULL;
    struct node *current= (struct node*)malloc(sizeof (struct node));
    current->data=98;
    current->link=NULL;
    struct node *next= (struct node*)malloc(sizeof (struct node));
    next->data=45;
    next->link=NULL;

    struct node *next2= (struct node*)malloc(sizeof (struct node));
    next2->data=45;
    next2->link=NULL;

    head->link=current;//connecting the lists;
    current->link=next;
    next->link=next2;

    print_data(head);//using function for counting the nodes;

}
