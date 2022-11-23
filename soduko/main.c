#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double k )
{
    return cos(k)-k;
}

int main()

{
    double a,b,mid=0.001;

    printf("donner a & b :  ");
    scanf("%lf",&a);
    scanf("%lf",&b );
 int c=0;

    while(  c<50){
        mid= (a + b)/2;

        printf("a = %0.10f  mid = %lf   b = %0.10f  \n\n",a,mid,b);

        if(f(a)*f(mid)<=0 )
            {  b=mid; c++;
            printf("in mid ");}

        else if( f(mid)*f(b) <= 0 )
       {      a=mid ;c++;
            printf("out mid ");

        }
        else
            break;
    }

    printf("-------------- end ");






    return 0;
}

