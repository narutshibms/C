#ifndef DF_H_INCLUDED
#define DF_H_INCLUDED

typedef struct Relation
{
    char *Admin;
    int l1;
    char *members;
    int l2;

    int x;
    char *Tab;

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
   struct AtoA *prev;

}AtA;




Re * head = NULL;
Re * tail = NULL;
Rs *B;
AtA *N;


Re* calling(Re *head,int n);
void showDF(Re *A);
void showparent(Rs *A);
void Get(Re *tm);
void getadmin(int lenght,Re *A);
void getmembers(int lenght,Re *A);
void getDF(Re *A);
int MtoA(Re *A,Re *B);
void tocopy(Re *A,Rs *B,Re *Nxt);
int detect_if_there(char A,char *v,int p);
int  getminx(char *A,int indice,int t);
char * Alphasort(char *A,int t);
void reltiongetter(Rs *B);
void pritab(char *A,int n);
void linkwithhead(Re* head ,AtA *who);
int check_if_eq(AtA * A,Rs *B);
void getcostumeKey(AtA  *N);
void get_admin_tab(AtA *me,Re* B);
void showSet(AtA *A);
void allfree(void);
void Drivefuntion();





#endif // DF_H_INCLUDED
