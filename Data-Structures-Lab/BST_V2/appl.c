#include "impl.h"


//no function ; direct application in appl.c 
// b. Check whether the BST is complete or not


int main()
{
    struct BST *t1 = NULL;
    struct BST *t2 = NULL;

    t1=insert(t1,10);
    t1=insert(t1,5);
    t1=insert(t1,50);
    t1=insert(t1,1);
    t1=insert(t1,40);
    t1=insert(t1,100);

    t2=insert(t2,10);
    t2=insert(t2,5);
    t2=insert(t2,50);
    t2=insert(t2,1);
    t2=insert(t2,40);
    t2=insert(t2,100);

    inorder(t1);
    printf("-----------------------\n") ;
    inorder(t2);
    printf("-----------------------\n") ;

    //to check similarity in trees 
    int arr1[10] , arr2[10];
    int *n = (int *)malloc(sizeof(int)) ;
    int *m = (int *)malloc(sizeof(int)) ;
    similar(t1, t2, arr1, arr2, n, m) ; 


    //no function ; direct application in appl.c 
    // b. Check whether the BST is complete or not

    int c=0;
    printf("\nEnter start and end of range of tree 1:");
    int s1,e1,s2,e2;
    int c1[20],c2[20],v1=0,v2=0;
    scanf("%d",&s1);
    scanf("%d",&e1);

    for(int i=0;i<*n;i++)
    {
        if(arr1[i]>=s1&&arr1[i]<=e1)
            c1[v1++]=arr1[i];
    }

    printf("\n");
    printf("Enter start and end of range of tree 2:\n");
    scanf("%d",&s2);
    scanf("%d",&e2);

    for(int i=0;i<*n;i++)
    {
        if(arr2[i]>=s2&&arr2[i]<=e2)
            c2[v2++]=arr2[i];
    }

    printf("\nNodes in tree 1 : %d\n",v1);
    for(int j=0;j<v1;j++)
        printf(" %d ",c1[j]);
    printf("\n");
    printf("Nodes in tree 2 : %d\n",v2);
    for(int k=0;k<v2;k++)
        printf(" %d ",c2[k]);

}