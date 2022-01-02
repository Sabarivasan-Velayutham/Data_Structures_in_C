
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to get maximum of two integers
int max(int a , int b)
{
    return (a > b )? a : b ;
}
 
// function to get the height of the tree
int height(struct dictionary *d)
{
    if (d == NULL)
        return 0;
    return d->height;
}

struct dictionary *rightRotate(struct dictionary *y)
{
    struct dictionary *x = y->left;
    struct dictionary *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 

struct dictionary *leftRotate(struct dictionary *x)
{
    struct dictionary *y = x->right;
    struct dictionary *T2 = y->left;
 
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
int getBalance(struct dictionary *d)
{
    if (d == NULL)
        return 0;
    return height(d->left) - height(d->right);
}

struct dictionary *insert(struct dictionary *d, struct wordMeaning x) 
{
    // strcmp(first_string, second_string) function 
    // compares two string and returns 0 if both strings are equal.

    /* 1.  Perform the normal BST insertion */
    if(d==NULL)
    {
        d = (struct dictionary *)malloc(sizeof(struct dictionary));
        // d = (struct dictionary *)malloc(sizeof(struct dictionary));
        d->w = x;
        d->left=NULL;
        d->right=NULL;
        d->height = 1 ; 
    }
 
    if (strlen(x.word) < strlen(d->w.word))
        d->left  = insert(d->left, x);
    else if ( strlen(x.word) > strlen(d->w.word))
        d->right  = insert(d->right, x);
    else // Equal keys are not allowed in BST
        return d;
 
    /* 2. Update height of this ancestor node */
    d->height = 1 + max(height(d->left),height(d->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(d);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && strlen(x.word) < strlen(d->left->w.word) )
        return rightRotate(d);
 
    // Right Right Case
    if (balance < -1 && strlen(x.word) > strlen(d->right->w.word) )
        return leftRotate(d);
 
    // Left Right Case
    if (balance > 1 && strlen(x.word) > strlen(d->left->w.word) )
    {
        d->left =  leftRotate(d->left);
        return rightRotate(d);
    }
 
    // Right Left Case
    if (balance < -1 && strlen(x.word) < strlen(d->right->w.word) )
    {
        d->right = rightRotate(d->right);
        return leftRotate(d);
    }
 
    /* return the (unchanged) node pointer */
    return d;
}
 
void preOrder(struct dictionary *root)
{
    if(root != NULL)
    {
        printf("%s - %s\n", root->w.word , root->w.meaning) ;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void display(struct dictionary *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%s - %s\n", root->w.word , root->w.meaning) ;
        display(root->right);
    }
}

void search(struct dictionary *d, char *word) 
{
    // if the key is not present in the key
    if (d == NULL)
        printf("\nElement not found ...") ; 
 
    // if the key is found
    else if (d->w.word == word)
    {
        printf("\nElement found :)") ;
        printf("\nMeaning : %s",d->w.meaning) ;
    }

    else if (strlen(word) < strlen(d->w.word)) 
        search(d->left,word);
    else 
        search(d->right,word);
}