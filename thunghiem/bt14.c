#include<stdio.h>
#include<string.h>
#define MAX 80
int main()
{
  FILE *f1,*f2;
  int i,j=0,n,k;
  char a[MAX+1];
  /*===doc file bt13.c===*/
  f2=fopen("file_2.c","w");
  if((f1=fopen("bt13.c","r"))==NULL)
    printf("Cannot open %s.\n","float.dat");
  else while(fgets(a,80,f1)!=NULL) fputs(a,f2);
  return 0;
}
