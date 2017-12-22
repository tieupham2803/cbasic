#include<stdio.h>
#include<stdlib.h>
#define MAX 81
typedef struct node {element el; struct node* prev; struct node* next;} node;
typedef struct item {node *root; node *last;} item;
/*====================================================================
          Cac ham phu (duoc khai bao trong chuong trinh chinh)
====================================================================*/
void printTitle();
void printNode(node *cur, int i);
element inputEl(); //Nhap them thong tin moi
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
void initList(item *list)
{
  list->root=NULL; list->last=NULL;
}
//Kiem tra danh sach rong
int isEmptyList(item list)
{
  return (list.root==NULL&&list.last==NULL);
}
//Ham dem so phan tu trong danh sach
int SizeofList(item list)
{
  int size=0; node *cur=list.root;
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
    newNode->el=El; newNode->prev=NULL; newNode->next=NULL;
    return newNode;
  }
}
/*====================================================================
                  Cac ham chinh (tac dong den danh sach)
====================================================================*/
//====================================================================
//Nhap du lieu tu file .dat
void importfromDatfiletoList(item *list, char path[MAX])
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
      new=makeNewNode(*import);
      if(isEmptyList(*list)) {list->root=new; list->last=new;}
      else
      {
        list->last->next=new; new->prev=list->last;
        list->last=new;
      }
    }
    free(import); fclose(file);
  }
}
//====================================================================
//Nhap du lieu tu file .dat co sap xep theo compareNode1
void insertNewNodeintosortedList(item *list, element El);
void displayList(item list, int i);
void importfromDatfiletosortedList(item *list, char path[MAX])
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
      insertNewNodeintosortedList(list,*import);
    }
    free(import); fclose(file);
  }
}
//====================================================================
//Ghi noi dung danh sach vao file van ban co tham so duong dan
void printfromListtoDatfile(item list, char path[MAX])
{
  FILE *file; node *cur;
  file=fopen(path,"w+b"); cur=list.root;
  while(cur!=NULL)
  {
    fwrite(&(cur->el),sizeof(element),1,file);
    cur=cur->next;
  }
  fclose(file);
}
//====================================================================
//Hien thi noi dung danh sach
void displayList(item list, int i)
{
  node *cur; cur=list.root;
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
void insertNewNode(item *list, element El, int n)
{
  int i=0;
  node *new=makeNewNode(El),*cur;
  if(n==1) {new->next=list->root; list->root=new;}
  else if(2<=n&&n<=SizeofList(*list)+1)
  {
    cur=list->root; while(i<=n-3) {cur=cur->next; i++;};
    new->next=cur->next; cur->next=new;
  }
}
//====================================================================
//Chen them node vao danh sach co sap xep theo CompareNode1
void insertNewNodeintosortedList(item *list, element El)
{
  node *new=makeNewNode(El),*cur;
  if(isEmptyList(*list))
    {list->root=new; list->last=new;}
  else if(compareNode1(new,list->root)<0)
    {new->next=list->root; list->root->prev=new; list->root=new;}
  else
  {
    cur=list->root;
    while(cur->next!=NULL&&compareNode1(new,cur->next)>=0) cur=cur->next;
    new->prev=cur; new->next=cur->next;
    if(cur->next!=NULL) cur->next->prev=new; else list->last=new;
    cur->next=new;    
  }
}
//====================================================================
//Chen them node vao dau danh sach
void enqrootList(item *list, element El)
{
  node *new=makeNewNode(El);
  if(isEmptyList(*list)) {list->root=new; list->last=new;}
  else {new->next=list->root; list->root->prev=new; list->root=new;}
}
//====================================================================
//Chen them node vao cuoi danh sach
void enqlastList(item *list, element El)
{
  node *new=makeNewNode(El);
  if(isEmptyList(*list)) {list->root=new; list->last=new;}
  else {list->last->next=new; new->prev=list->last; list->last=new;}
}
//====================================================================
//Xoa node khoi danh sach theo vi tri
void deleteNodebyOrder(item *list, int n)
{
  int i=0; node *before,*cur;
  if(n==1) {before=list->root; list->root=list->root->next; free(before);}
  else if(2<=n&&n<=SizeofList(*list)+1)
  {
    before=list->root; while(i<=n-3) {before=before->next; i++;};
    cur=before->next; before->next=cur->next;
    if(cur->next!=NULL) cur->next->prev=before; else list->last=before;
    free(cur);
  }
}
//====================================================================
//Xoa node dau tien khoi danh sach
element deqrootList(item *list)
{
  element El;
  node *cur; cur=list->root; El=cur->el;
  list->root=list->root->next; free(cur);
  if(list->root==NULL) list->last=NULL;
  return El;
}
//====================================================================
//Xoa node cuoi cung khoi danh sach
element deqlastList(item *list)
{
  element El;
  node *cur; cur=list->root; El=cur->el;
  list->last=list->last->prev; free(cur);
  if(list->last==NULL) list->root=NULL;
  return El;
}
//====================================================================
//Xoa node khoi danh sach theo ten
void deleteNodebyName(item *list, node *nd)
{
  node *before,*cur,*delete;
  while(!isEmptyList(*list)&&compareNode2(list->root,nd)==1)
  {
    delete=list->root; list->root=list->root->next;
    if(SizeofList(*list)==1) list->last=NULL;
    free(delete);
  }
  if(!isEmptyList(*list))
  {
    before=list->root;
    while(before->next!=NULL)
    {
      while(before->next!=NULL&&compareNode2(before->next,nd)!=1)
        before=before->next;
      cur=before->next;
      if(cur!=NULL)
      {
        before->next=cur->next;
        if(cur->next!=NULL) cur->next->prev=before; else list->last=before;
        free(cur);
      }
    }
  }
}
//====================================================================
//Tim kiem tren danh sach theo ten dien thoai
void searchList(item list, node *nd, int i)
{
  node *cur=list.root;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1) printNode(cur,i);
    cur=cur->next; i++;
  }
}
//====================================================================
//Tim kiem chien luoc dua ve dau danh sach
void movetoFrontsearchList(item *list, node *nd, int i)
{
  node *cur=list->root,*before=list->root; element tmp;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1)
    {
      printNode(cur,i);
      if(cur!=list->root)
      {
        before=cur->prev;
        tmp=cur->el; before->next=cur->next;
        if(cur->next!=NULL) cur->next->prev=before;
          else list->last=before;
        free(cur);
        enqrootList(list,tmp);
        cur=before;
      }
    }
    cur=cur->next; i++;
  }
}
//====================================================================
//Tim kiem chien luoc dua len truoc mot node
void transposesearchList(item *list, node *nd, int i)
{
  node *cur=list->root; element tmp;
  printTitle();
  while(cur!=NULL)
  {
    if(compareNode3(cur,nd)==1)
    {
      printNode(cur,i);
      if(cur!=list->root)
        {tmp=cur->prev->el; cur->prev->el=cur->el; cur->el=tmp;}
    }
    cur=cur->next; i++;
  }
}
//====================================================================
//Thay the mot node tren danh sach
void replaceNode(item *list, element El, int n)
{
  node *cur; int i=0;
  if(n==1) {list->root->el=El;}
  else if(2<=n&&n<=SizeofList(*list)+1)
  {
    cur=list->root; while(i<=n-2) {cur=cur->next; i++;};
    cur->el=El;
  }
}
//====================================================================
//Dao nguoc danh sach
void reverseList(item *list)
{
  node *cur=NULL,*before=NULL;
  while(!isEmptyList(*list))
  {
    cur=list->root; list->root=list->root->next;
    if(SizeofList(*list)==1) list->last=NULL;
    cur->next=before; if(before!=NULL) before->prev=cur; before=cur;
  }
  list->root=before;
}
//====================================================================
//Chia danh sach
void divideList(item list, item *divlist1, item *divlist2, int n)
{
  node *cur,*cur1,*cur2,*new; int i=0;
  initList(divlist1); initList(divlist2);
  if(1<=n&&n<=SizeofList(list)+1)
  {
    cur=list.root;
    while(i<=n-2)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*divlist1))
        {divlist1->root=new; divlist1->last=new; cur1=divlist1->root;}
      else {cur1->next=new; new->prev=cur1; cur1=cur1->next;};
      cur=cur->next; i++;
    };
    while(cur!=NULL)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*divlist2))
        {divlist2->root=new; divlist2->last=new; cur2=divlist2->root;}
      else {cur2->next=new; new->prev=cur2; cur2=cur2->next;};
      cur=cur->next;
    };
  }
}
//====================================================================
//Tach danh sach con tu danh sach me
void separateList(item list, item *seplist, int n1, int n2)
{
  node *cur,*sepcur,*new; int i=0;
  initList(seplist);
  if(1<=n1&&n1<=SizeofList(list)&&(n1+n2)<=SizeofList(list)+1)
  {
    cur=list.root;
    while(i<=n1-2) {cur=cur->next; i++;};
    while(i<=n1+n2-2)
    {
      new=makeNewNode(cur->el);
      if(isEmptyList(*seplist))
        {seplist->root=new; seplist->last=new; sepcur=seplist->root;}
      else {sepcur->next=new; new->prev=sepcur; sepcur=sepcur->next;};
      cur=cur->next; i++;
    };
  }
}
//====================================================================
//Free
void freeList(item *list)
{
  node *cur; cur=list->root;
  while(cur!=NULL) {list->root=list->root->next; free(cur); cur=list->root;}
}
