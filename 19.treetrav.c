#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d -> ",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d -> ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ",root->data);
}
struct node *create()
{
    int x;
    struct node *newnode;
    ;newnode=(struct node*)malloc(sizeof(struct node));
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
int main() {
  struct node *root;
  root=create();
  struct node *n=root;
  printf("Inorder traversal \n");
  inorder(root);

  printf("\nPreorder traversal \n");
  preorder(root);

  printf("\nPostorder traversal \n");
  postorder(root);
}