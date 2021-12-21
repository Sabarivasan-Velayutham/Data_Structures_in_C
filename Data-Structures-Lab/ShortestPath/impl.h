#include "adt.h"
#include<stdio.h>

void init(struct graph * G,int n)
{
 G->no=n;
 for(int i=1;i<=G->no;i++)
 {
   for(int j=1;j<=G->no;j++)
   {
     G->P[i][j]=0;
     if(i==j)
       G->D[i][i]=0;
     else  
       G->D[i][j]=999;
   }
 }
}

void DistanceMatrix(struct graph * G,int start,int end,int cost)
{
 G->D[start][end]=cost;
}

void FloydWarshall(struct graph *G)
{
  for(int k=1;k<=G->no;k++)
  {
   for(int i=1;i<=G->no;i++)
   {
    for(int j=1;j<=G->no;j++)
    {
       if(G->D[i][j]>G->D[i][k]+G->D[k][j])
       {
        G->D[i][j]=G->D[i][k]+G->D[k][j];
        G->P[i][j]=k; 
       }
    }
   }
   printf("\n------------------------------------\n") ; 
   Print(G);
  }
}

void printPath(struct graph * G,int source,int desti)
{
  if(G->P[source][desti]==0)
        printf(" %d",desti);
  else
  {
    printPath(G,source,G->P[source][desti]);
    printPath(G,G->P[source][desti],desti);
  }
}

void Print(struct graph * G)
{
  for(int i=1;i<=G->no;i++)
 {
    printf(" \n");
   for(int j=1;j<=G->no;j++)
   {
     printf(" %d",G->D[i][j]);
   }
 }
  printf(" \n");
 for(int i=1;i<=G->no;i++)
 {
    printf(" \n");
   for(int j=1;j<=G->no;j++)
   {
     printf(" %d",G->P[i][j]);
   }
 }
}