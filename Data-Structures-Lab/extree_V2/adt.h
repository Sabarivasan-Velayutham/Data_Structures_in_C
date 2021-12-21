struct Node
{
    char ch;
    struct Node *left,*right;
};

struct AddrStackADT
{
    int top,size;
    struct Node* arr[100];
   
};

struct expTree
{
    struct AddrStackADT *st;
    struct Node * node;
};

struct Node *create(char c);
void construct(struct expTree *t,char *pexp);
void push(struct expTree *t,struct Node*n);
struct Node* pop(struct expTree*t);
void infix(struct Node*n);