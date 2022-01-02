
#include "impl.h"
int main()
{
    struct poly *h1=(struct poly *)malloc(sizeof(struct poly));
    struct poly *h2=(struct poly *)malloc(sizeof(struct poly));
    int coeff, exp,n,i;
    h1->next=NULL,h2->next=NULL;
    int ask=1;
    printf("enter no of terms in first polynomial : \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter coeff and exp : \n");
        scanf("%d %d",&coeff,&exp);
        insertend(h1,coeff,exp);
    }

    printf("enter no of terms in second polynomial : \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter coeff and exp : \n");
        scanf("%d %d",&coeff,&exp);
        insertend(h2,coeff,exp);
    }

    struct poly *b=(struct poly *)malloc(sizeof(struct poly));
    struct poly *a=(struct poly *)malloc(sizeof(struct poly));

    while(ask)
    {
    printf("\nenter 1 for addition,2 for multiplication 4 for degree and 5 for evaluation : ");
    int choice;scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nadded polynomial is : ");
        a=addition(h1,h2);a=simplify(a);
        display(a);
        break;

        case 2:
        printf("\nmultiplied polynomial is : ");
        b=multiply(h1,h2);b=simplify(b);
        display(b);
        break;

        case 4:
        printf("degree of polynomial1 is : %d and polynomial2 is : %d\n",degree(h1),degree(h2));
        break;

        case 5:
        printf("\n%d is the evaluated answer of poly1\n",evaluate(h1));
        printf("\n%d is the evaluated answer of poly2\n",evaluate(h2));
        break;
    }

        printf("press 1 to continue 0 to finish");
        scanf("%d",&ask);
    }
}
