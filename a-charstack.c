#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int size=5,top=-1,i;
char stack[5];
int check1(char a)
{    
    if(isalpha(a)==0)
    {
        printf("Error : Invalid entry - not an alphabet\n");
        return 0;
    }
    else
    return 1;
}
int check2(char a)
{
    if(stack[top]==a)
    {
        printf("Error : No repetition of characters\n");
        return 0;
    }
    else
    return 1;
} 
void push()
{
    char a;
    if(top==size-1)
    printf("Stack overflow\n");
    else
    {
        printf("Enter a character : ");
        scanf(" %c",&a);
        if(check1(a)==1 & check2(a)==1)
        {
            if(top==-1)
            {
                top++;
                stack[top]=a;
                printf("%c has been pushed\n",a);
            }
            else
            {
                top++;
                stack[top]=a;
                printf("%c has been pushed\n",a);
            }
        }
        else
        printf("Enter a character\n");
    }
}

void pop()
{
    char temp;
    if(top==-1)
    printf("Stack underflow\n");
    else
    {
        temp=stack[top];
        top--;
        printf("%c has been popped out\n",temp);
    }
}

void num()
{
    char temp;
    int count=0;
    printf("Enter character : ");
    scanf(" %c",&temp);
    for(i=0;i<=top;i++)
    {
        if(stack[i]==temp)
        {
            count++;
        }
    }
    printf("No. of occurrences = %d\n",count);
}

void display()
{
    for(i=0;i<=top;i++)
    {
        printf("%c\t",stack[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nOperations\n1.Push\n2.Pop\n3.Number of occurrence\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            num();
            break;
            case 4:
            {
                exit(0);
            }
            default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}