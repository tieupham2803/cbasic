//UNTESTED!!!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree {element el; struct tree *left,*right;} tree;
//tree la cau truc tuong duong voi node trong danh sach lien ket

/*=========================================================================
            Cac ham phu (duoc khai bao trong chuong trinh chinh)
=========================================================================*/
void printNode1(tree *node, int height);
//Dung trong ham duyet cay theo chieu sau
void printNode2(tree *node); //In day du thong tin cua node
void printNodetofile(tree *node,FILE *f);
element inputEl();
//Dung trong ham ghi noi dung cay ra file
int compareElement1(element El1, element El2);
//Dung trong ham tim kiem tren BST
int compareElement2(element El1, element El2);
//Dung trong ham them node vao BST
int compareElement3(element El1, element El2);
//Dung trong ham xoa node trong BST
/*=========================================================================
                    Cac ham ho tro (dung de khao sat cay)
=========================================================================*/
//=========================================================================
//Khoi tao, kiem tra cay rong, kiem tra la, truy nhap con, tao node moi
//Khoi tao cay
void initTree(tree **root)
{
  (*root)=NULL;
}
//Kiem tra cay rong
int isEmptyTree(tree *root)
{
  return root==NULL;
}
//Truy nhap con trai
struct tree* LeftChild(tree *root)
{
  if(root!=NULL) return root->left;
  else return NULL;
}
//Truy nhap con phai
struct tree* RightChild(tree *root)
{
  if(root!=NULL) return root->right;
  else return NULL;
}
//Kiem tra 1 node co phai la la khong
int isLeaf(tree *node)
{
  if(node!=NULL)
    return (LeftChild(node)==NULL)&&(RightChild(node)==NULL);
  else return -1;
}
//Tao node moi
struct tree* makeNewNodeTree(element El)
{
  tree *newNode;
  newNode=(tree*)malloc(sizeof(tree));
  if(newNode==NULL)
    {printf("Cap phat node moi khong thanh cong!\n"); return NULL;}
  else
  {
    newNode->el=El; newNode->left=NULL; newNode->right=NULL;
    return newNode;
  }
}
//=========================================================================
//Cac ham dem
//Tinh so luong node
int countNode(tree *root)
{
  if(isEmptyTree(root)) return 0;
  else
    return 1+countNode(LeftChild(root))+countNode(RightChild(root));
}
//Tinh do cao cua mot cay
int heightTree(tree *root)
{
  int l,r;
  if(isLeaf(root)) return 0;
  else
  {
    l=heightTree(root->left); r=heightTree(root->right);
    if(r>=l) return r+1; else return l+1;
  }
}
//Tinh so luong la
int countLeaf(tree *root)
{
  if(isEmptyTree(root)) return 0;
  else if(isLeaf(root)==1) return 1;
  else return countLeaf(root->left)+countLeaf(root->right);
}
//Tinh so luong cac node trong
int countInternalNode(tree *root)
{
  if(isEmptyTree(root)||isLeaf(root)==1) return 0;
  else
    return countInternalNode(root->left)+countInternalNode(root->right)+1;
}
//Tinh so luong con phai
int countRightChild(tree *root)
{
  return countNode(root->right);
}
//Tinh so luong con trai
int countLeftChild(tree *root)
{
  return countNode(root->left);
}
//=========================================================================
//Xoa toan bo cay
void deleteTree(tree **root)
{
  if(isLeaf(*root)==1) free(*root);
  else
  {
    if((*root)->right!=NULL) deleteTree(&((*root)->right));
    if((*root)->left!=NULL) deleteTree(&((*root)->left));
  }
}
//=========================================================================
//Duyet cay theo chieu sau (Depth First Search - DFS)
//In cay theo thu tu giua (Inorder)
void InorderprintTree(tree *root, int height)
{
  if(!isEmptyTree(root))
  {
    InorderprintTree(root->left,height-1);
    printNode1(root,height);
    InorderprintTree(root->right,height-1);
  }
}
//Ghi noi dung cay vao file theo thu tu giua (Inorder)
void printTreetofile(tree *root, FILE *f)
{
  if(!isEmptyTree(root))
  {
    printTreetofile(root->left,f);
    printNodetofile(root,f);
    printTreetofile(root->right,f);
  }
}
//In cay theo thu tu sau (Postorder)
void PostorderprintTree(tree *root, int height)
{
  if(!isEmptyTree(root))
  {
    PostorderprintTree(root->left,height-1);
    PostorderprintTree(root->right,height-1);
    printNode1(root,height);
  }
}
//In cay theo thu tu truoc (Preorder)
void PreorderprintTree(tree *root, int height)
{
  if(!isEmptyTree(root))
  {
    printNode1(root,height);
    PreorderprintTree(root->left,height-1);
    PreorderprintTree(root->right,height-1);
  }
}
//Duyet cay theo chieu rong (Breadth First Search - BFS)
//In theo thu tu tu trai sang phai
/*=========================================================================
            Cac ham chinh trong thu vien (tac dong den cay)
=========================================================================*/
//=========================================================================
//Tao cay nhi phan hoan chinh cung co kieu du lieu element
void makeFullTree(tree **root, int height, element El)
{
  *root=makeNewNodeTree(El);
  if(height!=0)
  {
    makeFullTree(&((*root)->left),height-1,El);
    makeFullTree(&((*root)->right),height-1,El);
  }
}
//=========================================================================
//Tao 1 cay moi tu 2 cay con //UNTESTED!!!
struct tree* createNewTreefrom2Tree
(element El, tree *LeftTree, tree *RightTree)
{
  tree *newTree;
  newTree=(tree*)malloc(sizeof(tree));
  newTree->el=El; newTree->left=LeftTree; newTree->right=RightTree;
  return newTree; 
}
//=========================================================================
//Them mot node tu vi tri trai nhat //UNTESTED!!!
struct tree* addLeftPole(tree **root, element El)
{
  tree *NewNode=makeNewNodeTree(El);
  if(*root==NULL) *root=NewNode;
  else
  {
    tree *LeftPole=*root;
    while(LeftPole->left!=NULL) LeftPole=LeftPole->left;
    LeftPole->left=NewNode;
  }
  return(NewNode);
}
//=========================================================================
//Xoa not trai nhat nhung giu lai noi dung
element deleteLeftPoleofRightTree(tree **root)
{
  element El;
  if((*root)->left==NULL)
  {
    El=(*root)->el; (*root)=(*root)->right; //free((*root)->right);
    return El;
  }
  else return deleteLeftPoleofRightTree(&(*root)->left);
}
//=========================================================================
//Them mot node tu vi tri phai nhat //UNTESTED!!!
struct tree* addRightPole(tree **root, element El)
{
  tree *NewNode=makeNewNodeTree(El);
  if(*root==NULL) *root=NewNode;
  else
  {
    tree *RightPole=*root;
    while(RightPole->right!=NULL) RightPole=RightPole->right;
    RightPole->right=NewNode;
  }
  return(NewNode);
}
//=========================================================================
//Xoa not phai nhat nhung giu lai noi dung
element deleteRightPoleofLeftTree(tree **root)
{
  element El;
  if((*root)->right==NULL)
  {
    El=(*root)->el; (*root)=(*root)->left; //free((*root)->left);
    return El;
  }
  else return deleteLeftPoleofRightTree(&(*root)->right);
}
//=========================================================================
//Dao 2 ben trai phai cua cay
void reverseTree(tree **root)
{
  tree *tmp;
  if(!isEmptyTree(*root))
  {
    if(isEmptyTree((*root)->left))
      {(*root)->left=(*root)->right; (*root)->right=NULL;}
    else if(isEmptyTree((*root)->right))
      {(*root)->right=(*root)->left; (*root)->left=NULL;}
    else {tmp=(*root)->left; (*root)->left=(*root)->right; (*root)->right=tmp;}
    reverseTree(&(*root)->left); reverseTree(&(*root)->right);
  }
}
//=========================================================================
//Binary Search Tree (BST)
//=========================================================================
//Tim kiem tren cay nhi phan tim kiem (Binary Search Tree)
struct tree* searchBST(tree *root, element El)
{
  if(root==NULL) return NULL;
  else if(compareElement1(root->el,El)==0) return root;
  else if(compareElement1(root->el,El)<0)
    return searchBST(root->right,El);
  else searchBST(root->left,El);
}
//=========================================================================
//Them mot node vao cay nhi phan tim kiem (Binary Search Tree)
void insertNodeintoBST(tree **root, element El)
{
  if(*root==NULL)
  {
    *root=(tree*)malloc(sizeof(tree));
    (*root)->el=El; (*root)->left=NULL; (*root)->right=NULL;
  }
  else if(compareElement2((*root)->el,El)<0)
    insertNodeintoBST(&((*root)->right),El);
  else if(compareElement2((*root)->el,El)>0)
    insertNodeintoBST(&((*root)->left),El);
}
//=========================================================================
//Xoa node trong cay nhi phan tim kiem (Binary Search Tree)
//Ham nay can cai tien them: PHAI FREE NODE DE XOA
void deleteNodeinBST(tree **root, element El)
{
  if(!isEmptyTree(*root))
  {
    if((compareElement3(El,(*root)->el)<0))
      deleteNodeinBST(&((*root)->left),El);
    else if(compareElement3(El,(*root)->el)>0)
      deleteNodeinBST(&((*root)->right),El);
    else
    {
      if(isLeaf(*root)==1) *root=NULL;
      else if(isEmptyTree((*root)->left)) *root=(*root)->right;
      else if(isEmptyTree((*root)->right)) *root=(*root)->left;
      else (*root)->el=deleteLeftPoleofRightTree(&(*root)->right);
      //Gan gia tri node trai nhat cua cay con phai cho root
    }
  }
  else printf("Khong tim thay node de xoa!\n");
}
//=========================================================================
//In dep BST //Ham nay minh doc chang hieu cai gi sat T_T
void prettyprintBST(tree *root, char *prefix)
{
  char *prefixend=prefix+strlen(prefix);
  if(root!=NULL)
  {
    printNode2(root);
    if(root->left!=NULL)
      if(root->right==NULL) {printf("\304"); strcat(prefix," ");}
    else {printf("\302"); strcat(prefix,"\263 ");}
    prettyprintBST(root->left,prefix);
    *prefixend='\0';
    if(root->right!=NULL)
      if(root->left!=NULL) {printf("\n%s",prefix); printf("\300");}
    else printf("\304");
    strcat(prefix," ");
    prettyprintBST(root->right,prefix);
  }
}
