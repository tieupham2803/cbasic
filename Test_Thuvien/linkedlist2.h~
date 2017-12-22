#include<stdio.h>
#include<stdlib.h>
#define MAX 81
typedef struct node {elementtype el; struct node* next;} node;
/*====================================================================
          Cac ham phu (duoc khai bao trong chuong trinh chinh)
====================================================================*/
elementtype inputEl();
int compareNode1(node *nd1, node *nd2);
int compareNode2(node *nd1, node *nd2);
void displayList(node *root);
void displayDatfile(char path[MAX]);
void search(node *root, node *nd);
/*====================================================================
                    Cac ham ho tro cho xu li danh sach
====================================================================*/
//Ham khoi tao danh sach
void initList(node **root)
{
  (*root)=NULL;
}
//Kiem tra danh sach rong
int isEmptyList(node *root)
{
  return root==NULL;
}
//Ham dem so phan tu trong danh sach
int SizeofList(node *root)
{
  int size=0; node *cur=root;
  while(cur!=NULL) {cur=cur->next; size++;};
  return size;
}
//Tao node moi
struct node* makeNewNode(elementtype El)
{
  node *newNode=(node*)malloc(sizeof(node));
  if(newNode==NULL) printf("Cap phat node moi khong thanh cong!\n");
  else
  {
    newNode->el=El; newNode->next=NULL;
    return newNode;
  }
}
/*====================================================================
                  Cac ham chinh (tac dong den danh sach)
====================================================================*/
//====================================================================
//Nhap du lieu tu file .dat
void importfromDatfiletoList(node **root, char path[MAX])
{
  elementtype *import; node *new,*cur=NULL; FILE *file;
  if((file=fopen(path,"r+b"))==NULL)
    printf("Khong tim thay file %s de doc du lieu!\n",path);
  else
  {
    import=(elementtype*)malloc(sizeof(elementtype));
    while(fread(import,sizeof(elementtype),1,file)!=0)
    {
      new=makeNewNode(*import);
      if(isEmptyList(*root)) {*root=new; cur=*root;}
      else
      {
	cur=*root; while(cur->next!=NULL) cur=cur->next;
	cur->next=new; cur=cur->next;
      }
    }
    free(import); fclose(file);
  }
}
//====================================================================
//Nhap du lieu tu file .dat co sap xep theo compareNode2
struct node* importfromDatfiletosortedList
(node **root, char path[MAX])
{
  elementtype *import; node *new,*prev,*cur; FILE *file;
  if((file=fopen(path,"r+b"))==NULL)
    printf("Khong tim thay file %s de doc du lieu!\n",path);
  else
  {
    import=(elementtype*)malloc(sizeof(elementtype));
    while(fread(import,sizeof(elementtype),1,file)!=0)
    {
      new=makeNewNode(*import);
      if(isEmptyList(*root)||compareNode2(new,*root)==-1)
	{new->next=*root; *root=new;}
      else
      {
	prev=*root; cur=(*root)->next;
	while(cur!=NULL&&compareNode2(new,cur)!=-1)
	  {cur=cur->next; prev=prev->next;};
	new->next=cur; prev->next=new; prev=new;
      }
    }
    free(import); fclose(file);
  }
}
//====================================================================
//Ghi noi dung danh sach vao file van ban co tham so duong dan
void printfromListtoDatfile(node *root, char path[MAX])
{
  FILE *file; node *cur;
  file=fopen(path,"w+b"); cur=root;
  while(cur!=NULL)
  {
    fwrite(&(cur->el),sizeof(elementtype),1,file);
    cur=cur->next;
  }
  fclose(file);
}
//====================================================================
//Chen them node vao danh sach
void insertNewNode(node **root, elementtype El, int n)
{
  int i=0;
  node *insertNode=makeNewNode(El),*cur;
  if(n==1) {insertNode->next=*root; *root=insertNode;}
  else if(2<=n&&n<=SizeofList(*root)+1)
  {
    cur=*root; while(i<=n-3) {cur=cur->next; i++;};
    insertNode->next=cur->next; cur->next=insertNode;
  }
}
//====================================================================
//Xoa node khoi danh sach theo vi tri
void deleteNodebyOrder(node **root, int n)
{
  int i=0; node *prev,*cur;
  if(n==1) {prev=*root; *root=(*root)->next; free(prev);}
  else if(2<=n&&n<=SizeofList(*root)+1)
  {
    cur=*root; while(i<=n-3) {cur=cur->next; i++;};
    prev=cur; cur=cur->next; prev->next=cur->next; free(cur);
  }
}
//====================================================================
//Xoa node khoi danh sach theo ten
void deleteNodebyName(node **root, node *nd)
{
  node *prev,*cur,*delete;
  while(*root!=NULL&&compareNode1(*root,nd)==1)
  {
    delete=*root; *root=(*root)->next;
    free(delete);
  }
  if(isEmptyList(*root));
  prev=*root; cur=(*root)->next;
  while(cur!=NULL)
  {
    while(cur!=NULL&&compareNode1(cur,nd)!=1)
      {cur=cur->next; prev=prev->next;}
    if(cur!=NULL) {prev->next=cur->next; free(cur); cur=prev->next;}
  }
}
//====================================================================
//Thay the mot node tren danh sach
void replaceNode(node **root, elementtype El, int n)
{
  node *cur; int i=0;
  if(n==1) {(*root)->el=El;}
  else if(2<=n&&n<=SizeofList(*root)+1)
  {
    cur=*root; while(i<=n-2) {cur=cur->next; i++;};
    cur->el=El;
  }
}
//====================================================================
//Dao nguoc danh sach
void reverseList(node **root)
{
  node *cur=NULL,*prev=NULL;
  while(*root!=NULL)
  {
    cur=*root; *root=(*root)->next; cur->next=prev; prev=cur;
  }
  *root=prev;
}
//====================================================================
//Chia danh sach
void divideList(node *root, node **divroot1, node **divroot2, int n)
{
  node *cur,*cur1,*cur2,*new; int i=0;
  *divroot1=*divroot2=NULL;
  if(1<=n&&n<=SizeofList(root)+1)
  {
    cur=root;
    while(i<=n-2)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*divroot1)) {*divroot1=new; cur1=*divroot1;}
      else {new->next=cur1->next; cur1->next=new; cur1=cur1->next;};
      cur=cur->next; i++;
    };
    while(cur!=NULL)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*divroot2)) {*divroot2=new; cur2=*divroot2;}
      else {new->next=cur2->next; cur2->next=new; cur2=cur2->next;};
      cur=cur->next;
    };
  }
}
//====================================================================
//Tach danh sach con tu danh sach me
void separateList(node *root, node **seproot, int n1, int n2)
{
  node *cur,*sepcur,*new; int i=0;
  *seproot=NULL;
  if(1<=n1&&n1<=SizeofList(root)&&(n1+n2)<=SizeofList(root)+1)
  {
    cur=root;
    while(i<=n1-2) {cur=cur->next; i++;};
    while(i<=n1+n2-2)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*seproot)) {*seproot=new; sepcur=*seproot;}
      else
      {
        new->next=sepcur->next; sepcur->next=new;
	sepcur=sepcur->next;
      };
      cur=cur->next; i++;
    };
  }
}
//====================================================================
//Free
void freeList(node **root)
{
  node *cur; cur=*root;
  while(cur!=NULL) {*root=(*root)->next; free(cur); cur=*root;}
}
