#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
void scan(int *a,int j){


for(int i=0 ; i<j;i++){

    a[i] = (rand()%13 + 1) ;

}

}



int max(int  *a , int k)
{
    int max;
    max = a[0];
    for(int i=1 ; i<k ; i++)
    {
        if(max<a[i] )
        max = a[i];
    }
    return max;
}



int main()
{

int a[n];
srand(time(0));
scan(a,n);



    for(int i=0;i<n;i++)
        printf("|  A[%d] = %d \n\n",i+1,a[i] );
  printf("max  = %d   ",max(a,n));


    return 0;
}
