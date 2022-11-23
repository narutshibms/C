#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Relation
{
    char *Admin;
    int l1;
    char *members;
    int l2;
    int x;
    char *Tab;
    int was_here;
    struct Relation *next;
    struct Relation *prev;

} Re;

typedef struct parent
{

    char *relationship;
    int p_size;


} Rs;

typedef struct AtoA
{
    char *Total;
    char  *s;

    int t_size;
    int s_size ;

     Re *next;
   struct  AtoA *prev;

}AtA;




Re * head = NULL;
Re * tail =NULL;
Rs *B;
AtA *N;

void showDF(Re *A);
void showparent(Rs *A);
void Get(Re *tm);
void getadmin(int lenght,Re *A);
void getmembers(int lenght,Re *A);
void getDF(Re *A);
int MtoA(Re *A,Re *B);
void tocopy(Re *A,Rs *B,Re *Nxt);
int detect(char A,char *v,int p);
int  getminx(char *A,int indice,int t);
char * Alphasort(char *A,int t);
void reltiongetter(Rs *B);
void pritab(char *A,int n);
void linkwithhead(Re* head ,AtA *who);
int check_if_eq(AtA * A,Rs *B);
void getcostumeKey(AtA  *N);
void get_admin_tab(AtA *me,Re* B);
void allfree(void);
void Drivefuntion(int n);




Re *getlast(Re * tmp)
{
    if( tail ==NULL)
    {
        tail =tmp;
        tail ->next = NULL;
        tmp->prev = head;
    }
    else if (tail-> next == NULL)
    {
        tail ->next = tmp;
        tmp->next = NULL;
        tmp->prev = tail;
        tail = tmp;

    }
    return tail;
}

Re * aloocate(Re *head)
{
    Re * tmp ;
    tmp = (Re*)malloc(sizeof(Re));
    if( head == NULL)
    {
        head = tmp;
        head->next = NULL;
        head->prev = NULL;
    }
    else if(head ->next == NULL )
    {
        head->next = tmp ;
        tmp ->next = NULL;
        tmp->prev = head;
        tail = tmp;

    }
    else
        tail = getlast(tmp);

    return head;
}


Re* calling(Re *head,int n)
{
    for(int i=0 ; i<n; i++)
        head = aloocate(head);

    return head;
}

void  getadmin(int lenght,Re *A)
{
    A->Admin = (char*)malloc(lenght*sizeof(char));
    if(A==NULL)
        printf("Error d'allocation");
    A->l1 = lenght;

}

void  getmembers(int lenght,Re *A)
{

    A->members = (char*)malloc(lenght*sizeof(char));
    if(A==NULL)
        printf("Error d'allocation");

    A->l2= lenght;

}

void getDF(Re *A)
{
char T[10];char R[10];

    int n=0;int i=0;

A->Tab = (char*)malloc(15*sizeof(char));

    printf("   give the left side of the key  : ");

    do
    {
        scanf("%c",&A->Tab[i]);
        i++;
    } while( A->Tab[i-1] != '\n' && A->Tab[i-1] != '.' && A->Tab[i-1] != ' ');i--;n=i;



     printf("   give the right side of the key  : ");
     do
    {
        scanf("%c",&A->Tab[i]);
        i++;

    }
    while( A->Tab[i-1] != '\n' && A->Tab[i-1] != '.' && A->Tab[i-1] != ' '  );i-=1;

      // i-n  = members size

     getadmin(n,A); A->l1=n;
     getmembers(i-n,A);A->l2 = i-n;

     for(int j =0 ; j<n ;j++)
     {
        //if( A->Tab[j] != '\n' && A->Tab[j] != '.' && A->Tab[j] != ' ')
        A->Admin[j] = A->Tab[j];

     }
     for(int j =0,k=n ; k<i ;k++,j++)
      //  if( A->Tab[k] != '\n' && A->Tab[k] != '.' && A->Tab[k] != ' ')
        A->members[j] = A->Tab[k];
      Alphasort(A->Tab,n);
      Alphasort(A->Admin,A->l1);
      Alphasort(A->members,A->l2);

        A->x = (i);


}

void Get(Re *tm)
{
    Re *tm1;
    tm1 = tm;

    while(tm1) // initializing keys
    {

        getDF(tm1);
        printf("\n");
        tm1 = tm1->next;
    }

}




