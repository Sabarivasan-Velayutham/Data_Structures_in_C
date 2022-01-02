#include<stdio.h>
#include<stdlib.h>
struct numberADT
{
  int size;
  int a[50];
};
void init(struct numberADT *N,int s);
void insertElements(struct numberADT *N, int x[]);
void selSort(struct numberADT *N);
void shellSort(struct numberADT *N);
void display(struct numberADT *N);


