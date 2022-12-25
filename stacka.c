#include<stdio.h>
int stack[100],choice,n,top,x,i,s;
void push(void);
void pop(void);
void display(void);
void search(void);
int main()
{
    top=0;
    printf("\n Enter the size of the stack[max=100]: ");
    scanf("%d",&n);
    printf("\n\t Stack Operation Using Arrray");
    printf("\n\t---------------------------------------");
    printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT\n\t5.SEARCH");
    do
    {
      printf("\n Enter the Choice : ");
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
            display();
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        case 5:
        {
            search();
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4/5)");
        }
      }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top<n)
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    else
    {
        printf("\n\t Stack is overflow");
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is Underflow");
    }
    else
    {
        printf("\n\t The Popped Element is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n\t The Elements in Stack is :");
        for(i=top;i>=0;i--)
        printf("\n%d",stack[i]);
        printf("\n Press next Choice");
    }
    else
    {
        printf("\n The Stack is Empty");       
    }
}
void search()
{
    printf("enter the element to search: ");
    scanf("%d",&s);
    for(i=0;i<=n;i++)
    {
    if(stack[i]!=s)
    {
        printf("the searched element is present in the stack");
        break;
    }
    else
    {
        printf("the searched element is not present in the stack");
        break;
    }
    }
}

