#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct A
{
  char name[31];
  char mssv[10];
  float score;
  struct A *next;
} ListNode;
typedef struct
{
  ListNode *first,*last;
} list;
ListNode *MakeNode(char s[31],char mssv[10],float n)
{
  ListNode *Node;
  Node=(ListNode *)malloc(sizeof(ListNode));
  Node->score=n;
  strcpy(Node->name,s);
  strcpy(Node->mssv,mssv);
  Node->next=NULL;
  return Node;
}
void Insert(list *s,ListNode *Node)
{
  if(s->first==NULL) s->first=s->last=Node;
  else
  {
    s->last->next=Node;
    s->last=s->last->next;
    s->last->next = NULL;
  }
}

void PrintScreen(list *s)
{
  ListNode *Temp;
  Temp=s->first;
  while(Temp!=NULL)
  {
    printf("%10s-%-18s%-5.1f\n",Temp->mssv,Temp->name,Temp->score);
    Temp=Temp->next;
  }
}
int Search(list *s)
{ int count = 0;
  ListNode *Temp;
  Temp=s->first;
   char a[40];
    printf("Moi ban nhap mssv \n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
  while(Temp!=NULL)
  {
    if(strcmp(Temp ->mssv ,a) == 0)
    {
      printf("%10s-%-30s%-5.1f\n",Temp->mssv,Temp->name,Temp->score);
        count=count+1;

    }
    Temp=Temp->next;
  }
  if (count==0)
  {
    /* code */
    printf("khong tim thay sinh vien\n");
  }
  return count;
}
void DeleteMssv(list *s)
  {
  int count = 0;
  ListNode *Temp;
  ListNode *Temp1;
  ListNode *Node;

    char a[40];
    printf("Moi ban nhap mssv can xoa\n");
    fgets(a,40,stdin);
    a[strlen(a) - 1] = '\0';
    printf("%s\n",a );

    if(strcmp(s->first->mssv ,a) == 0)
    {
      s->first = s->first->next;
    }else
    {
    Temp1=(ListNode *)malloc(sizeof(ListNode));
    Temp1->next =s->first;
    Node = Temp1;
    Temp=s->first;

    while(Node->next!=NULL)
    {
      Temp = Node->next;
      if(strcmp(Temp->mssv ,a) == 0)
      {
        ListNode *Save;
        Save = Temp;
        Node->next = Temp->next;
        free(Save);
      }
      else {
      Node = Node->next;
      }
    }
    free(Temp1);
  }
  ListNode *Temp5;
  Temp5=s->first;
  while(Temp5!=NULL)
  {
    printf("%10s-%-18s%-5.1f\n",Temp5->mssv,Temp5->name,Temp5->score);
    Temp5=Temp5->next;
  }
}
void Makelist(list *s)
{
  char Tempchar[31];
   char a[10];
  ListNode *Node;
    printf("Moi ban nhap mssv \n");
    gets(a);
    Node=(ListNode *)malloc(sizeof(ListNode));
    strcpy(Node->mssv,a);
    printf("Nhap vao diem\n");
  scanf("%f",&Node->score);
  while(getchar()!='\n');
   printf("Moi ban nhap ten \n");
    // fgets(Tempchar,40,stdin);
   gets(Tempchar);
        // / Tempchar[strlen(Tempchar) - 1] = '\0';
     strcpy(Node->name,Tempchar);
  Insert(s,Node);
}
void WriteFile(list *s,FILE *f)
{
  ListNode *Temp;
  Temp=s->first;
  while(Temp!=NULL)
  {
    fprintf(f,"%s-%s-%f\n",Temp->mssv,Temp->name,Temp->score);
    Temp=Temp->next;
  }
}
char *catxau(char *a,char *b,char c)    
{
    int i,j= 0,k = 0;
    for(i = 0;i < strlen(a) + 1;i++)
    {
        if(a[i]== c)
        {
            b[i] = '\0';
            j = i + 1; break;
        }
        b[i] = a[i];
        if(i == strlen(a))
        {
            b[i] = '\0';    
        }
    }
    for(i = 0;i < strlen(a) ;i++)
    {
        a[i] = a[i+j];
    }
    return a;
}
void ReadFile()
{
  struct B
          {
            char name[31];
            char mssv[10];
            float score;

          } ListNode;
      struct  B sinhvien[100];
      
  char Tempchar[35];
   char vao[30],Nuon1[30];
    char *Nuon,temp[30],temp1[30];
  FILE *file;
  int i=0,a,sum=0,k;
  float ketqua;

 

  file = fopen("sinhvien.dat","rb");
   // do {
   //    fgets(Tempchar,35,file);

   // printf("%s\n",Tempchar );
   // } while (Tempchar != EOF);
while(fgets(Tempchar,40,file)){
  // printf("%s\n",Tempchar );
  Nuon = catxau(Tempchar,Nuon1,'-');
  // printf("%s---%s\n",Nuon,Nuon1);
  strcpy(sinhvien[i].mssv,Nuon1);
  // printf("%s\n",sinhvien[i].mssv );
  Nuon = catxau(Nuon,Nuon1,'-');
    // printf("%s---%s\n",Nuon,Nuon1);
      strcpy(sinhvien[i].name,Nuon1);
      sinhvien[i].score = atoi(Nuon);
      // printf("%f\n", sinhvien[i].score);
  i = i+1;
}
  for ( a = 0; a <= i; ++a)
  { int d=4;
    /* code */
    if (sinhvien[a].score >=d)
    {
      /* code */
       printf("%s-%s-%f\n",sinhvien[a].mssv,sinhvien[a].name,sinhvien[a].score );
       sum = sum+1;
    }
   
  }
  printf("%d-%d\n",sum,i );
  ketqua = (floats)sum/i;
  printf("so hoc sinh dat la : %.2f phan tram\n",ketqua*100);
  // printf("%f-%d-%d\n",ketqua ,sum,i);
  // k = (float)sum/i;
  // printf("%d\n",k );
}

void main()
{
  int k;
  FILE *f1;
  // float Search_float;
  list *s1,*s2,*s3,*excellent;
  s1=(list *)malloc(sizeof(list));

  while(1)
  {
    printf("\n-----------------MENU-----------------------\n");
    printf("1.Nhap Sinh Vien \n2. Search \n3. Xoa\n4. In\n5.Thoat \n6 ghi file\n 7 SInh vien dat\n------->Please choose\n");
    scanf("%d",&k); while(getchar()!='\n');
    if(k==1)
    {
      Makelist(s1);
      PrintScreen(s1);
    }
    else if(k==2)
    {

      Search(s1);
    }
    else if(k==3)
    {
  
      DeleteMssv(s1);
      // PrintScreen(s1);
    }
    else if(k==4)
    {
  PrintScreen(s1);
    }
    else if(k==5)
    {
      printf("cam on ban da su dung chuong trinh\n");
     break;
    }
    else if(k==6)
    {
     FILE *f=fopen("sinhvien.dat","wb");
     WriteFile(s1,f);
      fclose(f);
    }
      else if(k==7)
    {
      // PrintScreen(s1);
      ReadFile();
        
    }
    else break;
  }
}