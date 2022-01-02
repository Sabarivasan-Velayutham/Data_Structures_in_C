

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

void push(struct Node *node,struct AddrStackADT*st);
void pop(struct AddrStackADT *st);
void display(struct AddrStackADT*st);