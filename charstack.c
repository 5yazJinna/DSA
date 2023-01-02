#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int stack[5],top=-1,n=5;
void insert(char val)
{
    if(top>=n-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        if(isalpha(val)==0)
        {
            printf("Please enter a character\n");
        }
        
        else
        {
            int flag=0;   
           
            if(flag==1)
            {
                printf("Enter a different character\n");

            }
            if(flag==0)
            {
                top++;
                stack[top]=val;
                printf("Added to stack\n");
            }
        }
    }

}
void pop()
{
    if(top<=-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element: % c",stack[top]);
        top--;
    }
}
void print()
{
    if(top>=0)
    {
        printf("Elements in stack: \n");
        for(int i=top;i>=0;i--)
        {
            printf("\n %c",stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack Empty\n");
    }
}
void occur()
{
    char ch;
    int count=0,flag=0;
    printf("Enter the element to find out occurence\n");
    scanf(" %c",&ch);
    for(int i=top;i>=0;i--)
    {
        if(stack[i]==ch)
        {
            count++;
            flag=1;
        }
    }
    if(flag==1)
    {
    printf(" %c occurs %d times\n",ch,count);
    }
    if(flag==0)
    {
        printf("Entered character not present in stack\n");
    }
}
int main()
{
    
    int choice;
    char val;
    while(1)
    {
        printf("\n\t1.Insert\n\t2.pop\n\t3.Display\n\t4.occurence\n\t5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the Character to be inserted: ");
            scanf(" %c",&val);
            insert(val);
            break;
            case 2:
            pop();
            break;
            case 3:
            print();
            break;
            case 4:
            occur();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}

