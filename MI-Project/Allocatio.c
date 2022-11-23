#include <stdio.h>
#include <stdlib.h>
#include "Df.h"



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
   free(B);

}
void linkwithhead(Re* head , AtA *Set)
{
    head->prev = Set;
    Set ->next = head;
    Set ->prev = NULL;

}
