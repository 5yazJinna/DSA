#include<stdio.h>
#include<stdlib.h>
int size=10,a[10];

void insert(int value)
{
    int k,k1,i;
    k=value%11;
    if(a[k]==-1)
    {
        a[k]=value;
    }
    else
    {
        for(i=0;i<50;i++)
        {
            if(i<20)
            k1=(value%9)+i;
            else
            k1=(value%7)+i;
            if(a[k1]==-1)
            {
                a[k1]=value;
                break;
            }
        }
    }
}

void display()
{
    for(int i=0;i<size;i++)
    {
        printf("a[%d]=%d",i,a[i]);
        printf("\n");
    }
}

void main()
{
    int i,n,ch;
    for(i=0;i<10;i++)
    {
        a[i]=-1;
    }
    while(1)
    {
        printf("\n1.Insert\n0.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter value to insert : ");
            scanf("%d",&n);
            insert(n);
            display();
            break;
            case 0:
            exit(0);
            default:
            printf("Enter valid choice\n");
            break;
        }
    }
}