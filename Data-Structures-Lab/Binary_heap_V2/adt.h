struct data
{
    char emp_id;
    int sal_amt;

};
struct priorityQueueADT
{
    struct data d[100];
    int size,ctptr;    
};
void init(struct priorityQueueADT *p,int s);
void insert(struct priorityQueueADT *p,struct data d);
struct data del(struct priorityQueueADT *p);