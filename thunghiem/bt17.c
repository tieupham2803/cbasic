#include<stdio.h>
#include<string.h>
#include"list.h"
#define MAX 100
int main()
{
  datas sv;
  int i,n;
  List Li;
  do
    {
      printf("nhap vao so sinh vien: "); scanf("%d",&n);
    }while(n<2||n>10);
  for(i=0;i<n;i++)
    {
      printf("**Nhap du lieu sv thu %d**\n",i+1);
      do{printf("  MS: "); scanf("%s",sv.ms);}while(strlen(sv.ms)>10);
      do{printf("  Ten: "); getchar(); gets(sv.ten);}while(strlen(sv.ten)>30);
      do{printf("  Diem: "); scanf("%f",&sv.diem);}while(sv.diem<0||sv.diem>10);
      Insert(&Li,sv);
    }
  ShowList(Li);
  return 0;
}
