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

void ada(Re *tm);
void swaping(char *a, char *b);
void selectionSort(char *array, int  size);
void getadmin(int lenght,Re *A);
void getmembers(int lenght,Re *A);
void affich(Re *A,int l1,int l2);
int check (Re * A,Rs *B);
void getkey(Re *A);
int MtoA(Re *A,Re *B);
void tocopy(Re *A,Rs *B,Re *Nxt);
int detect(char A,char *v,int p);
int  getminx(char *A,int indice,int t);
char * Alphasort(char *A,int t);
void reltiongetter(Rs *B);
void pritab(char *A,int n);
void linkwithhead(Re* head ,AtA *who);


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

void getkey(Re *A)
{
char T[10];char R[10];

    int n=0;int i=0;

A->Tab = (char*)malloc(15*sizeof(char));


    printf("   give the left side of the key  : ");
    do
    {
        scanf("%c",&A->Tab[i]);
        i++;
    }
    while( A->Tab[i-1] != '\n' && A->Tab[i-1] != '.' && A->Tab[i-1] != ' ');i--;n=i;



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


void showkey(Re *A)
{




    printf("\t\n (");
    for(int i=0 ; i<A->l1; i++)
    {
        if(  A->Admin[i] =='.' || A->Admin[i] ==('\n')  )
            continue;
        printf(" %c, ",A->Admin[i]);
    }
    printf(")-->(");

    for(int i=0 ; i<A->l2; i++)
    {
        if(  A->members[i] =='.' || A->members[i] ==('\n')  )
            continue;
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


    printf("  Relatio getter : ");

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


void ada(Re *tm)
{
    Re *tm1;
    tm1 = tm;

    while(tm1) // initializing keys
    {

        getkey(tm1);
        tm1 = tm1->next;
    }
    tm1 = tm;
    while(tm1)
    {

        showkey(tm1);  //  showing keys
        tm1 = tm1->next;
    }


}
void pritab(char *A,int n)
{

    for(int j=0 ; j<n ; j++ )
     printf("%c ",A[j]);


}


void linkwithhead(Re* head ,AtA *who)
{
     head->prev = who;
     who ->next = head;
     who->prev = NULL;

}







