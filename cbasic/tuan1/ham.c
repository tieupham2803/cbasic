#include<stdio.h>
#define s 5
int ss(int a[], int b[])
{
  int i, n=1;
  for(i=0;i<s;i++)
    {
      if(a[i]==b[i]) n*=1;
      else n=n*0;
    }
  return n;
}
int main()
{
  int a[s], b[s], j;
  for(j=0;j<s;j++)
    {
      printf("Nhap phan tu thu %d cua day 1: ", j+1);
      scanf("%d", &a[j]);
      printf("Nhap phan tu thu %d cua day 2: ", j+1);
      scanf("%d", &b[j]);
    }
  if(ss(a, b)==1) printf("2 mang vua nhap giong nhau\n\n");
  else printf("2 mang vua nhap khong giong nhau\n\n");
  return 0;
}
