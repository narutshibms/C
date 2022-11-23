#include <stdio.h>
#include <stdlib.h>


int main()
{
 int n,x,c1=0,c2=0;
 printf("donner n&x : ");
 scanf("%d%d",&n,&x);

printf("les deviseur de %d are ",n);
 for(int i=2 ; i<n;i++)

 if(n%i==0){
      printf("%d ",i);
    c1= c1 + i;
 }
 printf("= %d \n",c1);
 printf("les deviseur de %d are ",x);
 for(int i=2 ; i<x;i++)

 if(x%i==0){
      printf("%d ",i);
    c2= c2 + i;
 }
 printf("= %d \n",c2);
if(c1==x && c2==n )
    printf("\n\n %d and %d are friends ! ",x,n);
    printf("\n\n %d and %d are not friends ! ",x,n);



    return 0;
}
