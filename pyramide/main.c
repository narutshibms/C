#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
    int k;
 printf("donner le nombre de linges : ");
 scanf("%d",&k);

 printf("\n\n");
  for (int i=0 ; i<k ; i++)
    {
    for (int j=0 ; j<=i ; j++)
        {
        printf(" *");

        }

    printf("\n");

    }


    return 0;
}
