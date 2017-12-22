#include <stdio.h>
#include "Quene.h"
#include <stdlib.h>
#include <string.h>
//===============================================================================================
int Read_file(Monphai **top,char *x)
{
	int tong = 0;
    Monphai *Node;
    char s[50],filename[50];
    int a,b,c,d;
    FILE *ptr;
    strcpy(filename,x);
    if((ptr = fopen(filename ,"r")) == NULL)
    {
        printf("Can not file\n");
    }
    else
    {
        while(fscanf(ptr,"%s",s) == 1)
        {
        	tong++;
            fscanf(ptr,"%d%d%d%d",&a,&b,&c,&d);
            if(a < 0 || b < 0|| c < 0|| d< 0) break;
            else
            {
                Node = AddQueue(s,a,b,c,d);
                InsearNode(&(*top),Node);
            }
        }       
    }
    fclose(ptr);
    return tong;
}
//==================================================================================================
Monphai * AddQueue(char *s,int a,int b,int c,int d)
{
    Monphai *Node;
    Node = (Monphai*)malloc(sizeof(Monphai));
    if(Node == NULL)
    {
        printf("Memory is full\n");
        return NULL;
    }
    else
    {
        strcpy(Node -> Name,s);
        Node -> mau = a;
        Node -> tancong = b;
        Node -> nhanhnhen = c;
        Node -> phongthu = d;
        Node -> point = 0;
    }
    Node -> next = NULL;
    return Node;
}
//=========================================================================================================
void Truepoint(int a)
{
    if(a < 0)
        printf("File khong hop le moi ban nhap lai\n");
}
//======================================================================================================
void InsearNode(Monphai **top,Monphai *Node)
{
    Monphai *temp;
    if((*top) == NULL)	
    {
        (*top) = Node;
    }
    else
    {
        temp = (*top);
        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = Node;
    }
}
//=======================================================================================================
void Prin1()
{
    printf("%-20s%-5s%-10s%-15s%-5s%5s\n", "Name", "mau", "tancong","nhanhnhen","phongthu","Diem"); 
}
//=========================================================================================================
void Prin(Monphai *top)
{
    if(top)
    {
        printf("%-20s%-5d%-10d%-15d%-5d%5d\n",top -> Name,top -> mau,top -> tancong,top ->nhanhnhen,top ->phongthu,top ->point );
        Prin(top -> next);
    }
}