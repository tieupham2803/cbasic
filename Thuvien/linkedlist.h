#include<stdio.h>
#include<stdlib.h>
#define MAX 81
typedef struct node {element el; struct node* next;} node;
/*====================================================================
          Cac ham phu (duoc khai bao trong chuong trinh chinh)
====================================================================*/
void printTitle();
void printNode(node *cur, int i);
element inputElement();
void editImport(element *import);
void displayDatfile(char path[MAX]);
//Sua noi dung element doc tu file, dung trong ham nhap tu file vao
//danh sach
int compareNode1(node *nd1, node *nd2);
//Dung trong ham chen vao danh sach co sap xep
int compareNode2(node *nd1, node *nd2);
//Dung trong ham xoa node theo ten
int compareNode3(node *nd1, node *nd2); //Dung trong ham tim kiem
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
struct node* makeNewNode(element El)
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
  element *import; node *new,*cur=NULL; FILE *file;
  if((file=fopen(path,"r+b"))==NULL)
    printf("Khong tim thay file %s de doc du lieu!\n",path);
  else
  {
    import=(element*)malloc(sizeof(element));
    while(fread(import,sizeof(element),1,file)!=0)
    {
      editImport(import);
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
//Nhap du lieu tu file .dat co sap xep theo compareNode1
void insertNewNodeintosortedList(node **root, element El);
void importfromDatfiletosortedList(node **root, char path[MAX])
{
  element *import; node *new; FILE *file;
  if((file=fopen(path,"r+b"))==NULL)
    printf("Khong tim thay file %s de doc du lieu!\n",path);
  else
  {
    import=(element*)malloc(sizeof(element));
    while(fread(import,sizeof(element),1,file)!=0)
    {
      editImport(import);
      insertNewNodeintosortedList(&*root,*import);
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
    fwrite(&(cur->el),sizeof(element),1,file);
    cur=cur->next;
  }
  fclose(file);
}
//====================================================================
//Hien thi noi dung danh sach
void displayList(node *root, int i)
{
  node *cur; cur=root;
  printTitle();
  while(cur!=NULL)
  {
    printNode(cur,i);
    cur=cur->next; i++;
  }
  free(cur);
}
//====================================================================
//Chen them node vao danh sach theo vi tri
void insertNewNode(node **root, element El, int n)
{
  int i=0;
  node *new=makeNewNode(El),*cur;
  if(n==1) {new->next=*root; *root=new;}
  else if(2<=n&&n<=SizeofList(*root)+1)
  {
    cur=*root; while(i<=n-3) {cur=cur->next; i++;};
    new->next=cur->next; cur->next=new;
  }
}
//====================================================================
//Chen them node vao danh sach co sap xep theo CompareNode1
void insertNewNodeintosortedList(node **root, element El)
{
  node *new=makeNewNode(El),*cur,*before;
  if(isEmptyList(*root)||compareNode1(new,*root)<0)
    {new->next=*root; *root=new;}
  else
  {
    before=*root; cur=(*root)->next;
    while(cur!=NULL&&compareNode1(new,cur)>=0)
      {cur=cur->next; before=before->next;};
    new->next=cur; before->next=new; before=new;
  }
}
//====================================================================
//Chen them node vao dau danh sach
void pushList(node **root, element El)
{
  node *new=makeNewNode(El);
  new->next=*root; *root=new;
}
//====================================================================
//Xoa node khoi danh sach theo vi tri
void deleteNodebyOrder(node **root, int n)
{
  int i=0; node *before,*cur;
  if(n==1) {before=*root; *root=(*root)->next; free(before);}
  else if(2<=n&&n<=SizeofList(*root)+1)
  {
    before=*root; while(i<=n-3) {before=before->next; i++;};
    cur=before->next; before->next=cur->next; free(cur);
  }
}
//====================================================================
//Xoa node dau tien khoi danh sach
element popList(node **root)
{
  element El;
  node *before; before=*root; El=before->el;
  *root=(*root)->next; free(before);
  return El;
}
//====================================================================
//Xoa node khoi danh sach theo ten
void deleteNodebyName(node **root, node *nd)
{
  node *before,*cur,*delete;
  while(!isEmptyList(*root)&&compareNode2(*root,nd)==1)
  {
    delete=*root; *root=(*root)->next;
    free(delete);
  }
  if(!isEmptyList(*root))
  {
    before=*root; cur=(*root)->next;
    while(cur!=NULL)
    {
      while(cur!=NULL&&compareNode2(cur,nd)!=1)
        {cur=cur->next; before=before->next;}
      if(cur!=NULL) {before->next=cur->next; free(cur); cur=before->next;}
    }
  }
}
//====================================================================
//Tim kiem tren danh sach theo ten dien thoai
void searchList(node *root, node *nd, int i)
{
  node *cur=root;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1) printNode(cur,i);
    cur=cur->next; i++;
  }
}
//====================================================================
//Tim kiem chien luoc dua ve dau danh sach
void movetoFrontsearchList(node **root, node *nd, int i)
{
  node *cur=*root,*before=*root; element tmp;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1)
    {
      printNode(cur,i);
      if(cur!=*root)
      {
        while(before->next!=cur) before=before->next;
        tmp=cur->el; before->next=cur->next; free(cur);
        pushList(&*root,tmp);
        cur=before;
      }
    }
    cur=cur->next; i++;
  }
}
//====================================================================
//Tim kiem chien luoc dua len truoc mot node
void transposesearchList(node **root, node *nd, int i)
{
  node *cur=*root,*before=*root; element tmp;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1)
    {
      printNode(cur,i);
      if(cur!=*root)
      {
        while(before->next!=cur) before=before->next;
        tmp=before->el; before->el=cur->el; cur->el=tmp;
      }
    }
    cur=cur->next; i++;
  }
}
//====================================================================
//Thay the mot node tren danh sach
void replaceNode(node **root, element El, int n)
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
  node *cur=NULL,*before=NULL;
  while(!isEmptyList(*root))
  {
    cur=*root; *root=(*root)->next; cur->next=before; before=cur;
  }
  *root=before;
}
//====================================================================
//Chia danh sach
void divideList(node *root, node **divroot1, node **divroot2, int n)
{
  node *cur,*cur1,*cur2,*new; int i=0;
  initList                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               