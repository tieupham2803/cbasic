//Chuyen doi so thap phan sang nhi phan
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
typedef int element;
#include"linkedlist.h"
void printTitle() {}
void printNode(node *cur, int i) {}
void editImport(element *import) {}
int compareNode1(node *nd1, node *nd2) {return 0;}
int compareNode2(node *nd1, node *nd2) {return 0;}
int compareNode3(node *nd1, node *nd2) {return 0;}
int menu()
{
  int chon;
  printf("=====Chuong trinh cong tru cac so nguyen duong=====\n");
  printf("1. Cong 2 so\n2. Tru 2 so\n3. Thoat\n");
  do {printf("Nhap lua chon (tu 1 den 3): "); scanf("%d",&chon);}
  while(chon<=0||4<=chon);
  return chon;
}
void nhap(node **rt1, node **rt2)
{
  char n1[max],n2[max],m[2]; element m1,m2,i;
  do {printf("Nhap so thu nhat: "); gets(n1);} while(kt(n1)==0);
  do {printf("Nhap so thu hai: "); gets(n2);} while(kt(n2)==0);
  initList(&*rt1); initList(&*rt2);
  i=0; while(i<=strlen(n1)-1)
	 {m[0]=n1[i]; m[1]='\0'; m1=atoi(m); pushList(&*rt1,m1); i++;}
  i=0; while(i<=strlen(n2)-1)
	 {m[0]=n2[i]; m[1]='\0'; m2=atoi(m); pushList(&*rt2,m2); i++;}
}
int compare(node *rt1, node *rt2)
{
  node *cur1,*cur2;
  cur1=rt1; cur2=rt2;
  while(cur1!=NULL||cur2!=NULL)
  {
    if(cur1==NULL&&cur2!=NULL) return 1;
    else if(cur1!=NULL&&cur2==NULL) return -1;
    else {cur1=cur1->next; cur2=cur2->next;};
  }
  cur1=rt1; cur2=rt2;
  while(cur1!=NULL||cur2!=NULL)
  {
    if(cur1->el<cur2->el) return 1;
    else if(cur1->el>cur2->el) return -1;
    else {cur1=cur1->next; cur2=cur2->next;};
  }
  return 0;
}
struct node* cong(node *rt1, node *rt2)
{
  node* rt3; element m1,m2,m3,flag=0; m1=m2=m3=0;
  initList(&rt3);
  while(!isEmptyList(rt1)||!isEmptyList(rt2)||m1!=0||m2!=0)
  {
    if(flag==1) m3=1; else m3=0;
    if(!isEmptyList(rt1)) m1=popList(&rt1); else m1=0;
    if(!isEmptyList(rt2)) m2=popList(&rt2); else m2=0;
    if(m1+m2+m3>=10) {m3=m3+m1+m2-10; flag=1;}
    else {m3=m3+m1+m2; flag=0;};
    if(!isEmptyList(rt1)||!isEmptyList(rt2)||m3!=0) pushList(&rt3,m3);
  }
  return rt3;
}
struct node* tru(node *rt1, node *rt2)
{
  node* rt3; element m1,m2,m3,flag=0; m1=m2=m3=0;
  initList(&rt3);
  while(!isEmptyList(rt1)||!isEmptyList(rt2)||m1!=0||m2!=0)
  {
    if(flag==1) m3=-1; else m3=0;
    if(!isEmptyList(rt1)) m1=popList(&rt1); else m1=0;
    if(!isEmptyList(rt2)) m2=popList(&rt2); else m2=0;
    if(m1-m2+m3<0) {m3=m3+m1-m2+10; flag=1;}
    else {m3=m3+m1-m2; flag=0;};
    if(!isEmptyList(rt1)||!isEmptyList(rt2)||m3!=0) pushList(&rt3,m3);
  }
  return rt3;
}
int kt(char str[max])
{
  int i=0,dem=0;
  while(str[i]!='\0') {if(str[i]<'0'||'9'<str[i]) dem++; i++;};
  if(dem==0) return 1; else return 0;
}
void main()
{
  node *rt1,*rt2,*rt3; int i,chon; element m3;
  do
  {
    chon=menu(); getchar();
    switch(chon)
      {
      case 1: nhap(&rt1,&rt2);
	rt3=cong(rt1,rt2);
        while(!isEmptyList(rt3)) {m3=popList(&rt3); printf("%d",m3);};
        printf("\n"); break;
      case 2: nhap(&rt1,&rt2);
	if(compare(rt1,rt2)<0) rt3=tru(rt1,rt2);
	else if(compare(rt1,rt2)>0) {printf("-"); rt3=tru(rt2,rt1);}
	else pushList(&rt3,0);
        while(!isEmptyList(rt3)) {m3=popList(&rt3); printf("%d",m3);};
	printf("\n"); break;
      }
  }
  while(chon!=3);
  freeList(&rt3);
}
