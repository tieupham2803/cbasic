#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------------
typedef struct A
{
	int Masp;
	char Tensp[20];
	int GiaSp;
	int soluong;
	int danhdau;
	struct A *next;
} ListNode;
typedef struct 
{
	ListNode *first,*last;
} list;
void Insert(list *s,ListNode *Node)
{
	if(s->first==NULL)
		s->first=s->last=Node;
	else
	{
		s->last->next=Node;
		s->last=s->last->next;
	}
}
ListNode *DeleteToLast(list *s)
{
	ListNode *temp;
	ListNode *temp1;
	temp=s->first;
	while(temp->next!=NULL)
	{
		temp1=temp;		
		temp=temp->next;
	}
	temp1->next=NULL;
	return temp;
}
void InputData(list *s)
{
	ListNode *Node;
	int TempMasp=-1;
	do
	{
		Node=(ListNode *)malloc(sizeof(ListNode));
		printf("Nhap vao ma san pham     :"); scanf("%d",&Node->Masp); while(getchar()!='\n');
		while(TempMasp >= Node->Masp && Node->Masp!=0)	
		{
			printf("Nhap lai ma san pham  :"); scanf("%d",&Node->Masp); while(getchar()!='\n');
		}
		printf("Nhap vao ten ma san pham :"); gets(Node->Tensp);
		printf("Nhap vao gia san pham    :"); scanf("%d",&Node->GiaSp);
		while(Node->GiaSp <=0 )
		{
			printf("Nhao lai gia cua san pham :"); scanf("%d",&Node->GiaSp);
		}
		printf("Nhao vao so luong san pham :"); scanf("%d",&Node->soluong);
		while(Node->soluong <0 )
		{
			printf("Nhao lai so luong san pham :"); scanf("%d",&Node->soluong);
		}		
		TempMasp=Node->Masp;
		Node->danhdau=0;
		Insert(s,Node);
	}while(TempMasp!=0);
	DeleteToLast(s);
	PrintScreen(s);
}
void PrintScreen(list *s)
{
	ListNode *temp=s->first;
	int count=1;
	while(temp!=NULL)
	{
		printf("%-3d%-7d%-4d%-20s\n",temp->Masp,temp->GiaSp,temp->soluong,temp->Tensp);
		temp=temp->next;
	}
}
void Sapxep(list *s)
{
	char Tempchar[20];
	int a,b,c;
	ListNode *temp,*temp1;
	for(temp=s->first;temp!=NULL;temp=temp->next)
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(temp->GiaSp> temp1->GiaSp)
			{
				strcpy(Tempchar,temp->Tensp);
				strcpy(temp->Tensp,temp1->Tensp);
				strcpy(temp1->Tensp,Tempchar);
				a=temp->Masp;
				temp->Masp=temp1->Masp;
				temp1->Masp=a;
				b=temp->GiaSp;
				temp->GiaSp=temp1->GiaSp;
				temp1->GiaSp=b;
				c=temp->soluong;
				temp->soluong=temp1->soluong;
				temp1->soluong=c;										
			}
		}
}
int CountGroup(list *s)
{
	int count=0;
	ListNode *temp,*temp1;
	for(temp=s->first;temp!=NULL;temp=temp->next)
	{
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(temp->GiaSp=temp1->GiaSp && temp1->danhdau==0 && temp->danhdau==0)
			{
				temp->danhdau=1;
				temp1->danhdau=1;
				count++;
			}
			else if(temp->GiaSp=temp1->GiaSp && temp->danhdau==1 && temp1->danhdau==0)
				temp1->danhdau=1;
		}
	}
	return count;	
}
void InTen(list *s)
{
	ListNode *Node=s->first;
	while(Node!=NULL)
	{
		Node->danhdau=0;
		Node=Node->next;
	}
	ListNode *temp,*temp1;
	for(temp=s->first;temp!=NULL;temp=temp->next)
	{
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(strcmp(temp->Tensp,temp1->Tensp)==0 && temp1->danhdau==0 && temp->danhdau==0)
			{
				printf("%-3d%-7d%-4d%-20s\n",temp->Masp,temp->GiaSp,temp->soluong,temp->Tensp);		
				printf("%-3d%-7d%-4d%-20s\n",temp1->Masp,temp1->GiaSp,temp1->soluong,temp1->Tensp);							
				temp->danhdau=1;
				temp1->danhdau=1;
			}
			else if(strcmp(temp->Tensp,temp1->Tensp)==0 && temp->danhdau==1 && temp1->danhdau==0)
			{	
				printf("%-3d%-7d%-4d%-20s\n",temp1->Masp,temp1->GiaSp,temp1->soluong,temp1->Tensp);	
				temp1->danhdau=1;
			}
		}
	}	

}
void main()
{
	int k;
	list *s=(list *)malloc(sizeof(list));
	s->first=s->last=NULL;
	while(1)
	{
		printf("\n-----------------MENU-----------------------\n");
		printf("1. Nhap du lieu \n2. Sap xep\n3. Dem san phan trung gia\n4. Ten trung nhau \n------->Please choose");
		scanf("%d",&k); while(getchar()!='\n');
		if(k==1) InputData(s);
		else if(k==2)
		{
			Sapxep(s);
			PrintScreen(s);
		}

		else if(k==3)
			printf("so nhom trung gia: %d\n",CountGroup(s));
		else if(k==4) InTen(s);
		else break;
	}
}
