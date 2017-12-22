#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BST.h"
#define MAX 80
FILE *f1;
int main()
{
  KeyType x;
  TreeType Root;
  f1=fopen("in.txt","r");
  while(!feof(f1))
    {
      while(!feof(f1))
	{
	  fscanf(f1,"%s",x.tu);
	  if(Search(x,Root)==NULL); InsertNode(x,&Root); 
	  printf("%s ",x.tu);
	}
    }
  printf("\n");
}
