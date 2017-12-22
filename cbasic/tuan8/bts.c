#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// typedef struct
// {
//   // char eng[20];
//   // char vn[20];
// 	int x;
// }data;
typedef int keytype;
typedef struct node
{
  keytype key;
  struct node *left,*right;
}node;
typedef  node* treetype;

treetype Search(keytype key,treetype root)
{
  if(root==NULL) return NULL;
  else if(root->key==key)
      return root;
  else if(root->key<key)
      return Search(key,root->right);
    else
      {
	return Search(key,root->left);
      }
}

void InsertNode(keytype key,treetype *root)
{
	// printf("%d\n",key );
// printf("1\n");
if (*root == NULL){
// printf("2\n");
  *root=(node*)malloc(sizeof(node)); 
  // printf("3\n");
  (*root)->key = key;
  (*root)->left = NULL; 
  (*root)->right = NULL; 
 }
 else{
 	// printf("qiweqwy\n");
  if (key<(*root)->key) InsertNode(key, &(*root)->left);
 else{  if (key>(*root)->key) InsertNode(key, &(*root)->right); }
}
}
// void InsertNode(keytype x,treetype *Root ){
// if (*Root == NULL){
// /* Create a new node for key x */
// *Root=(n*)malloc(sizeof(node));
// (*Root)->key = x;
// (*Root)->left = NULL;
// (*Root)->right = NULL;
// }
// else if (x < (*Root) ->key) InsertNode(x, & (*Root)->left);
// else if (x> Root->key) InsertNode(x, & (*Root)->right);
// }

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
    if(x<(*root)->key) DeleteNode(x,&(*root)->left);
    else if(x>(*root)->key)
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
      printf("%-20d\n",tree->key);
      printftree(tree->right);
    }
}
void  main()
{
	
	treetype p, tree = NULL;
	int i, n = 0;

	// scanf("%d", &n);
	// InsertNode(n,&tree); 
		srand(time(NULL));
	for ( i = 0; i < 10; i++ ) 
		InsertNode (rand() % 100, &tree ); 

	
	printf("\n");
  
	// InsertNode(2, tree ); 
	// InsertNode(1, tree ); 
	// InsertNode(5, tree ); 
		// printf("prettyprint:\n");
	printftree(tree);
	printf("\n");
	do {
		printf("Enter key to search (-1 to quit):\n");
		scanf("%d", &n);
		p= Search(n, tree);
		if (p!=NULL){ printf("Key %d found on the tree\n",n);
			DeleteNode(n,&tree);
			printftree(tree);
			}
		else {
				printf("deo tim thay so nay nhung anh dep trai da them vao cho chu\n");
			InsertNode(n, &tree);
		printftree(tree);}
		// else printf("deo co dau\n");
	}while (n!=-1);

}