struct Stack 
{
    int data[100] ; 
    int size , top ; 
} ; 

void init (struct Stack * , int limit) ; 
int isFull(struct Stack *) ; 
int isEmpty(struct Stack *) ; 
void push (struct Stack * , int data) ; 
void pop (struct Stack *) ; 
int gettop(struct Stack *) ; 