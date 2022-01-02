
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST * insert(struct BST *t,int x);
void inorder(struct BST *root);
// void insert(struct BST *, int x) ;
// void deleted(struct BST *, int x) ;
// void inorder(struct BST *) ;
// void levelorder(struct BST *) ;
// struct BST *find(struct BST *, int x) ;
// struct BST *findmin(struct BST *) ;