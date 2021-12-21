#include "impl.h"
#include<stdlib.h>
int main()
{
    struct priorityQueueADT *p=(struct priorityQueueADT *)malloc(sizeof(struct priorityQueueADT));
    init(p,5);
    insert(p,14);
    insert(p,16);
    insert(p,22);
    insert(p,11);
    insert(p,9);
    insert(p,18);
    insert(p,10);
    insert(p,7);
    insert(p,4);
    insert(p,1);
    display(p);
    
}