#include<stdio.h>
#include<stdlib.h>
int top=-1,stack[100],size;
void push()
{
    int n;
    if(top==size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the element to push : ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
        printf("%d has been pushed successfully\n",n);
    }
}
void pop()
{
    int temp;
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        temp=stack[top];
        top--;
        printf("%d has been popped out successfully\n",temp);
    }
}
void isempty()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}
void isfull()
{
    if(top==size-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
}
void peek()
{
    if(top>-1)
    {
        printf("Top element = %d\n",stack[top]);
    }
    else
    {
        printf("Stack underflow\n");
    }
}
void search()
{
    if(top>-1)
    {
        int n,i,flag=0,temp;
        printf("Enter the element to search : ");
        scanf("%d",&n);
        for(i=0;i<=top;i++)
        {
            if(stack[i]==n)
            {
                flag=1;
                temp=i+1;
            }
        }
        if(flag==1)
        {
            printf("%d is present in position %d\n",n,temp);
        }
    }
    else
    {
        printf("Stack underflow\n");
    }
}
void display()
{
    int i;
    if(top>-1)
    {
        printf("Elements of stack :\n");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
    }
    else
    {
        printf("Stack underflow\n");
    }
}
void main()
{
    int choice=1;
    printf("Enter size of stack : ");
    scanf("%d",&size);
    while(choice!=0)
    {
        printf("\nOperations in Stack\n");
        printf("1.Push\n2.Pop\n3.Check if stack is empty\n4.Check if stack is full\n5.Peek\n6.Search\n7.Display elements of stack\n8.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                isempty();
                break;
            }
            case 4:
            {
                isfull();
                break;
            }
            case 5:
            {
                peek();
                break;
            }
            case 6:
            {
                search();
                break;
            }
            case 7:
            {
                display();
                break;
            }
            case 8:
            {
                exit(0);
            }
            default:
            {
                printf("Enter a valid choice\n");
            }
        }
    }
}