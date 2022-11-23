#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
int scan(int *T,int g)
{

    for(int y=0 ; y<g ; y++)
    {
        printf(" T[%d] = ",y+1);
        scanf("%d",&T[y]);
        printf("\n");
    }

}
int mini(int *T,int i,int in)
{
    int temp;
    temp = T[i];
    T[i] = T[in];
    T[in] = temp;
}
int print(int *T,int b)
{


    printf("\n -------------------\n");

    for(int k =0 ; k<b; k++)
        printf("|  T[%2d]  =  %2d  |\n",k+1,T[k]);



}

int sele(int *T,int k)
{
    int m,index;
    for(int i=0; i<k; i++)
    {
        m = T[i];
        index = i;
        for(int j=i+1; j<(k); j++)
        {
            if(T[j]<m)
            {
                m = T[j];
                index= j;
                printf("m = %d\n",m);
            }
        }
        mini(T,i,index);
    }

}

int main()
{
    int T[n];
    scan(T,n);
    sele(T,n);
    print(T,n);

    return 0;
}
