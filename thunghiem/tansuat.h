#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
  char name[81];
  int dem;
}data;
typedef data elementtype;
typedef struct node
{
  elementtype element;
  struct node *left,*right;
}node;
typedef struct node *treetype;

void InsertNode(elementtype element,treetype *root)
{
if (*root == NULL){
  *root=(node*)malloc(sizeof(node)); 
  (*root)->element = element;
  (*root)->left = NULL; 
  (*root)->right = NULL; 
 }
 else if (strcmp(element.name,(*root)->element.name)==0) (*root)->element.dem++;
 else if (strcmp(element.name,(*root)->element.name)<0) InsertNode(element, &(*root)->left);
 else if (strcmp(element.name,(*root)->element.name)>0) InsertNode(element, &(*root)->right); 
}
void freetree(treetype tree)
{
	if (tree!=NULL)
	{
		freetree(tree->left);
		freetree(tree->right);
		free((void*) tree);
	}
}
void printftree(treetype tree)
{
  if(tree!=NULL)
    {
      printftree(tree->left);
      printf("%s %d\n",tree->element.name,tree->element.dem);
      printftree(tree->right);

    }
}
