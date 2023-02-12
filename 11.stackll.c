#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *top=0;
int size,count;

void push()
{
    if(count==size)
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to push : ");
        scanf("%d",&newnode->data);
        if (top==0)
        {
            newnode->next=0;
        }
        else
        {
            newnode->next=top;
        }
        top=newnode;
        count++;
        printf("%d has been inserted\n",newnode->data);
    }
}

void pop()
{
    if(top==0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *temp;
        temp=top;
        int value=top->data;
        top=top->next;
        free(temp);
        printf("%d has been popped\n",value);
        count--;
    }
}

void isempty()
{
    if(top==0)
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
    if (count==size)
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
    if(top==0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Top element = %d\n",top->data);
    }
}

void search()
{
    if(top==0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *temp;
        temp=top;
        int n,index=count,flag=0;
        printf("Enter the element to search : ");
        scanf("%d",&n);
        while(temp!=0)
        {
            if(temp->data==n)
            {
                flag=1;
                break;
            }
            else
            {
                temp=temp->next;
                index--;
            }
        }
        if (flag==1)
        printf("%d is present in position %d\n",n,index);
        else
        printf("%d is not present\n",n);
    }
}

void display()
{
    if(top==0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *temp;
        temp=top;
        while(temp->next!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void main()
{
    int choice=1;
    printf("Enter size of stack : ");
    scanf("%d",&size);
    while (choice!=0)
    {
        printf("\nOperations on stack \n");
        printf("1.Push\n2.Pop\n3.Check if stack is empty\n4.Check if stack is full\n5.Peek\n6.Search\n7.Display\n8.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            isempty();
            break;
            case 4:
            isfull();
            break;
            case 5:
            peek();
            break;
            case 6:
            search();
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            default:
            printf("Enter a valid choice\n");
        }
    }
}