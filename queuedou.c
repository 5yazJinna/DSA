#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void peek();  
void enqueue();  
void dequeue();  
void display();  
void search();  
void main ()  
{  
int choice =0;  
     printf("\nDoubly Linked List implementation of Queue\n"); 
    while(choice != 6)  
    {  
        printf("\nChoose one option \n");  
        printf("\n1.Insert \n2.Delete \n3.Search\n4.Show\n5.Peek\n6.Exit");  
        printf("\nEnter your choice: ");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                    enqueue(); display(); 
            break;  
            case 2:  
                    dequeue(); display(); 
            break;  
            case 3:  
            search();  
            break;  
            case 4:  
            display();  
            break; 
            case 5:
            peek();
            break;
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice");  
        }  
    }  
}  

void enqueue()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n Insert elements\n");  
   }  
   else  
   {  
       printf("\nEnter value : ");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\n node inserted\n");  
    }  

void dequeue()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n Queue is empty");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\n node deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\n node deleted\n");  
    }  
  
}  


void display()  
{  
    struct node *ptr;  
    printf("\nElements in Queue\n");  
    ptr = head;  
    while(ptr != NULL)
    { 
     if(ptr != NULL)    
        {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
        }  
     else
        {
        printf("Queue is empty"); 
        }
        
    }
}   
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\n Queue is Empty\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search: \n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\n Item found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\n Item not found\n");  
        }  
    }     
          
}  
void peek()
{
    printf("The peek element: %d",head->data);
}
