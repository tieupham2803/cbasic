#include<stdio.h>
#include<stdlib.h>
typedef int element;
#include"linkedlist.h"
void printTitle() {}
void editImport(element *import) {}
int compareNode1(node *nd1, node *nd2) {return 0;}
int compareNode2(node *nd1, node *nd2) {return 0;}
int compareNode3(node *nd1, node *nd2) {return 0;}
int menu()
{
  int chon;
  printf("=====Chuong trinh mo phong lenh undo=====\n");
  printf("1. Push 1 so nguyen vao stack\n");
  printf("2. Pop 1 so nguyen ra khoi stack\n");
  printf("3. Xem ca danh sach\n");
  printf("4. Undo\n5. Thoat\n");
  do {printf("Nhap lua chon (tu 1 den 5): "); scanf("%d",&chon);}
  while(chon<=0||chon>=6);
  return chon;
}
void printNode(node *cur, int i)
{
  printf("%d",cur->el);
  if(cur->next!=NULL) printf("--"); else printf("\n");
}
void main()
{
  node *n,*n1,*s; int chon,chon1; element p;
  initList(&n); initList(&n1); initList(&s);
  do
  {
    chon=menu(); if(chon==1||chon==2) chon1=chon;
    switch(chon)
      {
      case 1: printf("Nhap so ban muon push: "); scanf("%d",&p);
        pushList(&n,p); break;
      case 2: if(isEmptyList(n)) printf("Khong the pop!\n"); else pushList(&n1,popList(&n)); break;
      case 3: displayList(n,0); displayList(n1,0);; break;
      case 4: if(chon1==2) if(isEmptyList(n1)) printf("Khong the thuc hien undo!\n"); else pushList(&n,popList(&n1));
        else if(isEmptyList(n)) printf("Khong the thuc hien undo!\n"); else pushList(&n1,popList(&n));
        break;
      case 5: freeList(&n); freeList(&n1); break;
      }
  }
  while(chon!=5);
}
