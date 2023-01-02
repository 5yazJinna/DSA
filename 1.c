#double hashing

#include<stdio.h>
#include<stdlib.h>
#define size 10
int hash[size];
void initialise()
{
    for(int i=0;i<size;i++)
    {
        hash[i]= -1;
    }

}
void insert()
{
    int value,i;
    printf("Enter a value to be inserted in hash table\n");
    scanf("%d",&value);
    int key=value%11;
    if(hash[key]==-1)
    {
        hash[key]=value;
        printf("Insert success at first instance\n");
        for(i=0;i<size;i++)
        {
            printf("hash[%d] = %d\n",i,hash[i]);
        }
    }
    
    else
    {
        printf("Collision occured\n");    
        int h2=value%5;
        for(int i=0;i<size;i++)
        {
        
        
        int key_new=(key+(i*h2))%10;
        if(hash[key_new]==-1)
        {
            hash[key_new]=value;
            printf("Success\n");
            break;
        }
        printf("collision occurred %d\n",i);
        }
        
        

    }

}
void display()
{
    for(int i=0;i<size;i++)
    {
        printf("hash[%d] = %d\n",i,hash[i]);
    }
}
void main()
{
    initialise();
    int choice;
    while(1)
    {
    printf("1.Insert \t 2.Display \t3.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Enter a valid choice\n");
        break;
    }
    }

}


#stack

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
           // for(int i=0;i<n;i++)
          //  {
                if(stack[top]==val)
                {
                    flag=1;
                    
                }
          //  }
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
        printf("Elements in stack\n");
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
        printf("1.Insert\t2.pop\t3.Display\t4.occurence\t5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
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


#linear

#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
void init()
{   
    int i;
    for(i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}
void insert(int value)
{   
    for(int i=0;i<size;i++)
        {
        
        int val=value%10;
            
        int key = (val+i)% size;
        if(arr[key]==-1)
        {
            arr[key]=value;
            printf("Success\n");
            break;
        }
        printf("collision occurred %d\n",i);
        }
         
        
}

void del(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key = (value+i)% size;
            if(arr[key] == value)
            {   
                arr[key] = -1;
                flag=1;
                printf("Deleted\n");
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not present in table\n");
        }
    
}

void search(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key = (value+i)% size;
            if(arr[key] == value)
            {   
                printf("Search Found at index %d\n",key);
                flag=1;
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not found\n");
        }
    // int key = value % size;
    // if(arr[key] == value)
    //     printf("Search Found\n");
    // else
    //     printf("Search Not Found\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    init();
    int choice,val;
    while(1)
    {
        printf("1.Insert\t2.Delete\t3.Display\t4.Search\t5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&val);
            insert(val);
            break;
            case 2:
            printf("Enter the value to be deleted:");
            scanf("%d",&val);
            del(val);
            break;
            case 3:
            print();
            break;
            case 4:
            printf("Enter the value to be searched:");
            scanf("%d",&val);
            search(val);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

#quad

#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
int c1=1,c2=3;
void init()
{   
    int i;
    for(i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}
void insert(int value)
{   
    
        for(int i = 0; i < size; i++)
        {
            int key_val = value% size;
            int key=(key_val+c1*i+c2*i*i);
            if(arr[key] == -1)
            {   
                arr[key] = value;
                printf("%d inserted at arr[%d]\n", value,key);
                break;
            }
            printf("collision occurred %d\n",i);
            
        }
    
}

void del(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key_val = value% size;
            int key=(key_val+c1*i+c2*i*i);
            if(arr[key] == value)
            {   
                arr[key] = -1;
                flag=1;
                printf("Deleted\n");
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not present in table\n");
        }
    
}

void search(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key_val = value% size;
            int key=(key_val+c1*i+c2*i*i);
            if(arr[key] == value)
            {   
                printf("Search Found at index %d\n",key);
                flag=1;
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not found\n");
        }
    
}


void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    init();
    int choice,val;
    while(1)
    {
        printf("1.Insert\t2.Delete\t3.Display\t4.Search\t5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&val);
            insert(val);
            break;
            case 2:
            printf("Enter the value to be deleted:");
            scanf("%d",&val);
            del(val);
            break;
            case 3:
            print();
            break;
            case 4:
            printf("Enter the value to be searched:");
            scanf("%d",&val);
            search(val);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}


#separate
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
               int data;
               struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
    int i,key;
    printf("\nenter a value to insert into hash table\n");
    scanf("%d",&key);
    i=key%TABLE_SIZE;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next = NULL;
    if(head[i] == NULL)
        head[i] = newnode;
    else
    {
        c=head[i];
        while(c->next != NULL)
        {
           c=c->next;
        }
        c->next=newnode;
    }
}
void search()
{
    int key,index;
    printf("\nenter the element to be searched\n");
    scanf("%d",&key);
    index=key%TABLE_SIZE;
    if(head[index] == NULL)
        printf("\n Search element not found\n");
    else
    {
        // for(c=head[index];c!=NULL;c=c->next)
        c=head[index];
        while(c!=NULL)
        {
            if(c->data == key)
                {
                    printf("search element found\n");
                    break;
                }
                c=c->next;
        }
        if(c==NULL)
            printf("\n Search element not found\n");
   
    }
}

void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nentries at index %d\n",i);
               if(head[i] == NULL)
               {
               printf("No Hash Entry");
               
               }
               else
               {
                c=head[i];
                while(c!=NULL)
                {
                    printf("%d->",c->data);
                    c=c->next;
                }
                            //   for(c=head[i];c!=NULL;c=c->next)
                            //   printf("%d->",c->data);
               }
          }
         
}
void main()
{
    int opt,val,i;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t  \t5.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            //     case 4:
            //      printf("Enter the value to be deleted:");
            // scanf("%d",&val);
            // del(val);
                
                // break;
            case 5:exit(0);
            default:
            printf("Invalid choice\n");
                                           
        }
    }
}