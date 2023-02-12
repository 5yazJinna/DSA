#include<stdio.h>
#include<stdlib.h>
int heap[100];
int n=0;

void heapify(int heap1[],int n1,int i)
{
    int par=(i-1)/2;
    int t;
    if(heap1[par]>0)
    {
        if(heap1[i]>heap1[par])
        {
            t=heap1[i];
            heap1[i]=heap1[par];
            heap1[par]=t;

            heapify(heap1,n1,par);
        }
    }
}

void insert()
{
    int val;
    printf("\nEnter element to be inserted:");
    scanf("%d",&val);
    n=n+1;
    heap[n-1]=val;
    heapify(heap,n,n-1);
}

void delete()
{
    int del,i,m=0;
    printf("Enter element to be deleted : ");
    scanf("%d",&del);
    for(i=0;i<n;i++)
    {
        if(heap[i]==del)
        {
            heap[i]=heap[n-1];
            n--;
            for (int i = 1; i<=n; i++)
            {
                m=m+1;
                heapify(heap, m, m-1);
            }
            break;
        }
    }
}

void display()
{
    printf("\nMax Heap:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d->",heap[i]);
    }
}

void main()
{
    int ch;
    printf("\nMax Heap - Operations\n1.Insert\n2.Display\n3.Delete\n4.Exit");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert();
            display();
            break;
            case 2:
            display();
            break;
            case 3:
            delete();
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nEnter valid choice\n");
            break;
        }    
    }
}