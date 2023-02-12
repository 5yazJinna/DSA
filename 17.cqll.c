#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *rear=0,*front=0;
int size,count=0;
void enqueue()
{
    int n;
    if(count==size)
    {
        printf("Overflow\n");
    }
    else
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element : ");
        scanf("%d",&n);
        newnode->data=n;
        if(front==0)
        {
            newnode->next=0;
            rear=front=newnode;
        }
        else
        {
            newnode->next=front;
            rear->next=newnode;
            rear=newnode;
        }
        count++;
        printf("%d has been inserted\n",n);
    }
}
void dequeue()
{
    struct node *temp;
    if(front==0)
    printf("Underflow\n");
    else
    {
        if(count==1)
        front=rear=0;
        else if(count==2)
        {
            temp=front;
            front=front->next;
            rear->next=0;
        }
        else
        {
            temp=front;
            front=front->next;
            rear->next=front;
            count--;
        }
        printf("%d has been deleted\n",temp->data);
    }
}
void search()
{
    if(rear==0)
    printf("Underflow\n");
    else
    {
        struct node *temp;
        temp=front;
        int n,index=1,flag=0;
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
                index++;
            }
        }
        if (flag==1)
        printf("%d is present in position %d\n",n,index);
        else
        printf("%d is not present\n",n);
    }
}
void isfull()
{
    if(count==size)
    printf("Queue is full\n");
    else
    printf("Queue is not full\n");
}
void isempty()
{
    if(front==0)
    printf("Queue is empty\n");
    else
    printf("Queue is not empty\n");
}
void display()
{
    if(front==0)
    printf("Underflow");
    else
    {
        struct node *temp;
        temp=front;
        if(front==rear)
        printf("%d\t",temp->data);
        else
        {
            printf("%d\t",temp->data);
            temp=temp->next;
            while(temp!=front)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
        }
    }
    printf("\n");
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
            if(front==0)
            printf("Queue is empty\n");
            else
            printf("Front = %d\n",front->data);
            break;
            case 4:
            if(front==0)
            printf("Queue is empty\n");
            else
            printf("Rear = %d\n",rear->data);
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
            printf("Elements in circular queue : %d\n",count);
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