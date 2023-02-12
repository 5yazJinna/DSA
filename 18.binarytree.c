#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data (0 for no data) :");
    scanf("%d",&x);
    if (x==0)
    {return 0;}
    newnode->data=x;
    printf("\nEnter left child of %d : ",x);
    newnode->left=create();
    printf("\nEnter right child of %d : ",x);
    newnode->right=create();
    return newnode;
}
void display(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d -> ",root->data);
    display(root->left);
    display(root->right);
}
void main()
{
    struct node *root;
    root=create();
    struct node *n=root;
    display(n);
}