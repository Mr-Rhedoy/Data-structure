#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;
    printf("Enter your number of integers= ");

    scanf("%d",&n);//will take how many integer numbers;

    int *ptr= (int*)malloc(n*sizeof(int));//size of integer 4 so 4*n and it will give the address to *ptr;

    if(ptr==NULL)//if there are no memory it will print no memory and exit;
    {
        printf("No memory for loccation");
        exit(1);
    }
    for(i=0; i<n; i++) //0 to n loop will continue
    {
        printf("Enter integer num= ");
        scanf("%d",ptr+i);//ptr is adress so it will ptr+i i=0 so there 1st integer will go then i=1 (ptr+1)*4 if ptr 1000 so 1001*4= 1004 there will go second integer;

    }
    for(i=0; i<n; i++)
    {
        printf("%d\t",*ptr+i); //ptr+i was adress so *ptr+i will be the integer num and it will(*ptr+i) print the number;
    }
    return 0;
}
