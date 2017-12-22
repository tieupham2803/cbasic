#include<stdio.h>
#define n 26
int main()
{
  int i=0;
  int so[n]={0};
  char c='\n';
  printf("Nhap vao xau ki tu:\n");
  c=getchar();
  while(c!='\n' && c>=0)
    {
      if(c<='z' && c>='a') ++so[c-'a'];
      if(c<='Z' && c>='A') ++so[c-'A'];
      c=getchar();
    }
  for(i=0;i<n;i++)
    {
      if(so[i]>0)
	{
	  printf("So lan xuat hien cua ki tu %c la: %d\n", 'a'+i, so[i]);
	}
    }
  return 0;
}
