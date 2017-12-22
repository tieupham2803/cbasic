/*chuong trinh thu nghiem vao ra file, fgets*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char str[100];
  int n=0;
  FILE *filein, *fileout;
  filein=fopen("in.txt","r");
  fileout=fopen("out.txt","w");
  while(fgets(str,100,filein)!=NULL)
    {
      n=n+1;
      fprintf(fileout,"%d   %s",n,str);
    }
  fclose(filein);
  fclose(fileout);
  return 0;
}
