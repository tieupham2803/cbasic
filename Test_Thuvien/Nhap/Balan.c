#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 50
typedef float element;
#include"linkedlist.h"
void printTitle() {}
void printNode(node *cur, int i) {}
void editImport(element *import) {}
int compareNode1(node *nd1, node *nd2) {return 0;}
int compareNode2(node *nd1, node *nd2) {return 0;}
int compareNode3(node *nd1, node *nd2) {return 0;}
int kt(char ktstr[max])
{
  int i=0,dem;
  while(i<=strlen(ktstr)-1)
  {
    if('0'<=ktstr[i]&&ktstr[i]<='9'||ktstr[i]=='+'||ktstr[i]=='-'||ktstr[i]=='*'||ktstr[i]=='/'||ktstr[i]=='^'||ktstr[i]==' ') dem++;
    i++;
  }
  if(dem==0) return 0; else return 1;
}
int ktpheptoan(char str[max])
{
  if(strcmp(str,"+")==0||strcmp(str,"-")==0||strcmp(str,"*")==0||strcmp(str,"/")==0||strcmp(str,"^")==0) return 1; else return 0;
}
element tinhtoan(element a, element b, char str[max])
{
  element kq;
  if(strcmp(str,"+")==0) kq=a+b;
  if(strcmp(str,"-")==0) kq=a-b;
  if(strcmp(str,"*")==0) kq=a*b;
  if(strcmp(str,"/")==0) kq=a/b;
  if(strcmp(str,"^")==0) kq=pow(a,b);
  return kq;
}
int nhap(node* root, char str[max], element *c)
{
  char *ptr; element a,b; int dem=0,kt=1;
  ptr=strtok(str," ");
  while(ptr)
  {
    if(ktpheptoan(ptr)==1)
    {
      if(dem>=2)
      {
	a=popList(&root); b=popList(&root);
	*c=tinhtoan(b,a,ptr); pushList(&root,*c);
	dem--;
      }
      else {kt=0; break;};
    }
    else
    {
      *c=atof(ptr); pushList(&root,*c);
      dem++;
    }
    ptr=strtok(NULL," ");
  }
  *c=popList(&root); if(dem>=2) kt=0;
  return kt;
}
void main()
{
  char bt[max]; node *rt; element c;
  do {printf("Nhap vao bieu thuc hau to: "); gets(bt);} while(kt(bt)==0);
  if(nhap(rt,bt,&c)==1) printf("Ket qua can tinh: %.2f\n",c);
  else printf("Bieu thuc nhap khong phu hop!\n");
}
