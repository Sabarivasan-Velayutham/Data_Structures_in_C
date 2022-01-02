struct Job
{
    int no , cputime ;  
};

struct Queue
{
    struct Job arr[50] ; 
    int f , r ,size; 
};

void init (struct Queue *q , int limit ) ; 
void enqueue (struct Queue *q , struct Job j ) ;
void dequeue (struct Queue *q ) ; 
int isFull(struct Queue *q) ; 
int isEmpty(struct Queue *q) ;   
void display (struct Queue *q) ; 
