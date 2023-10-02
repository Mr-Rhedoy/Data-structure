#include<stdio.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

// Function to push data onto the stack
void push(int data)
{
    // Check if the stack is full
    if(top == MAX - 1)
    {
        printf("STACK IS FULL\n");
        return;
    }
    else
    {
        // Increment the top and add data to the stack.
        top++;
        stack_arr[top] = data;
        printf("Pushed %d onto the stack\n", data);
    }
}

int main()
{
    // Push elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5); // Trying to push more elements than the stack size

    return 0;
}
