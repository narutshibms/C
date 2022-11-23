#include <stdio.h>
#include <stdlib.h>
#define nl 4
int main()
{
    int T[4][4], N[4][4],H[4][4];

    for(int i=0 ; i<4 ; i++)

        for(int k=0 ; k<4 ; k++)
        {
            printf("N[%d][%d] =  \n",i+1,k+1);

            scanf("%d",&N[i][k]);
            printf("T[%d][%d] =  \n",i+1,k+1);
            scanf("%d",&T[i][k]);
        }

        int i=0,k=0,n=0,s=0;
        while (i!=nl)
        {
            while(n<nl)
            {
                 while(k<nl){
                s = T[i][k]*N[k][n] + s ;
                k++;
                }
                H[i][n]=s;
                s=0;
                n++;
                k=0;

            }
             s=0;
             k=0;
             n=0;

            i++;}
            for(int i=0 ;i<4 ; i++){
            printf("|");
    for(int k=0 ;k<4 ; k++){

            printf("%d ",H[i][k]);

            }
            printf("|\n");
            }



            return 0;
        }

