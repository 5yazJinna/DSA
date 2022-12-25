#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front,*rear;
void push(){
    struct node *newnode;
    int item;
    printf("Enter item to insert:");
    scanf("%d",&item);
    if(front==NULL){
       front=(struct node *)malloc(sizeof(struct node));
       front->data=item;
       front->next=NULL;
       rear=front;
    }
    else{
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=item;
       newnode->next=NULL;
       rear->next=newnode;
       rear=newnode;
    }
}
void pop(){
    struct node *ptr;
    if(front==NULL)
       printf("Queue is empty");
    else{
        ptr=front;
        front=front->next;
        printf("Item deleted:%d\n",ptr->data);
        free(ptr);
    }
}
void peek(){
    printf("First element is:%d\n",front->data);
}
void display(){
    struct node *ptr;
    if(front==NULL){
        printf("Queue is empty");
    }else{
        ptr=front;
        printf("The elements are:\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void search(int no)
{
    int count=0,pos=0;
    struct node *temp=front;
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else{
        while(temp!=NULL)
        {
            pos+=1;
            if(temp->data==no)
            {
                printf("Item found in Queue[%d]\n",pos);
                count+=1;
            }
            temp = temp->next;
        }
        printf("There are %d in list\n",count);
    }
    
}



int main(){
    int choice,val;
    while(1){
        printf("Operations:\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Search\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:printf("Enter element to be searched:");scanf("%d",&val);search(val);break;
            case 6:exit(0);
            default:printf("Wrong choice!");
        }
    }
}
