
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

// function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
// function to get the height of the tree
int height(struct avl *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct avl *rightRotate(struct avl *y)
{
    struct avl *x = y->left;
    struct avl *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 

struct avl *leftRotate(struct avl *x)
{
    struct avl *y = x->right;
    struct avl *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node n
int getBalance(struct avl *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
 
struct avl* insert(struct avl* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if(node==NULL)
    {
        node=(struct avl *)malloc(sizeof(struct avl));
        node->data=key;
        node->left=NULL;
        node->right=NULL;
        node->height = 1 ; 
    }
 
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
void preOrder(struct avl *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inorder(struct avl *root)
{
    if(root->left)
        inorder(root->left);
    printf("%d\n",root->data);
    if(root->right)
        inorder(root->right);
}