#include <stdio.h>
#include <stdlib.h>

int main()
{

    int c = 0,s=0;
    const int P=4;
    int lines,colon;
    int a=0,b=0,e=0,d=0,total=0;
    printf(" enter lines & colones \n");
    printf("lines : ");
    scanf("%d",&lines);
    printf("colones : ");
    scanf("%d",&colon);
    printf("\n\n");
    for(int k=0,n,m=0,c=0; k<lines ; k++)
    {
        n= m + 1;
        m = m + colon;

        for(int i=n; i<=m ; i++)
        {
            printf("%3d.0 ",i);
            s = s + i;
            if (i== n )
                a = a + i;
            else if (i== n +1)
                b = b + i ;
            else if (i== n +2)
                e = e + i ;
            else if ( i== n +3 )
                d = i+d;
        }
        printf(" |%d.0",s);
        total = s + total ;
        s=0;
        printf("\n\n");
    }

    printf("------------------------------------\n");
    printf("%4d %5d  %4d  %5d ",a,b,e,d);
    printf(" |%d.0\n\n",total);

    return 0;
}
