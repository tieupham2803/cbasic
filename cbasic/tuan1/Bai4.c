#include<stdio.h>
#include<string.h>
void main()
{
  char Xau[125];
  int i = 0, j;

  printf("\nNhap vao Xau kiem tra : ");
  gets(Xau);
  j = strlen(Xau) - 1;
  printf("%d\n",j );

  while(Xau[i++] == Xau[j--])     // thuc hien j+1 lan
  ;
  if (--i>=++j)          // luc nay chac chan j==0 va i== strlen(Xau) ( neu Xau doi xung)
   printf("Xau doi xung\n");
  else
   printf("Xau khong doi xung\n");
}  