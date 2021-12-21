struct list 
{ 
 char c; 
 struct list *next; 
 struct list *prev; 
}; 

void display(struct list *l); 
struct list *insertfront(struct list *l,char c); void insertend(struct list *l,char c); 
void insertmiddle(struct list *l,char c,char d); struct list * deletion(struct list *l,char d); 
void search(struct list *l,char c); 
void pal(struct list *l); 
void sep(struct list *l); 
void swap(struct list *l,int k); 
