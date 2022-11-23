#include <stdio.h>
#include <stdlib.h>
#define n 10

int saisir(int *T,int k){

    for(int i=0 ; i<k; i++)
    {
        printf("| T[%d] =  ",i+1);
        scanf("%d",&T[i]);
        printf("\n");
    }


}


int inserction(int *T,int k)
{

    int i,value =0,pos=0;
    for(i=1; i<k; i++)
    {

        value = T[i];
        pos = i;

        while(pos>0 && T[pos-1]>value )
        {
            T[pos] = T[pos-1];
            pos = pos -1 ;
        }
        T[pos] = value;
    }

}


int main()
{
int T[n];

saisir(T,n);

inserction(T,n);

printf("\n -------------------\n");

for(int k =0 ; k<n; k++)
printf("|  T[%2d]  =  %2d  |\n",k+1,T[k]);


    return 0;
}
