#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 80
int main()
{
  int n;
  char buff[81];
  FILE *filein, *fileout;
  filein=fopen("in.txt","r");
  fileout=fopen("out.txt","w");
  while(!feof(filein))
    {
      fread(buff,sizeof(char),MAX_LEN,filein);
      n=strlen(buff);
      fwrite(buff,sizeof(char),n,fileout);
    }
  fclose(filein);
  fclose(fileout);
  return 0;
}

