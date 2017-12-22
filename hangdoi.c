/** Ho va ten: Nguyen Tri Minh. MSSV: 20132599
  * Bo mon: C Basic.
  * Bai lam de thi nam 2010.
  */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_{
     char biethieu[21];
     int mau, tancong, nhanhnhen, phongthu;
     int diem;
     struct Node_ *next;
} Node;
/*----------------------------------------------------------------------------------*/
int isEmpty(Node *top)
{
     return (top==NULL);
}
/*----------------------------------------------------------------------------------*/
Node *deQueue(Node **top)
{
     Node *node;
     node=(*top);
     (*top)=(*top)->next;
     return node;
}
/*----------------------------------------------------------------------------------*/
void addHead(Node **top, Node *newNode)
{
     newNode->next=(*top);
     (*top)=newNode;
}
/*----------------------------------------------------------------------------------*/
void addQueue(Node **top, Node *newNode)
{
     Node *node;
     if ((*top)==NULL)
          addHead(top, newNode);
     else
     {
          for (node=(*top); node->next!=NULL; node=node->next);
          node->next=newNode;
     }
}
/*----------------------------------------------------------------------------------*/
int kt(int a)
{
     if (a<=0)
     {
          printf("File du lieu khong hop le!\n");
          return 0;
     }
     return 1;
}
/*----------------------------------------------------------------------------------*/
int getData(Node **top, char filename[])
{
     FILE *f;
     if ( (f=fopen(filename, "r"))==NULL )
     {
          printf("FILE NOT FOUND!\n");
          return 0;
     }
     else
     {
          Node *node;
          int count=0;
          char Biethieu[21], Mau[5], Tancong[5], Phongthu[5], Nhanhnhen[5];

          while (fscanf(f, "%s", Biethieu)==1)
          {
               node=(Node *)malloc(sizeof(Node));

               strcpy(node->biethieu, Biethieu);

               fscanf(f, "%s", Mau);
               node->mau=atoi(Mau);
               if (!kt(node->mau)) return 0;

               fscanf(f, "%s", Tancong);
               node->tancong=atoi(Tancong);
               if (!kt(node->tancong)) return 0;

               fscanf(f, "%s", Nhanhnhen);
               node->nhanhnhen=atoi(Nhanhnhen);
               if (!kt(node->nhanhnhen)) return 0;

               fscanf(f, "%s", Phongthu);
               node->phongthu=atoi(Phongthu);
               if (!kt(node->phongthu)) return 0;

               node->diem=0;
               addQueue(top, node);
               count++;
          }
          return count;
     }
}
/*----------------------------------------------------------------------------------*/
void Display(Node *top)
{
     Node *node;
     int i=1;

     for (node=top; node!=NULL; node=node->next)
     printf("%-3d%-10s%-10d%-10d%-10d%-10d\n", i++, node->biethieu,
            node->mau, node->tancong, node->nhanhnhen, node->phongthu);
}
/*----------------------------------------------------------------------------------*/
void addSort(Node **top, Node *newNode)
{
     if (isEmpty(*top))
          addHead(top, newNode);
     else
     {
          Node *sau,*truoc;

          sau=(*top);
          truoc=(*top);
          if (newNode->diem>sau->diem)
          {
               newNode->next=(*top);
               *top=newNode;
          } else
          {
               while ( (sau!=NULL) && (sau->diem>=newNode->diem) )
               {
                    truoc=sau;
                    sau=sau->next;
               }
               truoc->next=newNode;
               newNode->next=sau;
          }
     }
}
/*----------------------------------------------------------------------------------*/
void thidau(Node **queue1, Node **queue2, Node *XepHang)
{
     Node *VoSi1, *VoSi2;
     //kt=1 thi VoSi1 tan cong, kt=2 thi VoSi2 tan cong
     //kt=-1 VoSi1 bi loai, kt=-2 VoSi2 bi loai
     int kt=0;
     int count=0;

     while ( !isEmpty(*queue1) &&  !isEmpty(*queue2))
     {
          VoSi1=deQueue(queue1);
          VoSi2=deQueue(queue2);
          //turn1, turn2 la lan tan cong thu bao nhieu
          int turn1=1, turn2=1;

          printf("Tran %-3d: MP1 - %-10s%-10d%-10d%-10d%-10d\n", count+1, VoSi1->biethieu,
                 VoSi1->mau, VoSi1->tancong, VoSi1->nhanhnhen, VoSi1->phongthu);
          printf("VS      : MP2 - %-10s%-10d%-10d%-10d%-10d\n", VoSi2->biethieu,
                 VoSi2->mau, VoSi2->tancong, VoSi2->nhanhnhen, VoSi2->phongthu);

          //lan dau tan cong
          if (VoSi1->nhanhnhen>VoSi2->nhanhnhen)
               kt=1; //VoSi1 tan cong trc
          else
               kt=2; //VoSi2 tan cong truoc

          while (kt>0)
          {
               if (kt==1)
               {
                    int matMau;
                    matMau=VoSi1->tancong-VoSi2->phongthu;
                    if (matMau<=0)
                         matMau=0;

                    VoSi2->mau=VoSi2->mau-matMau;

                    printf("%-10s tan cong - %-10s mat %d mau\n", VoSi1, VoSi2, matMau);
                    if (VoSi2->mau<=0)
                         if (turn1==1) //day la lan tan cong dau tien
                         {
                              VoSi1->diem+=3;
                              kt=-2;
                              printf("%-10s bi KNOCKOUT.\n", VoSi2->biethieu);
                         }
                         else //khong phai lan tan cong dau tien
                         {
                              VoSi1->diem++;
                              kt=-2;
                              printf("%-10s bi loai.\n", VoSi2->biethieu);
                         }
                    else
                         {
                              VoSi1->diem++;
                              kt=2;
                              turn1++;
                         }
               } else
               {
                    int matMau;
                    matMau=VoSi2->tancong-VoSi1->phongthu;
                    if (matMau<=0)
                         matMau=0;

                    VoSi1->mau=VoSi1->mau-matMau;

                    printf("%-10s tan cong - %-10s mat %d mau\n", VoSi2, VoSi1, matMau );
                    if (VoSi1->mau<=0)
                         if (turn2==1) //lan tan cong dau tien
                         {
                              VoSi2->diem+=3;
                              kt=-1;
                              printf("%-10s bi KNOCKOUT.\n", VoSi1->biethieu);
                         }
                         else //khong phai lan tan cong dau tien
                         {
                              VoSi2->diem++;
                              kt=-1;
                              printf("%-10s bi loai.\n", VoSi1->biethieu);
                         }
                    else
                    {
                         VoSi2->diem++;
                         kt=1;
                         turn2++;
                    }
               }


          }
          if (kt==-1)
          {
               addSort(XepHang, VoSi1); //them VoSi1 vao xep hang
               addHead(queue2, VoSi2); //them VoSi2 vao lai hang doi
          }
          else
          {
               addSort(XepHang, VoSi2); //them VoSi2 vao xep hang
               addHead(queue1, VoSi1); //them VoSi1 vao lai hang doi
          }
          count++;
          printf("\n-----------------------------------------\n");
     }

     if (isEmpty(*queue1))
     {
          printf("KET QUA: Mon phai 1 THUA.\n");
          while (!isEmpty(*queue2))
               addSort(XepHang, deQueue(queue2));
     }
     else
     {
          printf("KET QUA: Mon phai 2 THUA.\n");
          while (!isEmpty(*queue1))
               addSort(XepHang, deQueue(queue1));
     }
}
/*----------------------------------------------------------------------------------*/
void DisplaySort(Node *top)
{
     Node *node;
     int i=1;

     for (node=top; node!=NULL; node=node->next)
     printf("%-3d%-10s%-10d\n", i++, node->biethieu, node->diem);
}
/*----------------------------------------------------------------------------------*/
void free_all(Node **top)
{
     Node *node;
     while (isEmpty(*top))
          node=deQueue(top);
     free(node);
}
/*----------------------------------------------------------------------------------*/
int main()
{
     int menu;

     Node *queue1=NULL, *queue2=NULL;
     Node *XepHang=NULL;
     int count1, count2;


     while (1)
     {
          printf("--------------------------------------------------------\n");
          printf("                          MENU                          \n");
          printf("--------------------------------------------------------\n");
          printf("%-s%-s%-s%-s","1. Doc du lieu\n",
                                "2. Thi dau\n",
                                "3. Xep hang vo si\n",
                                "4. Thoat\n");
          printf("Input choice: ");

          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   count1=getData(&queue1, "monphai1.txt");
                         count2=getData(&queue2, "monphai2.txt");
                         if (count1==0 || count2==0) break; //truong hop du lieu sai
                         if (count1!=count2)
                              printf("Luc luong khong can bang. Yeu cau sua lai so lieu!\n");
                         else
                         {

                              printf("Danh sach mon phai 1:\n");
                              Display(queue1);
                              printf("Danh sach mon phai 2:\n");
                              Display(queue2);
                         }
                         break;
               case 2:   thidau(&queue1, &queue2, &XepHang);
                         break;
               case 3:   if (isEmpty(XepHang))
                              printf("Chua co du lieu!\n");
                         else
                         {
                              printf("Bang xep hang: \n");
                              DisplaySort(XepHang);
                         }
                         break;
               case 4:   if (!isEmpty(XepHang))
                              free_all(&XepHang);
                         return 0;
               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}
