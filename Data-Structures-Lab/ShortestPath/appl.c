#include "impl.h"
#include<stdlib.h>

int main()
{
  int start,end,cost;
  struct graph * G=(struct graph *)malloc(sizeof(struct graph));
  printf("Enter vertices : ");
  int n;
  scanf( "%d",&n);
  init(G,n);
  Print(G);
  printf("\nEnter no of edges :");
  int ne;
  scanf( "%d",&ne);
  for(int i=0;i<ne;i++)
  {
    printf("Enter start end and cost:");
    scanf( "%d %d %d",&start,&end,&cost);
    DistanceMatrix(G,start,end,cost);
  }
   Print(G);
   FloydWarshall(G);
   printf("\n");
   printf(" Path : \n") ; 
   printf(" 1");
   printPath(G,1,3);
}