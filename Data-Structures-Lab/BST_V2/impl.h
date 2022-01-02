
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

struct BST *insert(struct BST *root,int x)
{
    if(root==NULL)
    {
        root=(struct BST *)malloc(sizeof(struct BST));
        root->data=x;
        root->left=NULL;
        root->right=NULL;
    }
    else if(x < root -> data)
        root -> left = insert(root -> left,x);
    else if(x > root -> data)
        root -> right = insert(root -> right,x);

    return root;
}

void inorder(struct BST *root)
{
    if(root->left)
        inorder(root->left);
    printf("%d\n",root->data);
    if(root->right)
        inorder(root->right);
}

// void levelorder(struct BST *root) 
// {
//     printf("%d\n", root->data);
//     if (root -> left)
//         levelorder(root->left);
//     if (root->right)
//         levelorder(root->right);
// }

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
    struct BST* current = root;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct BST* delete(struct BST* root, int x)
{
    if (root == NULL) return root;
        if (x < root->data)
            root->left = delete(root->left, x);
        else if (x > root->data)
            root->right = delete(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            struct BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BST *temp = root->left;
            free(root);
            return temp;
        }
        struct BST* temp = findmin_address(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void mod_inorder(struct BST *root , int arr[] , int *n)
{
    if(root->left)
        mod_inorder(root->left,arr,n);
    arr[(*n)++] = root -> data ; 
    if(root->right)
        mod_inorder(root->right,arr,n);
}

// a. Check whether the two BST contains the same set of elements
void similar(struct BST* root1 , struct BST* root2 , int arr1[] , int arr2[] , int *n , int *m)
{
    if (*n==*m)
    {
        mod_inorder(root1,arr1,n) ; 
        mod_inorder(root2,arr2,m) ;
        int chk = 0 ; 
        for (int i = 0 ; i < *n ; i++)
        {
            if (arr2[i] != arr1[i])
            {
                chk = 1 ; 
                printf("\nDisimilar elements in both trees ...") ;
                break ; 
            } 
        }

        if (chk == 0 )
            printf("\nBoth trees are similar ") ;

    } 

    else
        printf("\nNumber of nodes in both trees are unequal ...") ; 
}


