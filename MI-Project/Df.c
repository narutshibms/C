#include <stdio.h>
#include <stdlib.h>
#include "Df.h"
#include "Display.c"
#include "Allocatio.c"


void Drivefuntion()
{
    int n;

    printf("\n\n\Number Of DF You Have  :  ");
    scanf("%d",&n);
    fflush(stdin);

    N  = (AtA*)malloc(sizeof(AtA)); // set struct.
    B  = (Rs*)malloc(sizeof(Rs)); // Parent struct.

    reltiongetter(B); // schema relation getter (parent).

    head = calling(head,n);  // Create n of DF Dynamically
    linkwithhead(head,N);   /// Link set with Head.

    Get(head); /// ini DF for every struct .

    printf("\n\n\t The parent relation is :  ");
    showparent(B);

    printf("\n\n\tDependence functions are :  \n");
    showDF(head);

    getcostumeKey(N);

    search(N); // First search

    search(N); // second Search

    check_if_eq(N,B);

    allfree(); // to free All the memorey space .
}

int MtoA(Re *A,Re *B) /// check members to Admin
{

    int mx,min,tmp;

    mx =A->x;
    min =B->l1;
    if( mx>min )
     printf("");

     else
     {
         tmp = mx;
         mx  = min;
         min = tmp;
     }

    for(int j=0 ; j<mx ; j++)
        for(int i=0 ; i<min ; i++ )
        {
            if( A->Tab[j] == B->Admin[i]  )
                return 1;

            else
                continue;
        }

    return 0;

}




void tocopy(Re *A,Rs *B,Re *Nxt)
{



    int s= MtoA(A,Nxt);
    int h=A->x;
    if(s  )
    {
        for(int i=0 ; i<(Nxt->x ) ; i++)
        {

            s = detect_if_there(Nxt->Tab[i],A->Tab,h);
            if(s)
            {
                A->Tab[h] = Nxt->Tab[i];
                h++;
            }

        }

        (A->x = h);
        return 1;
    }
    return 0;
}

int check_if_eq(AtA * A,Rs *B)
{
    int c=1;
    Alphasort(A->Total,A->t_size );
    Alphasort(B->relationship,B->p_size );

    for(int i=0 ; i<B->p_size ; i++)
    {
        if ( A->Total[i] == B->relationship[i])
            continue;

        else
        {

            c=0;
            break;

        }

    }

    if(c)
    {
        pritab(A->s,A->s_size);
        printf(" : can determine schema Relation,because  : \n\n\t");
        printf("{");
        showSet(A);
        printf("}");
        printf(" == ");
        showparent(B);
        printf("\n");

    }
    else
    {
        pritab(A->s,A->s_size);
        printf(" : cannot determine schema Relation , because : \n\n\t");
        printf("{");
        showSet(A);
        printf("}");
        printf(" < > ");
        showparent(B);
        printf("\n");


    }

}

/// to look foR a costume st :

void getcostumeKey(AtA  *N)
{

    int i=0;

    N->Total =(char*)malloc(15*sizeof(char)); // Total
    N->s =(char*)malloc(5*sizeof(char)); //Admin

    printf("   give a set to test it  :  ");
    do
    {
        scanf("%c",&N->Total[i]);
        N->s[i]= N->Total[i];
        i++;
    }
    while( N->Total[i-1] != '\n');

    N->t_size = i-1;
    N->s_size = i-1;

}






int  search(AtA *me)
{
    Re *Ti;
    Ti = me->next;
    while(Ti)
    {


        for(int j=0 ; j<me->t_size ; j++)
            for(int i=0 ; i<Ti->l1 ; i++)
                if( Ti->Admin[i] == me->Total[j])
                    get_admin_tab(me,Ti);


        Ti = Ti->next;

    }
}

void get_admin_tab(AtA *me,Re* B)
{
    int s,k;
    k= me->t_size;

    for(int  i=0  ; i<B->x ; i++)
    {
        s = detect_if_there(B->Tab[i],me->Total,me->t_size);

        if(s)
        {
            me->Total[k] = B->Tab[i];
            k++;

        }

    }
    me->t_size = k;

}





int detect_if_there(char A,char *v,int p)
{
    for(int i=0 ; i<p ; i++)
        if( v[i] == A )
            return 0;


    return 1;
}


int  getminx(char *A,int indice,int t)
{
    char b;
    int j;
    b = A[indice];
    j= indice;
    for(int i=indice+1; i<t; i++)
        if(b>A[i] )
        {
            b= A[i];
            j = i;
        }


    return j;
}

char * Alphasort(char *A,int t)
{
    int  b;
    char tmp;
    for(int i=0; i<t-1 ; i++)
    {
        b  =  getminx(A,i,t);
        tmp = A[i];
        A[i] = A[b];
        A[b] = tmp;
    }


}
void getDF(Re *A) /// ini of Admin and Members  = Tab
{
    char T[15];
    char R[15];

    int n=0;
    int i=0;

    A->Tab = (char*)malloc(15*sizeof(char));

    printf("   give the left side of the key  : ");

    do
    {
        scanf("%c",&A->Tab[i]);
        i++;
    }
    while( A->Tab[i-1] != '\n');
    i--;
    n=i; // Admin size.


    printf("\n\t\t     ");pritab(A->Tab,i);
    printf("  -->  ");                      // Graph The key

    do
    {
        scanf("%c",&A->Tab[i]);
        i++;

    }while( A->Tab[i-1] != '\n' );

    i-=1; // Tab size

    // i-n  = members size

    getadmin(n,A);  // Allocation de Admin tab
    getmembers(i-n,A); // Allocation de Members Tab


    for(int j =0 ; j<n ; j++)
        A->Admin[j] = A->Tab[j];

    for(int j =0,k=n ; k<i ; k++,j++)
        A->members[j] = A->Tab[k];

    Alphasort(A->Tab,n);
    Alphasort(A->members,A->l2);

    A->x = (i); // TAB size which is l1 + l2.


}

void Get(Re *tm) // Get Df for every struct .
{
    Re *tm1;
    tm1 = tm;

    while(tm1) // initializing keys
    {

        getDF(tm1);
        printf("\n");
        tm1 = tm1->next; // changement de  DFs
    }

}


void reltiongetter(Rs *B)
{
    int i=0;
    int n=0;
    char T[20];


    printf("\n\t Schema Relation is  : ");

    do
    {
        scanf("%c",&T[i]);
        i++;
    }
    while( T[i-1] != '\n' && T[i-1] != '.' );
    i--;
    B->relationship = (char*)malloc(i*sizeof(char));
    B->p_size = i;

    while(T[n]!='\n')
    {

        B->relationship[n] = T[n];
        n++;
    }
    Alphasort(B->relationship,B->p_size);
    printf("\n");
}







