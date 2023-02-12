#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *parent=NULL;
int count=0;
struct node *create(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int val)
{
    if (root==NULL)
    return create(val);
    if(val<root->data)
    root->left=insert(root->left,val);
    else if(val>root->data)
    root->right=insert(root->right,val);
    return root;
}
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
void display()
{
    if(parent==NULL)
    printf("Tree is empty\n");
    else
    {
        printf("Inorder traversal \n");
        inorder(parent);
        printf("\nPreorder traversal \n");
        preorder(parent);
        printf("\nPostorder traversal \n");
        postorder(parent);
        printf("\n");
    }
}
int search(struct node* root, int value) 
{ 
    while (root != NULL)
    {
        if (value > root->data) 
        root = root->right; 
        else if (value < root->data) 
        root = root->left; 
        else
        return 1;
    } 
    return 0; 
} 
struct node* minvalue(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
    {
        current = current->left;
    }
	return current;
}
struct node* delete(struct node* root, int key)
{
	if (root == NULL)
	return root;
	if (key < root->data)
	root->left = delete(root->left, key);
	else if (key > root->data)
	root->right = delete(root->right, key);
	else 
    {
		if (root->left == NULL)
        {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) 
        {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minvalue(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
	}
	return root;
}

void main()
{
    int choice=1,val,n,find,del;
    struct node*root=NULL;
    while(choice!=0)
    {
        printf("\nTree Operations\n");
        printf("1.Insert\n2.Delete\n3.Search\n4.Is empty\n5.Display\n6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter value to insert : ");
            scanf("%d",&val);
            if(count==0)
            {
                root=insert(root,val); 
                parent=root;
            }
            else
            insert(root,val);
            count++;
            display();
            break;
            case 2:
            printf("Enter value to delete : ");
            scanf("%d",&del);
            delete(root,del);
            display();
            break;
            case 3:
            printf("Enter value to search : ");
            scanf("%d",&n);
            find=search(parent,n);
            if(find==1)
            printf("%d is found in tree\n",n);
            else
            printf("%d is not found in tree\n",n);
            break;
            case 4:
            if(parent==NULL)
            printf("Tree is empty\n");
            else
            printf("Tree is not empty\n");
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
            default:
            printf("Enter a valid choice : ");
            break;
        }
    }  
}