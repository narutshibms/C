#include <stdio.h>
#define n 8
MERGE_SORT(arr, beg, end)
 {
int mid;

if (beg < end){

 mid = (beg + end)/2;
 printf("execution left\n");

MERGE_SORT(arr, beg, mid);
printf("execution  right\n");
MERGE_SORT(arr, mid + 1, end);


printf("execution \n");
merge(arr, beg, mid, end);
  }
}
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2]; //temporary arrays

    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
    LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
    RightArray[j] = a[mid + 1 + j];

    i = 0, /* initial index of first sub-array */
    j = 0; /* initial index of second sub-array */
    k = beg;  /* initial index of merged sub-array */

    while (i < n1 && j < n2)
    {
        if(LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

int main(){


    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    MERGE_SORT(a,0,n-1);
    printf("---------\n");
 for(int i=0;i<n;i++)
        printf("  %d \n",a[i]);







    return 0;}
