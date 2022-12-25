#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void preorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);   
    }
}
void inorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ->", root->data);
        inorder(root->right);   
    }
}
void postorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->", root->data);   
    }
}
struct node* createnode()
{
    
    int value;
    struct node *new=malloc(sizeof(struct node));
    printf("Enter the value:(-1 for termination)\n");
    scanf("%d",&value);
    if (value==-1)
    {
        return 0;
    }
    new->data=value;
    printf("Enter the left child of %d\n",value);
    new->left=createnode();
    printf("Enter the right child of %d\n",value);
    new->right=createnode();
    return new;
};
void display()
{
    int choice1;
    printf("Please choose any one option:\n");
    printf("1.Pre-Order Traversal\n2.In-Order Traversal\n3.Post-Order Traversal\n");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1:
        printf("PRE-ORDER TRAVERSAL\n");
        preorder(root);
        break;
    case 2:
        printf("IN-ORDER TRAVERSAL\n");
        inorder(root);
        break;
    case 3:
        printf("POST-ORDER TRAVERSAL\n");
        postorder(root);
        break;
    default:
        printf("Wrong Option\n");
        break;
    }
}
void search(struct node *root,int item)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        if (root->data==item)
        {
            printf("Element is present\n");
            return;
        }
        else
        {
            search(root->left,item);
            search(root->right,item);
        }
    }
}
void main()
{
    int choice,item;
    printf("BINARY TREE OPERATIONS\n");
    while (choice!=0)
    {
        printf("Please enter any one option:\n");
        printf("\n1.Insertion\n2.Traversal\n3.Search\nCaution:\nThis options is based on root node\nPress 0 for Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("INSERTION\n");
            root=createnode();
            break;
        case 2:
            printf("TRAVERSAL\n");
            display();
            break;
        case 3:
            printf("SEARCH\n");
            printf("Enter the value to search:\n");
            scanf("%d",&item);
            search(root,item);
            break;
        default:
            printf("Wrong Option....");
            break;
        }
    }
}
