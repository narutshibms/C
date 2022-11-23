#include <stdio.h>
#include <stdlib.h>
#define x 6

int saisir(int *T,int k)
{

    for(int i=0 ; i<k; i++)
    {
        printf("T[%d] =  \n",i+1);
        scanf("%d",&T[i]);

    }


}
int bul(int *T,int n){
int temp = 0;

for(int i=0 ; i<n ; i++)
   for(int j=i+1 ; j< n;j++) {
        if (T[j]>T[j+1])
        {
            temp = T[j];
            T[j] = T[j+1];
            T[j+1] = temp;
        }
    }
}

int main()
{
    int T[x],temp=0;

    saisir(T,x);

    bul(T,x);


    for(int i =0 ; i<x; i++)
    printf("T[%d] =  %d \n",i+1,T[i]);







    return 0;
}
