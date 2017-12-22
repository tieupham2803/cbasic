#define MAX 30 //Quy dinh do dai toi da cua ten
typedef struct element {char name[MAX];} element;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"binarytree.h"
void printNode1(tree *node, int height) 
{
  int i;
  for(i=0;i<height;i++) printf("               ");
  printf("%s\n",node->el.name);
}
void printNode2(tree *node) {}
void printNodetofile(tree *node,FILE *f) {}
int compareElement1(element El1, element El2) {return 1;}
int compareElement2(element El1, element El2) {return 1;}
int compareElement3(element El1, element El2) {return 1;}
//Tao cay tu file
void createBinTreefromFile(FILE *f, tree **root)
{
  char buff[MAX];
  if(*root!=NULL)
  {
    createBinTreefromFile(f,&((*root)->left));
    createBinTreefromFile(f,&((*root)->right));
    if(isLeaf(*root)==1)
    {
      if(!feof(f)) fgets(buff,81,f);
      buff[strlen(buff)-1]='\0';
      //nhap vao theo tung dong
      //neu thay yeu cau chi viet tren 1 dong thi phai sua lai
      strcpy((*root)->el.name,buff);
    }
    else
    {
      if(rand()%2==0)
	strcpy((*root)->el.name,(*root)->left->el.name);
      else strcpy((*root)->el.name,(*root)->right->el.name);
    }
  }
}
//In ra cay
void printTree(FILE *f, tree *root, int height)
{
  int i;
  if(!isEmptyTree(root))
  {
    printTree(f,root->left,height-1);
    for(i=0;i<height;i++)
      {printf("               "); fprintf(f,"               ");};
    printf("%s\n",root->el.name); fprintf(f,"%s\n",root->el.name);
    printTree(f,root->right,height-1);
  }
}
void main()
{
  char file1[MAX],file2[MAX]; FILE *f1,*f2; tree *rt; int h=4;
  element El; strcpy(El.name,"");
  srand(time(NULL));
  printf("Nhap ten file nguon: "); gets(file1);
  printf("Nhap ten file de ghi ket qua: "); gets(file2);
  f2=fopen(file2,"w");
  if((f1=fopen(file1,"r"))==NULL) printf("Cant open file %s\n",file1);
  else
  {
    rewind(f1);
    makeFullTree(&rt,4,El);
    createBinTreefromFile(f1,&rt);
    printTree(f2,rt,h);
  }
  printf("So luong node: %d\n",countNode(rt));
  printf("Chieu cao cay: %d\n",heightTree(rt));
  printf("So luong la: %d\n",countLeaf(rt));
  printf("So luong node trong: %d\n",countInternalNode(rt)); 
  fclose(f1); fclose(f2);
}
