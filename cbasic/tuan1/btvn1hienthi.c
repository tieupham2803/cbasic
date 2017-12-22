#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define a '\n'
void hienthi(char s[])
{
  int i;
  for(i=0;i<strlen(s);i++)
    {
      if(s[i]==' ') s[i]=a;
    }
}
int main()
{
  char s[100];
  printf("Moi nhap van ban: ");
  gets(s);
  hienthi(s);
  printf("Xau sau khi xu ly la:\n%s\n\n", s);
  return 0;
}
