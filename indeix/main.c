#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char ** R;
int nb,T[];
}Res;
void aff_res(Res*A){
    int i;
    for (i=0;i<A->nb;i++)
        printf("\\ T[%d]<-------(%s) \n\n", i+1, A->R[i]);
    }
void couper(char*T){
  int i,ii=0,lg=strlen(T); // declaration
  char TT[50] ;   // declaration

  if( T[0]!=' ') // test
    TT[ii++]=T[0];

  for(i=1;i<lg;i++){
    if(T[i]!=' '){
        TT[ii++]=T[i];
    }else if ( T[i-1]!=' '){
    TT[ii]='\0';
    ii=0;
    printf("\\ ---->:'%s'",TT);
    }
  }
  if(ii){
    TT[ii]='\0';
     printf("\\ ---->:'%s'",TT);
  }

    }
Res*couper1(char*T){
    int i, ii=0, lg=strlen(T);
    char TT[50];
    Res* A = (Res *)malloc(sizeof(Res));
    A->R=NULL; A->nb=0;
    if (A==NULL)
    {
        printf("Erreur");
        exit(33);
    }
    if(T[0] !=' ')
        TT[ii++]=T[0];
    for(i=1; i<lg;i++){
        if(T[i] !=' '){
           TT[ii++]=T[i];
        }else if(T[i-1] !=' '){
        TT[ii]='\0' ;
        ii=0;
        //zone d'allocation et de traitement
      A->R=(char **)realloc( A->R, sizeof(char *)*++A->nb);
      if(A->R == NULL){
        printf("\\ Erreuuur d'allocation ");
        exit(33);
      }
      A->R[A->nb-1]=(char *)malloc(sizeof(char )*(strlen(TT)+1));
      if(A->R[A->nb-1]==NULL){
         printf("\\ Erreuuur d'allocation ");
        exit(33);
      }
      strcpy( A->R[A->nb-1],TT);
      //printf("\\ ----->"%s",R[nbr-1]);
      }
      }
      if(ii){
        TT[ii]='\0';
        //zone d'allocation et de traitement
        A->R=(char **)realloc( A->R, sizeof(char *)*++A->nb);
      if(A->R == NULL){
        printf("\\ Erreuuur d'allocation ");
        exit(33);
      }
      A->R[A->nb-1]=(char *)malloc(sizeof(char )*(strlen(TT)+1));
      if(A->R[A->nb-1]==NULL){
         printf("\\ Erreuuur d'allocation ");
        exit(33);
      }
      strcpy( A->R[A->nb-1],TT);
      //printf("\\ ----->"%s",R[nbr-1]);

    }
    return A;
}
int main(){
char T[800000]; // insialize

Res* B;

printf("\\ donner votre phrase : ");

gets(T);

B=couper1(T);

aff_res(B);

system("pause" ) ;
return 0;
}
