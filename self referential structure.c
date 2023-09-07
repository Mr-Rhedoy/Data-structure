#include<stdio.h>
struct code
{
    int i;
    char c;
    struct code *ptr;

};
int main()
{
    struct code var1;
    struct code var2;

    //for var 1;
    var1.i=65;
    var1.c='A';
    var1.ptr= NULL;

    //for var 2;
    var2.i=66;
    var2.c='B';
    var2.ptr= NULL;

    var1.ptr=&var2;//var 1 will now contain the address of var2;

    printf("%d %c\n",var1.i,var1.c);//printing var1;

    printf("%d %c\n",var1.ptr->i,var1.ptr->c);//printing the i and c of var2 using var1;

    return 0;


}
