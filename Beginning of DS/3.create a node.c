//Create a note and print it;
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};//taking node ;
int main()
{
    //take the first node name head and free it;
    struct node *head= NULL;

    //taking memory for struct node and give it to head pointer;
    head=(struct node*)malloc(sizeof (struct node));

    head->data=90;//intialize data;
    head->link=NULL;

    printf("%d",head->data);//print it;

    free(head);//free the node;
    return 0;

}
