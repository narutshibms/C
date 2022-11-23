#include<stdio.h>

void mergesort(int a[],int i,int j);
void merge(int a[],int first1,int last1,int first2,int last2);

int main()
{
int a[30],n,i;
printf("Enter no of elements:");
scanf("%d",&n);
printf("Enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
mergesort(a,0,n-1);
printf("\nSorted array is :");
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}

void mergesort(int a[],int i,int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
printf("      mid-left = %d\n\n",mid);
mergesort(a,i,mid); //left recursion
printf("      mid-right = %d\n\n",mid);
mergesort(a,mid+1,j); //right recursion
printf("mid = %d\n",mid);
merge(a,i,mid,mid+1,j); //merging of two sorted sub-arrays
}
}

void merge(int a[],int first1,int last1,int first2,int last2)
{
int temp[50]; //array used for merging
int i,j,k;
i=first1; //beginning of the first list
j=first2; //beginning of the second list
k=0;
while(i<=last1 && j<=last2) //while elements in both lists
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=last1) //copy remaining elements of the first list
temp[k++]=a[i++];
while(j<=last2) //copy remaining elements of the second list
temp[k++]=a[j++];
//Transfer elements from temp[] back to a[]
for(i=first1,j=0;i<=last2;i++,j++)
a[i]=temp[j];
}
