#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"
int main()
{
  FILE *f1;
  f1=fopen("tudien.txt","r");
  KeyType x;
  TreeType root;
  do
    {
      fscanf(f1,"%s",x.eng);
      fgetc(f1);
      fgets(x.vi,20,f1);
      x.vi[strlen(x.vi)-1]='\0';
      printf("%-20s%s\n",x.eng,x.vi);
      InsertNode(x,&root);
      printf("%-20s%s\n",&(*root)->key.eng,&(*root)->key.vi);
    }while(!feof(f1));
}
