#include <stdio.h>
#include <stdlib.h>

int fact();

int main()
{
    int a;

    printf("Enter a numbr which you want to calcul it's fact : ");
    scanf("%d",&a);
    printf("%d! = %d .\n", a,fact(a));


    return 0;
}


int fact(int k)
{
    if ( (k==0) ||	(k==1)	)
        return 1;
    else
        return k*fact(k-1);
}

