
struct avl
{
    int data;
    struct avl *left;
    struct avl *right;
    int height ; 
};

/*
max just return max val
height 
return null else t->ht
getbalance return 0 hright(t-left)-heigth(t-right)
left rotate 
*/
struct bst *insert(struct bst *t,int x )
{
    if (t == NULL)
    {
        t->left=t->right=null;
        t->ht=1;
        t->data=x
    }
    //update nopde ancestor 
    node->ht = 1+(max(heigth(t->left),height(t->right)));

    int ball = getbalnace(node ) ; 

    if (ball>1 && x < t->left->data) right rotate 
    if (ball<-1 && x > t->right->data) left rotate 
    if (ball>1 && x > t->left->data) temp = leftrotae(temp),right rotate 
    if (ball>1 && x < t->left->data)
}