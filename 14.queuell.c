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
    if (count==size)
    {
        printf("Overflow\n");
    }
    else
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to push : ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(front==0)
        {
            front=newnode;
            rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
        count++;
        printf("%d has been inserted\n",newnode->data);
    }
}

void dequeue()
{
    if(rear==0)
    {
        printf("Underflow\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        int value=front->data;
        front=front->next;
        free(temp);
        printf("%d has been deleted\n",value);
        count--;
    }
}

void isfull()
{
    if (count==size)
    printf("Queue is full\n");
    else
    printf("Queue is not full\n");
}

void isempty()
{
    if(rear==0)
    printf("Queue is empty\n");
    else
    printf("Queue is not empty\n");
}

void search()
{
    if(rear==0)
    {
        printf("Underflow\n");
    }
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

void display()
{
    if(rear==0)
    {
        printf("Underflow\n");
    }
    else
    {
        struct node *temp;
        temp=front;
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
    printf("Enter size of queue : ");
    scanf("%d",&size);
    while(choice!=0)
    {
        printf("\nQueue Operations\n");
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
            printf("Front = %d",front->data);
            break;
            case 4:
            printf("Rear = %d",rear->data);
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
            printf("Number of elements in queue : %d\nElements in queue : \n",count);
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