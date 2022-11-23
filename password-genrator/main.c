#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,i ;
    srand(time(0));

    printf("----------------------------------------------\n");
    printf("------------PASSWORD GENERATOR----------------\n");
    printf("-----------------------------------------------\n\n");
    do
    {
        printf("please give the leanght of your password , must be greater than 5  : \n");
        scanf("%d",&a);
        printf("your password is   : ");

    }
    while(a<5);
    for(int i =0 ; i<=7 ; i++ )
    {
        a =rand()%127;
        //if ((a >= 34&& a<= 42 ) ||(a >= 64&& a<= 90)||(a >= 97&& a<= 127 ) ||(a >= 49&& a<= 57))
        if (a >32 && a< 126 )


            printf("%c",a);
        else
        {
            i--;
        }

    }







    return 0;
}
