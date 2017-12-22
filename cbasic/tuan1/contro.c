#include<stdio.h>
void hien(double n, int *a, double *b)
{
  *a=(int)n;
  *b=n-*a;
}
int main()
{
  double n, s;
  int i;
  printf("Moi nhap so: ");
  scanf("%lf", &n);
  hien(n, &i, &s);
  printf("Phan nguyen cua so vua nhap la: %d\n", i);
  printf("Phan thap phan cua so vua nhap la: %f\n\n", s);
  return 0;
}
