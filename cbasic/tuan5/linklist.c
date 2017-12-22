

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*----------------------------------------------------------------------------------*/
typedef struct {
     int date, month, year;
} Birthday;
typedef struct Node_ {
	char name[30];
     char mssv[10];
     float diem;
	struct Node_ *next;
} Node;
/*----------------------------------------------------------------------------------*/
typedef struct {
	Node *top;
} Linklist;
/*----------------------------------------------------------------------------------*/
void Print1()
{
     printf("%-30s%-12s%-13s%-8s%-8s\n", "Ho va ten", "Gioi tinh", "Ngay sinh", "Lop", "Khoa");
}
/*----------------------------------------------------------------------------------*/
void Print2(Node *node)
{
     printf("%-30s%-12s%2d/%2d/%-7d%-8s%-8s\n", node->name, node->sex, node->birthday.date, node->birthday.month,
                                                  node->birthday.year, node->Class, node->grade);
}
/*----------------------------------------------------------------------------------*/
void Full() //thong bao khi ham malloc tra ve NULL (khong cap phat dc)
{
     printf("NO MEMORY!\n");
}
/*----------------------------------------------------------------------------------*/
int IsEmpty(Linklist *s) //kt danh sach trong ko
{
     return (s->top==NULL);
}
/*----------------------------------------------------------------------------------*/
Linklist *Creat()
{
     Linklist *s;
     s=(Linklist *)malloc(sizeof(Linklist));
     if (s==NULL) return s;
     s->top=NULL;
     return s;
}
/*----------------------------------------------------------------------------------*/
int TrueName(char *s) //kt xau co dau cach ko
{
     int i;
     if (s[0]=='\0') return 0;
     for (i=1; i<strlen(s)-1; i++)
     if (s[i]==' ') return 1;
     return 0;
}
/*----------------------------------------------------------------------------------*/
int TrueDate(int d, int m, int y) //kt ngay thang co chuan ko
{
     if ((d<=0)||(m<=0)||(m>12)||(y<1900)||(y>2014)) return 0;
     switch (m){
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12: if (d>31) return 0;

          case 2: if ((y%400==0)||(y%4==0 && y%100!=0))
                    {if (d>28) return 0;}
                  else
                    if (d>29) return 0;
          case 4:
          case 6:
          case 9:
          case 11: if (d>30) return 0;
     }

     return 1;
}
/*----------------------------------------------------------------------------------*/
Node *makeNode() //tao node moi
{
     Node *node;
     node=(Node *)malloc(sizeof(Node));
     if (node==NULL){
          Full();
          return NULL;
     }


     while (getchar()!='\n');
     while (1){
          printf("Nhap ten sinh vien: ");
          gets(node->name);
          if (!TrueName(node->name)) printf("TEN SAI!\n"); //kt ten co dau cach ko
          else break;
     }
     printf("Nhap khoa: "); gets(node->grade);
     printf("Nhap lop: "); gets(node->Class);
     printf("Nhap gioi tinh: "); gets(node->sex);

     //Nhap ngay sinh va kt
     node->birthday.date= node->birthday.month= node->birthday.year= 0;
     while (1){
          printf("Nhap ngay sinh (DD/MM/YYY): ");
          scanf("%d/%d/%d", &node->birthday.date, &node->birthday.month, &node->birthday.year);
          if (!TrueDate(node->birthday.date, node->birthday.month, node->birthday.year))
               {
                    printf("WRONG DATE!\n");
                    while (getchar()!='\n');
               }
          else break;
     }
     node->next=NULL;

     return node;
}
/*----------------------------------------------------------------------------------*/
int Add_Head(Linklist *s, Node *node) //them node vao dau danh sach
{
     node->next=s->top;
     s->top=node;
     return 0;
}
/*----------------------------------------------------------------------------------*/
void daoten(char *s, char *s2)
{
     int i,j ,l;
     char tg[30];
     char *p;
     p=s+strlen(s)-1;
     while ((*p)!=' ') p--;
     p++;
     strcpy(tg, p);

     strcat(tg, " ");
     strcat(tg, s);
     strcpy(s2, tg);
}
/*----------------------------------------------------------------------------------*/
int Node_cmp(Node *node1, Node *node2) //ham tra ve 1 neu node1 dung truoc node2 va tra ve 0 neu node1 sau node2
{
     if (strcmp(node1->grade, node2->grade)<0) return 1;
     if (strcmp(node1->grade, node2->grade)==0) {
          if (strcmp(node1->Class, node2->Class)<0) return 1;
          if (strcmp(node1->Class, node2->Class)==0){
               char tmp1[30], tmp2[30];
               daoten(node1->name, tmp1);
               daoten(node2->name, tmp2);
               if (strcmp(tmp1, tmp2)<0) return 1;
          }
     }

     return 0;
}
/*----------------------------------------------------------------------------------*/
void Add_Sort(Linklist *s, Node *node) //them va sap xep
{
     Node *sau,*trc;
     char tmp1[30], tmp2[30];

     sau=s->top;
     trc=s->top;
     daoten(node->name, tmp1);
     daoten(s->top->name, tmp2);

     if( Node_cmp(node,s->top) ) Add_Head(s, node);
     else {
          while (   (sau!=NULL) && ( !Node_cmp(node, sau) )    ){
               trc=sau;
               sau=sau->next;
          }
          trc->next=node;
          node->next=sau;
     }
}
/*----------------------------------------------------------------------------------*/
void add(Linklist *s)
{
     int m, i;
     Node  *p;
     printf("Nhap so sinh vien muon them: "); scanf("%d", &m);
     for (i=0; i<m; i++){
          if (IsEmpty(s)) Add_Head(s, makeNode());
          else Add_Sort(s, makeNode());
     }
}
/*----------------------------------------------------------------------------------*/
int Search(Linklist *s)
{
     if (IsEmpty(s)){
          printf("EMPTY!\n");
          return 1;
     }

     char name[30];
     int kt=0;
     Node *node1, *node2;

     while (getchar()!='\n');
     printf("Nhap ten muon tim kiem: "); gets(name);

     for (node1=s->top; node1!=NULL; node1=node1->next)        //kt xem co ten ko
     if (strcmp(name, node1->name)==0){
          kt=1;
          break;
     }

     if (kt) {
          Print1;
          for (node2=node1; node2!=NULL; node2=node2->next)
          if (strcmp(node2->name, name)==0) Print2(node2);
     }else printf("KHONG TIM THAY!\n");
}
/*----------------------------------------------------------------------------------*/
void Display_all(Linklist *s)
{
     Node *node;
     Print1();
     for (node=s->top; node!=NULL; node=node->next) Print2(node);
}
/*----------------------------------------------------------------------------------*/
void Display_Class(Linklist *s)
{
     int kt=0;
     Node *node, *node1;
     char Class[5];

     while (getchar()!='\n');
     printf("Nhap lop muon in: "); gets(Class);

     for (node=s->top; node!=NULL; node=node->next)
     if (strcmp(node->Class, Class)==0){
          kt=1;
          break;
     }

     if (kt==1){
          Print1;
          for (node1=node; node1!=NULL; node1=node1->next)
          if (strcmp(node1->Class, Class)==0) Print2(node1);
     } else printf("KHONG CO LOP %-s!\n", Class);
}
/*----------------------------------------------------------------------------------*/
void Display_grade(Linklist *s)
{
     int kt=0;
     char Grade[5];
     Node *node, *node1;

     while (getchar()!='\n');
     printf("Nhap khoa muon in: "); gets(Grade);

     for (node=s->top; node!=NULL; node=node->next)
     if (strcmp(node->grade, Grade)==0){
          kt=1;
          break;
     }

     if (kt==1){
          Print1;
          for (node1=node; node1!=NULL; node1=node1->next)
          if (strcmp(node1->grade, Grade)==0) Print2(node1);
     } else printf("KHONG CO KHOA %-s!\n", Grade);
}
/*----------------------------------------------------------------------------------*/
int Display(Linklist *s)
{
     if (IsEmpty(s)){
          printf("EMPTY LIST!\n");
          return 1;
     }

     int menu;
     while (1)
     {
          printf("--------------------------------------------------------\n");

          printf("%-s%-s%-s%-s","1. In tat ca danh sach\n",
                                "2. In theo lop\n",
                                "3. In theo khoa\n",
                                "4. Thoat\n");
          printf("Input choice: ");
          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   Display_all(s);
                         break;
               case 2:   Display_Class(s);
                         break;
               case 3:   Display_grade(s);
                         break;
               case 4:   return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
}
/*----------------------------------------------------------------------------------*/
int Read_data(Linklist *s)
{
     FILE *f=fopen("data.dat", "rb");
     if (f==NULL) {
          add(s);
          return 0;
     }else{
          int n, i;
          fseek(f, 0, SEEK_END);
          n=ftell(f)/sizeof(Node);
          rewind(f);

          for (i=0; i<n; i++){
               Node *node;
               node=(Node *)malloc(sizeof(Node));
               fread(node, sizeof(Node), 1, f);

               if (IsEmpty(s)) Add_Head(s, node);
               else Add_Sort(s, node); //dung trong truong hop lay file tu bai trc sang chua dc sap xep
          }

          fclose(f);
          return n;
     }
}
/*----------------------------------------------------------------------------------*/
void Save_data(Linklist *s)
{
     FILE *f=fopen("data.dat", "wb");
     Node *node;
     for (node=s->top; node!=NULL; node=node->next)
     fwrite(node, sizeof(Node), 1, f);
     fclose(f);
}
/*----------------------------------------------------------------------------------*/
void Destroy(Linklist *s)
{
     Node *node;
     while (!IsEmpty(s)){
          node=s->top;
          s->top=node->next;
          free(node);
     }
     free(s);
}
/*----------------------------------------------------------------------------------*/
int Linklist_size(Linklist *s)
{
     Node *node;
     int count=0;
     for (node=s->top; node!=NULL; node=node->next) count++;
     return count;
}
/*----------------------------------------------------------------------------------*/
int main()
{
     Linklist *ds;
     ds=Creat();
     if (ds==NULL){
          Full;
          return 1;
     }

     int menu, size;

     size=Read_data(ds);

     while (1)
     {
          printf("--------------------------------------------------------\n");
          printf("                          MENU                          \n");
          printf("--------------------------------------------------------\n");
          printf("%-s%-s%-s%-s","1. Nhap danh sach\n",
                                "2. Tim kiem\n",
                                "3. Xoa sinh vien \n",
                                "4. Thoat\n");
          printf("Input choice: ");

          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   add(ds);
                         break;
               case 2:   Search(ds);
                         break;
               case 3:   Display(ds);
                         break;
               case 4:   if (size<Linklist_size(ds)) Save_data(ds);
                         //de phong truong hop khi ko co file, ham add() yeu cau nhap so sinh vien
                         //neu nguoi dung nhap 0 sau do neu van ghi file thi file se rong
                         //khi doc se bi loi

                         Destroy(ds);
                         return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}

