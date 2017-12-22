#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
  int i,n,dem=0;
  char a[30],c;
  printf("nhap vao chuoi a: ");
  gets(a);
  n=strlen(a);
  for(c='a';c<'z'+1;c++)
    {
      for(i=0;i<n;i++)
	if(a[i]==c || a[i]==(c-32)) dem=dem+1;
      if(dem!=0) printf("chu cai %c xuat hien: %d lan\n",c,dem);
      dem=0;
    }
  return 0;
}
