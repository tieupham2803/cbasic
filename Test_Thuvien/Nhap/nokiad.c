typedef struct element
{char ten[30]; char dl[7]; char kt[5]; char gia[15];} element;
#include"doublelinkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printTitle()
{
  printf("Stt  Ten dien thoai                     Dung luong     ");
  printf("Kich thuoc man hinh      Gia tien\n");
}
void printNode(node *cur, int i)
{
  printf("%-5d%-35s%-15s",i+1,cur->el.ten,cur->el.dl);
  printf("%-25s%s\n",cur->el.kt,cur->el.gia);
}
//Nhap them thong tin moi
element inputEl()
{
  element in;
  printf("Nhap thong tin cho dien thoai\n");
  printf("Ten: "); gets(in.ten);
  printf("Dung luong bo nho: "); gets(in.dl);
  printf("Kich thuoc man hinh: "); gets(in.kt);
  printf("Gia tien: "); gets(in.gia);
  return in;
}
//Xu li ten de co dau cach
void editImport(element *import)
{
  int i;
  for(i=0;i<=strlen((*import).ten)-1;i++) if((*import).ten[i]=='_') (*import).ten[i]=' ';
}
//4. Hien thi noi dung file dat
void displayDatfile(char path[MAX])
{
  FILE *file; int i=0; element *dat;
  dat=(element*)malloc(sizeof(element));
  if((file=fopen(path,"r+b"))==NULL)
    {printf("Khong tim thay file %s de doc du lieu!\n",path);}
  else
  {
    printTitle();
    while(fread(dat,sizeof(element),1,file)!=0)
    {
      printf("%-5d%-35s%-15s",i+1,dat->ten,dat->dl);
      printf("%-25s%s\n",dat->kt,dat->gia); i++;
    };
    free(dat);
  }
}
//Dung trong ham chen vao danh sach co sap xep:
//So sanh thong tin cua node trong chuoi (ve gia tien)
int compareNode1(node *nd1, node *nd2)
{
  if(atoi(nd1->el.gia)<=atoi(nd2->el.gia)) return -1;
  else return 0;
}
//Dung trong ham xoa node theo ten:
//So sanh thong tin cua node trong chuoi (ve ten)
int compareNode2(node *nd1, node *nd2)
{
  char buff[MAX]; strcpy(buff,"");
  strncat(buff,nd1->el.ten,strlen(nd2->el.ten));
  if(strcmp(buff,nd2->el.ten)==0) return 1; else return 0;
}
//Dung trong ham tim kiem:
//So sanh thong tin cua node trong chuoi (ve ten)
int compareNode3(node *nd1, node *nd2)
{
  return compareNode2(nd1,nd2);
}
int menu()
{
  int chon;
  printf("==========Chuong trinh quan li dien thoai Nokia==========\n");
  printf("1. Import from NokiaDB.dat (insert after)\n");
  printf("2. Save from list to file\n");
  printf("3. Display list\n4. Display file\n");
  printf("5. Insert at position\n6. Delete at position\n");
  printf("7. Find in list\n8. Updates to list\n");
  printf("9. Reverse list\n10. Divide and Extract\n");
  printf("11. Quit (Free)\n");
  do {printf("Nhap lua chon (tu 1 den 11): "); scanf("%d",&chon);}
  while(chon<=0||12<=chon);
  return chon;
}
void main()
{
  item lt,lt1,lt2; node *nd;
  int flag=0,chon,chon2,vt,d; char str[MAX];
  initList(&lt); initList(&lt1); initList(&lt2);
  do
  {
    chon=menu(); getchar();
    if(chon!=1&&chon!=4&&chon!=11&&flag==0)
    {
      printf("Chua co du lieu de thuc hien (nhap muc 1 de nap)!\n");
      continue;
    };
    switch(chon)
     {
     case 1: printf("Nhap duong dan de mo file: "); gets(str);
       printf("1. Nhap binh thuong\n2. Nhap co sap xep\n");
       do {printf("Nhap lua chon (1 hoac 2): "); scanf("%d",&chon2);}
       while(chon2<=0||3<=chon2); getchar();
       switch(chon2)
         {
         case 1: importfromDatfiletoList(&lt,str); break;
         case 2: importfromDatfiletosortedList(&lt,str); break;
         }
       flag=1; break;
     case 2: printf("Nhap duong dan de luu file: "); gets(str);
       printfromListtoDatfile(lt,str); break;
     case 3: displayList(lt,0); break;
     case 4: printf("Nhap duong dan de hien thi file: "); gets(str);
       displayDatfile(str); break;
     case 5: printf("Nhap vi tri muon chen nut: "); scanf("%d",&vt);
       getchar();
       if(vt<=0) vt=1;
       else if(vt>=SizeofList(lt)+2) vt=SizeofList(lt)+1;
       insertNewNode(&lt,inputEl(),vt);
       break;
     case 6: printf("1. Xoa theo vi tri\n2. Xoa theo ten\n");
       do {printf("Nhap lua chon (1 hoac 2): "); scanf("%d",&chon2);}
       while(chon2<=0||3<=chon2); getchar();
       if(chon2==1)
       {
	 printf("Nhap vi tri muon xoa nut: ");
	 scanf("%d",&vt); getchar();
	 if(vt<=0||vt>=SizeofList(lt)+1) printf("Nhap sai vi tri!\n");
	 else deleteNodebyOrder(&lt,vt);
       }
       else
       {
	 printf("Nhap ten dien thoai can xoa: "); gets(str);
	 nd=(node*)malloc(sizeof(node));
	 strcpy(nd->el.ten,str); nd->next=NULL;
	 deleteNodebyName(&lt,nd);
	 free(nd); break;
       }
       break;
     case 7: printf("Nhap ten dien thoai can tim: "); gets(str);
       printf("1. Tim kiem binh thuong\n"); 
       printf("2. Tim kiem move to front\n");
       printf("3. Tim kiem transpose\n");
       do {printf("Nhap lua chon (1 den 3): "); scanf("%d",&chon2);}
       while(chon2<=0||4<=chon2); getchar();
       nd=(node*)malloc(sizeof(node));
       strcpy(nd->el.ten,str); nd->next=NULL;
       switch(chon2)
         {
         case 1: searchList(lt,nd,0); break;
         case 2: movetoFrontsearchList(&lt,nd,0); break;
         case 3: transposesearchList(&lt,nd,0); break;
         }
       break;
     case 8: printf("Nhap vi tri nut muon thay doi noi dung: ");
       scanf("%d",&vt); getchar();
       if(vt<=0||vt>=SizeofList(lt)+1) printf("Nhap sai vi tri!\n");
       else replaceNode(&lt,inputEl(),vt);
       break;
     case 9: reverseList(&lt); break;
     case 10: printf("1. Chia danh sach\n2. Tach danh sach\n");
       do {printf("Nhap lua chon (1 hoac 2): "); scanf("%d",&chon2);}
       while(chon2<=0||3<=chon2);
       if(chon2==1)
       {
         printf("Nhap vi tri nut muon chia danh sach: ");
         scanf("%d",&vt); getchar();
	 if(vt<=0||vt>=SizeofList(lt)+1) printf("Nhap sai vi tri!\n");
         else
         {
	   divideList(lt,&lt1,&lt2,vt);
	   printf("Danh sach 1\n"); displayList(lt1,0);
	   printf("Danh sach 2\n"); displayList(lt2,0);
         }
       }
       else
       {
	 printf("Nhap vi tri muon tach danh sach: "); scanf("%d",&vt);
	 printf("Nhap kich thuoc danh sach con: "); scanf("%d",&d);
	 getchar();
	 if(vt<=0&&(SizeofList(lt)+1)<=vt&&SizeofList(lt)+1<=(vt+d))
	   printf("Nhap sai vi tri hoac kich thuoc khong phu hop!\n");
	 else
	 {
	   separateList(lt,&lt1,vt,d); displayList(lt1,0);
	   printf("Nhap duong dan de luu file: "); gets(str);
	   printfromListtoDatfile(lt1,str);
	 }
       }
       break;
     case 11: freeList(&lt); freeList(&lt1); freeList(&lt2); break;
     }
  }
  while(chon!=11);
}
