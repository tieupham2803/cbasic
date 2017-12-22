#include<stdio.h>
#define MAX 100
int main()
{
  int a[MAX],n,i,temp;
  printf("nhap so phan tu cua mang: ");
  scanf("%d", &n);
  for(i=0;i<n;i++)
    {
      a[i]=rand()%100+1;
      printf ("%d  ",a[i]);
    }
  printf("\n");
  for(i=0;i<n/2;i++)
    {
      temp=a[i];
      a[i]=a[n-1-i];
      a[n-1-i]=temp;
    }
  for(i=0;i<n;i++)
    {
      printf("%d  ", a[i]);
    }
}
