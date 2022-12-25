#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int choice, pos;
struct node *head, *newnode, *temp, *pretemp, *temp2;
void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void creating_linklist()
{
    head = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nEnter 1 to add and 0 to quit:\n");
        scanf("%d", &choice);
    }
    display();
}
void insert_at_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->next = head;
    head = newnode;
    display();
}
void insert_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    display();
}
void insert_at_specific_position()
{
    printf("\nenter the position to insert:\n");
    scanf("%d", &pos);
    if(pos==1){
        insert_at_beginning();
    }
    else{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    int i = 1;
    while (i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    display();
    }
}
void delete_at_beginning()
{
    temp = head;
    head = head->next;
    free(temp);
    display();
}
void delete_at_end()
{
    temp = head;
    while (temp->next != 0)
    {
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = 0;
    free(temp);
    display();
}
void delete_at_specific_position()
{
    int i = 1;
    printf("enter the position to delete:\n");
    scanf("%d", &pos);
    if(pos==1){
        delete_at_beginning();
    }
    else{
    temp = head;
    while (i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    display();
    }
}
int main()
{
    while (choice != 9)
    {
        printf("\npress 1 to create\npress 2 to insert at beginning\npress 3 to insert at end\npress 4 to insert at specific position\npress 5 to delete at beginning\npress 6 to delete at last\npress 7 to delete at specific positiom\npress 8 to quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            creating_linklist();
            break;
            case 2:
            insert_at_beginning();
            break;
            case 3:
            insert_at_end();
            break;
            case 4:
            insert_at_specific_position();
            break;
            case 5:
            delete_at_beginning();
            break;
            case 6:
            delete_at_end();
            break;
            case 7:
            delete_at_specific_position();
            break;
            case 8:
            return choice = 0;
            break;
            default:
            printf("invalid input");
            break;
        }
    }
}