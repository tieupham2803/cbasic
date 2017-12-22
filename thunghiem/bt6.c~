#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
  int i,n,dem;
  char a[30],c;
  printf("nhap vao chuoi a: ");
  gets(a);
  n=strlen(a);
  for(c=0;c<256;c++)
    {
      for(i=0;i<n;i++)
	if(a[i]==c) dem=dem+1;
      if(dem!=0) printf("ki tu c xuat hien: %d lan\n",dem);
    }
  return 0;
}
