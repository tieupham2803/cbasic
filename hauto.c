#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackArray.h"
int calc(char token, int x1, int x2)
{
  int i,n=1;
  if(token=='+') n=x2+x1;
  if(token=='-') n=x2-x1;
  if(token=='*') n=x2*x1;
  if(token=='/') n=x2/x1;
  if(token=='^') 
    {
      if(x1==0) n=1; 
      else for(i=1;i<=x1;i++) n=n*x2;
    }
  return n;
}
int checktoken(char c)
{
  if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return 1;
  else return 0;
}
int main()
{
  StackType stack;   
  int i, k=0, m=0, n, x1 , x2, a, b; 
  char token, s[80];
  printf("Nhap vao bieu thuc hau to: ");
  scanf("%s",s);
  for(i=0;i<strlen(s);i++)
    {
      token=s[i];
      if(token>=48 && token<=57)
	{
	  b=token-'0';
	  push(token-'0',stack);
	}
      else if (checktoken(token)==1)
      {
	x1=pop(stack); 
	x2=pop(stack);
	a=calc(token,x1,x2);
	push(a,stack);
      }
      else continue;
    }
  printf("gia tri cua bieu thuc hau to: %d\n",pop(stack));
  return 0;
}
 
 
