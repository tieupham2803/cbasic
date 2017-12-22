#include<stdio.h>
#define MAX 100
int main()
{
  int a[MAX],n,i,le=0,chan=0, b[MAX],c[MAX];
  printf("nhap so phan tu cua mang: ");
  scanf("%d", &n);
  printf("mang ban dau: ");
  for(i=0;i<n;i++)
    {
      a[i]=rand()%100+1;
      printf ("%d  ",a[i]);
    }
  printf("\n");
  for(i=0;i<n;i++)
    {
      if(a[i]%2==0) {b[chan]=a[i]; chan=chan+1;}
      else {c[le]=a[i]; le=le+1;}
    }
  printf("co tat ca la %d so chan",chan);
  printf("day cac so chan: ");
  for(i=0;i<chan;i++)
    {
      printf("%d  ", b[i]);
    }
  printf("\n");
  printf("co tat ca la %d so le",le);
  printf("day cac so le: ");
  for(i=0;i<le;i++)
    {
      printf("%d  ", c[i]);
    }
  printf("\n");
}
