
#include <stdio.h>
#include <stdlib.h>

struct BST *insert(struct BST *root,int x)
{
   if (root == NULL) 
   {
       root = (struct BST *)malloc(sizeof(struct BST)) ; 
       root -> data = x  ;
       root -> left = root -> right = NULL ; 
   } 
   else if (x < root-> data ) root -> left = insert (root->left,x) ;
   else root -> right =  insert(root->right,x); 
}

void inorder(struct BST *root)
{
    if(root->left)    inorder(root->left);
    printf("%d\n",root->data);
    if(root->right)   inorder(root->right);
}


void mod_inorder(struct BST *root , int arr[] , int *n)
{
    if(root->left)
        mod_inorder(root->left,arr,n);
    arr[(*n)++] = root -> data ; 
    if(root->right)
        mod_inorder(root->right,arr,n);
}

int findmin(struct BST *root) 
{
    if(root -> left == NULL)
        return root -> data ;
    else
        return findmin(root -> left);
}

void find(struct BST *root, int x)
{
    // if the key is not present in the key
    if (root == NULL)
        printf("\nElement not found ...") ; 
 
    // if the key is found
    else if (root->data == x)
        printf("\nElement found :)") ;

    else if (x < root->data) 
        find(root->left,x);
    else 
        find(root->right,x);
}

struct BST *findmin_address(struct BST *root )
{
    if (root->left=NULL) return root ; 
    return findmin_address(root->left) ; 
}

struct BST* delete(struct BST* root, int x)
{
    if (root == NULL ) return root ; 
    else if (x < root->data) delete(root->left,x);
    else if (x > root -> data ) de;ete (root->right,x);
    else
    {
        struct BST temp* = (struct BST *)malloc(sizeof(struct BST)) ; 
        if (root->left==NULL)
        {
            temp = root->right ; 
            free(root);
            return temp ; 
        }
        if (root->right==NULL)
        {
            temp = root->left ; 
            free(root);
            return temp ; 
        }
        temp = findmin_address(root->right) ; 
        root -> data = temp->data
        return delete(root->right,temp->right) ; 
    }
    return root ; 
}