#include<stdio.h>
#include<stdlib.h>
int queue[100],size,front=0,rear=-1;
void enqueue()
{
    int n;
    if(rear==size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d",&n);
        rear=rear+1;
        queue[rear]=n;
        printf("%d has been inserted\n",n);
    }
}
void dequeue()
{
    int temp,i;
    if(rear==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        temp=queue[front];
        for(i=0;i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
        printf("%d has been deleted\n",temp);
    }
}
void search()
{
    int n,i,flag=0,pos;
    printf("Enter number to search : ");
    scanf("%d",&n);
    for(i=0;i<=rear;i++)
    {
        if(queue[i]==n)
        {
            flag=1;
            pos=i+1;
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
void isfull()
{
    if(size==rear+1)
    printf("Queue is full\n");
    else
    printf("Queue is not full\n");
}
void isempty()
{
    if(rear==-1)
    printf("Queue is empty\n");
    else
    printf("Queue is not empty\n");
}
void display()
{
    int i;
    for(i=0;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}
void main()
{
    int choice=1;
    printf("Enter size of queue : ");
    scanf("%d",&size);
    while(choice!=0)
    {
        printf("\nQUEUE OPERATIONS\n");
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
            printf("Front = %d",queue[front]);
            break;
            case 4:
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
            printf("Number of elements in queue : %d\nElements in queue : \n",rear+1);
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