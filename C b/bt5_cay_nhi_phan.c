/**Ho va ten: Nguyen Tri Minh. MSSV:20132599.
  *Nhom:3. Bo mon: C Basic
  *Bai tap ve tim kiem nhi phan
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     int hour;
     int minute;
} TimeType; //cau truc thoi gian
/*----------------------------------------------------------------------------------*/
typedef struct Task_Node{ //cau truc cong viec
     TimeType beginTime;
     TimeType endTime;
     char Subject[100];  //noi dung
     int level;          //muc do
     struct Task_Node *leftTask;
     struct Task_Node *rightTask;
} TaskType;
/*----------------------------------------------------------------------------------*/
typedef struct Day_Node{ //cau truc ngay chua cong viec va gia tri cua ngay
     int Date;
     TaskType *Task;    //cong viec
     struct Day_Node *leftDate;
     struct Day_Node *rightDate;
} DateNode;
/*----------------------------------------------------------------------------------*/
void Print1()
{
     printf("%-10s%-20s%-17s%-17s%-15s\n","Ngay", "Cong viec", "TG bat dau",
                                        "TG ket thuc", "Muc do");
}
/*----------------------------------------------------------------------------------*/
void Print2(TaskType *node, int date) //in ra 1 cong viec
{
     printf("%-10d%-20s%8d:%-8d%8d:%-8d", date, node->Subject, node->beginTime.hour, node->beginTime.minute,
                                    node->endTime.hour,node->endTime.minute);
     if (node->level==1) printf("Rat quan trong\n");
     if (node->level==2) printf("Quan trong\n");
     if (node->level==3) printf("Can thiet\n");
     if (node->level==4) printf("Khong can thiet\n");

}
/*----------------------------------------------------------------------------------*/
void getDate(int *a) //nhap vao ngay
{
     while (1){
          if (scanf("%d", a)!=1) {
               printf("WRONG DATE!\nINPUT AGAIN: ");
               while (getchar()!='\n');
          }
          else if ((*a<1)||(*a>31)) printf("WRONG DATE!\nINPUT AGAIN: ");
          else break;
     }
}
/*----------------------------------------------------------------------------------*/
void getTime(TimeType *a) //nhap vao gio
{
     while (1){
          if (scanf("%d:%d", &a->hour, &a->minute)!=2) {
               printf("WRONG TIME!\nINPUT AGAIN: ");
               while (getchar()!='\n');
          }
          else if ((a->hour<0)||(a->hour>24)||(a->minute<0)||(a->minute>59))
               printf("WRONG TIME!\nINPUT AGAIN: ");
          else break;
     }
}
/*----------------------------------------------------------------------------------*/
void getLevel(int *a) //nhap vao muc do
{
     while (1){
          if (scanf("%d", a)!=1) {
               printf("WRONG LEVEL!\nINPUT AGAIN: ");
               while (getchar()!='\n');
          }
          else if ((*a<1)||(*a>4)) printf("WRONG LEVEL!\nINPUT AGAIN: ");
          else break;
     }
}
/*----------------------------------------------------------------------------------*/
TaskType *makeTask() //tao task moi
{
     TaskType *node;
     node=(TaskType *)malloc(sizeof(TaskType));

     printf("Nhap thoi gian bat dau (XX:YY): ");
     getTime(&node->beginTime);

     printf("Nhap thoi gian ket thuc (XX:YY): ");
     getTime(&node->endTime);

     while (getchar()!='\n');
     printf("Nhap noi dung: ");
     gets(node->Subject);

     printf("Nhap muc do (1,2,3,4 tuong ung: rat quan trong, quan trong, can thiet, khong can thiet): ");
     getLevel(&node->level);

     node->leftTask=NULL;
     node->rightTask=NULL;

     return node;
}
/*----------------------------------------------------------------------------------*/
DateNode *makeDay(int InputDate, TaskType *TaskNode) // tao node ngay moi
{
     DateNode *node;
     node=(DateNode *)malloc(sizeof(DateNode));

     node->Date=InputDate;

     node->Task=TaskNode;

     node->leftDate=NULL;
     node->rightDate=NULL;

     return node;
}
/*----------------------------------------------------------------------------------*/
int TimeCmp(TimeType a, TimeType b) //so sanh a va b
{
     if (a.hour<b.hour) return -1;
     if (a.hour==b.hour) {
          if (a.minute<b.minute) return -1;
          if (a.minute==b.minute) return 0;
     }
     return 1;
}
/*----------------------------------------------------------------------------------*/
void InsertTask(TaskType **node, TaskType *InputTask) //chen task vao ngay
{
     if ((*node)==NULL) (*node)=InputTask;
     else {
          if (TimeCmp( (*node)->beginTime, InputTask->beginTime )>0)  InsertTask(&(*node)->leftTask, InputTask);
          if (TimeCmp( (*node)->beginTime, InputTask->beginTime )<0)  InsertTask(&(*node)->rightTask, InputTask);
     }
}
/*----------------------------------------------------------------------------------*/
void InsertDate(DateNode **node, int InputDate, TaskType *InputTask) //chen them ngay
{
     if ((*node)==NULL) (*node)=makeDay(InputDate, InputTask);
     else {
          if ((*node)->Date>InputDate)    InsertDate(&(*node)->leftDate, InputDate, InputTask);
          if ((*node)->Date<InputDate)    InsertDate(&(*node)->rightDate, InputDate, InputTask);
          if ((*node)->Date==InputDate)   InsertTask(&(*node)->Task, InputTask);
     }
}
/*----------------------------------------------------------------------------------*/
void Add_DateNode(DateNode **rootPtr) //ham them cong viec
{
     int InputDate;

     printf("Nhap ngay muon them cong viec: ");
     getDate(&InputDate);

     InsertDate(rootPtr, InputDate, makeTask());
}
/*==================================================================================*/
void DisplayTask(TaskType *node, int InputDate) //hien thi cong viec cua ngay InputDate
{
     if ((!node->leftTask)&&(!node->rightTask)) Print2(node, InputDate);
     else {
          if (node->leftTask) DisplayTask(node->leftTask, InputDate);
          Print2(node, InputDate);
          if (node->rightTask) DisplayTask(node->rightTask, InputDate);
     }
}
/*----------------------------------------------------------------------------------*/
void DisplayDateNode(DateNode *node)  //hien thi tat ca cong viec
{
     if ((!node->leftDate)&&(!node->rightDate)) DisplayTask(node->Task, node->Date);
     else {
          if (node->leftDate) DisplayDateNode(node->leftDate);
          DisplayTask(node->Task, node->Date);
          if (node->rightDate) DisplayDateNode(node->rightDate);
     }
}
/*==================================================================================*/
DateNode *Search_Date(DateNode *node, int InputDate) //tim node chua ngay InputDate
{
     if (node!=NULL){
          if (node->Date<InputDate) return (Search_Date(node->rightDate, InputDate));
          if (node->Date>InputDate) return (Search_Date(node->leftDate, InputDate));
     }
     return node;
}
/*----------------------------------------------------------------------------------*/
void DisplayDate(DateNode *root) //hien thi cong viec cua ngay bat ki
{
     if (!root) printf("CHUA TAO LICH!\n");
     else {
          int InputDate;
          DateNode *node;

          printf("Nhap ngay muon hien thi cong viec: ");
          scanf("%d", &InputDate);

          node=Search_Date(root, InputDate);
          if (!node) printf("KHONG THAY NGAY %d!\n", InputDate);
          else {
               Print1();
               DisplayTask(node->Task, node->Date);
          }
     }
}
/*==================================================================================*/
void Search_Level_Task(TaskType *node, int InputDate, int InputLevel) //tim cac cong viec co muc do InputLevel trong 1 ngay
{
     if (node!=NULL) {
          if (node->level==InputLevel) Print2(node, InputDate);
          Search_Level_Task(node->leftTask, InputDate, InputLevel);
          Search_Level_Task(node->rightTask, InputDate, InputLevel);
     }
}
/*----------------------------------------------------------------------------------*/
void Search_Level_Date(DateNode *node, int InputLevel) //tim cac cong viec co muc do InputLevel trong lich
{
     if (node!=NULL){
          Search_Level_Task(node->Task, node->Date, InputLevel);
          Search_Level_Date(node->leftDate,InputLevel);
          Search_Level_Date(node->rightDate, InputLevel);
     }
}
/*----------------------------------------------------------------------------------*/
void DisplayLevel(DateNode *root) //hien thi cong viec co muc do bat ki
{
     if (!root) printf("CHUA TAO LICH\n");
     else{
          int InputLevel;
          DateNode *node;

          printf("Nhap muc do cong viec muon hien thi: ");
          scanf("%d", &InputLevel);

          Print1();
          Search_Level_Date(root, InputLevel);
     }
}
/*==================================================================================*/
void Display_TaskChualam(TaskType *node, int InputDate, TimeType InputTime) //hien thi cac cong viec chua lam trong 1 ngay
{
     if (node) {
          if (TimeCmp(node->beginTime, InputTime)>0) {
               Display_TaskChualam(node->leftTask, InputDate, InputTime);
               Print2(node, InputDate);
               Display_TaskChualam(node->rightTask, InputDate, InputTime);
          }

          if (TimeCmp(node->beginTime, InputTime)<=0)
               Display_TaskChualam(node->rightTask, InputDate, InputTime);
     }
}
/*----------------------------------------------------------------------------------*/
void Display_Chualam(DateNode *node, int InputDate, TimeType InputTime) //hien thi cac cong viec chua lam trong lich
{
     if (node) {
          if (node->Date==InputDate) {
               Display_TaskChualam(node->Task, InputDate, InputTime);
               Display_Chualam(node->rightDate, InputDate, InputTime);
          }

          if (node->Date>InputDate) {
               Display_Chualam(node->leftDate, InputDate, InputTime);
               DisplayTask(node->Task, node->Date);
               Display_Chualam(node->rightDate, InputDate, InputTime);
          }

          if (node->Date<InputDate) {
               Display_Chualam(node->rightDate, InputDate, InputTime);
          }
     }
}
/*----------------------------------------------------------------------------------*/
void Display_TaskDalam(TaskType *node, int InputDate, TimeType InputTime) //hien thi cac cong viec da lam trong 1 ngay
{
     if (node) {
          if (TimeCmp(node->beginTime, InputTime)<0) {
               Display_TaskDalam(node->leftTask, InputDate, InputTime);
               Print2(node, InputDate);
               Display_TaskDalam(node->rightTask, InputDate, InputTime);
          }

          if (TimeCmp(node->beginTime, InputTime)>=0)
               Display_TaskDalam(node->leftTask, InputDate, InputTime);
     }
}
/*----------------------------------------------------------------------------------*/
void Display_Dalam(DateNode *node, int InputDate, TimeType InputTime) //hien thi cong viec da lam trong lich
{
     if (node) {
          if (node->Date==InputDate) {
               Display_TaskDalam(node->Task, InputDate, InputTime);
               Display_Dalam(node->leftDate, InputDate, InputTime);
          }

          if (node->Date<InputDate) {
               Display_Dalam(node->leftDate, InputDate, InputTime);
               DisplayTask(node->Task, node->Date);
               Display_Dalam(node->rightDate, InputDate, InputTime);
          }

          if (node->Date>InputDate) {
               Display_Dalam(node->leftDate, InputDate, InputTime);
          }
     }
}
/*----------------------------------------------------------------------------------*/
int DisplayDo(DateNode *root) //ham hien thi cong viec da (chua) lam so voi ngay hom nay
{
     if (!root) printf("CHUA TAO LICH\n");
     else {

          int InputDate;
          TimeType InputTime;
          printf("--------------------------------------------------------\n");
          printf("Nhap ngay hom nay: "); scanf("%d", &InputDate);
          printf("Nhap gio bat dau: "); getTime(&InputTime);

          while (1) {
               int menu;


               printf("--------------------------------------------------------\n");
               printf("%-s%-s%-s","1. Xem viec da lam\n",
                              "2. Xem viec chua lam\n",
                              "3. Thoat\n");
               printf("Input choice: ");

               if (scanf("%d", &menu)!=1) {
                    while (getchar()!='\n');
                    printf("WRONG CHOIE!\n");
                    continue;
               }


               switch (menu){
                    case 1:   Print1();
                              Display_Dalam(root, InputDate, InputTime);
                              break;
                    case 2:   Print1();
                              Display_Chualam(root, InputDate, InputTime);
                              break;
                    case 3:   return 0;
               }
          }
     }
}
/*==================================================================================*/
/*----------------------------------------------------------------------------------*/
TaskType *Find_TaskMin(TaskType *node) //tim cong viec co beginTime be nhat trong cay co goc node
{
     if (node) return NULL;
     else
          if (!node->leftTask) return node;
          else return (Find_TaskMin(node->leftTask));
}
/*----------------------------------------------------------------------------------*/
void DeleteTask(TaskType **node, TimeType TimeDelete) //xoa cong viec muon xoa
{
     if (*node) {
          if (TimeCmp(TimeDelete, (*node)->beginTime)<0) DeleteTask(&(*node)->leftTask, TimeDelete);
          if (TimeCmp(TimeDelete, (*node)->beginTime)>0) DeleteTask(&(*node)->rightTask, TimeDelete);
          if (TimeCmp(TimeDelete, (*node)->beginTime)==0) {
               if ((*node)->leftTask && (*node)->rightTask) { //(*node) co 2 con, phan tu the cho la phan tu min o cay con phai
                    TaskType *tmp;

                    tmp=Find_TaskMin((*node)->rightTask);

                    (*node)->beginTime.hour=tmp->beginTime.hour;
                    (*node)->beginTime.minute=tmp->endTime.minute;

                    (*node)->endTime.hour=tmp->endTime.hour;
                    (*node)->endTime.minute=tmp->endTime.minute;

                    (*node)->level=tmp->level;

                    strcpy((*node)->Subject, tmp->Subject);

                    DeleteTask(&(*node)->rightTask, (*node)->beginTime);
               }
               else { //(*node) co 1 con hoac khong con
                    TaskType *tmp;
                    tmp=(*node);
                    if (!(*node)->leftTask) (*node)=(*node)->rightTask; //co con phai hoac khong co con
                    else
                         if (!(*node)->rightTask) (*node)=(*node)->leftTask; //chi co con trai

                    free(tmp);
               }
          }
     }
}
/*----------------------------------------------------------------------------------*/
DateNode *Find_DateMin(DateNode *node) //tim ngay be nhat trong cay co goc la node
{
     if (!node) return NULL;
     else
          if (!node->leftDate) return node;
          else return (Find_DateMin(node->leftDate));
}
/*----------------------------------------------------------------------------------*/
void DeleteDate(DateNode **node, int DateDelete) //xoa ngay muon xoa
{
     if (*node) {

          if (DateDelete<(*node)->Date) DeleteDate(&(*node)->leftDate, DateDelete);
          if (DateDelete>(*node)->Date) DeleteDate(&(*node)->rightDate, DateDelete);
          if (DateDelete==(*node)->Date) {
               if ( (*node)->leftDate && (*node)->rightDate ) { //co 2 con

                    DateNode *tmp;

                    tmp=Find_DateMin((*node)->rightDate);

                    (*node)->Date=tmp->Date;
                    (*node)->Task=tmp->Task;

                    DeleteDate(&(*node)->rightDate, (*node)->Date);
               } else {
                    DateNode *tmp;
                    tmp=(*node);
                    if (!(*node)->leftDate) (*node)=(*node)->rightDate; //co con phai hoc khong con
                    else
                         if (!(*node)->rightDate) (*node)=(*node)->rightDate; //chi co con trai
                    }
          }
     }
}
/*----------------------------------------------------------------------------------*/
void DeleteInDate(DateNode **node, int DateDelete, TimeType TimeDelete) //tim ngay co cong viec muon xoa
{
     if (*node) {
          if (DateDelete<(*node)->Date) DeleteInDate(&(*node)->leftDate, DateDelete, TimeDelete);
          if (DateDelete>(*node)->Date) DeleteInDate(&(*node)->rightDate, DateDelete, TimeDelete);
          if (DateDelete==(*node)->Date) {
               DeleteTask(&(*node)->Task, TimeDelete);

               if (!(*node)->Task) DeleteDate(node, DateDelete); //neu ngay khong con cong viec thi xoa ngay
          }
     }
}
/*----------------------------------------------------------------------------------*/
void Edit(DateNode **rootNode) //sua lich
{
     if (!(*rootNode)) printf("CHUA TAO LICH!\n");
     else {
          TimeType TimeDelete;
          int DateDelete;

          printf("Nhap ngay muon xoa cong viec: ");
          scanf("%d", &DateDelete);

          while (getchar()!='\n');
          printf("Nhap gio bat dau cua cong viec muon xoa: ");
          getTime(&TimeDelete);

          DeleteInDate(rootNode, DateDelete, TimeDelete);
     }
}
/*==================================================================================*/
void freeTask(TaskType *node)
{
     if ((!node->leftTask)&&(!node->rightTask))   free(node);
     else {
          if (node->leftTask) freeTask(node->leftTask);
          if (node->rightTask) freeTask(node->rightTask);
          free(node);
     }
}
/*----------------------------------------------------------------------------------*/
void freeDate(DateNode *node)
{
     if ((!node->leftDate)&&(!node->rightDate)) {
          freeTask(node->Task);
          free(node);
     } else {
          if (node->leftDate) freeDate(node->leftDate);
          if (node->rightDate) freeDate(node->rightDate);
          freeTask(node->Task);
          free(node);
     }
}
/*==================================================================================*/
int main()
{
     int menu;

     DateNode *root;
     root=NULL;

     while (1)
     {
          printf("--------------------------------------------------------\n");
          printf("                          MENU                          \n");
          printf("--------------------------------------------------------\n");
          printf("%-s%-s%-s%-s%-s%-s%-s","1. Nhap cong viec\n",
                                "2. Xem cong viec theo ngay\n",
                                "3. Xem cong viec theo tinh chat\n",
                                "4. Xem cong viec da (chua) hoan thanh\n",
                                "5. Dieu chinh lich\n",
                                "6. Hien thi tat ca cong viec\n",
                                "7. Thoat\n");
          printf("Input choice: ");

          if (scanf("%d", &menu)!=1) {
               while (getchar()!='\n');
               printf("WRONG CHOIE!\n");
               continue;
          }


          switch (menu){
               case 1:   Add_DateNode(&root);//them cong viec
                         Print1();
                         DisplayDateNode(root);
                         break;
               case 2:   DisplayDate(root);  //xem cong viec theo ngay
                         break;
               case 3:   DisplayLevel(root); //xem cong viec theo muc do
                         break;
               case 4:   DisplayDo(root); //xem cong viec da (chua) lam
                         break;
               case 5:   Edit(&root);
                         break;
               case 6:   Print1();
                         DisplayDateNode(root);
                         break;
               case 7:   if (root) freeDate(root);
                         return 0;

               default:  printf("WRONG CHOICE!\n");
          }
     }
     return 0;
}
