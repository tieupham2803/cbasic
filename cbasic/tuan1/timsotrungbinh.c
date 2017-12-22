#include<stdio.h>
int main()
{
  int i, n, m;
  float a[10], tb, tong=0, so;
  printf("Nhap cac phan tu cua mang:\n");
  for(i=0;i<10;i++)
    {
      printf("Nhap phan tu thu %d: ", i+1);
      scanf("%f", &a[i]);
      tong+=a[i];
    }
  tb=tong/10;
  so=a[0];
  for(i=1;i<10;i++)
    {
      n=a[i]-tb;
      if(n<0) n=-n;
      m=so-tb;
      if(m<0) m=-m;
      if(n<m) so=a[i];
    }
  printf("So trung binh cua day so la: %.2f\n", tb);
  printf("So gan so trung binh nhat la: %.2f\n\n", so);
  return 0;
}
