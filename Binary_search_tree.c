#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int search(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){

        // checking condition and passing right subtree & recusing 
        if (value > root->key) 
            root = root->right; 

        // checking condition and passing left subtree & recusing 
        else if (value < root->key) 
            root = root->left; 
        else
            return 1; // if the value is found return 1 
    } 
    return 0; 
} 


// Driver code
int main() {
  int i,n,val,dval,choice;
  struct node *root = NULL;

 do      
        {  
            printf("\nSelect one of the operations::");  
            printf("\n1. To insert a new node in the Binary Tree");  
            printf("\n2. To delete a value from tree.\n");  
            printf("\n3. To search the node in tree\n");
            printf("\n4. To display the elements in inorder traversal\n");
 
            scanf("%d",&choice);              
            switch (choice)  
            {  
            case 1 :   
                printf("Enter the number of elements to add: ");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                scanf("%d",&val);
                root = insert(root, val);
                }                   
                break;                            
            case 2 :   
                printf("Enter an element to delete: ");
                scanf("%d",&dval);
                root = deleteNode(root, dval); 
                break; 
            case 3 :   
                int item;
                printf("Enter an item to delete: ");
                scanf("%d" ,&item);

                // Function to find item in the tree
                int found = search(root,item);

                if(found)
                    printf("%d value is found in the tree",item);
                else
                    printf("%d value not found",item);

            case 4 :   
                printf("Inorder traversal: ");
                inorder(root); 
                break; 
            default :   
                printf("Wrong Entry\n");  
                break;     
            }  
  
            printf("\nDo you want to continue (Type y or n)\n");  
            scanf(" %c",&choice);                          
        } while (choice == 'Y'|| choice == 'y');  
  
   return 0;  

}
