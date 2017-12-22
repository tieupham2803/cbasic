/*
Ho va Ten : Nguyen Van Quang
MSSV      : 20133099
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Quene.h"

void DataInput(Monphai **top1,Monphai **top2);
void addHead(Monphai **top, Monphai *newNode);
void Strart(Monphai **top1,Monphai **top2);
int thidau(Monphai *a,Monphai *b);
void luotdanh(Monphai **top1,Monphai **top2,int l);
void Mp2truoc(Monphai **top1,Monphai **top2,int l);
void Mp1truoc(Monphai **top1,Monphai **top2,int l);
void Taodsmoi(Monphai **top3,Monphai **top1,Monphai **top2);
void Addsort(Monphai *newNode,Monphai **top3);

main()
{
    Monphai *top3 =NULL;
    Monphai *top1 = NULL;
    Monphai *top2 = NULL;
    int imenu;
    while(1)
    {   
        printf("\n==============MENU==============\n");
        printf("  1:Tao Data\n");
        printf("  2:In ds\n");
        printf("  3:Bat dau tran dau\n");
        printf("  4:Xuong hang va in \n");
        printf("  5:Xuat file \n");
        printf("  6:Thoat\n");
        printf("Moi ban chon chuc nang\n");
        scanf("%d",&imenu);
        while(getchar() != '\n');
        switch(imenu)
        {   
            case 1 :
            {
                DataInput(&top1,&top2);
                continue;
            }
            case 2 :
            {
                Prin1();
                Prin(top1);
                Prin(top2);
                continue;
            }
            case 3 :
            {
                Strart(&top1,&top2);
                continue;
            }
            case 4:
            {
                Taodsmoi(&top3,&top1,&top2);
                Prin(top3);
                continue;
            }
            case 5 :
            {
                Prin(top2);
                continue;
            }
            default :
            {
                printf("Input wroong!...\n");
                printf("Please input again!\n");
            }
            case 6 :
            {
                //Deleteall(root);
                break;
            }
        }
        break;
    }
}

void DataInput(Monphai **top1,Monphai **top2)
{
    int tong1,tong2;
    char s1[50],s2[50];
    while(1)
    {
        printf("Moi ban nhap file name doc \n");
        fgets(s1,50,stdin);
        s1[strlen(s1) - 1] = '\0';
        fgets(s2,50,stdin);
        s2[strlen(s2) - 1] = '\0' ;    
        tong1 = Read_file(&(*top1),s1);
        tong2 = Read_file(&(*top2),s2);
        if(tong1 == tong2) break;
        else
            printf("Moi ban nhap lai file dau vao\n");
    }
}

void Strart(Monphai **top1,Monphai **top2)
{
    Monphai *a,*b;
    a = (*top1);
    b = (*top2);
    int l,k = 0;
    printf("Loi dai bat dau \n");
    while((a) != NULL || (b) != NULL)
    {
        k++;
        printf("Tran %d Mp1 %s(%d %d %d %d)-", k,(a)-> Name,(a)-> mau,
            (a)-> tancong,(a)->nhanhnhen,(a)->phongthu);
            printf("Mp2 %s(%d %d %d %d)\n", (b)-> Name,(b)-> mau,
            (b)-> tancong,(b)->nhanhnhen,(b)->phongthu);       
        l = 0;
        luotdanh(&(a),&(b),l);
        if((b) == NULL)
        {
            printf("MP2 thua\n");
            break;
        }
        else if((a) == NULL)
        {
            printf("MP1 thua\n");
            break;
        }
    }
}

int thidau(Monphai *a,Monphai *b)
{
    int m;
    m = a -> tancong - b -> phongthu;
    if(m < 0) m = 0;
    b -> mau = b -> mau - m;
    if(b -> mau < 0) b-> mau = 0;
    a -> point++;
    return m;
}

void luotdanh(Monphai **top1,Monphai **top2,int l)
{
    while((*top1) != NULL || (*top2) != NULL)
        { 
        l++;
        if((*top1) -> nhanhnhen < (*top2) -> nhanhnhen)
        {
            Mp2truoc(&(*top1),&(*top2),l);
        }
        if((*top1) -> nhanhnhen > (*top2) -> nhanhnhen) Mp1truoc(&(*top2),&(*top1),l);
        if((*top1) -> mau <= 0 || (*top2) -> mau <= 0 )
        {
            if((*top1) -> mau <= 0) 
            {
                printf("MP1 %s bi loai\n",(*top1)->Name );
                if(l == 1) (*top2) -> point = (*top2) -> point + 2;
                (*top1) = (*top1) -> next;
                break;
            }
            else if((*top2) -> mau <= 0)
            {
                printf("MP2 %s bi loai\n",(*top2)->Name );
                if(l == 1) (*top1) -> point = (*top1) -> point + 2;
                (*top2) = (*top2) -> next;
                break;
            }
        }
    }
}
//============================================================
void Mp2truoc(Monphai **top1,Monphai **top2,int l)
{
    int m;
    if(l % 2 != 0)
    {
        printf("luot %d\n",l );
        m = thidau(*top2,*top1);
        printf("MP2 %s (%d) tan cong - MP1 %s (%d) mat %d mau\n",(*top2) -> Name,(*top2)-> mau,(*top1) -> Name,(*top1)  -> mau,m );
    }
    else if( l % 2 == 0)
    {
        printf("luot %d\n",l );
        m = thidau(*top1,*top2);
        printf("MP1 %s (%d) tan cong - MP2 %s (%d) mat %d mau\n",(*top1) -> Name,(*top1)-> mau,(*top2)   -> Name,(*top2)  -> mau,m );
    }
}

void Mp1truoc(Monphai **top1,Monphai **top2,int l)
{
    int m;
    if(l % 2 != 0)
    {
        printf("luot %d\n",l );
        m = thidau(*top2,*top1);
        printf("MP1 %s (%d) tan cong - MP2 %s (%d) mat %d mau\n",(*top1) -> Name,(*top1)-> mau,(*top2)   -> Name,(*top2)  -> mau,m );
    }
    else if( l % 2 == 0)
    {
        printf("luot %d\n",l );
        m = thidau(*top1,*top2);
        printf("MP2 %s (%d) tan cong - MP1 %s (%d) mat %d mau\n",(*top2) -> Name,(*top2)-> mau,(*top1)   -> Name,(*top1)  -> mau,m );
    }
}

void Addsort(Monphai *newNode,Monphai **top3)
{
    if((*top3) == NULL)
        {
            addHead(&(*top3),newNode);
        }
        else
        {
        Monphai *sau,*truoc;

          sau=(*top3);
          truoc=(*top3);
          if (newNode->point>sau->point)
          {
               newNode->next=(*top3);
               (*top3)=newNode;
          } else
          {
               while ( (sau!=NULL) && (sau->point>=newNode->point) )
               {
                    truoc=sau;
                    sau=sau->next;
               }
               truoc->next=newNode;
               newNode->next=sau;
          }
      }
}

void Taodsmoi(Monphai **top3,Monphai **top1,Monphai **top2)
{
    Monphai *Node1,*Node2;
    while((*top1))
    {
        Node1 = (*top1);
        Node2 = (*top2);
        (*top1) = (*top1)->next;
        (*top2) = (*top2)->next;
        Addsort(Node1,&(*top3));
        printf("%s\n", "1");
        Addsort(Node2,&(*top3));
        printf("%s\n", "1");
    }
}

void addHead(Monphai **top, Monphai *newNode)
{
     newNode->next=(*top);
     (*top)=newNode;
}
