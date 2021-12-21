#include "impl.h"

int main()
{
    struct avl *t = NULL;

    t=insert(t,29);
    t=insert(t,12);
    t=insert(t,13);
    t=insert(t,4);
    t=insert(t,45);
    t=insert(t,54);
    // t=insert(t,45);
    // t=insert(t,56);
    // t=insert(t,49);

    inorder(t);
    // printf("-----------------------\n") ;

}