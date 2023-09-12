#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
    };
int main()
{
    struct node *head= (struct node*)malloc(sizeof (struct node));
    head->data=45;
    head->link=NULL;
    struct node *current= (struct node*)malloc(sizeof (struct node));
    current->data=98;
    current->link=NULL;
    struct node *next= (struct node*)malloc(sizeof (struct node));
    next->data=45;
    next->link=NULL;

    head->link=current;
    current->link=next;


    printf("%d %d %d \t",head->data,current->data,next->data);

}
