#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
typedef struct element
{char ten[30]; char dl[7]; char kt[5]; char gia[15];} element;
#include"binarytree.h"
void printNode1(tree *node, int height)
{
  int i;
  for(i=0;i<height;i++) printf("               ");
  printf("%s\n",node->el.ten);
}
void printNode2(tree *node)
{
  printf("%-35s",node->el.ten);
  printf("%-10s",node->el.dl);
  printf("%-10s",node->el.kt);
  printf("%-20s\n",node->el.gia);
}
void printNodetofile(tree *node,FILE *f) {}
int compareElement1(element El1, element El2)
{
  return strcmp(El1.ten,El2.ten);
}
int compareElement2(element El1, element El2)
{
  return strcmp(El1.ten,El2.ten);
}
int compareElement3(element El1, element El2)
{
  return strcmp(El1.ten,El2.ten);
}
int menu()
{
  int chon;
  printf("=====Quan li dien thoai Nokia tren BST=====\n");
  printf("1. Nhap du lieu tu file\n");
  printf("2. Them\n3. Xoa\n4. Tim kiem\n");
  printf("5. Sua\n6. In ra danh sach\n7. Thoat\n");
  do {printf("Nhap lua chon (tu 1 den 7): "); scanf("%d",&chon);}
  while(chon<=0||8<=chon);
  return chon;
}
void nhap(FILE *f, tree **root) //Nhap du lieu tu file vao BST
{
  element El;
  while(!feof(f))
  {
    while(!feof(f))
    {
      fscanf(f,"%s %s %s %s\n",El.ten,El.dl,El.kt,El.gia);
      insertNodeintoBST(root,El);
    }
  }
}
element tao() //Tao element moi
{
  element new;
  printf("Nhap ten dien thoai: "); gets(new.ten);
  printf("Nhap dung luong dien thoai: "); gets(new.dl);
  printf("Nhap kich thuoc man hinh dien thoai: "); gets(new.kt);
  printf("Nhap gia dien thoai: "); gets(new.gia);
  return new;
}
void main()
{
  FILE *f; char file[MAX]; int chon,flag=0;
  tree *rt; element El;
  initTree(&rt);
  do
  {
    chon=menu(); getchar();
    if(chon!=1&&flag==0&&chon!=6)
    {
      printf("Phai chon 1 de nhap du lieu dau tien hoac 7 de thoat!\n");
      continue;
    }
    switch(chon)
      {
      case 1: flag=1;
	printf("Nhap ten file nguon de nhap du lieu: ");
	gets(file);
	if((f=fopen(file,"r"))==NULL)
	  {printf("Khong mo duoc file de doc du lieu!"); exit(1);}
	else nhap(f,&rt);
	break;
      case 2: insertNodeintoBST(&rt,tao()); break;
      case 3: printf("Nhap ten dien thoai can xoa: ");
	gets(El.ten);
	deleteNodeinBST(&rt,El);
	break;
      case 4: printf("Nhap ten dien thoai can tim: ");
	gets(El.ten);
	printNode2(searchBST(rt,El));
	break;
      case 5: printf("Nhap ten dien thoai can sua: ");
	gets(El.ten);
	deleteNodeinBST(&rt,El);
	printf("Nhap dien thoai moi\n");
	insertNodeintoBST(&rt,tao());
	break;
      case 6: InorderprintTree(rt,heightTree(rt));
        printf("So luong node: %d\n",countNode(rt));
        printf("Chieu cao cay: %d\n",heightTree(rt));
        printf("So luong la: %d\n",countLeaf(rt));
        printf("So luong node trong: %d\n",countInternalNode(rt)); 
	break;
      case 7: deleteTree(&rt); break;
      }
  }
  while(chon!=7);
}
