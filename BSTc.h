#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
  char eng[20];
  char vn[20];
}data;
typedef data keytype;
typedef struct node
{
  keytype key;
  struct node *left,*right;
}node;
typedef struct node *treetype;
treetype Search(keytype key,treetype root)
{
  if(root==NULL) return NULL;
  else if(strcmp(root->key.eng,key.eng)==0)
      return root;
  else if(strcmp(root->key.eng,key.eng)<0)
      return Search(key,root->right);
    else
      {
	return Search(key,root->left);
      }
}

void InsertNode(keytype key,treetype *root)
{
if (*root == NULL){
  *root=(node*)malloc(sizeof(node)); 
  (*root)->key = key;
  (*root)->left = NULL; 
  (*root)->right = NULL; 
 }
 else if (strcmp(key.eng,(*root)->key.eng)<0) InsertNode(key, &(*root)->left);
 else if (strcmp(key.eng,(*root)->key.eng)>0) InsertNode(key, &(*root)->right); 
}

keytype DeleteMin(treetype *root)
{
  keytype k;
  if((*root)->left==NULL)
    {
      k=(*root)->key;
      (*root)=(*root)->right;
      return k;
    }
  else return DeleteMin(&(*root)->left);
}

void DeleteNode(keytype x,treetype *root)
{
  if(*root!=NULL)
    if(strcmp(x.eng,(*root)->key.eng)<0) DeleteNode(x,&(*root)->left);
    else if(strcmp(x.eng,(*root)->key.eng)>0)
      DeleteNode(x,&(*root)->right);
    else if
      (((*root)->left==NULL)&&((*root)->right==NULL))
      *root=NULL;
    else if((*root)->left==NULL)
      *root=(*root)->right;
    else if((*root)->right==NULL)
      *root=(*root)->left;
    else (*root)->key = DeleteMin(&(*root)->right); 
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
      printf("%-20s%s\n",tree->key.eng,tree->key.vn);
      printftree(tree->right);
    }
}
