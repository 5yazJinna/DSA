#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *ptr, *preptr, *start=0;
int count=0;

void insert1()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter data to insert : ");
    scanf("%d",&value);
    if(start==0)
    {
        newnode->data=value;
        newnode->next=0;
        start=newnode;
        count++;
        printf("%d has been inserted in the beginning\n",value);
    }
    else
    {
        ptr=start;
        newnode->data=value;
        newnode->next=ptr;
        start=newnode;
        count++;
        printf("%d has been inserted in the beginning\n",value);
    }
    
}

void insert2()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter data to insert : ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=0;
    ptr=start;
    while(ptr->next!=0)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    count++;
    printf("%d has been inserted in the end\n",value);
}

void insert3()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int value,num;
    printf("Enter data to insert : ");
    scanf("%d",&value);
    printf("Enter number after which the data has to be inserted : ");
    scanf("%d",&num);
    if (start==0)
    {
        printf("Underflow - use 1 or 2 to add data to list\n");
    }
    else
    {
        newnode->data=value;
        ptr=start;
        preptr=ptr;
        while(preptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=newnode;
        newnode->next=ptr;
        count++;
        printf("%d has been inserted after %d\n",value,num);
    }
}

void insert4()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int value,num;
    printf("Enter data to insert : ");
    scanf("%d",&value);
    printf("Enter number before which the data has to be inserted : ");
    scanf("%d",&num);
    if (start==0)
    {
        printf("Underflow - use 1 or 2 to add data to list\n");
    }
    else
    {
        newnode->data=value;
        ptr=start;
        preptr=ptr;
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr==start)
        {
            preptr->next=newnode;
            newnode->next=ptr;
            start==newnode;
        }
        else
        {
            preptr->next=newnode;
            newnode->next=ptr;
        }
        count++;
        printf("%d has been inserted before %d\n",value,num);
    }
}

void delete5()
{
    if(start==0)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        start=start->next;
        printf("%d has been deleted from the beginning\n",ptr->data);
        free(ptr);
    }
    count--;
}

void delete6()
{
    if(start==0)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        preptr=ptr;
        while(ptr->next!=0)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=0;
        printf("%d has been deleted from the end\n",ptr->data);
        free(ptr);
        count--;
    }
}

void delete7()
{
    int num;
    printf("Enter number after which the data has to be deleted : ");
    scanf("%d",&num);
    if(start==0)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        preptr=ptr;
        while(preptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        printf("%d has been deleted\n",ptr->data);
        free(ptr);
        count--;
    }
}

void delete8()
{
    int num;
    struct node *temp;
    printf("Enter number before which the data has to be deleted : ");
    scanf("%d",&num);
    if(start==0)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        preptr=ptr;
        temp=preptr;
        while(ptr->data!=num)
        {
            temp=preptr;
            preptr=ptr;
            ptr=ptr->next;
        }
        temp->next=preptr->next;
        printf("%d has been deleted\n",preptr->data);
        free(preptr);
        count--;
    }
}

void delete9()
{
    int num;
    printf("Enter the number to be deleted : ");
    scanf("%d",&num);
    if(start==0)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        preptr=ptr;
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        printf("%d has been deleted\n",ptr->data);
        free(ptr);
        count--;
    }
}

void display()
{
    struct node *temp1;
    temp1=start;
    if(start==0)
    {
        printf("Underflow");
    }
    else
    {
        while (temp1!=0)
        {
          printf("%d\t",temp1->data);
          temp1=temp1->next;
        }
    }
    
}

void main()
{
    int choice=1;
    while(choice!=0)
    {
        printf("\nOperations on Linked list\n");
        printf("1.Insert at beginning\n2.Insert at end\n3.Insert after node\n4.Insert before node\n5.Delete at beginning\n6.Delete at end\n7.Delete after node\n8.Delete before node\n9.Delete given node\n10.Display number of elements\n11.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert1();
            display();
            break;
            case 2:
            insert2();
            display();
            break;
            case 3:
            insert3();
            display();
            break;
            case 4:
            insert4();
            display();
            break;
            case 5:
            delete5();
            display();
            break;
            case 6:
            delete6();
            display();
            break;
            case 7:
            delete7();
            display();
            break;
            case 8:
            delete8();
            display();
            break;
            case 9:
            delete9();
            display();
            break;
            case 10:
            {
                printf("Number of elements = %d\n",count);
                display();
                break;
            }
            case 11:
            exit(0);
            default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}