#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double racine_new(double a,double eps);
int main()
{
    double a;
   do{
    system("cls");
    printf("Saisir a : ");
    scanf("%lf",&a);
    printf("La racine de %lf est : \n\n |%.20lf |\n\n",a,racine_new(a,0.0000000001));
    system("pause");
   }while(1);
    return 0;
}
double racine_new(double a,double eps){
    double x=1,y;
    int i = 1;
    do{
       y=x;
       x=(y+a/y)/2;
       printf("\n\t i = %d , Vn = %lf , pas = %lf ",i++,x,x-y);
    }while(fabs(x-y )>eps);
    return x;
}