void showkey(Re *A)
{




    printf("\t\n (");
    for(int i=0 ; i<A->l1; i++)
    {
        if(  A->Admin[i] =='.' || A->Admin[i] ==('\n')  )
            continue;
         printf(" %c ",A->Admin[i]);



    }
    printf(")-->(");

    for(int i=0 ; i<A->l2; i++)
    {
        if(  A->members[i] =='.' || A->members[i] ==('\n')  )
            continue;
           if(i== A->l2-1)
        printf(" %c ",A->members[i]);
           else
           printf(" %c, ",A->members[i]);

    }
    printf("). \n\n\t");
}

int MtoA(Re *A,Re *B)
{

    int mx,min;

    mx =A->x;
    min =B->l1;


        for(int j=0 ; j<mx ; j++)
        for(int i=0 ; i<min ; i++ )

        {
            if( A->Tab[j] == B->Admin[i] ||   A->Tab[i] == B->Admin[i]   )
                return 1;

            else
                continue;
        }

    return 0;

}


void reltiongetter(Rs *B)
{
    int i=0;
    int n=0;
    char T[10];


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

void tocopy(Re *A,Rs *B,Re *Nxt)
{



    int s= MtoA(A,Nxt);
    int h=A->x;
    if(s  )
    {
        for(int i=0 ; i<(Nxt->x ) ; i++)
        {

            s = detect(Nxt->Tab[i],A->Tab,h);
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

    return A;
}

int detect(char A,char *v,int p)
{
    for(int i=0 ; i<p ; i++)
        if( v[i] == A )
            return 0;


    return 1;
}



void pritab(char *A,int n)
{
    for(int j=0 ; j<n ; j++ )
          printf(" %c ",A[j]);

}


void linkwithhead(Re* head ,AtA *who)
{
     head->prev = who;
     who ->next = head;
     who->prev = NULL;

}


int check_if_eq(AtA * A,Rs *B)
{
    int c=0;

    for(int i=0 ; i<A->t_size ; i++)
    {
        if ( A->Total[i] == B->relationship[i])
            c=1;

        else{
            c=0;
            break;
            }

    }







    if(c)
    {
        pritab(A->s,A->s_size);
        printf(" : can determine schema Relation  .\t\n");

    }
     else{
        pritab(A->s,A->s_size);
        printf(" ,cannot determine schema Relation .\n\t");



        }

}

/// to look fo a costume st :

void getcostumeKey(AtA  *N)
 {

    int i=0;

        N->Total =(char*)malloc(15*sizeof(char));
        N->s =(char*)malloc(5*sizeof(char));

    printf("   give a set to test it  :  ");
    do
    {
        scanf("%c",&N->Total[i]);
        N->s[i]= N->Total[i];
        i++;
    }
    while( N->Total[i-1] != '\n' && N->Total[i-1] != '.' &&N->Total[i-1]!=' ' );i--;

      N->t_size = i;
      N->s_size = i;

Alphasort(N->Total,N->t_size);


 }

void get_admin_tab(AtA *me,Re* B)
{
    int s,k;
    k= me->t_size;

        for(int  i=0  ; i<B->x ; i++)
        {
        s = detect(B->Tab[i],me->Total,me->t_size);
            if(s)
                {
            me->Total[k] = B->Tab[i];
            k++;

                }

        }
        me->t_size = k;

}

int  search(AtA *me)
{
    Re *Ti;
    Ti = me->next;

    while(Ti)  {


            for(int j=0 ;j<me->t_size ; j++)
            for(int i=0 ; i<Ti->l1 ; i++)
        if( Ti->Admin[i] == me->Total[j])
            get_admin_tab(me,Ti);


         Ti = Ti->next;

               }


}

void allfree(void)
{
 Re *less;
   less = head;
while( less)
{

    free(less->prev);
    less = less->next;
}
   free(less);

}

void showparent(Rs *A)
{
       printf("R( ");
       pritab(A->relationship,A->p_size);
        printf(") ");

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

void Drivefuntion(int n)
{


    N  = (AtA*)malloc(sizeof(AtA));
    B  = (Rs*)malloc(sizeof(Rs));

    reltiongetter(B);

    head = calling(head,n);
    linkwithhead(head,N);

    Get(head);

    printf("\n\n\t The parent relation is :  ");
     showparent(B);
    printf("\n\n\tDependence functions are :  \n");
    showDF(head);

    getcostumeKey(N);
    search(N);
    search(N);
    check_if_eq(N,B);
    allfree();
}

