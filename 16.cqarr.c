#include<stdio.h>
#include<stdlib.h>
int queue[100],size,front=-1,rear=-1;
void enqueue()
{
    int n;
    if((rear+1)%size==front)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d",&n);
        rear=(rear+1)%size;
        queue[rear]=n;
        if(front==-1)
        front=front+1;
        printf("%d has been inserted\n",n);
    }
}
void dequeue()
{
    int temp,i;
    if(front==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        temp=queue[front];
        if(rear==front)
        front=rear-1;
        else
        front=(front+1)%size;
        printf("%d has been deleted\n",temp);
    }
}
void search()
{
    int n,i,flag=0,pos;
    printf("Enter number to search : ");
    scanf("%d",&n);
    if(front==-1)
    printf("Underflow\n");
    else
    {
        for(i=0;i<size;i++)
        {
            if(queue[i]==n)
            {
                flag=1;
                pos=i+1;
                break;
            }
        }
        if(flag==1)
        {
            printf("%d is present in position %d\n",n,pos);
        }
        else
        {
            printf("%d is not present\n",n);
        }
    }
}
void isfull()
{
    if((rear+1)%size==front)
    printf("Queue is full\n");
    else
    printf("Queue is not full\n");
}
void isempty()
{
    if(front==-1)
    printf("Queue is empty\n");
    else
    printf("Queue is not empty\n");
}
void display()
{
    int f=front,r=rear;
    if(front==-1 && rear==-1)
    printf("Queue is empty\n");
    else
    {
        printf("Elements in circular queue : \n");
        if(f<=r)
        {
            while (f<=r)
            {
                printf("%d\t",queue[f]);
                f++;
            }
        }
        else
        {
            while(f<=size-1)
            {
                printf("%d\t",queue[f]);
                f++;
            }
            f=0;
            while(f<=r)
            {
                printf("%d\t",queue[f]);
                f++;
            }
        }
    }
}
void main()
{
    int choice=1;
    printf("Enter size of queue : ");
    scanf("%d",&size);
    while(choice!=0)
    {
        printf("\nCircular Queue Operations\n");
        printf("1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\n5.IsFull\n6.IsEmpty\n7.Search\n8.Display\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            enqueue();
            display();
            break;
            case 2:
            dequeue();
            display();
            break;
            case 3:
            if(front==-1)
            printf("Queue is empty\n");
            else
            printf("Front = %d",queue[front]);
            break;
            case 4:
            if(front==-1)
            printf("Queue is empty\n");
            else
            printf("Rear = %d",queue[rear]);
            break;
            case 5:
            isfull();
            break;
            case 6:
            isempty();
            break;
            case 7:
            search();
            break;
            case 8:
            printf("Elements in queue : %d\n",rear+1);
            display();
            break;
            case 9:
            exit(0);
            default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}
