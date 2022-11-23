#include <stdio.h>
#include "Df.h"





            /// Print Functions :

void pritab(char *A,int n)
{
    for(int j=0 ; j<n ; j++ )
        printf("%c",A[j]);

}



void showparent(Rs *A)
{
    printf("R( ");

for(int k=0 ; k< A->p_size ; k++ ){

    if(     k == A->p_size -1 )
     printf(" %c ",A->relationship[k]);
    else
    printf(" %c, ",A->relationship[k]);

 }


    printf("). ");

}

void showDF(Re *A)
{
    Re* tmp;
    tmp = A;

    while(tmp)
    {
        showkey(tmp);

        tmp = tmp->next;

    }

    printf("\n");
}

void showkey(Re *A) // display key which are n struct.
{




    printf("\t\n (");

    for(int i=0 ; i<A->l1; i++)
    {
        if(A->Admin[i] ==('\n')  )
            continue;
        printf("%c",A->Admin[i]);



    }
    printf(")-->(");

    for(int i=0 ; i<A->l2; i++)
    {
        if(i== A->l2-1)
            printf(" %c ",A->members[i]);
        else
            printf(" %c, ",A->members[i]);

    }
    printf("). \n\n\t");
}
void showSet(AtA *A)
{

for(int i=0 ; i<A->t_size; i++)
    {
        if(i== A->t_size -1)
            printf(" %c ",A->Total[i]);
        else
            printf(" %c, ",A->Total[i]);

    }

}
