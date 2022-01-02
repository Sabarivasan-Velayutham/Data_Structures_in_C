#include "impl.h"
#include <stdlib.h>

int main ()
{
    city *c = (city *)malloc(sizeof(city)) ;
    create(c);
    display(c);
    bfs(c,'A'); 
    dfs(c,'A');
}