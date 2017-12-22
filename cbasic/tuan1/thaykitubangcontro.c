#include<stdio.h>
#include<string.h>
#define a 100
void thay(char *s, char c1, char c2)
{
  if(s==NULL) return;
  while(*s != '\0')
    {
      if(*s==c1) *s=c2;
      s++;
    }
}
int main()
{
  char s[a], c1, c2, tmp;
  printf("Moi nhap xau: ");
  scanf("%s", &s);
  printf("Moi nhap ki tu duoc thay the: ");
  scanf("%c", &c1);
  do{tmp=getchar();} while(tmp!='\n');
  printf("Moi nhap ki tu thay the: ");
  scanf("%c", &c2);
  thay(s, c1, c2);
  printf("Xau sau khi thay la: %s\n\n", s);
  return 0;
}
