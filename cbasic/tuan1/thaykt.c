#include<stdio.h>
#include<string.h>
void thay(char s[], char a, char b)
{
  int i;
  for(i=0;s[i]!='\0';i++)
    {
      if (s[i]==a) s[i]=b;
    }
}
int main()
{
  char s[100], a, b, tmp;
  int i;
  printf("Moi nhap xau ki tu: ");
  scanf("%s", &s);
  printf("Moi nhap ki tu duoc thay the: \n");
  scanf("%c", &a);
  do{tmp=getchar();} while(tmp!='\n');
  printf("Moi nhap ki tu thay the: \n");
  scanf("%c", &b);
  /*  for(i=0;i<strlen(s); i++)
    {
      if(s[i]==a) s[i]=b;
      } */
  thay(s, a, b);
  printf("Xau sau khi thay the la: %s\n\n", s);
  return 0;
}
