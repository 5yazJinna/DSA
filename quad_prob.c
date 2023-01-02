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
            printf("Collision Occurred %d\n",i);
            
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
        printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Search\n\t5.Exit\n");
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