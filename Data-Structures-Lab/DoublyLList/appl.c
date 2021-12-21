
#include "impl.h" 
int main() 
{ 
 printf("enter  1.insertfront,2.insertend,3.insertmiddle,4.delete,5.search,6.palindrome,7.sepa rate vowels and cons,8.swapping"); 
 int z,k;int a=1;char c,d,temp;struct list *l;l=NULL; 
 while(a) 
 { 
 printf("\nENTER CHOICE:"); 
 scanf("%d",&z); 
 switch(z) 
 { 
 case 1: 
 scanf("%c",&temp); 
 printf("enter character\n"); 
 scanf("%c",&c); 
 l=insertfront(l,c); 
 break; 
 case 2: 
 scanf("%c",&temp); 
 printf("enter character\n"); 
 scanf("%c",&c); 
 insertend(l,c); 
 break; 
 case 3: 
 scanf("%c",&temp); 
 printf("enter characters\n"); 
 scanf("%c %c",&c,&d); 
 insertmiddle(l,c,d); 
 break; 
 case 4:
 scanf("%c",&temp); 
 printf("enter character\n");  scanf("%c",&c); 
 deletion(l,c); 
 break; 
 case 5: 
 scanf("%c",&temp); 
 printf("enter character\n");  scanf("%c",&c); 
 search(l,c); 
 break; 
 case 6: 
 pal(l); 
 break; 
 case 7: 
 sep(l); 
 break; 
 case 8: 
 scanf("%c",&temp); 
 printf("enter k\n"); 
 scanf("%d",&k); 
 swap(l,k); 
 break; 
 } 
 printf("enter 1 to continue");scanf("%d",&a);  } 
 display(l); 
} 
