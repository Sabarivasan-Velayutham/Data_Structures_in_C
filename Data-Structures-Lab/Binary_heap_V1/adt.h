struct priorityQueueADT
{
    int elt[100],size,ctptr;    
};

void init(struct priorityQueueADT *p,int s);
void insert(struct priorityQueueADT *p,int d);
int del(struct priorityQueueADT *p);