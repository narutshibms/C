#include <stdio.h>
#include <stdlib.h>
#include <time.h>



double racine(double n){

if ( n==0.0 || n == 1.0)
    return 1.0;
else
    return ((racine(n-1.0)/2.0)+(n/(racine(n-1.0)*2.0)));

}


int main(){


int i ,w,v,m;
printf("donner un nombre  : ");
scanf("%d",&i);

printf("\t| sqrt (%d) = %f | \n" ,i,racine(i));

return 0;
}



