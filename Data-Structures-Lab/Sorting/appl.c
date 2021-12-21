#include "impl.h"
int main()
{
    
    int c,n,num;
    printf("Enter size: ");
    scanf("%d",&n);
    int x[n];
    for(int i=0;i<n;i++)
    {
      printf("Enter data: ");
      scanf("%d",&num);
      x[i]=num;
    }
    char ch;
    struct numberADT *N=malloc(sizeof(struct numberADT));
    init(N,n);
    insertElements(N,x);
    do
    {
      printf("MENU\n");
      printf("1.To Perform Selection sort\n");
      printf("2.To Perform Shell sort\n");
      printf("3.Display the array\n");
      printf("Enter your choice:");
      scanf("%d",&c);
      switch(c)
      {
        case 1 :
          selSort(N);
          break;
        case 2 :
          shellsort(N);
          break;
        case 3 :
          display(N);
          printf("\n");
          break;
        default:
          printf("Invalid choice"); 
      }
      printf("\nDo you want to continue? y/n  ");
      scanf(" %c",&ch);
    }while(ch=='y');
}
