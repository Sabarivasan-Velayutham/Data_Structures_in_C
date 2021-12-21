#include "impl.h"
#include<stdlib.h>
void employee(struct priorityQueueADT *p)
{
    struct data d;
    d.sal_amt=15000;
    d.emp_id='A';
    insert(p,d);
    d.sal_amt=12000;
    d.emp_id='K';
    insert(p,d);
    d.sal_amt=4000;
    d.emp_id='R';
    insert(p,d);
    d.sal_amt=3500;
    d.emp_id='T';
    insert(p,d);
    d.sal_amt=4600;
    d.emp_id='L';
    insert(p,d);
    d.sal_amt=6000;
    d.emp_id='P';
    insert(p,d);
    d.sal_amt=8600;
    d.emp_id='Y';
    insert(p,d);
    display(p);
    printf("\n\nDeletion:\n");
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
    d=del(p);
    printf("(%c,%d)\n",d.emp_id,d.sal_amt);
}
int main()
{
    struct priorityQueueADT *p=(struct priorityQueueADT *)malloc(sizeof(struct priorityQueueADT));
    init(p,7);
    employee(p);
    
}